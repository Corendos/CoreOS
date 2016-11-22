ENTRY(reset)

virtual_start = 0x80000000;

kernel_code_start_physical = 0x00010000;
kernel_data_start_physical = 0x00100000;
kernel_data_start_virtual = virtual_start + kernel_data_start_physical;

SECTIONS
{
    __start = .;

    .text.isr :
    {
        KEEP(*(.text.isr));
    }

    . = kernel_code_start_physical;

    __low_kernel_start = .;
    .text.low_kernel :
    {
        KEEP(*(.text.low_kernel))
    }
    . = ALIGN(4096);
    __low_kernel_end = .;


    high_kernel_code_start_virtual = virtual_start + __low_kernel_end;

    . = high_kernel_code_start_virtual;

    __text_start = .;
    .text : AT(__text_start - virtual_start)
    {
        KEEP(*(.text.boot))
        *(.text)
    }
    . = ALIGN(4096);
    __text_end = .;
    

    . = kernel_data_start_virtual;


    __data_start = .;
    .data : AT(__data_start - virtual_start)
    {
        KEEP(*(.data.var));
        KEEP(*(.data.page));
        . = ALIGN(16384);
        KEEP(*(.data.section_descriptor));
        *(.data)
    }
    . = ALIGN(4096);
    __data_end = .;



    __rodata_start = .;
    .rodata : AT(__rodata_start - virtual_start)
    {
        *(.rodata)
    }
    . = ALIGN(4096);
    __rodata_end = .;
 


    __bss_start = .;
    .bss : AT(__bss_start - virtual_start)
    {
        bss = .;
        *(.bss)
    }
    . = ALIGN(4096);
    __bss_end = .;



    __end = .;
}
