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
/*************************************************************************
 *
 * Common LUT definitions
 *
 **************************************************************************/
 #include "fsl_flexspi.h"
 #include "flexspiflashdefs.h"
 
const uint32_t customLUT[CUSTOM_LUT_LENGTH] = {
    /* Fast read Quad Input/output sequence*/
    [4 * LUT_SEQ_IDX_READ_FRQIO] 		 = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, FLEXSPI_NOR_CMD_FRQIO, kFLEXSPI_Command_RADDR_SDR, kFLEXSPI_4PAD, ADDR_3B),
    [4 * LUT_SEQ_IDX_READ_FRQIO + 1] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_DUMMY_SDR, kFLEXSPI_4PAD, 6, kFLEXSPI_Command_READ_SDR, kFLEXSPI_4PAD, 8),
	[4 * LUT_SEQ_IDX_READ_FRQIO + 2] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_JUMP_ON_CS, 0, 0, kFLEXSPI_Command_STOP, 0, 0),
	[4 * LUT_SEQ_IDX_READ_FRQIO + 3] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),
	
	/*READ ID sequence*/
    [4 * LUT_SEQ_IDX_READID] 		 = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, FLEXSPI_NOR_CMD_RDJDID, kFLEXSPI_Command_READ_SDR, kFLEXSPI_1PAD, 3),
    [4 * LUT_SEQ_IDX_READID + 1] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),
	[4 * LUT_SEQ_IDX_READID + 2] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),
	[4 * LUT_SEQ_IDX_READID + 3] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),
	
	/*Write Enable sequence*/
	[4 * LUT_SEQ_IDX_WRITEENABLE] 		= FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, FLEXSPI_NOR_CMD_WREN, kFLEXSPI_Command_STOP, 0, 0),
    [4 * LUT_SEQ_IDX_WRITEENABLE + 1] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),
	[4 * LUT_SEQ_IDX_WRITEENABLE + 2] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),
	[4 * LUT_SEQ_IDX_WRITEENABLE + 3] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),

	/*Block 4K Erase sequence*/
	[4 * LUT_SEQ_IDX_ERASESECTOR] 		= FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, FLEXSPI_NOR_CMD_SER, kFLEXSPI_Command_RADDR_SDR, kFLEXSPI_1PAD, ADDR_3B),
    [4 * LUT_SEQ_IDX_ERASESECTOR + 1] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),
	[4 * LUT_SEQ_IDX_ERASESECTOR + 2] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),
	[4 * LUT_SEQ_IDX_ERASESECTOR + 3] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),

	/*Chip Erase sequence*/
	[4 * LUT_SEQ_IDX_ERASECHIP] 		= FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, FLEXSPI_NOR_CMD_CER, kFLEXSPI_Command_STOP, 0, 0),
    [4 * LUT_SEQ_IDX_ERASECHIP + 1] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),
	[4 * LUT_SEQ_IDX_ERASECHIP + 2] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),
	[4 * LUT_SEQ_IDX_ERASECHIP + 3] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),
	
	/*Quad Page Program secquence*/
	[4 * LUT_SEQ_IDX_PAGEPROGRAM_QUAD] 		 = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, FLEXSPI_NOR_CMD_PPQ, kFLEXSPI_Command_RADDR_SDR, kFLEXSPI_1PAD, ADDR_3B),
    [4 * LUT_SEQ_IDX_PAGEPROGRAM_QUAD + 1] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_WRITE_SDR, kFLEXSPI_4PAD, 0, kFLEXSPI_Command_STOP, 0, 0),
	[4 * LUT_SEQ_IDX_PAGEPROGRAM_QUAD + 2] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),
	[4 * LUT_SEQ_IDX_PAGEPROGRAM_QUAD + 3] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),
	
	/*Read Status Register sequence*/ 
	[4 * LUT_SEQ_IDX_READSTATUSREG] 		 = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, FLEXSPI_NOR_CMD_RDSR, kFLEXSPI_Command_READ_SDR, kFLEXSPI_1PAD, 1),
    [4 * LUT_SEQ_IDX_READSTATUSREG + 1] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),
	[4 * LUT_SEQ_IDX_READSTATUSREG + 2] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),
	[4 * LUT_SEQ_IDX_READSTATUSREG + 3] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),
	
	/*Write Status Register sequence*/
	[4 * LUT_SEQ_IDX_WRITESTATUSREG] 		 = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_SDR, kFLEXSPI_1PAD, FLEXSPI_NOR_CMD_WRSR, kFLEXSPI_Command_WRITE_SDR, kFLEXSPI_1PAD, 1),
    [4 * LUT_SEQ_IDX_WRITESTATUSREG + 1] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),
	[4 * LUT_SEQ_IDX_WRITESTATUSREG + 2] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),
	[4 * LUT_SEQ_IDX_WRITESTATUSREG + 3] = FLEXSPI_LUT_SEQ(kFLEXSPI_Command_STOP, 0, 0, kFLEXSPI_Command_STOP, 0, 0),
};
 
 



