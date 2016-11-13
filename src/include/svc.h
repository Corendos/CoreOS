#ifndef __SVC_H__
#define __SVC_H__

#include <stddef.h>
#include <stdint.h>

void svc_call(uint32_t code);

#endif