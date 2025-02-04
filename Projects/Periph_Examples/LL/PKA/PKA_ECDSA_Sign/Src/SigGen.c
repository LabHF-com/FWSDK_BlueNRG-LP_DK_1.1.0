/**
  ******************************************************************************
  * @file    PKA/PKA_ECDSA_Sign/Src/SigGen.c
  * @author  MCD Application Team
  * @brief   This file contains reference buffers from 
  *          NIST Cryptographic Algorithm Validation Program (CAVP).
  *          (http://csrc.nist.gov/groups/STM/cavp/)
  *          1 test vector is extracted to demonstrate PKA capability to
  *          sign a message using ECDSA (Elliptic Curve Digital Signature Algorithm) 
  *          signature generation function principle.
  *          It is adapted from SigGen.txt section [P-256,SHA-256] available under
  *          http://csrc.nist.gov/groups/STM/cavp/documents/dss/186-3ecdsatestvectors.zip
  *          and provided in the same directory for reference.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics. 
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the 
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
  
/* Includes ------------------------------------------------------------------*/
#include "PKA_ECDSA_Sign_main.h"
/*
  Adapted from
  [P-256,SHA-256]
  Msg = 5905238877c77421f73e43ee3da6f2d9e2ccad5fc942dcec0cbd25482935faaf416983fe165b1a045ee2bcd2e6dca3bdf46c4310a7461f9a37960ca672d3feb5473e253605fb1ddfd28065b53cb5858a8ad28175bf9bd386a5e471ea7a65c17cc934a9d791e91491eb3754d03799790fe2d308d16146d5c9b0d0debd97d79ce8
  d = 519b423d715f8b581f4fa8ee59f4771a5b44c8130b4e3eacca54a56dda72b464
  Qx = 1ccbe91c075fc7f4f033bfa248db8fccd3565de94bbfb12f3c59ff46c271bf83
  Qy = ce4014c68811f9a21a1fdb2c0e6113e06db7ca93b7404e78dc7ccd5ca89a4ca9
  k = 94a1bbb14b906a61a280f245f9e93c7f3b4a6247824f5d33b9670787642a68de
  R = f3ac8061b514795b8843e3d6629527ed2afd6b1f6a555a7acabb5e6f79c8c2ac
  S = 8bf77819ca05a6b2786c76262bf7371cef97b218e96f175a3ccdda2acc058903
*/


#ifdef CONFIG_DEVICE_BLUENRG_LPS

__ALIGNED(4) const uint8_t SigGen_Msg[] = {
  0x59, 0x05, 0x23, 0x88, 0x77, 0xc7, 0x74, 0x21, 0xf7, 0x3e, 0x43, 0xee, 0x3d, 0xa6, 0xf2, 0xd9,
  0xe2, 0xcc, 0xad, 0x5f, 0xc9, 0x42, 0xdc, 0xec, 0x0c, 0xbd, 0x25, 0x48, 0x29, 0x35, 0xfa, 0xaf,
  0x41, 0x69, 0x83, 0xfe, 0x16, 0x5b, 0x1a, 0x04, 0x5e, 0xe2, 0xbc, 0xd2, 0xe6, 0xdc, 0xa3, 0xbd,
  0xf4, 0x6c, 0x43, 0x10, 0xa7, 0x46, 0x1f, 0x9a, 0x37, 0x96, 0x0c, 0xa6, 0x72, 0xd3, 0xfe, 0xb5,
  0x47, 0x3e, 0x25, 0x36, 0x05, 0xfb, 0x1d, 0xdf, 0xd2, 0x80, 0x65, 0xb5, 0x3c, 0xb5, 0x85, 0x8a,
  0x8a, 0xd2, 0x81, 0x75, 0xbf, 0x9b, 0xd3, 0x86, 0xa5, 0xe4, 0x71, 0xea, 0x7a, 0x65, 0xc1, 0x7c,
  0xc9, 0x34, 0xa9, 0xd7, 0x91, 0xe9, 0x14, 0x91, 0xeb, 0x37, 0x54, 0xd0, 0x37, 0x99, 0x79, 0x0f,
  0xe2, 0xd3, 0x08, 0xd1, 0x61, 0x46, 0xd5, 0xc9, 0xb0, 0xd0, 0xde, 0xbd, 0x97, 0xd7, 0x9c, 0xe8
};

const uint32_t SigGen_Msg_len = 128;

/* Result of hashing SigGen_Msg (You can verify using "openssl dgst -sha256" or "sha256sum" utilities)*/
__ALIGNED(4) const uint8_t SigGen_Hash_Msg[] = {
  0x44, 0xac, 0xf6, 0xb7, 0xe3, 0x6c, 0x13, 0x42, 0xc2, 0xc5, 0x89, 0x72, 0x04, 0xfe, 0x09, 0x50, 
  0x4e, 0x1e, 0x2e, 0xfb, 0x1a, 0x90, 0x03, 0x77, 0xdb, 0xc4, 0xe7, 0xa6, 0xa1, 0x33, 0xec, 0x56
};

const uint32_t SigGen_Hash_Msg_len = 32;

__ALIGNED(4) const uint8_t SigGen_d[] = {
  0x51, 0x9b, 0x42, 0x3d, 0x71, 0x5f, 0x8b, 0x58, 0x1f, 0x4f, 0xa8, 0xee, 0x59, 0xf4, 0x77, 0x1a,
  0x5b, 0x44, 0xc8, 0x13, 0x0b, 0x4e, 0x3e, 0xac, 0xca, 0x54, 0xa5, 0x6d, 0xda, 0x72, 0xb4, 0x64
};

const uint32_t SigGen_d_len = 32;

__ALIGNED(4) const uint8_t SigGen_Qx[] = {
  0x1c, 0xcb, 0xe9, 0x1c, 0x07, 0x5f, 0xc7, 0xf4, 0xf0, 0x33, 0xbf, 0xa2, 0x48, 0xdb, 0x8f, 0xcc,
  0xd3, 0x56, 0x5d, 0xe9, 0x4b, 0xbf, 0xb1, 0x2f, 0x3c, 0x59, 0xff, 0x46, 0xc2, 0x71, 0xbf, 0x83
};
const uint32_t SigGen_Qx_len = 32;

__ALIGNED(4) const uint8_t SigGen_Qy[] = {
  0xce, 0x40, 0x14, 0xc6, 0x88, 0x11, 0xf9, 0xa2, 0x1a, 0x1f, 0xdb, 0x2c, 0x0e, 0x61, 0x13, 0xe0,
  0x6d, 0xb7, 0xca, 0x93, 0xb7, 0x40, 0x4e, 0x78, 0xdc, 0x7c, 0xcd, 0x5c, 0xa8, 0x9a, 0x4c, 0xa9
};
const uint32_t SigGen_Qy_len = 32;

__ALIGNED(4) const uint8_t SigGen_k[] = {
  0x94, 0xa1, 0xbb, 0xb1, 0x4b, 0x90, 0x6a, 0x61, 0xa2, 0x80, 0xf2, 0x45, 0xf9, 0xe9, 0x3c, 0x7f,
  0x3b, 0x4a, 0x62, 0x47, 0x82, 0x4f, 0x5d, 0x33, 0xb9, 0x67, 0x07, 0x87, 0x64, 0x2a, 0x68, 0xde
};

const uint32_t SigGen_k_len = 32;

__ALIGNED(4) const uint8_t SigGen_R[] = {
  0xf3, 0xac, 0x80, 0x61, 0xb5, 0x14, 0x79, 0x5b, 0x88, 0x43, 0xe3, 0xd6, 0x62, 0x95, 0x27, 0xed,
  0x2a, 0xfd, 0x6b, 0x1f, 0x6a, 0x55, 0x5a, 0x7a, 0xca, 0xbb, 0x5e, 0x6f, 0x79, 0xc8, 0xc2, 0xac
};
const uint32_t SigGen_R_len = 32;

__ALIGNED(4) const uint8_t SigGen_S[] = {
  0x8b, 0xf7, 0x78, 0x19, 0xca, 0x05, 0xa6, 0xb2, 0x78, 0x6c, 0x76, 0x26, 0x2b, 0xf7, 0x37, 0x1c,
  0xef, 0x97, 0xb2, 0x18, 0xe9, 0x6f, 0x17, 0x5a, 0x3c, 0xcd, 0xda, 0x2a, 0xcc, 0x05, 0x89, 0x03
};
const uint32_t SigGen_S_len = 32;

#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
