/* SPDX-License-Identifier: Apache-2.0 */
/*
 * Copyright (C) 2022-2023 chargebyte GmbH
 * Copyright (C) 2022-2023 Contributors to EVerest
 */

/*****************************************************
 *
 * @author
 * @version
 *
 * The Code is generated! Changes may be overwritten.
 *
 *****************************************************/

/**
  * @file iso20_CommonMessages_Encoder.h
  * @brief Description goes here
  *
  **/

#ifndef ISO20_COMMON_MESSAGES_ENCODER_H
#define ISO20_COMMON_MESSAGES_ENCODER_H

#ifdef __cplusplus
extern "C" {
#endif


#include "common/exi_bitstream.h"
#include "iso20_CommonMessages_Datatypes.h"


// main function for encoding
int encode_iso20_exiDocument(exi_bitstream_t* stream, struct iso20_exiDocument* exiDoc);

#ifdef __cplusplus
}
#endif

#endif /* ISO20_COMMON_MESSAGES_ENCODER_H */

