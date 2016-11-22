#include "kernel_low.h"

#define AVAILABLE_MEMORY 522 240
#define NUMBER_OF_PAGE 130 560
#define NUMBER_OF_BYTE 16 320
#define VIRTUAL_START 0x80000000


extern uint32_t virtual_start;
extern void activate_mmu(void);

__attribute__((section(".data.page")))

uint8_t pages[16320];

__attribute__((section(".data.section_descriptor")))
uint32_t first_level_entries[4096];

__attribute__((section(".data.section_descriptor")))
uint32_t kcode_sl_entries[256];

__attribute__((section(".data.section_descriptor")))
uint32_t kdata_sl_entries[256];

__attribute__((section(".data.section_descriptor")))
uint32_t icode_sl_entries[256];

__attribute__((section(".data.section_descriptor")))
uint32_t idata_sl_entries[256];

__attribute__((section(".text.low_kernel")))

void kernel_low(uint32_t r0, uint32_t r1, uint32_t atags)
{
	(void)r0;
	(void)r1;
	(void)atags;
	low_kernel_init_desc();
	activate_mmu();
}

__attribute__((section(".text.low_kernel")))

void low_kernel_init_desc(void)
{
	uint32_t* first_level_entries_physical = (uint32_t*)((uint32_t)first_level_entries - VIRTUAL_START);
	uint32_t* kernel_code_second_level_entries_physical = (uint32_t*)((uint32_t)kcode_sl_entries - VIRTUAL_START);
	uint32_t* kernel_data_second_level_entries_physical = (uint32_t*)((uint32_t)kdata_sl_entries - VIRTUAL_START);

	for(int i = 0;i < 4096;++i)
	{
		first_level_entries_physical[i] = 0x00;
	}

	for(int i = 0;i < 256;++i)
	{
		kernel_code_second_level_entries_physical[i] = 0x00;
		kernel_data_second_level_entries_physical[i] = 0x00;
	}

	first_level_entries_physical[2048] = ((uint32_t)kernel_code_second_level_entries_physical & 0xFFFFFC00) | 0x01;
	first_level_entries_physical[2049] = ((uint32_t)kernel_data_second_level_entries_physical & 0xFFFFFC00) | 0x01;

	for(int i = 0;i < 256;++i)
	{
		kernel_code_second_level_entries_physical[i] = (i * 0x1000) | 0x2;
		kernel_data_second_level_entries_physical[i] = (0x00100000 + (i * 0x100)) | 0x2;
	}
}