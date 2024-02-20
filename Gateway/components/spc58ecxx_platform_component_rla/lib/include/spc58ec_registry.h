/****************************************************************************
*
* Copyright © 2015-2019 STMicroelectronics - All Rights Reserved
*
* This software is licensed under SLA0098 terms that can be found in the
* DM00779817_1_0.pdf file in the licenses directory of this software product.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*****************************************************************************/

/**
 * @file    spc58ec_registry.h
 * @brief   SPC58ECxx capabilities registry.
 *
 * @addtogroup PLATFORM
 * @{
 */

#ifndef SPC5_REGISTRY_H
#define SPC5_REGISTRY_H

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/**
 * @name    SPC58ECxx capabilities
 * @{
 */
/* eDMA attribures.*/
#define SPC5_HAS_EDMA                       TRUE
#define SPC5_HAS_EDMA0                      FALSE
#define SPC5_HAS_EDMA1                      TRUE
#define SPC5_EDMA_DMA1_BASE                 0xF40A4000UL
#define SPC5_EDMA_NCHANNELS                 64U
#define SPC5_EDMA_COMBO_CH_ERR_HANDLER      vector52
#define SPC5_EDMA_CH0_HANDLER               vector53
#define SPC5_EDMA_CH1_HANDLER               vector54
#define SPC5_EDMA_CH2_HANDLER               vector55
#define SPC5_EDMA_CH3_HANDLER               vector56
#define SPC5_EDMA_CH4_HANDLER               vector57
#define SPC5_EDMA_CH5_HANDLER               vector58
#define SPC5_EDMA_CH6_HANDLER               vector59
#define SPC5_EDMA_CH7_HANDLER               vector60
#define SPC5_EDMA_CH8_HANDLER               vector61
#define SPC5_EDMA_CH9_HANDLER               vector62
#define SPC5_EDMA_CH10_HANDLER              vector63
#define SPC5_EDMA_CH11_HANDLER              vector64
#define SPC5_EDMA_CH12_HANDLER              vector65
#define SPC5_EDMA_CH13_HANDLER              vector66
#define SPC5_EDMA_CH14_HANDLER              vector67
#define SPC5_EDMA_CH15_HANDLER              vector68
#define SPC5_EDMA_CH16_HANDLER              vector69
#define SPC5_EDMA_CH17_HANDLER              vector70
#define SPC5_EDMA_CH18_HANDLER              vector71
#define SPC5_EDMA_CH19_HANDLER              vector72
#define SPC5_EDMA_CH20_HANDLER              vector73
#define SPC5_EDMA_CH21_HANDLER              vector74
#define SPC5_EDMA_CH22_HANDLER              vector75
#define SPC5_EDMA_CH23_HANDLER              vector76
#define SPC5_EDMA_CH24_HANDLER              vector77
#define SPC5_EDMA_CH25_HANDLER              vector78
#define SPC5_EDMA_CH26_HANDLER              vector79
#define SPC5_EDMA_CH27_HANDLER              vector80
#define SPC5_EDMA_CH28_HANDLER              vector81
#define SPC5_EDMA_CH29_HANDLER              vector82
#define SPC5_EDMA_CH30_HANDLER              vector83
#define SPC5_EDMA_CH31_HANDLER              vector84
#define SPC5_EDMA_CH32_HANDLER              vector85
#define SPC5_EDMA_CH33_HANDLER              vector86
#define SPC5_EDMA_CH34_HANDLER              vector87
#define SPC5_EDMA_CH35_HANDLER              vector88
#define SPC5_EDMA_CH36_HANDLER              vector89
#define SPC5_EDMA_CH37_HANDLER              vector90
#define SPC5_EDMA_CH38_HANDLER              vector91
#define SPC5_EDMA_CH39_HANDLER              vector92
#define SPC5_EDMA_CH40_HANDLER              vector93
#define SPC5_EDMA_CH41_HANDLER              vector94
#define SPC5_EDMA_CH42_HANDLER              vector95
#define SPC5_EDMA_CH43_HANDLER              vector96
#define SPC5_EDMA_CH44_HANDLER              vector97
#define SPC5_EDMA_CH45_HANDLER              vector98
#define SPC5_EDMA_CH46_HANDLER              vector99
#define SPC5_EDMA_CH47_HANDLER              vector100
#define SPC5_EDMA_CH48_HANDLER              vector101
#define SPC5_EDMA_CH49_HANDLER              vector102
#define SPC5_EDMA_CH50_HANDLER              vector103
#define SPC5_EDMA_CH51_HANDLER              vector104
#define SPC5_EDMA_CH52_HANDLER              vector105
#define SPC5_EDMA_CH53_HANDLER              vector106
#define SPC5_EDMA_CH54_HANDLER              vector107
#define SPC5_EDMA_CH55_HANDLER              vector108
#define SPC5_EDMA_CH56_HANDLER              vector109
#define SPC5_EDMA_CH57_HANDLER              vector110
#define SPC5_EDMA_CH58_HANDLER              vector111
#define SPC5_EDMA_CH59_HANDLER              vector112
#define SPC5_EDMA_CH60_HANDLER              vector113
#define SPC5_EDMA_CH61_HANDLER              vector114
#define SPC5_EDMA_CH62_HANDLER              vector115
#define SPC5_EDMA_CH63_HANDLER              vector116
#define SPC5_EDMA_COMBO_CH_ERR_NUMBER       52U
#define SPC5_EDMA_CH0_NUMBER                53U
#define SPC5_EDMA_HAS_MUX                   TRUE
#define SPC5_EDMA_NUM_OF_MUX                4U
#define SPC5_EDMA_MUX0_BASE                 0xF7F6C000UL
#define SPC5_EDMA_MUX0_CH_NUM               16U
#define SPC5_EDMA_MUX1_BASE                 0xFBF6C000UL
#define SPC5_EDMA_MUX1_CH_NUM               16U
#define SPC5_EDMA_MUX2_BASE                 0xF7F6C200UL
#define SPC5_EDMA_MUX2_CH_NUM               16U
#define SPC5_EDMA_MUX3_BASE                 0xFBF6C200UL
#define SPC5_EDMA_MUX3_CH_NUM               16U
#define SPC5_EDMA_MUX0_PCTL                 36
#define SPC5_EDMA_MUX1_PCTL                 164

/* DSPI attributes.*/
#define SPC5_HAS_DSPI0                      TRUE
#define SPC5_DSPI0_BASE                     0xF7E70000UL
#define SPC5_HAS_DSPI1                      TRUE
#define SPC5_DSPI1_BASE                     0xFBE70000UL
#define SPC5_HAS_DSPI2                      TRUE
#define SPC5_DSPI2_BASE                     0xF7E74000UL
#define SPC5_HAS_DSPI3                      TRUE
#define SPC5_DSPI3_BASE                     0xFBE74000UL
#define SPC5_HAS_DSPI4                      TRUE
#define SPC5_DSPI4_BASE                     0xF7E78000UL
#define SPC5_HAS_DSPI5                      TRUE
#define SPC5_DSPI5_BASE                     0xFBE78000UL
#define SPC5_HAS_DSPI6                      TRUE
#define SPC5_DSPI6_BASE                     0xF7E7C000UL
#define SPC5_HAS_DSPI7                      TRUE
#define SPC5_DSPI7_BASE                     0xFBE7C000UL
#define SPC5_HAS_DSPI8                      FALSE
#define SPC5_HAS_DSPI9                      FALSE

#define SPC5_DSPI_FIFO_DEPTH                4U

#define SPC5_DSPI0_EOQF_HANDLER             vector260
#define SPC5_DSPI0_EOQF_NUMBER              260
#define SPC5_DSPI0_TFFF_HANDLER             vector261
#define SPC5_DSPI0_TFFF_NUMBER              261
#define SPC5_DSPI0_RFDF_HANDLER             vector263
#define SPC5_DSPI0_RFDF_NUMBER              263

#define SPC5_DSPI1_EOQF_HANDLER             vector269
#define SPC5_DSPI1_EOQF_NUMBER              269
#define SPC5_DSPI1_TFFF_HANDLER             vector270
#define SPC5_DSPI1_TFFF_NUMBER              270
#define SPC5_DSPI1_RFDF_HANDLER             vector272
#define SPC5_DSPI1_RFDF_NUMBER              272

#define SPC5_DSPI2_EOQF_HANDLER             vector278
#define SPC5_DSPI2_EOQF_NUMBER              278
#define SPC5_DSPI2_TFFF_HANDLER             vector279
#define SPC5_DSPI2_TFFF_NUMBER              279
#define SPC5_DSPI2_RFDF_HANDLER             vector281
#define SPC5_DSPI2_RFDF_NUMBER              281

#define SPC5_DSPI3_EOQF_HANDLER             vector287
#define SPC5_DSPI3_EOQF_NUMBER              287
#define SPC5_DSPI3_TFFF_HANDLER             vector288
#define SPC5_DSPI3_TFFF_NUMBER              288
#define SPC5_DSPI3_RFDF_HANDLER             vector290
#define SPC5_DSPI3_RFDF_NUMBER              290

#define SPC5_DSPI4_EOQF_HANDLER             vector296
#define SPC5_DSPI4_EOQF_NUMBER              296
#define SPC5_DSPI4_TFFF_HANDLER             vector297
#define SPC5_DSPI4_TFFF_NUMBER              297
#define SPC5_DSPI4_RFDF_HANDLER             vector299
#define SPC5_DSPI4_RFDF_NUMBER              299

#define SPC5_DSPI5_EOQF_HANDLER             vector305
#define SPC5_DSPI5_EOQF_NUMBER              305
#define SPC5_DSPI5_TFFF_HANDLER             vector306
#define SPC5_DSPI5_TFFF_NUMBER              306
#define SPC5_DSPI5_RFDF_HANDLER             vector308
#define SPC5_DSPI5_RFDF_NUMBER              308

#define SPC5_DSPI6_EOQF_HANDLER             vector314
#define SPC5_DSPI6_EOQF_NUMBER              314
#define SPC5_DSPI6_TFFF_HANDLER             vector315
#define SPC5_DSPI6_TFFF_NUMBER              315
#define SPC5_DSPI6_RFDF_HANDLER             vector317
#define SPC5_DSPI6_RFDF_NUMBER              317

#define SPC5_DSPI7_EOQF_HANDLER             vector323
#define SPC5_DSPI7_EOQF_NUMBER              323
#define SPC5_DSPI7_TFFF_HANDLER             vector324
#define SPC5_DSPI7_TFFF_NUMBER              324
#define SPC5_DSPI7_RFDF_HANDLER             vector326
#define SPC5_DSPI7_RFDF_NUMBER              326

#define SPC5_DSPI0_PCTL                     99
#define SPC5_DSPI1_PCTL                     227
#define SPC5_DSPI2_PCTL                     98
#define SPC5_DSPI3_PCTL                     226
#define SPC5_DSPI4_PCTL                     97
#define SPC5_DSPI5_PCTL                     225
#define SPC5_DSPI6_PCTL                     96
#define SPC5_DSPI7_PCTL                     224

#define SPC5_DSPI0_RX_DMA_MUX0_DEV_ID       3
#define SPC5_DSPI0_RX_DMA_MUX2_DEV_ID       12
#define SPC5_DSPI0_TX1_DMA_MUX0_DEV_ID      4
#define SPC5_DSPI0_TX1_DMA_MUX2_DEV_ID      13
#define SPC5_DSPI0_TX2_DMA_MUX0_DEV_ID      5
#define SPC5_DSPI0_TX2_DMA_MUX2_DEV_ID      14

#define SPC5_DSPI1_RX_DMA_MUX0_DEV_ID       6
#define SPC5_DSPI1_RX_DMA_MUX2_DEV_ID       15
#define SPC5_DSPI1_TX1_DMA_MUX0_DEV_ID      7
#define SPC5_DSPI1_TX1_DMA_MUX2_DEV_ID      16
#define SPC5_DSPI1_TX2_DMA_MUX0_DEV_ID      8
#define SPC5_DSPI1_TX2_DMA_MUX2_DEV_ID      17

#define SPC5_DSPI2_RX_DMA_MUX0_DEV_ID       9
#define SPC5_DSPI2_RX_DMA_MUX2_DEV_ID       18
#define SPC5_DSPI2_TX1_DMA_MUX0_DEV_ID      10
#define SPC5_DSPI2_TX1_DMA_MUX2_DEV_ID      19
#define SPC5_DSPI2_TX2_DMA_MUX0_DEV_ID      11
#define SPC5_DSPI2_TX2_DMA_MUX2_DEV_ID      20

#define SPC5_DSPI3_RX_DMA_MUX0_DEV_ID       12
#define SPC5_DSPI3_RX_DMA_MUX2_DEV_ID       21
#define SPC5_DSPI3_TX1_DMA_MUX0_DEV_ID      13
#define SPC5_DSPI3_TX1_DMA_MUX2_DEV_ID      22
#define SPC5_DSPI3_TX2_DMA_MUX0_DEV_ID      14
#define SPC5_DSPI3_TX2_DMA_MUX2_DEV_ID      23

#define SPC5_DSPI4_RX_DMA_MUX1_DEV_ID       3
#define SPC5_DSPI4_RX_DMA_MUX3_DEV_ID       10
#define SPC5_DSPI4_TX1_DMA_MUX1_DEV_ID      4
#define SPC5_DSPI4_TX1_DMA_MUX3_DEV_ID      11
#define SPC5_DSPI4_TX2_DMA_MUX1_DEV_ID      5
#define SPC5_DSPI4_TX2_DMA_MUX3_DEV_ID      12

#define SPC5_DSPI5_RX_DMA_MUX1_DEV_ID       6
#define SPC5_DSPI5_RX_DMA_MUX3_DEV_ID       13
#define SPC5_DSPI5_TX1_DMA_MUX1_DEV_ID      7
#define SPC5_DSPI5_TX1_DMA_MUX3_DEV_ID      14
#define SPC5_DSPI5_TX2_DMA_MUX1_DEV_ID      8
#define SPC5_DSPI5_TX2_DMA_MUX3_DEV_ID      15

#define SPC5_DSPI6_RX_DMA_MUX1_DEV_ID       9
#define SPC5_DSPI6_RX_DMA_MUX3_DEV_ID       16
#define SPC5_DSPI6_TX1_DMA_MUX1_DEV_ID      10
#define SPC5_DSPI6_TX1_DMA_MUX3_DEV_ID      17
#define SPC5_DSPI6_TX2_DMA_MUX1_DEV_ID      11
#define SPC5_DSPI6_TX2_DMA_MUX3_DEV_ID      18

#define SPC5_DSPI7_RX_DMA_MUX2_DEV_ID       1
#define SPC5_DSPI7_RX_DMA_MUX3_DEV_ID       35
#define SPC5_DSPI7_TX1_DMA_MUX2_DEV_ID      2
#define SPC5_DSPI7_TX1_DMA_MUX3_DEV_ID      36
#define SPC5_DSPI7_TX2_DMA_MUX2_DEV_ID      3
#define SPC5_DSPI7_TX2_DMA_MUX3_DEV_ID      37

#define SPC5_DSPI0_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI0_PCTL, SPC5_SPI_DSPI0_START_PCTL)
#define SPC5_DSPI0_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI0_PCTL, SPC5_SPI_DSPI0_STOP_PCTL)
#define SPC5_DSPI1_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI1_PCTL, SPC5_SPI_DSPI1_START_PCTL)
#define SPC5_DSPI1_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI1_PCTL, SPC5_SPI_DSPI1_STOP_PCTL)
#define SPC5_DSPI2_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI2_PCTL, SPC5_SPI_DSPI2_START_PCTL)
#define SPC5_DSPI2_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI2_PCTL, SPC5_SPI_DSPI2_STOP_PCTL)
#define SPC5_DSPI3_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI3_PCTL, SPC5_SPI_DSPI3_START_PCTL)
#define SPC5_DSPI3_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI3_PCTL, SPC5_SPI_DSPI3_STOP_PCTL)
#define SPC5_DSPI4_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI4_PCTL, SPC5_SPI_DSPI4_START_PCTL)
#define SPC5_DSPI4_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI4_PCTL, SPC5_SPI_DSPI4_STOP_PCTL)
#define SPC5_DSPI5_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI5_PCTL, SPC5_SPI_DSPI5_START_PCTL)
#define SPC5_DSPI5_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI5_PCTL, SPC5_SPI_DSPI5_STOP_PCTL)
#define SPC5_DSPI6_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI6_PCTL, SPC5_SPI_DSPI6_START_PCTL)
#define SPC5_DSPI6_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI6_PCTL, SPC5_SPI_DSPI6_STOP_PCTL)
#define SPC5_DSPI7_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI7_PCTL, SPC5_SPI_DSPI7_START_PCTL)
#define SPC5_DSPI7_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI7_PCTL, SPC5_SPI_DSPI7_STOP_PCTL)

/*
 * I2S attributes
 */
#define SPC5_I2S_DSPI0_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI0_PCTL, SPC5_I2S_DSPI0_START_PCTL)
#define SPC5_I2S_DSPI0_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI0_PCTL, SPC5_I2S_DSPI0_STOP_PCTL)
#define SPC5_I2S_DSPI1_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI1_PCTL, SPC5_I2S_DSPI1_START_PCTL)
#define SPC5_I2S_DSPI1_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI1_PCTL, SPC5_I2S_DSPI1_STOP_PCTL)
#define SPC5_I2S_DSPI2_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI2_PCTL, SPC5_I2S_DSPI2_START_PCTL)
#define SPC5_I2S_DSPI2_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI2_PCTL, SPC5_I2S_DSPI2_STOP_PCTL)
#define SPC5_I2S_DSPI3_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI3_PCTL, SPC5_I2S_DSPI3_START_PCTL)
#define SPC5_I2S_DSPI3_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI3_PCTL, SPC5_I2S_DSPI3_STOP_PCTL)
#define SPC5_I2S_DSPI4_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI4_PCTL, SPC5_I2S_DSPI4_START_PCTL)
#define SPC5_I2S_DSPI4_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI4_PCTL, SPC5_I2S_DSPI4_STOP_PCTL)
#define SPC5_I2S_DSPI5_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI5_PCTL, SPC5_I2S_DSPI5_START_PCTL)
#define SPC5_I2S_DSPI5_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI5_PCTL, SPC5_I2S_DSPI5_STOP_PCTL)
#define SPC5_I2S_DSPI6_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI6_PCTL, SPC5_I2S_DSPI6_START_PCTL)
#define SPC5_I2S_DSPI6_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI6_PCTL, SPC5_I2S_DSPI6_STOP_PCTL)
#define SPC5_I2S_DSPI7_ENABLE_CLOCK()                                           \
  SPCSetPeripheralClockMode(SPC5_DSPI7_PCTL, SPC5_I2S_DSPI7_START_PCTL)
#define SPC5_I2S_DSPI7_DISABLE_CLOCK()                                          \
  SPCSetPeripheralClockMode(SPC5_DSPI7_PCTL, SPC5_I2S_DSPI7_STOP_PCTL)

/* LINFlex attributes.*/
#define SPC5_HAS_LINFLEX0                   TRUE
#define SPC5_LINFLEX0_BASE                  0xF7E8C000UL
#define SPC5_LINFLEX0L_BASE                 0xF7E8C000UL
#define SPC5_LINFLEX0H_BASE                 0xF7E8C08CUL
#define SPC5_LINFLEX0_PCTL                  92
#define SPC5_LINFLEX0_RXI_HANDLER           vector376
#define SPC5_LINFLEX0_TXI_HANDLER           vector377
#define SPC5_LINFLEX0_ERR_HANDLER           vector378
#define SPC5_LINFLEX0_RXI_NUMBER            376
#define SPC5_LINFLEX0_TXI_NUMBER            377
#define SPC5_LINFLEX0_ERR_NUMBER            378
#define SPC5_LINFLEX0_DMA_SUPPORTED         TRUE
#define SPC5_LINFLEX0_RX_DMA_MUX0_DEV_ID    15
#define SPC5_LINFLEX0_RX_DMA_MUX2_DEV_ID    24
#define SPC5_LINFLEX0_TX_DMA_MUX0_DEV_ID    16
#define SPC5_LINFLEX0_TX_DMA_MUX2_DEV_ID    25
#define SPC5_LINFLEX0_CLK                   SPC5_LIN_CLK0

#define SPC5_HAS_LINFLEX1                   TRUE
#define SPC5_LINFLEX1_BASE                  0xFBE8C000UL
#define SPC5_LINFLEX1L_BASE                 0xFBE8C000UL
#define SPC5_LINFLEX1H_BASE                 0xFBE8C08CUL
#define SPC5_LINFLEX1_PCTL                  220
#define SPC5_LINFLEX1_RXI_HANDLER           vector380
#define SPC5_LINFLEX1_TXI_HANDLER           vector381
#define SPC5_LINFLEX1_ERR_HANDLER           vector382
#define SPC5_LINFLEX1_RXI_NUMBER            380
#define SPC5_LINFLEX1_TXI_NUMBER            381
#define SPC5_LINFLEX1_ERR_NUMBER            382
#define SPC5_LINFLEX1_DMA_SUPPORTED         TRUE
#define SPC5_LINFLEX1_RX_DMA_MUX0_DEV_ID    17
#define SPC5_LINFLEX1_RX_DMA_MUX2_DEV_ID    26
#define SPC5_LINFLEX1_TX_DMA_MUX0_DEV_ID    18
#define SPC5_LINFLEX1_TX_DMA_MUX2_DEV_ID    27
#define SPC5_LINFLEX1_CLK                   SPC5_LIN_CLK0

#define SPC5_HAS_LINFLEX2                   TRUE
#define SPC5_LINFLEX2_BASE                  0xF7E90000UL
#define SPC5_LINFLEX2L_BASE                 0xF7E90000UL
#define SPC5_LINFLEX2H_BASE                 0xF7E9008CUL
#define SPC5_LINFLEX2_PCTL                  91
#define SPC5_LINFLEX2_RXI_HANDLER           vector384
#define SPC5_LINFLEX2_TXI_HANDLER           vector385
#define SPC5_LINFLEX2_ERR_HANDLER           vector386
#define SPC5_LINFLEX2_RXI_NUMBER            384
#define SPC5_LINFLEX2_TXI_NUMBER            385
#define SPC5_LINFLEX2_ERR_NUMBER            386
#define SPC5_LINFLEX2_DMA_SUPPORTED         TRUE
#define SPC5_LINFLEX2_RX_DMA_MUX0_DEV_ID    19
#define SPC5_LINFLEX2_RX_DMA_MUX2_DEV_ID    28
#define SPC5_LINFLEX2_TX_DMA_MUX0_DEV_ID    20
#define SPC5_LINFLEX2_TX_DMA_MUX2_DEV_ID    29
#define SPC5_LINFLEX2_CLK                   SPC5_LIN_CLK0

#define SPC5_HAS_LINFLEX3                   TRUE
#define SPC5_LINFLEX3_BASE                  0xFBE90000UL
#define SPC5_LINFLEX3L_BASE                 0xFBE90000UL
#define SPC5_LINFLEX3H_BASE                 0xFBE9008CUL
#define SPC5_LINFLEX3_PCTL                  219
#define SPC5_LINFLEX3_RXI_HANDLER           vector388
#define SPC5_LINFLEX3_TXI_HANDLER           vector389
#define SPC5_LINFLEX3_ERR_HANDLER           vector390
#define SPC5_LINFLEX3_RXI_NUMBER            388
#define SPC5_LINFLEX3_TXI_NUMBER            389
#define SPC5_LINFLEX3_ERR_NUMBER            390
#define SPC5_LINFLEX3_DMA_SUPPORTED         TRUE
#define SPC5_LINFLEX3_RX_DMA_MUX3_DEV_ID    19
#define SPC5_LINFLEX3_TX_DMA_MUX3_DEV_ID    20
#define SPC5_LINFLEX3_CLK                   SPC5_LIN_CLK0

#define SPC5_HAS_LINFLEX4                   TRUE
#define SPC5_LINFLEX4_BASE                  0xF7E94000UL
#define SPC5_LINFLEX4L_BASE                 0xF7E94000UL
#define SPC5_LINFLEX4H_BASE                 0xF7E9408CUL
#define SPC5_LINFLEX4_PCTL                  90
#define SPC5_LINFLEX4_RXI_HANDLER           vector392
#define SPC5_LINFLEX4_TXI_HANDLER           vector393
#define SPC5_LINFLEX4_ERR_HANDLER           vector394
#define SPC5_LINFLEX4_RXI_NUMBER            392
#define SPC5_LINFLEX4_TXI_NUMBER            393
#define SPC5_LINFLEX4_ERR_NUMBER            394
#define SPC5_LINFLEX4_DMA_SUPPORTED         TRUE
#define SPC5_LINFLEX4_RX_DMA_MUX1_DEV_ID    14
#define SPC5_LINFLEX4_RX_DMA_MUX3_DEV_ID    21
#define SPC5_LINFLEX4_TX_DMA_MUX1_DEV_ID    15
#define SPC5_LINFLEX4_TX_DMA_MUX3_DEV_ID    22
#define SPC5_LINFLEX4_CLK                   SPC5_LIN_CLK0

#define SPC5_HAS_LINFLEX5                   TRUE
#define SPC5_LINFLEX5_BASE                  0xFBE94000UL
#define SPC5_LINFLEX5L_BASE                 0xFBE94000UL
#define SPC5_LINFLEX5H_BASE                 0xFBE9408CUL
#define SPC5_LINFLEX5_PCTL                  218
#define SPC5_LINFLEX5_RXI_HANDLER           vector396
#define SPC5_LINFLEX5_TXI_HANDLER           vector397
#define SPC5_LINFLEX5_ERR_HANDLER           vector398
#define SPC5_LINFLEX5_RXI_NUMBER            396
#define SPC5_LINFLEX5_TXI_NUMBER            397
#define SPC5_LINFLEX5_ERR_NUMBER            398
#define SPC5_LINFLEX5_DMA_SUPPORTED         TRUE
#define SPC5_LINFLEX5_RX_DMA_MUX1_DEV_ID    16
#define SPC5_LINFLEX5_RX_DMA_MUX3_DEV_ID    23
#define SPC5_LINFLEX5_TX_DMA_MUX1_DEV_ID    17
#define SPC5_LINFLEX5_TX_DMA_MUX3_DEV_ID    24
#define SPC5_LINFLEX5_CLK                   SPC5_LIN_CLK0

#define SPC5_HAS_LINFLEX6                   TRUE
#define SPC5_LINFLEX6_BASE                  0xF7E98000UL
#define SPC5_LINFLEX6L_BASE                 0xF7E98000UL
#define SPC5_LINFLEX6H_BASE                 0xF7E9808CUL
#define SPC5_LINFLEX6_PCTL                  89
#define SPC5_LINFLEX6_RXI_HANDLER           vector400
#define SPC5_LINFLEX6_TXI_HANDLER           vector401
#define SPC5_LINFLEX6_ERR_HANDLER           vector402
#define SPC5_LINFLEX6_RXI_NUMBER            400
#define SPC5_LINFLEX6_TXI_NUMBER            401
#define SPC5_LINFLEX6_ERR_NUMBER            402
#define SPC5_LINFLEX6_DMA_SUPPORTED         TRUE
#define SPC5_LINFLEX6_RX_DMA_MUX1_DEV_ID    18
#define SPC5_LINFLEX6_RX_DMA_MUX3_DEV_ID    25
#define SPC5_LINFLEX6_TX_DMA_MUX1_DEV_ID    19
#define SPC5_LINFLEX6_TX_DMA_MUX3_DEV_ID    26
#define SPC5_LINFLEX6_CLK                   SPC5_LIN_CLK0

#define SPC5_HAS_LINFLEX7                   TRUE
#define SPC5_LINFLEX7_BASE                  0xFBE98000UL
#define SPC5_LINFLEX7L_BASE                 0xFBE98000UL
#define SPC5_LINFLEX7H_BASE                 0xFBE9808CUL
#define SPC5_LINFLEX7_PCTL                  217
#define SPC5_LINFLEX7_RXI_HANDLER           vector404
#define SPC5_LINFLEX7_TXI_HANDLER           vector405
#define SPC5_LINFLEX7_ERR_HANDLER           vector406
#define SPC5_LINFLEX7_RXI_NUMBER            404
#define SPC5_LINFLEX7_TXI_NUMBER            405
#define SPC5_LINFLEX7_ERR_NUMBER            406
#define SPC5_LINFLEX7_DMA_SUPPORTED         TRUE
#define SPC5_LINFLEX7_RX_DMA_MUX0_DEV_ID    21
#define SPC5_LINFLEX7_RX_DMA_MUX2_DEV_ID    30
#define SPC5_LINFLEX7_TX_DMA_MUX0_DEV_ID    22
#define SPC5_LINFLEX7_TX_DMA_MUX2_DEV_ID    31
#define SPC5_LINFLEX7_CLK                   SPC5_LIN_CLK1

#define SPC5_HAS_LINFLEX8                   TRUE
#define SPC5_LINFLEX8_BASE                  0xF7E9C000UL
#define SPC5_LINFLEX8L_BASE                 0xF7E9C000UL
#define SPC5_LINFLEX8H_BASE                 0xF7E9C08CUL
#define SPC5_LINFLEX8_PCTL                  88
#define SPC5_LINFLEX8_RXI_HANDLER           vector408
#define SPC5_LINFLEX8_TXI_HANDLER           vector409
#define SPC5_LINFLEX8_ERR_HANDLER           vector410
#define SPC5_LINFLEX8_RXI_NUMBER            408
#define SPC5_LINFLEX8_TXI_NUMBER            409
#define SPC5_LINFLEX8_ERR_NUMBER            410
#define SPC5_LINFLEX8_DMA_SUPPORTED         TRUE
#define SPC5_LINFLEX8_RX_DMA_MUX1_DEV_ID    20
#define SPC5_LINFLEX8_RX_DMA_MUX3_DEV_ID    27
#define SPC5_LINFLEX8_TX_DMA_MUX1_DEV_ID    21
#define SPC5_LINFLEX8_TX_DMA_MUX3_DEV_ID    28
#define SPC5_LINFLEX8_CLK                   SPC5_LIN_CLK1

#define SPC5_HAS_LINFLEX9                   TRUE
#define SPC5_LINFLEX9_BASE                  0xFBE9C000UL
#define SPC5_LINFLEX9L_BASE                 0xFBE9C000UL
#define SPC5_LINFLEX9H_BASE                 0xFBE9C08CUL
#define SPC5_LINFLEX9_PCTL                  216
#define SPC5_LINFLEX9_RXI_HANDLER           vector412
#define SPC5_LINFLEX9_TXI_HANDLER           vector413
#define SPC5_LINFLEX9_ERR_HANDLER           vector414
#define SPC5_LINFLEX9_RXI_NUMBER            412
#define SPC5_LINFLEX9_TXI_NUMBER            413
#define SPC5_LINFLEX9_ERR_NUMBER            414
#define SPC5_LINFLEX9_DMA_SUPPORTED         TRUE
#define SPC5_LINFLEX9_RX_DMA_MUX1_DEV_ID    22
#define SPC5_LINFLEX9_TX_DMA_MUX1_DEV_ID    23
#define SPC5_LINFLEX9_CLK                   SPC5_LIN_CLK1

#define SPC5_HAS_LINFLEX10                  TRUE
#define SPC5_LINFLEX10_BASE                 0xF7EA0000UL
#define SPC5_LINFLEX10L_BASE                0xF7EA0000UL
#define SPC5_LINFLEX10H_BASE                0xF7EA008CUL
#define SPC5_LINFLEX10_PCTL                 87
#define SPC5_LINFLEX10_RXI_HANDLER          vector416
#define SPC5_LINFLEX10_TXI_HANDLER          vector417
#define SPC5_LINFLEX10_ERR_HANDLER          vector418
#define SPC5_LINFLEX10_RXI_NUMBER           416
#define SPC5_LINFLEX10_TXI_NUMBER           417
#define SPC5_LINFLEX10_ERR_NUMBER           418
#define SPC5_LINFLEX10_DMA_SUPPORTED        TRUE
#define SPC5_LINFLEX10_RX_DMA_MUX0_DEV_ID   23
#define SPC5_LINFLEX10_RX_DMA_MUX2_DEV_ID   32
#define SPC5_LINFLEX10_TX_DMA_MUX0_DEV_ID   24
#define SPC5_LINFLEX10_TX_DMA_MUX2_DEV_ID   33
#define SPC5_LINFLEX10_CLK                  SPC5_LIN_CLK1

#define SPC5_HAS_LINFLEX11                  TRUE
#define SPC5_LINFLEX11_BASE                 0xFBEA0000UL
#define SPC5_LINFLEX11L_BASE                0xFBEA0000UL
#define SPC5_LINFLEX11H_BASE                0xFBEA008CUL
#define SPC5_LINFLEX11_PCTL                 215
#define SPC5_LINFLEX11_RXI_HANDLER          vector420
#define SPC5_LINFLEX11_TXI_HANDLER          vector421
#define SPC5_LINFLEX11_ERR_HANDLER          vector422
#define SPC5_LINFLEX11_RXI_NUMBER           420
#define SPC5_LINFLEX11_TXI_NUMBER           421
#define SPC5_LINFLEX11_ERR_NUMBER           422
#define SPC5_LINFLEX11_DMA_SUPPORTED        TRUE
#define SPC5_LINFLEX11_RX_DMA_MUX2_DEV_ID   4
#define SPC5_LINFLEX11_RX_DMA_MUX3_DEV_ID   38
#define SPC5_LINFLEX11_TX_DMA_MUX2_DEV_ID   5
#define SPC5_LINFLEX11_TX_DMA_MUX3_DEV_ID   39
#define SPC5_LINFLEX11_CLK                  SPC5_LIN_CLK1

#define SPC5_HAS_LINFLEX12                  TRUE
#define SPC5_LINFLEX12_BASE                 0xF7EA4000UL
#define SPC5_LINFLEX12L_BASE                0xF7EA4000UL
#define SPC5_LINFLEX12H_BASE                0xF7EA408CUL
#define SPC5_LINFLEX12_PCTL                 86
#define SPC5_LINFLEX12_RXI_HANDLER          vector424
#define SPC5_LINFLEX12_TXI_HANDLER          vector425
#define SPC5_LINFLEX12_ERR_HANDLER          vector426
#define SPC5_LINFLEX12_RXI_NUMBER           424
#define SPC5_LINFLEX12_TXI_NUMBER           425
#define SPC5_LINFLEX12_ERR_NUMBER           426
#define SPC5_LINFLEX12_DMA_SUPPORTED        TRUE
#define SPC5_LINFLEX12_RX_DMA_MUX2_DEV_ID   6
#define SPC5_LINFLEX12_RX_DMA_MUX3_DEV_ID   40
#define SPC5_LINFLEX12_TX_DMA_MUX2_DEV_ID   7
#define SPC5_LINFLEX12_TX_DMA_MUX3_DEV_ID   41
#define SPC5_LINFLEX12_CLK                  SPC5_LIN_CLK1

#define SPC5_HAS_LINFLEX13                  TRUE
#define SPC5_LINFLEX13_BASE                 0xFBEA4000UL
#define SPC5_LINFLEX13L_BASE                0xFBEA4000UL
#define SPC5_LINFLEX13H_BASE                0xFBEA408CUL
#define SPC5_LINFLEX13_PCTL                 214
#define SPC5_LINFLEX13_RXI_HANDLER          vector428
#define SPC5_LINFLEX13_TXI_HANDLER          vector429
#define SPC5_LINFLEX13_ERR_HANDLER          vector430
#define SPC5_LINFLEX13_RXI_NUMBER           428
#define SPC5_LINFLEX13_TXI_NUMBER           429
#define SPC5_LINFLEX13_ERR_NUMBER           430
#define SPC5_LINFLEX13_DMA_SUPPORTED        TRUE
#define SPC5_LINFLEX13_RX_DMA_MUX3_DEV_ID   2
#define SPC5_LINFLEX13_TX_DMA_MUX3_DEV_ID   3
#define SPC5_LINFLEX13_CLK                  SPC5_LIN_CLK1

#define SPC5_HAS_LINFLEX14                  TRUE
#define SPC5_LINFLEX14_BASE                 0xF7EA8000UL
#define SPC5_LINFLEX14L_BASE                0xF7EA8000UL
#define SPC5_LINFLEX14H_BASE                0xF7EA808CUL
#define SPC5_LINFLEX14_PCTL                 85
#define SPC5_LINFLEX14_RXI_HANDLER          vector432
#define SPC5_LINFLEX14_TXI_HANDLER          vector433
#define SPC5_LINFLEX14_ERR_HANDLER          vector434
#define SPC5_LINFLEX14_RXI_NUMBER           432
#define SPC5_LINFLEX14_TXI_NUMBER           433
#define SPC5_LINFLEX14_ERR_NUMBER           434
#define SPC5_LINFLEX14_DMA_SUPPORTED        TRUE
#define SPC5_LINFLEX14_RX_DMA_MUX3_DEV_ID   4
#define SPC5_LINFLEX14_TX_DMA_MUX3_DEV_ID   5
#define SPC5_LINFLEX14_CLK                  SPC5_LIN_CLK0

#define SPC5_HAS_LINFLEX15                  TRUE
#define SPC5_LINFLEX15_BASE                 0xFBEA8000UL
#define SPC5_LINFLEX15L_BASE                0xFBEA8000UL
#define SPC5_LINFLEX15H_BASE                0xFBEA808CUL
#define SPC5_LINFLEX15_PCTL                 213
#define SPC5_LINFLEX15_RXI_HANDLER          vector436
#define SPC5_LINFLEX15_TXI_HANDLER          vector437
#define SPC5_LINFLEX15_ERR_HANDLER          vector438
#define SPC5_LINFLEX15_RXI_NUMBER           436
#define SPC5_LINFLEX15_TXI_NUMBER           437
#define SPC5_LINFLEX15_ERR_NUMBER           438
#define SPC5_LINFLEX15_DMA_SUPPORTED        TRUE
#define SPC5_LINFLEX15_RX_DMA_MUX0_DEV_ID   25
#define SPC5_LINFLEX15_RX_DMA_MUX2_DEV_ID   34
#define SPC5_LINFLEX15_TX_DMA_MUX0_DEV_ID   26
#define SPC5_LINFLEX15_TX_DMA_MUX2_DEV_ID   35
#define SPC5_LINFLEX15_CLK                  SPC5_LIN_CLK0

#define SPC5_HAS_LINFLEX16                  TRUE
#define SPC5_LINFLEX16_BASE                 0xF7EAC000UL
#define SPC5_LINFLEX16L_BASE                0xF7EAC000UL
#define SPC5_LINFLEX16H_BASE                0xF7EAC08CUL
#define SPC5_LINFLEX16_PCTL                 84
#define SPC5_LINFLEX16_RXI_HANDLER          vector440
#define SPC5_LINFLEX16_TXI_HANDLER          vector441
#define SPC5_LINFLEX16_ERR_HANDLER          vector442
#define SPC5_LINFLEX16_RXI_NUMBER           440
#define SPC5_LINFLEX16_TXI_NUMBER           441
#define SPC5_LINFLEX16_ERR_NUMBER           442
#define SPC5_LINFLEX16_DMA_SUPPORTED        TRUE
#define SPC5_LINFLEX16_RX_DMA_MUX2_DEV_ID   8
#define SPC5_LINFLEX16_RX_DMA_MUX3_DEV_ID   42
#define SPC5_LINFLEX16_TX_DMA_MUX2_DEV_ID   9
#define SPC5_LINFLEX16_TX_DMA_MUX3_DEV_ID   43
#define SPC5_LINFLEX16_CLK                  SPC5_LIN_CLK0

#define SPC5_HAS_LINFLEX17                  TRUE
#define SPC5_LINFLEX17_BASE                 0xFBEAC000UL
#define SPC5_LINFLEX17L_BASE                0xFBEAC000UL
#define SPC5_LINFLEX17H_BASE                0xFBEAC08CUL
#define SPC5_LINFLEX17_PCTL                 212
#define SPC5_LINFLEX17_RXI_HANDLER          vector444
#define SPC5_LINFLEX17_TXI_HANDLER          vector445
#define SPC5_LINFLEX17_ERR_HANDLER          vector446
#define SPC5_LINFLEX17_RXI_NUMBER           444
#define SPC5_LINFLEX17_TXI_NUMBER           445
#define SPC5_LINFLEX17_ERR_NUMBER           446
#define SPC5_LINFLEX17_DMA_SUPPORTED        TRUE
#define SPC5_LINFLEX17_RX_DMA_MUX3_DEV_ID   6
#define SPC5_LINFLEX17_TX_DMA_MUX3_DEV_ID   7
#define SPC5_LINFLEX17_CLK                  SPC5_LIN_CLK0

#define SPC5_HAS_LINFLEX18                  FALSE
#define SPC5_HAS_LINFLEX19                  FALSE
#define SPC5_HAS_LINFLEX20                  FALSE
#define SPC5_HAS_LINFLEX21                  FALSE
#define SPC5_HAS_LINFLEX22                  FALSE
#define SPC5_HAS_LINFLEX23                  FALSE

/* SIUL2 attributes.*/
#define SPC5_HAS_SIUL2                      TRUE
#define SPC5_HAS_SIUL_PARALLEL_PORT_REG     TRUE
#define SPC5_SIUL2_PCTL                     15
#define SPC5_SIUL2_NUM_PORTS                13
#define SPC5_SIUL2_NUM_MUXES                420

/* PIT attributes. PITv2 driver support*/
#define SPC5_HAS_PIT0                       TRUE
#define SPC5_PIT0_BASE                      0xF7F84000UL
#define SPC5_PIT0_CHANNELS                  8
#define SPC5_PIT0_PCTL                      30
#define SPC5_PIT0_ENABLE_CLOCK()            SPCSetPeripheralClockMode(SPC5_PIT0_PCTL, SPC5_PIT0_START_PCTL);
#define SPC5_PIT0_DISABLE_CLOCK()           SPCSetPeripheralClockMode(SPC5_PIT0_PCTL, SPC5_PIT0_STOP_PCTL);
#define SPC5_HAS_PIT0_CH0                   TRUE
#define SPC5_HAS_PIT0_CH1                   TRUE
#define SPC5_HAS_PIT0_CH2                   TRUE
#define SPC5_HAS_PIT0_CH3                   TRUE
#define SPC5_HAS_PIT0_CH4                   TRUE
#define SPC5_HAS_PIT0_CH5                   TRUE
#define SPC5_HAS_PIT0_CH6                   TRUE
#define SPC5_HAS_PIT0_CH7                   TRUE
#define SPC5_PIT0_CH0_HANDLER               vector226
#define SPC5_PIT0_CH1_HANDLER               vector227
#define SPC5_PIT0_CH2_HANDLER               vector228
#define SPC5_PIT0_CH3_HANDLER               vector229
#define SPC5_PIT0_CH4_HANDLER               vector230
#define SPC5_PIT0_CH5_HANDLER               vector231
#define SPC5_PIT0_CH6_HANDLER               vector232
#define SPC5_PIT0_CH7_HANDLER               vector233
#define SPC5_PIT0_CH0_INT_NUMBER            226
#define SPC5_PIT0_CH1_INT_NUMBER            227
#define SPC5_PIT0_CH2_INT_NUMBER            228
#define SPC5_PIT0_CH3_INT_NUMBER            229
#define SPC5_PIT0_CH4_INT_NUMBER            230
#define SPC5_PIT0_CH5_INT_NUMBER            231
#define SPC5_PIT0_CH6_INT_NUMBER            232
#define SPC5_PIT0_CH7_INT_NUMBER            233

#define SPC5_HAS_PIT1                       TRUE
#define SPC5_PIT1_BASE                      0xFBF84000UL
#define SPC5_PIT1_CHANNELS                  2
#define SPC5_PIT1_PCTL                      158
#define SPC5_PIT1_ENABLE_CLOCK()            SPCSetPeripheralClockMode(SPC5_PIT1_PCTL, SPC5_PIT1_START_PCTL);
#define SPC5_PIT1_DISABLE_CLOCK()           SPCSetPeripheralClockMode(SPC5_PIT1_PCTL, SPC5_PIT1_STOP_PCTL);
#define SPC5_HAS_PIT1_CH0                   TRUE
#define SPC5_HAS_PIT1_CH1                   TRUE
#define SPC5_HAS_PIT1_CH2                   FALSE
#define SPC5_HAS_PIT1_CH3                   FALSE
#define SPC5_HAS_PIT1_CH4                   FALSE
#define SPC5_HAS_PIT1_CH5                   FALSE
#define SPC5_HAS_PIT1_CH6                   FALSE
#define SPC5_HAS_PIT1_CH7                   FALSE
#define SPC5_PIT1_CH0_HANDLER               vector240
#define SPC5_PIT1_CH1_HANDLER               vector241
#define SPC5_PIT1_CH0_INT_NUMBER            240
#define SPC5_PIT1_CH1_INT_NUMBER            241

/* STM attributes.*/
#define SPC5_HAS_STM0                       TRUE
#define SPC5_HAS_STM1                       FALSE
#define SPC5_HAS_STM2                       TRUE
#define SPC5_STM0_BASE                      0xF4068000UL
#define SPC5_STM0_CHANNELS                  4
#define SPC5_HAS_STM0_CH0                   TRUE
#define SPC5_HAS_STM0_CH1                   TRUE
#define SPC5_HAS_STM0_CH2                   TRUE
#define SPC5_HAS_STM0_CH3                   TRUE
#define SPC5_STM0_CH1_CH3_SHARED_INT        FALSE
#define SPC5_STM0_CH0_HANDLER               vector36
#define SPC5_STM0_CH1_HANDLER               vector37
#define SPC5_STM0_CH2_HANDLER               vector38
#define SPC5_STM0_CH3_HANDLER               vector39
#define SPC5_STM0_CH0_INT_NUMBER            36
#define SPC5_STM0_CH1_INT_NUMBER            37
#define SPC5_STM0_CH2_INT_NUMBER            38
#define SPC5_STM0_CH3_INT_NUMBER            39

#define SPC5_STM2_BASE                      0xF4070000UL
#define SPC5_STM2_CHANNELS                  4
#define SPC5_HAS_STM2_CH0                   TRUE
#define SPC5_HAS_STM2_CH1                   TRUE
#define SPC5_HAS_STM2_CH2                   TRUE
#define SPC5_HAS_STM2_CH3                   TRUE
#define SPC5_STM2_CH0_HANDLER               vector44
#define SPC5_STM2_CH1_HANDLER               vector45
#define SPC5_STM2_CH2_HANDLER               vector46
#define SPC5_STM2_CH3_HANDLER               vector47
#define SPC5_STM2_CH0_INT_NUMBER            44
#define SPC5_STM2_CH1_INT_NUMBER            45
#define SPC5_STM2_CH2_INT_NUMBER            46
#define SPC5_STM2_CH3_INT_NUMBER            47

/* I2C attributes.*/
#define SPC5_HAS_I2C                        1
#define SPC5_I2C0_PCTL                       101
#define SPC5_I2C0_HANDLER                    vector448
#define	SPC5_I2C0_INT_NUMBER                 448

/* CAN SUBSYSTEM 0 attributes.*/
#define SPC5_HAS_CAN_SUB_0_M_CAN_0             TRUE
#define SPC5_CAN_SUB_0_M_CAN_0_PTCL            72
#define SPC5_CAN_SUB_0_M_CAN_0_ENABLE_CLOCK()  SPCSetPeripheralClockMode(SPC5_CAN_SUB_0_M_CAN_0_PTCL, SPC5_CAN_SUB_0_M_CAN_0_START_PTCL);
#define SPC5_CAN_SUB_0_M_CAN_0_DISABLE_CLOCK() SPCSetPeripheralClockMode(SPC5_CAN_SUB_0_M_CAN_0_PTCL, SPC5_CAN_SUB_0_M_CAN_0_STOP_PTCL);
#define SPC5_CAN_SUB_0_M_CAN_0_L0_HANDLER      vector686
#define SPC5_CAN_SUB_0_M_CAN_0_L1_HANDLER      vector687
#define SPC5_CAN_SUB_0_M_CAN_0_L0_NUMBER       686
#define SPC5_CAN_SUB_0_M_CAN_0_L1_NUMBER       687

#define SPC5_HAS_CAN_SUB_0_M_CAN_1             TRUE
#define SPC5_CAN_SUB_0_M_CAN_1_PTCL            69
#define SPC5_CAN_SUB_0_M_CAN_1_ENABLE_CLOCK()  SPCSetPeripheralClockMode(SPC5_CAN_SUB_0_M_CAN_1_PTCL, SPC5_CAN_SUB_0_M_CAN_1_START_PTCL);
#define SPC5_CAN_SUB_0_M_CAN_1_DISABLE_CLOCK() SPCSetPeripheralClockMode(SPC5_CAN_SUB_0_M_CAN_1_PTCL, SPC5_CAN_SUB_0_M_CAN_1_STOP_PTCL);
#define SPC5_CAN_SUB_0_M_CAN_1_L0_HANDLER      vector688
#define SPC5_CAN_SUB_0_M_CAN_1_L1_HANDLER      vector689
#define SPC5_CAN_SUB_0_M_CAN_1_L0_NUMBER       688
#define SPC5_CAN_SUB_0_M_CAN_1_L1_NUMBER       689

#define SPC5_HAS_CAN_SUB_0_M_CAN_2             TRUE
#define SPC5_CAN_SUB_0_M_CAN_2_PTCL            68
#define SPC5_CAN_SUB_0_M_CAN_2_ENABLE_CLOCK()  SPCSetPeripheralClockMode(SPC5_CAN_SUB_0_M_CAN_2_PTCL, SPC5_CAN_SUB_0_M_CAN_2_START_PTCL);
#define SPC5_CAN_SUB_0_M_CAN_2_DISABLE_CLOCK() SPCSetPeripheralClockMode(SPC5_CAN_SUB_0_M_CAN_2_PTCL, SPC5_CAN_SUB_0_M_CAN_2_STOP_PTCL);
#define SPC5_CAN_SUB_0_M_CAN_2_L0_HANDLER      vector690
#define SPC5_CAN_SUB_0_M_CAN_2_L1_HANDLER      vector691
#define SPC5_CAN_SUB_0_M_CAN_2_L0_NUMBER       690
#define SPC5_CAN_SUB_0_M_CAN_2_L1_NUMBER       691

#define SPC5_HAS_CAN_SUB_0_M_CAN_3             TRUE
#define SPC5_CAN_SUB_0_M_CAN_3_PTCL            67
#define SPC5_CAN_SUB_0_M_CAN_3_ENABLE_CLOCK()  SPCSetPeripheralClockMode(SPC5_CAN_SUB_0_M_CAN_3_PTCL, SPC5_CAN_SUB_0_M_CAN_3_START_PTCL);
#define SPC5_CAN_SUB_0_M_CAN_3_DISABLE_CLOCK() SPCSetPeripheralClockMode(SPC5_CAN_SUB_0_M_CAN_3_PTCL, SPC5_CAN_SUB_0_M_CAN_3_STOP_PTCL);
#define SPC5_CAN_SUB_0_M_CAN_3_L0_HANDLER      vector692
#define SPC5_CAN_SUB_0_M_CAN_3_L1_HANDLER      vector693
#define SPC5_CAN_SUB_0_M_CAN_3_L0_NUMBER       692
#define SPC5_CAN_SUB_0_M_CAN_3_L1_NUMBER       693

#define SPC5_HAS_CAN_SUB_0_M_CAN_4             FALSE

#define SPC5_HAS_CAN_SUB_0_RAM                 TRUE
#define SPC5_CAN_SUB_0_RAM_PTCL                74
#define SPC5_CAN_SUB_0_RAM_ENABLE_CLOCK()      SPCSetPeripheralClockMode(SPC5_CAN_SUB_0_RAM_PTCL, SPC5_CAN_SUB_0_RAM_START_PTCL);
#define SPC5_CAN_SUB_0_RAM_DISABLE_CLOCK()     SPCSetPeripheralClockMode(SPC5_CAN_SUB_0_RAM_PTCL, SPC5_CAN_SUB_0_RAM_STOP_PTCL);

/* CAN SUBSYSTEM 1 attributes.*/
#define SPC5_HAS_CAN_SUB_1_M_CAN_0             FALSE

#define SPC5_HAS_CAN_SUB_1_M_CAN_1             TRUE
#define SPC5_CAN_SUB_1_M_CAN_1_PTCL            198
#define SPC5_CAN_SUB_1_M_CAN_1_ENABLE_CLOCK()  SPCSetPeripheralClockMode(SPC5_CAN_SUB_1_M_CAN_1_PTCL, SPC5_CAN_SUB_1_M_CAN_1_START_PTCL);
#define SPC5_CAN_SUB_1_M_CAN_1_DISABLE_CLOCK() SPCSetPeripheralClockMode(SPC5_CAN_SUB_1_M_CAN_1_PTCL, SPC5_CAN_SUB_1_M_CAN_1_STOP_PTCL);
#define SPC5_CAN_SUB_1_M_CAN_1_L0_HANDLER      vector694
#define SPC5_CAN_SUB_1_M_CAN_1_L1_HANDLER      vector695
#define SPC5_CAN_SUB_1_M_CAN_1_L0_NUMBER       694
#define SPC5_CAN_SUB_1_M_CAN_1_L1_NUMBER       695

#define SPC5_HAS_CAN_SUB_1_M_CAN_2             TRUE
#define SPC5_CAN_SUB_1_M_CAN_2_PTCL            197
#define SPC5_CAN_SUB_1_M_CAN_2_ENABLE_CLOCK()  SPCSetPeripheralClockMode(SPC5_CAN_SUB_1_M_CAN_2_PTCL, SPC5_CAN_SUB_1_M_CAN_2_START_PTCL);
#define SPC5_CAN_SUB_1_M_CAN_2_DISABLE_CLOCK() SPCSetPeripheralClockMode(SPC5_CAN_SUB_1_M_CAN_2_PTCL, SPC5_CAN_SUB_1_M_CAN_2_STOP_PTCL);
#define SPC5_CAN_SUB_1_M_CAN_2_L0_HANDLER      vector696
#define SPC5_CAN_SUB_1_M_CAN_2_L1_HANDLER      vector697
#define SPC5_CAN_SUB_1_M_CAN_2_L0_NUMBER       696
#define SPC5_CAN_SUB_1_M_CAN_2_L1_NUMBER       697

#define SPC5_HAS_CAN_SUB_1_M_CAN_3             TRUE
#define SPC5_CAN_SUB_1_M_CAN_3_PTCL            196
#define SPC5_CAN_SUB_1_M_CAN_3_ENABLE_CLOCK()  SPCSetPeripheralClockMode(SPC5_CAN_SUB_1_M_CAN_3_PTCL, SPC5_CAN_SUB_1_M_CAN_3_START_PTCL);
#define SPC5_CAN_SUB_1_M_CAN_3_DISABLE_CLOCK() SPCSetPeripheralClockMode(SPC5_CAN_SUB_1_M_CAN_3_PTCL, SPC5_CAN_SUB_1_M_CAN_3_STOP_PTCL);
#define SPC5_CAN_SUB_1_M_CAN_3_L0_HANDLER      vector698
#define SPC5_CAN_SUB_1_M_CAN_3_L1_HANDLER      vector699
#define SPC5_CAN_SUB_1_M_CAN_3_L0_NUMBER       698
#define SPC5_CAN_SUB_1_M_CAN_3_L1_NUMBER       699
                                           
#define SPC5_HAS_CAN_SUB_1_M_CAN_4             TRUE
#define SPC5_CAN_SUB_1_M_CAN_4_PTCL            195
#define SPC5_CAN_SUB_1_M_CAN_4_ENABLE_CLOCK()  SPCSetPeripheralClockMode(SPC5_CAN_SUB_1_M_CAN_4_PTCL, SPC5_CAN_SUB_1_M_CAN_4_START_PTCL);
#define SPC5_CAN_SUB_1_M_CAN_4_DISABLE_CLOCK() SPCSetPeripheralClockMode(SPC5_CAN_SUB_1_M_CAN_4_PTCL, SPC5_CAN_SUB_1_M_CAN_4_STOP_PTCL);
#define SPC5_CAN_SUB_1_M_CAN_4_L0_HANDLER      vector700
#define SPC5_CAN_SUB_1_M_CAN_4_L1_HANDLER      vector701
#define SPC5_CAN_SUB_1_M_CAN_4_L0_NUMBER       700
#define SPC5_CAN_SUB_1_M_CAN_4_L1_NUMBER       701

#define SPC5_HAS_CAN_SUB_1_RAM                 TRUE
#define SPC5_CAN_SUB_1_RAM_PTCL                202
#define SPC5_CAN_SUB_1_RAM_ENABLE_CLOCK()      SPCSetPeripheralClockMode(SPC5_CAN_SUB_1_RAM_PTCL, SPC5_CAN_SUB_1_RAM_START_PTCL);
#define SPC5_CAN_SUB_1_RAM_DISABLE_CLOCK()     SPCSetPeripheralClockMode(SPC5_CAN_SUB_1_RAM_PTCL, SPC5_CAN_SUB_1_RAM_STOP_PTCL);

/* CAN SUBSYSTEM 2 attributes.*/       
#define SPC5_HAS_CAN_SUB_2_M_CAN_0             FALSE
#define SPC5_HAS_CAN_SUB_2_M_CAN_1             FALSE
#define SPC5_HAS_CAN_SUB_2_M_CAN_2             FALSE
#define SPC5_HAS_CAN_SUB_2_M_CAN_3             FALSE
#define SPC5_HAS_CAN_SUB_2_M_CAN_4             FALSE
#define SPC5_HAS_CAN_SUB_2_RAM                 FALSE

/* CLOCK CALIBRATION CONTROL UNIT */
#define SPC5_HAS_CCCU_0                        TRUE
#define SPC5_CCCU_0_PTCL                       62
#define SPC5_CCCU_0_ENABLE_CLOCK()             SPCSetPeripheralClockMode(SPC5_CCCU_0_PTCL, SPC5_CCCU_0_START_PTCL);
#define SPC5_CCCU_0_DISABLE_CLOCK()            SPCSetPeripheralClockMode(SPC5_CCCU_0_PTCL, SPC5_CCCU_0_STOP_PTCL);

#define SPC5_HAS_CCCU_1                        FALSE

/* SWT attributes.*/
#define SPC5_HAS_SWT0                       TRUE
#define SPC5_SWT0_FCCU_CHANNEL              20U
#define SPC5_SWT0_BASE                      0xF4050000UL
#define SPC5_SWT0_HANDLER                   vector32
#define SPC5_SWT0_INT_NUMBER                32

#define SPC5_HAS_SWT1                       FALSE

#define SPC5_HAS_SWT2                       TRUE
#define SPC5_SWT2_FCCU_CHANNEL              18U
#define SPC5_SWT2_BASE                      0xF4058000UL
#define SPC5_SWT2_HANDLER                   vector34
#define SPC5_SWT2_INT_NUMBER                34

#define SPC5_HAS_SWT3                       TRUE
#define SPC5_SWT3_FCCU_CHANNEL              17U
#define SPC5_SWT3_BASE                      0xF405C000UL
#define SPC5_SWT3_HANDLER                   vector35
#define SPC5_SWT3_INT_NUMBER                35

/* FCCU Attributes */
#define SPC5_HAS_FCCU                       TRUE
#define SPC5_FCCU_BASE                      0xFBF58000UL
#define SPC5_FCCU_CH_NUMBER                 128U
#define SPC5_FCCU_ALARM_HANDLER             vector488
#define SPC5_FCCU_CONFIG_HANDLER            vector489
#define SPC5_FCCU_ALARM_INT_NUMBER          488
#define SPC5_FCCU_CONFIG_INT_NUMBER         489
#define SPC5_FCCU_HAS_ERR_INPUT_PIN         TRUE
#define SPC5_FCCU_EIN_ERR_CH                96U
#define SPC5_FCCU_EIN_MSCR_IO               27U
#define SPC5_FCCU_RF_E_REG_RESET_VAL        {0x00040040UL, 0x00000000UL, 0x00000000UL, 0x00000000UL}
#define SPC5_FCCU_MAX_DELTA_T_US            10000UL

#define MC_RGM_FCCU_RST                     MC_RGM.PRST5.B.FCCU_RST

/* SARADC attributes.*/
#define SPC5_HAS_SARADC12_0                 	TRUE
#define SPC5_SARADC12_0_PCTL                	127
#define SPC5_SARADC12_0_HANDLER             	vector528
#define SPC5_SARADC12_0_INT_NUMBER          	528
#define SPC5_SARADC12_0_DMA_MUX0_DEV_ID     	2
	
#define SPC5_HAS_SARADC12_1                 	TRUE
#define SPC5_SARADC12_1_PCTL                	255
#define SPC5_SARADC12_1_HANDLER             	vector529
#define SPC5_SARADC12_1_INT_NUMBER          	529
#define SPC5_SARADC12_1_DMA_MUX1_DEV_ID     	1
	
#define SPC5_HAS_SARADC12_2                 	FALSE
	
#define SPC5_HAS_SARADC12_3                 	TRUE
#define SPC5_SARADC12_3_PCTL                	254
#define SPC5_SARADC12_3_HANDLER             	vector531
#define SPC5_SARADC12_3_INT_NUMBER          	531
#define SPC5_SARADC12_3_DMA_MUX3_DEV_ID     	1
	
#define SPC5_HAS_SARADC12_4                 	FALSE
#define SPC5_HAS_SARADC12_5                 	FALSE
#define SPC5_HAS_SARADC12_6                 	FALSE
	
#define SPC5_HAS_SARADC12_SV                	TRUE
#define SPC5_SARADC12_SV_PCTL               	112
#define SPC5_SARADC12_SV_HANDLER            	vector543
#define SPC5_SARADC12_SV_INT_NUMBER         	543
#define SPC5_SARADC12_SV_DMA_MUX0_DEV_ID    	1
	
#define SPC5_HAS_SARADC12_SV_1              	FALSE
#define SPC5_HAS_SARADC10_0                 	FALSE
#define SPC5_HAS_SARADC10_1                 	FALSE
	
#define SPC5_HAS_SARADC10_STANDBY           	TRUE
#define SPC5_SARADC10_STANDBY_PCTL          	114
#define SPC5_SARADC10_STANDBY_HANDLER       	vector557
#define SPC5_SARADC10_STANDBY_INT_NUMBER    	557
#define SPC5_SARADC10_STANDBY_DMA_MUX1_DEV_ID   2

#define SPC5_SARADC_MASK_REG_NUM                3U

/* eMIOS attributes.*/
#define SPC5_HAS_EMIOS0                     TRUE
#define SPC5_EMIOS0_BASE                    0xF7C38000UL
#define SPC5_EMIOS0_PCTL                    241
#define SPC5_EMIOS0_GFR_F0F1_HANDLER        vector900
#define SPC5_EMIOS0_GFR_F2F3_HANDLER        vector901
#define SPC5_EMIOS0_GFR_F4F5_HANDLER        vector902
#define SPC5_EMIOS0_GFR_F6F7_HANDLER        vector903
#define SPC5_EMIOS0_GFR_F8F9_HANDLER        vector904
#define SPC5_EMIOS0_GFR_F10F11_HANDLER      vector905
#define SPC5_EMIOS0_GFR_F12F13_HANDLER      vector906
#define SPC5_EMIOS0_GFR_F14F15_HANDLER      vector907
#define SPC5_EMIOS0_GFR_F16F17_HANDLER      vector908
#define SPC5_EMIOS0_GFR_F18F19_HANDLER      vector909
#define SPC5_EMIOS0_GFR_F20F21_HANDLER      vector910
#define SPC5_EMIOS0_GFR_F22F23_HANDLER      vector911
#define SPC5_EMIOS0_GFR_F24F25_HANDLER      vector912
#define SPC5_EMIOS0_GFR_F26F27_HANDLER      vector913
#define SPC5_EMIOS0_GFR_F28F29_HANDLER      vector914
#define SPC5_EMIOS0_GFR_F30F31_HANDLER      vector915
#define SPC5_EMIOS0_GFR_F0F1_NUMBER         900
#define SPC5_EMIOS0_GFR_F2F3_NUMBER         901
#define SPC5_EMIOS0_GFR_F4F5_NUMBER         902
#define SPC5_EMIOS0_GFR_F6F7_NUMBER         903
#define SPC5_EMIOS0_GFR_F8F9_NUMBER         904
#define SPC5_EMIOS0_GFR_F10F11_NUMBER       905
#define SPC5_EMIOS0_GFR_F12F13_NUMBER       906
#define SPC5_EMIOS0_GFR_F14F15_NUMBER       907
#define SPC5_EMIOS0_GFR_F16F17_NUMBER       908
#define SPC5_EMIOS0_GFR_F18F19_NUMBER       909
#define SPC5_EMIOS0_GFR_F20F21_NUMBER       910
#define SPC5_EMIOS0_GFR_F22F23_NUMBER       911
#define SPC5_EMIOS0_GFR_F24F25_NUMBER       912
#define SPC5_EMIOS0_GFR_F26F27_NUMBER       913
#define SPC5_EMIOS0_GFR_F28F29_NUMBER       914
#define SPC5_EMIOS0_GFR_F30F31_NUMBER       915

#define SPC5_HAS_EMIOS1                     TRUE
#define SPC5_EMIOS1_BASE                    0xFBC38000UL
#define SPC5_EMIOS1_PCTL                    240
#define SPC5_EMIOS1_GFR_F0F1_HANDLER        vector916
#define SPC5_EMIOS1_GFR_F2F3_HANDLER        vector917
#define SPC5_EMIOS1_GFR_F4F5_HANDLER        vector918
#define SPC5_EMIOS1_GFR_F6F7_HANDLER        vector919
#define SPC5_EMIOS1_GFR_F8F9_HANDLER        vector920
#define SPC5_EMIOS1_GFR_F10F11_HANDLER      vector921
#define SPC5_EMIOS1_GFR_F12F13_HANDLER      vector922
#define SPC5_EMIOS1_GFR_F14F15_HANDLER      vector923
#define SPC5_EMIOS1_GFR_F16F17_HANDLER      vector924
#define SPC5_EMIOS1_GFR_F18F19_HANDLER      vector925
#define SPC5_EMIOS1_GFR_F20F21_HANDLER      vector926
#define SPC5_EMIOS1_GFR_F22F23_HANDLER      vector927
#define SPC5_EMIOS1_GFR_F24F25_HANDLER      vector928
#define SPC5_EMIOS1_GFR_F26F27_HANDLER      vector929
#define SPC5_EMIOS1_GFR_F28F29_HANDLER      vector930
#define SPC5_EMIOS1_GFR_F30F31_HANDLER      vector931
#define SPC5_EMIOS1_GFR_F0F1_NUMBER         916
#define SPC5_EMIOS1_GFR_F2F3_NUMBER         917
#define SPC5_EMIOS1_GFR_F4F5_NUMBER         918
#define SPC5_EMIOS1_GFR_F6F7_NUMBER         919
#define SPC5_EMIOS1_GFR_F8F9_NUMBER         920
#define SPC5_EMIOS1_GFR_F10F11_NUMBER       921
#define SPC5_EMIOS1_GFR_F12F13_NUMBER       922
#define SPC5_EMIOS1_GFR_F14F15_NUMBER       923
#define SPC5_EMIOS1_GFR_F16F17_NUMBER       924
#define SPC5_EMIOS1_GFR_F18F19_NUMBER       925
#define SPC5_EMIOS1_GFR_F20F21_NUMBER       926
#define SPC5_EMIOS1_GFR_F22F23_NUMBER       927
#define SPC5_EMIOS1_GFR_F24F25_NUMBER       928
#define SPC5_EMIOS1_GFR_F26F27_NUMBER       929
#define SPC5_EMIOS1_GFR_F28F29_NUMBER       930
#define SPC5_EMIOS1_GFR_F30F31_NUMBER       931

#define SPC5_HAS_EMIOS2                     FALSE

/* WKPU Attributes */
#define SPC5_HAS_WKPU0                      TRUE
#define SPC5_WKPU0_BASE                     0xF7F98000UL
#define SPC5_WKPU0_IRQ0_HANDLER             vector247
#define SPC5_WKPU0_IRQ1_HANDLER             vector248
#define SPC5_WKPU0_IRQ2_HANDLER             vector249
#define SPC5_WKPU0_IRQ3_HANDLER             vector250
#define SPC5_WKPU0_IRQ0_INT_NUMBER          247
#define SPC5_WKPU0_IRQ1_INT_NUMBER          248
#define SPC5_WKPU0_IRQ2_INT_NUMBER          249
#define SPC5_WKPU0_IRQ3_INT_NUMBER          250

#define SPC5_HAS_WKPU1                      FALSE

#define SPC5_WKPU_SUPPORT_EXT_SRC           TRUE

/* RTC/API Attributes */
#define SCP5_RTC_RTC_HANDLER                vector224
#define SCP5_RTC_API_HANDLER                vector225
#define SCP5_RTC_RTC_INT_NUMBER             224
#define SCP5_RTC_API_INT_NUMBER             225

/* BCTU Attributes */
#define SPC5_BCTU_BASE                      0xF7C30000UL
#define SPC5_BCTU_PCTL                      243
#define SPC5_BCTU_TRIGGER_NUMBER            64U

/* CMPU Attributes */
#define SPC5_CMPU_NUM_OF_ENTRIES            24U

/** @} */

#endif /* SPC5_REGISTRY_H */

/** @} */
