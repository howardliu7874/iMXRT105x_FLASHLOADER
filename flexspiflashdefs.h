/*
* The Clear BSD License
* Copyright (c) 2015-2016, Freescale Semiconductor, Inc.
 * Copyright 2018 NXP
* All rights reserved.
*
* 
* Redistribution and use in source and binary forms, with or without modification,
* are permitted (subject to the limitations in the disclaimer below) provided
*  that the following conditions are met:
*
* o Redistributions of source code must retain the above copyright notice, this list
*   of conditions and the following disclaimer.
*
* o Redistributions in binary form must reproduce the above copyright notice, this
*   list of conditions and the following disclaimer in the documentation and/or
*   other materials provided with the distribution.
*
* o Neither the name of the copyright holder nor the names of its
*   contributors may be used to endorse or promote products derived from this
*   software without specific prior written permission.
*
* NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
* ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "stdint.h"

// Size definitions for FlexSPI nor flash on EVKB
#define FLASH_PAGE_SIZE  (0x100) //Programming Page Siz (256)
#define FLASH_SECTORE_SIZE (0x1000) //4K
#define FLASH_SIZE (0x00800000U) //8MB

// Redefine i.MX RT1050 external flash (FlexSPI) based address
#define FLASH_BASE_ADDR (0x60000000)

#define EXAMPLE_FLEXSPI FLEXSPI

/** local definitions **/
#define FLEXSPI_NOR_CMD_NORD        0x03
#define FLEXSPI_NOR_CMD_FRD         0x0B
#define FLEXSPI_NOR_CMD_FRDIO       0xBB
#define FLEXSPI_NOR_CMD_FRDO        0x3B
#define FLEXSPI_NOR_CMD_FRQIO       0xEB
#define FLEXSPI_NOR_CMD_FRQO        0x6B
#define FLEXSPI_NOR_CMD_FRDTR       0x0D
#define FLEXSPI_NOR_CMD_FRDDTR      0xBD
#define FLEXSPI_NOR_CMD_FRQDTR      0xED
#define FLEXSPI_NOR_CMD_PP          0x02
#define FLEXSPI_NOR_CMD_PPQ         0x32
#define FLEXSPI_NOR_CMD_SER         0xD7
#define FLEXSPI_NOR_CMD_BER32       0x52
#define FLEXSPI_NOR_CMD_BER64       0xD8
#define FLEXSPI_NOR_CMD_SECUNLOCK   0x26
#define FLEXSPI_NOR_CMD_RDDYB       0xFA
#define FLEXSPI_NOR_CMD_WRDYB       0xFB
#define FLEXSPI_NOR_CMD_RDPPB       0xFC
#define FLEXSPI_NOR_CMD_PGPPB       0xFD
#define FLEXSPI_NOR_CMD_4NORD       0x13
#define FLEXSPI_NOR_CMD_4FRD        0x0C
#define FLEXSPI_NOR_CMD_4FRDIO      0xBC
#define FLEXSPI_NOR_CMD_4FRDO       0x3C
#define FLEXSPI_NOR_CMD_4FRQIO      0xEC
#define FLEXSPI_NOR_CMD_4FRQO       0x6C
#define FLEXSPI_NOR_CMD_4FRDTR      0x0E
#define FLEXSPI_NOR_CMD_4FRDDTR     0xBE
#define FLEXSPI_NOR_CMD_4FRQDTR     0xEE
#define FLEXSPI_NOR_CMD_4PP         0x12
#define FLEXSPI_NOR_CMD_4PPQ        0x3E
#define FLEXSPI_NOR_CMD_4SER        0x21
#define FLEXSPI_NOR_CMD_4BER32      0x5C
#define FLEXSPI_NOR_CMD_4BER64      0xDC
#define FLEXSPI_NOR_CMD_4SECUNLOCK  0x25
#define FLEXSPI_NOR_CMD_4RDDYB      0xE0
#define FLEXSPI_NOR_CMD_4WRDYB      0xE1
#define FLEXSPI_NOR_CMD_4RDPPB      0xE2
#define FLEXSPI_NOR_CMD_4PGPPB      0xE3
#define FLEXSPI_NOR_CMD_CER         0x60
#define FLEXSPI_NOR_CMD_WREN        0x06
#define FLEXSPI_NOR_CMD_WRDI        0x04
#define FLEXSPI_NOR_CMD_RDSR        0x05
#define FLEXSPI_NOR_CMD_WRSR        0x01
#define FLEXSPI_NOR_CMD_RDFR        0x48
#define FLEXSPI_NOR_CMD_WRFR        0x42
#define FLEXSPI_NOR_CMD_QIOEN       0x35
#define FLEXSPI_NOR_CMD_QIODI       0xF5
#define FLEXSPI_NOR_CMD_PERSUS      0xB0
#define FLEXSPI_NOR_CMD_PERRSM      0x30
#define FLEXSPI_NOR_CMD_DP          0xB9
#define FLEXSPI_NOR_CMD_RDID        0xAB
#define FLEXSPI_NOR_CMD_SRPNV       0x65
#define FLEXSPI_NOR_CMD_SRPV        0x63
#define FLEXSPI_NOR_CMD_SERPNV      0x85
#define FLEXSPI_NOR_CMD_SERPV       0x83
#define FLEXSPI_NOR_CMD_RDRP        0x61
#define FLEXSPI_NOR_CMD_RDERP       0x81
#define FLEXSPI_NOR_CMD_CLERP       0x82
#define FLEXSPI_NOR_CMD_RDJDID      0x9F
#define FLEXSPI_NOR_CMD_RDMDID      0x90
#define FLEXSPI_NOR_CMD_RDJDIDQ     0xAF
#define FLEXSPI_NOR_CMD_RDUID       0x4B
#define FLEXSPI_NOR_CMD_RDSFDP      0x5A
#define FLEXSPI_NOR_CMD_NOP         0x00
#define FLEXSPI_NOR_CMD_RSTEN       0x66
#define FLEXSPI_NOR_CMD_RST         0x99
#define FLEXSPI_NOR_CMD_IRER        0x64
#define FLEXSPI_NOR_CMD_IRP         0x62
#define FLEXSPI_NOR_CMD_IRRD        0x68
#define FLEXSPI_NOR_CMD_SECLOCK     0x24
#define FLEXSPI_NOR_CMD_RDABR       0x14
#define FLEXSPI_NOR_CMD_WRABR       0x15
#define FLEXSPI_NOR_CMD_RDBR        0xC8
#define FLEXSPI_NOR_CMD_WRBRV       0xC5
#define FLEXSPI_NOR_CMD_WRBRNV      0x18
#define FLEXSPI_NOR_CMD_EN4B        0xB7
#define FLEXSPI_NOR_CMD_EX4B        0x29
#define FLEXSPI_NOR_CMD_RDASP       0x2B
#define FLEXSPI_NOR_CMD_PGASP       0x2F
#define FLEXSPI_NOR_CMD_RDPLB       0xA7
#define FLEXSPI_NOR_CMD_WRPLB       0xA6
#define FLEXSPI_NOR_CMD_SFRZ        0x91
#define FLEXSPI_NOR_CMD_RDPWD       0xE7
#define FLEXSPI_NOR_CMD_PGPWD       0xE8
#define FLEXSPI_NOR_CMD_UNPWD       0xE9
#define FLEXSPI_NOR_CMD_GBLK        0x7E
#define FLEXSPI_NOR_CMD_GBUN        0x98

#define ADDR_3B        24
#define ADDR_4B        32 

/* Common LUT definitions */
#define LUT_SEQ_IDX_READ_FRQIO 0
#define LUT_SEQ_IDX_READID 1
#define LUT_SEQ_IDX_WRITEENABLE 2
#define LUT_SEQ_IDX_ERASESECTOR 3
#define LUT_SEQ_IDX_ERASECHIP 4
#define LUT_SEQ_IDX_PAGEPROGRAM_QUAD 5
#define LUT_SEQ_IDX_READSTATUSREG 6
#define LUT_SEQ_IDX_WRITESTATUSREG 7


#define CUSTOM_LUT_LENGTH 32
#define FLASH_BUSY_STATUS_POL 1
#define FLASH_BUSY_STATUS_OFFSET 0

extern const uint32_t customLUT[];

void flexspi_flash_init(void);
int32_t flexspi_flash_erase_chip(void);
int32_t flexspi_flash_block_erase_4K(uint32_t address);
int32_t flexspi_flash_page_program(uint32_t address, uint32_t size, uint8_t * data);
