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
  * @file iso20_AC_Encoder.c
  * @brief Description goes here
  *
  **/
#include <stdint.h>

#include "common/exi_basetypes.h"
#include "common/exi_basetypes_encoder.h"
#include "common/exi_error_codes.h"
#include "common/exi_header.h"
#include "iso20_AC_Datatypes.h"
#include "iso20_AC_Encoder.h"



static int encode_iso20_ac_TransformType(exi_bitstream_t* stream, struct iso20_ac_TransformType* TransformType);
static int encode_iso20_ac_TransformsType(exi_bitstream_t* stream, struct iso20_ac_TransformsType* TransformsType);
static int encode_iso20_ac_DSAKeyValueType(exi_bitstream_t* stream, struct iso20_ac_DSAKeyValueType* DSAKeyValueType);
static int encode_iso20_ac_X509IssuerSerialType(exi_bitstream_t* stream, struct iso20_ac_X509IssuerSerialType* X509IssuerSerialType);
static int encode_iso20_ac_DigestMethodType(exi_bitstream_t* stream, struct iso20_ac_DigestMethodType* DigestMethodType);
static int encode_iso20_ac_RSAKeyValueType(exi_bitstream_t* stream, struct iso20_ac_RSAKeyValueType* RSAKeyValueType);
static int encode_iso20_ac_CanonicalizationMethodType(exi_bitstream_t* stream, struct iso20_ac_CanonicalizationMethodType* CanonicalizationMethodType);
static int encode_iso20_ac_SignatureMethodType(exi_bitstream_t* stream, struct iso20_ac_SignatureMethodType* SignatureMethodType);
static int encode_iso20_ac_KeyValueType(exi_bitstream_t* stream, struct iso20_ac_KeyValueType* KeyValueType);
static int encode_iso20_ac_ReferenceType(exi_bitstream_t* stream, struct iso20_ac_ReferenceType* ReferenceType);
static int encode_iso20_ac_RetrievalMethodType(exi_bitstream_t* stream, struct iso20_ac_RetrievalMethodType* RetrievalMethodType);
static int encode_iso20_ac_X509DataType(exi_bitstream_t* stream, struct iso20_ac_X509DataType* X509DataType);
static int encode_iso20_ac_PGPDataType(exi_bitstream_t* stream, struct iso20_ac_PGPDataType* PGPDataType);
static int encode_iso20_ac_SPKIDataType(exi_bitstream_t* stream, struct iso20_ac_SPKIDataType* SPKIDataType);
static int encode_iso20_ac_SignedInfoType(exi_bitstream_t* stream, struct iso20_ac_SignedInfoType* SignedInfoType);
static int encode_iso20_ac_SignatureValueType(exi_bitstream_t* stream, struct iso20_ac_SignatureValueType* SignatureValueType);
static int encode_iso20_ac_KeyInfoType(exi_bitstream_t* stream, struct iso20_ac_KeyInfoType* KeyInfoType);
static int encode_iso20_ac_ObjectType(exi_bitstream_t* stream, struct iso20_ac_ObjectType* ObjectType);
static int encode_iso20_ac_RationalNumberType(exi_bitstream_t* stream, struct iso20_ac_RationalNumberType* RationalNumberType);
static int encode_iso20_ac_DetailedCostType(exi_bitstream_t* stream, struct iso20_ac_DetailedCostType* DetailedCostType);
static int encode_iso20_ac_SignatureType(exi_bitstream_t* stream, struct iso20_ac_SignatureType* SignatureType);
static int encode_iso20_ac_DetailedTaxType(exi_bitstream_t* stream, struct iso20_ac_DetailedTaxType* DetailedTaxType);
static int encode_iso20_ac_MessageHeaderType(exi_bitstream_t* stream, struct iso20_ac_MessageHeaderType* MessageHeaderType);
static int encode_iso20_ac_SignaturePropertyType(exi_bitstream_t* stream, struct iso20_ac_SignaturePropertyType* SignaturePropertyType);
static int encode_iso20_ac_AC_CPDReqEnergyTransferModeType(exi_bitstream_t* stream, struct iso20_ac_AC_CPDReqEnergyTransferModeType* AC_CPDReqEnergyTransferModeType);
static int encode_iso20_ac_DisplayParametersType(exi_bitstream_t* stream, struct iso20_ac_DisplayParametersType* DisplayParametersType);
static int encode_iso20_ac_AC_CPDResEnergyTransferModeType(exi_bitstream_t* stream, struct iso20_ac_AC_CPDResEnergyTransferModeType* AC_CPDResEnergyTransferModeType);
static int encode_iso20_ac_EVSEStatusType(exi_bitstream_t* stream, struct iso20_ac_EVSEStatusType* EVSEStatusType);
static int encode_iso20_ac_Dynamic_AC_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_ac_Dynamic_AC_CLReqControlModeType* Dynamic_AC_CLReqControlModeType);
static int encode_iso20_ac_Scheduled_AC_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_ac_Scheduled_AC_CLReqControlModeType* Scheduled_AC_CLReqControlModeType);
static int encode_iso20_ac_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_ac_CLReqControlModeType* CLReqControlModeType);
static int encode_iso20_ac_MeterInfoType(exi_bitstream_t* stream, struct iso20_ac_MeterInfoType* MeterInfoType);
static int encode_iso20_ac_ReceiptType(exi_bitstream_t* stream, struct iso20_ac_ReceiptType* ReceiptType);
static int encode_iso20_ac_Dynamic_AC_CLResControlModeType(exi_bitstream_t* stream, struct iso20_ac_Dynamic_AC_CLResControlModeType* Dynamic_AC_CLResControlModeType);
static int encode_iso20_ac_Scheduled_AC_CLResControlModeType(exi_bitstream_t* stream, struct iso20_ac_Scheduled_AC_CLResControlModeType* Scheduled_AC_CLResControlModeType);
static int encode_iso20_ac_CLResControlModeType(exi_bitstream_t* stream, struct iso20_ac_CLResControlModeType* CLResControlModeType);
static int encode_iso20_ac_BPT_AC_CPDReqEnergyTransferModeType(exi_bitstream_t* stream, struct iso20_ac_BPT_AC_CPDReqEnergyTransferModeType* BPT_AC_CPDReqEnergyTransferModeType);
static int encode_iso20_ac_AC_ChargeParameterDiscoveryReqType(exi_bitstream_t* stream, struct iso20_ac_AC_ChargeParameterDiscoveryReqType* AC_ChargeParameterDiscoveryReqType);
static int encode_iso20_ac_BPT_AC_CPDResEnergyTransferModeType(exi_bitstream_t* stream, struct iso20_ac_BPT_AC_CPDResEnergyTransferModeType* BPT_AC_CPDResEnergyTransferModeType);
static int encode_iso20_ac_AC_ChargeParameterDiscoveryResType(exi_bitstream_t* stream, struct iso20_ac_AC_ChargeParameterDiscoveryResType* AC_ChargeParameterDiscoveryResType);
static int encode_iso20_ac_BPT_Scheduled_AC_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_ac_BPT_Scheduled_AC_CLReqControlModeType* BPT_Scheduled_AC_CLReqControlModeType);
static int encode_iso20_ac_BPT_Scheduled_AC_CLResControlModeType(exi_bitstream_t* stream, struct iso20_ac_BPT_Scheduled_AC_CLResControlModeType* BPT_Scheduled_AC_CLResControlModeType);
static int encode_iso20_ac_BPT_Dynamic_AC_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_ac_BPT_Dynamic_AC_CLReqControlModeType* BPT_Dynamic_AC_CLReqControlModeType);
static int encode_iso20_ac_AC_ChargeLoopReqType(exi_bitstream_t* stream, struct iso20_ac_AC_ChargeLoopReqType* AC_ChargeLoopReqType);
static int encode_iso20_ac_BPT_Dynamic_AC_CLResControlModeType(exi_bitstream_t* stream, struct iso20_ac_BPT_Dynamic_AC_CLResControlModeType* BPT_Dynamic_AC_CLResControlModeType);
static int encode_iso20_ac_AC_ChargeLoopResType(exi_bitstream_t* stream, struct iso20_ac_AC_ChargeLoopResType* AC_ChargeLoopResType);
static int encode_iso20_ac_ManifestType(exi_bitstream_t* stream, struct iso20_ac_ManifestType* ManifestType);
static int encode_iso20_ac_SignaturePropertiesType(exi_bitstream_t* stream, struct iso20_ac_SignaturePropertiesType* SignaturePropertiesType);

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Transform; type={http://www.w3.org/2000/09/xmldsig#}TransformType; base type=; content type=mixed;
//          abstract=False; final=False; choice=True;
// Particle: Algorithm, anyURI (1, 1); ANY, anyType (0, 1); XPath, string (0, 1);
static int encode_iso20_ac_TransformType(exi_bitstream_t* stream, struct iso20_ac_TransformType* TransformType) {
    int grammar_id = 0;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 0:
            // Grammar: ID=0; read/write bits=1; START (Algorithm)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (anyURI); next=1

                // string should not be found in table, so add 2
                error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(TransformType->Algorithm.charactersLen + 2));
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_characters(stream, TransformType->Algorithm.charactersLen, TransformType->Algorithm.characters, iso20_ac_Algorithm_CHARACTER_SIZE);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 1;
                    }
                }
            }
            break;
        case 1:
            // Grammar: ID=1; read/write bits=2; START (ANY), START (XPath), END Element
            if (TransformType->ANY_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ANY, base64Binary); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)TransformType->ANY.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, TransformType->ANY.bytesLen, TransformType->ANY.bytes, iso20_ac_anyType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            else if (TransformType->XPath_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (XPath, string); next=2

                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // string should not be found in table, so add 2
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(TransformType->XPath.charactersLen + 2));
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_characters(stream, TransformType->XPath.charactersLen, TransformType->XPath.characters, iso20_ac_XPath_CHARACTER_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Transforms; type={http://www.w3.org/2000/09/xmldsig#}TransformsType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Transform, TransformType (1, 1);
static int encode_iso20_ac_TransformsType(exi_bitstream_t* stream, struct iso20_ac_TransformsType* TransformsType) {
    int grammar_id = 4;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 4:
            // Grammar: ID=4; read/write bits=1; START (Transform)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (TransformType); next=2
                error = encode_iso20_ac_TransformType(stream, &TransformsType->Transform);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 2;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}DSAKeyValue; type={http://www.w3.org/2000/09/xmldsig#}DSAKeyValueType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: P, CryptoBinary (0, 1)(was 1, 1)(seq. ['P', 'Q']); Q, CryptoBinary (0, 1)(was 1, 1)(seq. ['P', 'Q']); G, CryptoBinary (0, 1); Y, CryptoBinary (1, 1); J, CryptoBinary (0, 1); Seed, CryptoBinary (0, 1)(was 1, 1)(seq. ['Seed', 'PgenCounter']); PgenCounter, CryptoBinary (0, 1)(was 1, 1)(seq. ['Seed', 'PgenCounter']);
static int encode_iso20_ac_DSAKeyValueType(exi_bitstream_t* stream, struct iso20_ac_DSAKeyValueType* DSAKeyValueType) {
    int grammar_id = 5;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 5:
            // Grammar: ID=5; read/write bits=2; START (P), START (G), START (Y)
            if (DSAKeyValueType->P_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (P, base64Binary); next=6
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)DSAKeyValueType->P.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->P.bytesLen, DSAKeyValueType->P.bytes, iso20_ac_CryptoBinary_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 6;
                                }
                            }
                        }
                    }
                }
            }
            else if (DSAKeyValueType->G_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (G, base64Binary); next=8
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)DSAKeyValueType->G.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->G.bytesLen, DSAKeyValueType->G.bytes, iso20_ac_CryptoBinary_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 8;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Y, base64Binary); next=9
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)DSAKeyValueType->Y.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->Y.bytesLen, DSAKeyValueType->Y.bytes, iso20_ac_CryptoBinary_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 9;
                                }
                            }
                        }
                    }
                }
            }
            break;
        case 6:
            // Grammar: ID=6; read/write bits=1; START (Q)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (base64Binary); next=7
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)DSAKeyValueType->Q.bytesLen);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->Q.bytesLen, DSAKeyValueType->Q.bytes, iso20_ac_CryptoBinary_BYTES_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 7;
                            }
                        }
                    }
                }
            }
            break;
        case 7:
            // Grammar: ID=7; read/write bits=2; START (G), START (Y)
            if (DSAKeyValueType->G_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (G, base64Binary); next=8
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)DSAKeyValueType->G.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->G.bytesLen, DSAKeyValueType->G.bytes, iso20_ac_CryptoBinary_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 8;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Y, base64Binary); next=9
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)DSAKeyValueType->Y.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->Y.bytesLen, DSAKeyValueType->Y.bytes, iso20_ac_CryptoBinary_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 9;
                                }
                            }
                        }
                    }
                }
            }
            break;
        case 8:
            // Grammar: ID=8; read/write bits=1; START (Y)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (base64Binary); next=9
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)DSAKeyValueType->Y.bytesLen);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->Y.bytesLen, DSAKeyValueType->Y.bytes, iso20_ac_CryptoBinary_BYTES_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 9;
                            }
                        }
                    }
                }
            }
            break;
        case 9:
            // Grammar: ID=9; read/write bits=2; START (J), START (Seed), END Element
            if (DSAKeyValueType->J_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (J, base64Binary); next=10
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)DSAKeyValueType->J.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->J.bytesLen, DSAKeyValueType->J.bytes, iso20_ac_CryptoBinary_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 10;
                                }
                            }
                        }
                    }
                }
            }
            else if (DSAKeyValueType->Seed_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Seed, base64Binary); next=11
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)DSAKeyValueType->Seed.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->Seed.bytesLen, DSAKeyValueType->Seed.bytes, iso20_ac_CryptoBinary_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 11;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 10:
            // Grammar: ID=10; read/write bits=2; START (Seed), END Element
            if (DSAKeyValueType->Seed_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Seed, base64Binary); next=11
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)DSAKeyValueType->Seed.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->Seed.bytesLen, DSAKeyValueType->Seed.bytes, iso20_ac_CryptoBinary_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 11;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 11:
            // Grammar: ID=11; read/write bits=2; START (PgenCounter), END Element
            if (DSAKeyValueType->PgenCounter_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (PgenCounter, base64Binary); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)DSAKeyValueType->PgenCounter.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->PgenCounter.bytesLen, DSAKeyValueType->PgenCounter.bytes, iso20_ac_CryptoBinary_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}X509IssuerSerial; type={http://www.w3.org/2000/09/xmldsig#}X509IssuerSerialType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: X509IssuerName, string (1, 1); X509SerialNumber, integer (1, 1);
static int encode_iso20_ac_X509IssuerSerialType(exi_bitstream_t* stream, struct iso20_ac_X509IssuerSerialType* X509IssuerSerialType) {
    int grammar_id = 12;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 12:
            // Grammar: ID=12; read/write bits=1; START (X509IssuerName)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (string); next=13

                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(X509IssuerSerialType->X509IssuerName.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, X509IssuerSerialType->X509IssuerName.charactersLen, X509IssuerSerialType->X509IssuerName.characters, iso20_ac_X509IssuerName_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 13;
                            }
                        }
                    }
                }
            }
            break;
        case 13:
            // Grammar: ID=13; read/write bits=1; START (X509SerialNumber)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (decimal); next=2
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_integer_32(stream, X509IssuerSerialType->X509SerialNumber);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 2;
                        }
                    }
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}DigestMethod; type={http://www.w3.org/2000/09/xmldsig#}DigestMethodType; base type=; content type=mixed;
//          abstract=False; final=False;
// Particle: Algorithm, anyURI (1, 1); ANY, anyType (0, 1);
static int encode_iso20_ac_DigestMethodType(exi_bitstream_t* stream, struct iso20_ac_DigestMethodType* DigestMethodType) {
    int grammar_id = 14;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 14:
            // Grammar: ID=14; read/write bits=1; START (Algorithm)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (anyURI); next=15

                // string should not be found in table, so add 2
                error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(DigestMethodType->Algorithm.charactersLen + 2));
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_characters(stream, DigestMethodType->Algorithm.charactersLen, DigestMethodType->Algorithm.characters, iso20_ac_Algorithm_CHARACTER_SIZE);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 15;
                    }
                }
            }
            break;
        case 15:
            // Grammar: ID=15; read/write bits=2; START (ANY), END Element
            if (DigestMethodType->ANY_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ANY, base64Binary); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)DigestMethodType->ANY.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, DigestMethodType->ANY.bytesLen, DigestMethodType->ANY.bytes, iso20_ac_anyType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}RSAKeyValue; type={http://www.w3.org/2000/09/xmldsig#}RSAKeyValueType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Modulus, CryptoBinary (1, 1); Exponent, CryptoBinary (1, 1);
static int encode_iso20_ac_RSAKeyValueType(exi_bitstream_t* stream, struct iso20_ac_RSAKeyValueType* RSAKeyValueType) {
    int grammar_id = 16;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 16:
            // Grammar: ID=16; read/write bits=1; START (Modulus)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (base64Binary); next=17
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)RSAKeyValueType->Modulus.bytesLen);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bytes(stream, RSAKeyValueType->Modulus.bytesLen, RSAKeyValueType->Modulus.bytes, iso20_ac_CryptoBinary_BYTES_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 17;
                            }
                        }
                    }
                }
            }
            break;
        case 17:
            // Grammar: ID=17; read/write bits=1; START (Exponent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (base64Binary); next=2
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)RSAKeyValueType->Exponent.bytesLen);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bytes(stream, RSAKeyValueType->Exponent.bytesLen, RSAKeyValueType->Exponent.bytes, iso20_ac_CryptoBinary_BYTES_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}CanonicalizationMethod; type={http://www.w3.org/2000/09/xmldsig#}CanonicalizationMethodType; base type=; content type=mixed;
//          abstract=False; final=False;
// Particle: Algorithm, anyURI (1, 1); ANY, anyType (0, 1);
static int encode_iso20_ac_CanonicalizationMethodType(exi_bitstream_t* stream, struct iso20_ac_CanonicalizationMethodType* CanonicalizationMethodType) {
    int grammar_id = 18;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 18:
            // Grammar: ID=18; read/write bits=1; START (Algorithm)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (anyURI); next=19

                // string should not be found in table, so add 2
                error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(CanonicalizationMethodType->Algorithm.charactersLen + 2));
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_characters(stream, CanonicalizationMethodType->Algorithm.charactersLen, CanonicalizationMethodType->Algorithm.characters, iso20_ac_Algorithm_CHARACTER_SIZE);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 19;
                    }
                }
            }
            break;
        case 19:
            // Grammar: ID=19; read/write bits=2; START (ANY), END Element
            if (CanonicalizationMethodType->ANY_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ANY, base64Binary); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)CanonicalizationMethodType->ANY.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, CanonicalizationMethodType->ANY.bytesLen, CanonicalizationMethodType->ANY.bytes, iso20_ac_anyType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SignatureMethod; type={http://www.w3.org/2000/09/xmldsig#}SignatureMethodType; base type=; content type=mixed;
//          abstract=False; final=False;
// Particle: Algorithm, anyURI (1, 1); HMACOutputLength, HMACOutputLengthType (0, 1); ANY, anyType (0, 1);
static int encode_iso20_ac_SignatureMethodType(exi_bitstream_t* stream, struct iso20_ac_SignatureMethodType* SignatureMethodType) {
    int grammar_id = 20;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 20:
            // Grammar: ID=20; read/write bits=1; START (Algorithm)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (anyURI); next=21

                // string should not be found in table, so add 2
                error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(SignatureMethodType->Algorithm.charactersLen + 2));
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_characters(stream, SignatureMethodType->Algorithm.charactersLen, SignatureMethodType->Algorithm.characters, iso20_ac_Algorithm_CHARACTER_SIZE);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 21;
                    }
                }
            }
            break;
        case 21:
            // Grammar: ID=21; read/write bits=2; START (HMACOutputLength), START (ANY), END Element
            if (SignatureMethodType->HMACOutputLength_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (HMACOutputLength, integer); next=22
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_integer_32(stream, SignatureMethodType->HMACOutputLength);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 22;
                            }
                        }
                    }
                }
            }
            else if (SignatureMethodType->ANY_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ANY, base64Binary); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)SignatureMethodType->ANY.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, SignatureMethodType->ANY.bytesLen, SignatureMethodType->ANY.bytes, iso20_ac_anyType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 22:
            // Grammar: ID=22; read/write bits=2; START (ANY), END Element
            if (SignatureMethodType->ANY_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ANY, base64Binary); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)SignatureMethodType->ANY.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, SignatureMethodType->ANY.bytesLen, SignatureMethodType->ANY.bytes, iso20_ac_anyType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}KeyValue; type={http://www.w3.org/2000/09/xmldsig#}KeyValueType; base type=; content type=mixed;
//          abstract=False; final=False; choice=True;
// Particle: DSAKeyValue, DSAKeyValueType (0, 1); RSAKeyValue, RSAKeyValueType (0, 1); ANY, anyType (0, 1);
static int encode_iso20_ac_KeyValueType(exi_bitstream_t* stream, struct iso20_ac_KeyValueType* KeyValueType) {
    int grammar_id = 23;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 23:
            // Grammar: ID=23; read/write bits=2; START (DSAKeyValue), START (RSAKeyValue), START (ANY)
            if (KeyValueType->DSAKeyValue_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (DSAKeyValue, DSAKeyValueType); next=2
                    error = encode_iso20_ac_DSAKeyValueType(stream, &KeyValueType->DSAKeyValue);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (KeyValueType->RSAKeyValue_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RSAKeyValue, RSAKeyValueType); next=2
                    error = encode_iso20_ac_RSAKeyValueType(stream, &KeyValueType->RSAKeyValue);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ANY, base64Binary); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)KeyValueType->ANY.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, KeyValueType->ANY.bytesLen, KeyValueType->ANY.bytes, iso20_ac_anyType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Reference; type={http://www.w3.org/2000/09/xmldsig#}ReferenceType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); Type, anyURI (0, 1); URI, anyURI (0, 1); Transforms, TransformsType (0, 1); DigestMethod, DigestMethodType (1, 1); DigestValue, DigestValueType (1, 1);
static int encode_iso20_ac_ReferenceType(exi_bitstream_t* stream, struct iso20_ac_ReferenceType* ReferenceType) {
    int grammar_id = 24;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 24:
            // Grammar: ID=24; read/write bits=3; START (Id), START (Type), START (URI), START (Transforms), START (DigestMethod)
            if (ReferenceType->Id_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Id, NCName); next=25

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(ReferenceType->Id.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, ReferenceType->Id.charactersLen, ReferenceType->Id.characters, iso20_ac_Id_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 25;
                        }
                    }
                }
            }
            else if (ReferenceType->Type_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Type, anyURI); next=26

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(ReferenceType->Type.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, ReferenceType->Type.charactersLen, ReferenceType->Type.characters, iso20_ac_Type_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 26;
                        }
                    }
                }
            }
            else if (ReferenceType->URI_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (URI, anyURI); next=27

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(ReferenceType->URI.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, ReferenceType->URI.charactersLen, ReferenceType->URI.characters, iso20_ac_URI_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 27;
                        }
                    }
                }
            }
            else if (ReferenceType->Transforms_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Transforms, TransformsType); next=28
                    error = encode_iso20_ac_TransformsType(stream, &ReferenceType->Transforms);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 28;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (DigestMethod, DigestMethodType); next=29
                    error = encode_iso20_ac_DigestMethodType(stream, &ReferenceType->DigestMethod);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 29;
                    }
                }
            }
            break;
        case 25:
            // Grammar: ID=25; read/write bits=3; START (Type), START (URI), START (Transforms), START (DigestMethod)
            if (ReferenceType->Type_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Type, anyURI); next=26

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(ReferenceType->Type.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, ReferenceType->Type.charactersLen, ReferenceType->Type.characters, iso20_ac_Type_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 26;
                        }
                    }
                }
            }
            else if (ReferenceType->URI_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (URI, anyURI); next=27

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(ReferenceType->URI.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, ReferenceType->URI.charactersLen, ReferenceType->URI.characters, iso20_ac_URI_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 27;
                        }
                    }
                }
            }
            else if (ReferenceType->Transforms_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Transforms, TransformsType); next=28
                    error = encode_iso20_ac_TransformsType(stream, &ReferenceType->Transforms);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 28;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (DigestMethod, DigestMethodType); next=29
                    error = encode_iso20_ac_DigestMethodType(stream, &ReferenceType->DigestMethod);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 29;
                    }
                }
            }
            break;
        case 26:
            // Grammar: ID=26; read/write bits=2; START (URI), START (Transforms), START (DigestMethod)
            if (ReferenceType->URI_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (URI, anyURI); next=27

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(ReferenceType->URI.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, ReferenceType->URI.charactersLen, ReferenceType->URI.characters, iso20_ac_URI_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 27;
                        }
                    }
                }
            }
            else if (ReferenceType->Transforms_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Transforms, TransformsType); next=28
                    error = encode_iso20_ac_TransformsType(stream, &ReferenceType->Transforms);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 28;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (DigestMethod, DigestMethodType); next=29
                    error = encode_iso20_ac_DigestMethodType(stream, &ReferenceType->DigestMethod);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 29;
                    }
                }
            }
            break;
        case 27:
            // Grammar: ID=27; read/write bits=2; START (Transforms), START (DigestMethod)
            if (ReferenceType->Transforms_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Transforms, TransformsType); next=28
                    error = encode_iso20_ac_TransformsType(stream, &ReferenceType->Transforms);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 28;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (DigestMethod, DigestMethodType); next=29
                    error = encode_iso20_ac_DigestMethodType(stream, &ReferenceType->DigestMethod);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 29;
                    }
                }
            }
            break;
        case 28:
            // Grammar: ID=28; read/write bits=1; START (DigestMethod)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (DigestMethodType); next=29
                error = encode_iso20_ac_DigestMethodType(stream, &ReferenceType->DigestMethod);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 29;
                }
            }
            break;
        case 29:
            // Grammar: ID=29; read/write bits=1; START (DigestValue)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (base64Binary); next=2
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)ReferenceType->DigestValue.bytesLen);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bytes(stream, ReferenceType->DigestValue.bytesLen, ReferenceType->DigestValue.bytes, iso20_ac_DigestValueType_BYTES_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}RetrievalMethod; type={http://www.w3.org/2000/09/xmldsig#}RetrievalMethodType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Type, anyURI (0, 1); URI, anyURI (0, 1); Transforms, TransformsType (0, 1);
static int encode_iso20_ac_RetrievalMethodType(exi_bitstream_t* stream, struct iso20_ac_RetrievalMethodType* RetrievalMethodType) {
    int grammar_id = 30;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 30:
            // Grammar: ID=30; read/write bits=3; START (Type), START (URI), START (Transforms), END Element
            if (RetrievalMethodType->Type_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Type, anyURI); next=31

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(RetrievalMethodType->Type.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, RetrievalMethodType->Type.charactersLen, RetrievalMethodType->Type.characters, iso20_ac_Type_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 31;
                        }
                    }
                }
            }
            else if (RetrievalMethodType->URI_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (URI, anyURI); next=32

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(RetrievalMethodType->URI.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, RetrievalMethodType->URI.charactersLen, RetrievalMethodType->URI.characters, iso20_ac_URI_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 32;
                        }
                    }
                }
            }
            else if (RetrievalMethodType->Transforms_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Transforms, TransformsType); next=2
                    error = encode_iso20_ac_TransformsType(stream, &RetrievalMethodType->Transforms);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 31:
            // Grammar: ID=31; read/write bits=2; START (URI), START (Transforms), END Element
            if (RetrievalMethodType->URI_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (URI, anyURI); next=32

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(RetrievalMethodType->URI.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, RetrievalMethodType->URI.charactersLen, RetrievalMethodType->URI.characters, iso20_ac_URI_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 32;
                        }
                    }
                }
            }
            else if (RetrievalMethodType->Transforms_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Transforms, TransformsType); next=2
                    error = encode_iso20_ac_TransformsType(stream, &RetrievalMethodType->Transforms);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 32:
            // Grammar: ID=32; read/write bits=2; START (Transforms), END Element
            if (RetrievalMethodType->Transforms_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Transforms, TransformsType); next=2
                    error = encode_iso20_ac_TransformsType(stream, &RetrievalMethodType->Transforms);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}X509Data; type={http://www.w3.org/2000/09/xmldsig#}X509DataType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: X509IssuerSerial, X509IssuerSerialType (0, 1); X509SKI, base64Binary (0, 1); X509SubjectName, string (0, 1); X509Certificate, base64Binary (0, 1); X509CRL, base64Binary (0, 1); ANY, anyType (0, 1);
static int encode_iso20_ac_X509DataType(exi_bitstream_t* stream, struct iso20_ac_X509DataType* X509DataType) {
    int grammar_id = 33;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 33:
            // Grammar: ID=33; read/write bits=3; START (X509IssuerSerial), START (X509SKI), START (X509SubjectName), START (X509Certificate), START (X509CRL), START (ANY)
            if (X509DataType->X509IssuerSerial_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (X509IssuerSerial, X509IssuerSerialType); next=2
                    error = encode_iso20_ac_X509IssuerSerialType(stream, &X509DataType->X509IssuerSerial);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (X509DataType->X509SKI_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (X509SKI, base64Binary); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)X509DataType->X509SKI.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, X509DataType->X509SKI.bytesLen, X509DataType->X509SKI.bytes, iso20_ac_base64Binary_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            else if (X509DataType->X509SubjectName_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (X509SubjectName, string); next=2

                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // string should not be found in table, so add 2
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(X509DataType->X509SubjectName.charactersLen + 2));
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_characters(stream, X509DataType->X509SubjectName.charactersLen, X509DataType->X509SubjectName.characters, iso20_ac_X509SubjectName_CHARACTER_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            else if (X509DataType->X509Certificate_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (X509Certificate, base64Binary); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)X509DataType->X509Certificate.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, X509DataType->X509Certificate.bytesLen, X509DataType->X509Certificate.bytes, iso20_ac_base64Binary_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            else if (X509DataType->X509CRL_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (X509CRL, base64Binary); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)X509DataType->X509CRL.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, X509DataType->X509CRL.bytesLen, X509DataType->X509CRL.bytes, iso20_ac_base64Binary_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ANY, base64Binary); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)X509DataType->ANY.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, X509DataType->ANY.bytesLen, X509DataType->ANY.bytes, iso20_ac_anyType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}PGPData; type={http://www.w3.org/2000/09/xmldsig#}PGPDataType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False; choice=True; sequence=True (2;
// Particle: PGPKeyID, base64Binary (1, 1); PGPKeyPacket, base64Binary (0, 1); ANY, anyType (0, 1); PGPKeyPacket, base64Binary (1, 1); ANY, anyType (0, 1);
static int encode_iso20_ac_PGPDataType(exi_bitstream_t* stream, struct iso20_ac_PGPDataType* PGPDataType) {
    int grammar_id = 34;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 34:
            // Grammar: ID=34; read/write bits=1; START (PGPKeyID)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (base64Binary); next=35
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)PGPDataType->choice_1.PGPKeyID.bytesLen);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bytes(stream, PGPDataType->choice_1.PGPKeyID.bytesLen, PGPDataType->choice_1.PGPKeyID.bytes, iso20_ac_base64Binary_BYTES_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 35;
                            }
                        }
                    }
                }
            }
            break;
        case 35:
            // Grammar: ID=35; read/write bits=2; START (PGPKeyPacket), START (ANY), START (PGPKeyPacket)
            if (PGPDataType->choice_1.PGPKeyPacket_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (PGPKeyPacket, base64Binary); next=36
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)PGPDataType->choice_1.PGPKeyPacket.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, PGPDataType->choice_1.PGPKeyPacket.bytesLen, PGPDataType->choice_1.PGPKeyPacket.bytes, iso20_ac_base64Binary_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 36;
                                }
                            }
                        }
                    }
                }
            }
            else if (PGPDataType->choice_1.ANY_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ANY, base64Binary); next=37
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)PGPDataType->choice_1.ANY.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, PGPDataType->choice_1.ANY.bytesLen, PGPDataType->choice_1.ANY.bytes, iso20_ac_anyType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 37;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (PGPKeyPacket, base64Binary); next=38
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)PGPDataType->choice_2.PGPKeyPacket.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, PGPDataType->choice_2.PGPKeyPacket.bytesLen, PGPDataType->choice_2.PGPKeyPacket.bytes, iso20_ac_base64Binary_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 38;
                                }
                            }
                        }
                    }
                }
            }
            break;
        case 36:
            // Grammar: ID=36; read/write bits=2; START (ANY), START (PGPKeyPacket)
            if (PGPDataType->choice_1.ANY_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ANY, base64Binary); next=37
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)PGPDataType->choice_1.ANY.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, PGPDataType->choice_1.ANY.bytesLen, PGPDataType->choice_1.ANY.bytes, iso20_ac_anyType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 37;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (PGPKeyPacket, base64Binary); next=38
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)PGPDataType->choice_2.PGPKeyPacket.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, PGPDataType->choice_2.PGPKeyPacket.bytesLen, PGPDataType->choice_2.PGPKeyPacket.bytes, iso20_ac_base64Binary_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 38;
                                }
                            }
                        }
                    }
                }
            }
            break;
        case 37:
            // Grammar: ID=37; read/write bits=1; START (PGPKeyPacket)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (base64Binary); next=38
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)PGPDataType->choice_2.PGPKeyPacket.bytesLen);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bytes(stream, PGPDataType->choice_2.PGPKeyPacket.bytesLen, PGPDataType->choice_2.PGPKeyPacket.bytes, iso20_ac_base64Binary_BYTES_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 38;
                            }
                        }
                    }
                }
            }
            break;
        case 38:
            // Grammar: ID=38; read/write bits=2; START (ANY), END Element
            if (PGPDataType->choice_2.ANY_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ANY, base64Binary); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)PGPDataType->choice_2.ANY.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, PGPDataType->choice_2.ANY.bytesLen, PGPDataType->choice_2.ANY.bytes, iso20_ac_anyType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SPKIData; type={http://www.w3.org/2000/09/xmldsig#}SPKIDataType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: SPKISexp, base64Binary (1, 1); ANY, anyType (0, 1);
static int encode_iso20_ac_SPKIDataType(exi_bitstream_t* stream, struct iso20_ac_SPKIDataType* SPKIDataType) {
    int grammar_id = 39;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 39:
            // Grammar: ID=39; read/write bits=1; START (SPKISexp)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (base64Binary); next=40
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)SPKIDataType->SPKISexp.bytesLen);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bytes(stream, SPKIDataType->SPKISexp.bytesLen, SPKIDataType->SPKISexp.bytes, iso20_ac_base64Binary_BYTES_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 40;
                            }
                        }
                    }
                }
            }
            break;
        case 40:
            // Grammar: ID=40; read/write bits=2; START (ANY), END Element
            if (SPKIDataType->ANY_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ANY, base64Binary); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)SPKIDataType->ANY.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, SPKIDataType->ANY.bytesLen, SPKIDataType->ANY.bytes, iso20_ac_anyType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SignedInfo; type={http://www.w3.org/2000/09/xmldsig#}SignedInfoType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); CanonicalizationMethod, CanonicalizationMethodType (1, 1); SignatureMethod, SignatureMethodType (1, 1); Reference, ReferenceType (1, 1);
static int encode_iso20_ac_SignedInfoType(exi_bitstream_t* stream, struct iso20_ac_SignedInfoType* SignedInfoType) {
    int grammar_id = 41;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 41:
            // Grammar: ID=41; read/write bits=2; START (Id), START (CanonicalizationMethod)
            if (SignedInfoType->Id_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Id, NCName); next=42

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(SignedInfoType->Id.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, SignedInfoType->Id.charactersLen, SignedInfoType->Id.characters, iso20_ac_Id_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 42;
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (CanonicalizationMethod, CanonicalizationMethodType); next=43
                    error = encode_iso20_ac_CanonicalizationMethodType(stream, &SignedInfoType->CanonicalizationMethod);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 43;
                    }
                }
            }
            break;
        case 42:
            // Grammar: ID=42; read/write bits=1; START (CanonicalizationMethod)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (CanonicalizationMethodType); next=43
                error = encode_iso20_ac_CanonicalizationMethodType(stream, &SignedInfoType->CanonicalizationMethod);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 43;
                }
            }
            break;
        case 43:
            // Grammar: ID=43; read/write bits=1; START (SignatureMethod)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (SignatureMethodType); next=44
                error = encode_iso20_ac_SignatureMethodType(stream, &SignedInfoType->SignatureMethod);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 44;
                }
            }
            break;
        case 44:
            // Grammar: ID=44; read/write bits=1; START (Reference)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (ReferenceType); next=2
                error = encode_iso20_ac_ReferenceType(stream, &SignedInfoType->Reference);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 2;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SignatureValue; type={http://www.w3.org/2000/09/xmldsig#}SignatureValueType; base type=base64Binary; content type=simple;
//          abstract=False; final=False; derivation=extension;
// Particle: Id, ID (0, 1); CONTENT, SignatureValueType (1, 1);
static int encode_iso20_ac_SignatureValueType(exi_bitstream_t* stream, struct iso20_ac_SignatureValueType* SignatureValueType) {
    int grammar_id = 45;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 45:
            // Grammar: ID=45; read/write bits=2; START (Id), START (CONTENT)
            if (SignatureValueType->Id_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Id, NCName); next=46

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(SignatureValueType->Id.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, SignatureValueType->Id.charactersLen, SignatureValueType->Id.characters, iso20_ac_Id_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 46;
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (CONTENT, base64Binary); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)SignatureValueType->CONTENT.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, SignatureValueType->CONTENT.bytesLen, SignatureValueType->CONTENT.bytes, iso20_ac_SignatureValueType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            break;
        case 46:
            // Grammar: ID=46; read/write bits=1; START (CONTENT)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (base64Binary); next=2
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)SignatureValueType->CONTENT.bytesLen);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bytes(stream, SignatureValueType->CONTENT.bytesLen, SignatureValueType->CONTENT.bytes, iso20_ac_SignatureValueType_BYTES_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}KeyInfo; type={http://www.w3.org/2000/09/xmldsig#}KeyInfoType; base type=; content type=mixed;
//          abstract=False; final=False; choice=True;
// Particle: Id, ID (0, 1); KeyName, string (0, 1); KeyValue, KeyValueType (0, 1); RetrievalMethod, RetrievalMethodType (0, 1); X509Data, X509DataType (0, 1); PGPData, PGPDataType (0, 1); SPKIData, SPKIDataType (0, 1); MgmtData, string (0, 1); ANY, anyType (0, 1);
static int encode_iso20_ac_KeyInfoType(exi_bitstream_t* stream, struct iso20_ac_KeyInfoType* KeyInfoType) {
    int grammar_id = 47;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 47:
            // Grammar: ID=47; read/write bits=4; START (Id), START (KeyName), START (KeyValue), START (RetrievalMethod), START (X509Data), START (PGPData), START (SPKIData), START (MgmtData), START (ANY)
            if (KeyInfoType->Id_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Id, NCName); next=48

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(KeyInfoType->Id.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, KeyInfoType->Id.charactersLen, KeyInfoType->Id.characters, iso20_ac_Id_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 48;
                        }
                    }
                }
            }
            else if (KeyInfoType->KeyName_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (KeyName, string); next=2

                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // string should not be found in table, so add 2
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(KeyInfoType->KeyName.charactersLen + 2));
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_characters(stream, KeyInfoType->KeyName.charactersLen, KeyInfoType->KeyName.characters, iso20_ac_KeyName_CHARACTER_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            else if (KeyInfoType->KeyValue_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (KeyValue, KeyValueType); next=2
                    error = encode_iso20_ac_KeyValueType(stream, &KeyInfoType->KeyValue);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (KeyInfoType->RetrievalMethod_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RetrievalMethod, RetrievalMethodType); next=2
                    error = encode_iso20_ac_RetrievalMethodType(stream, &KeyInfoType->RetrievalMethod);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (KeyInfoType->X509Data_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (X509Data, X509DataType); next=2
                    error = encode_iso20_ac_X509DataType(stream, &KeyInfoType->X509Data);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (KeyInfoType->PGPData_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (PGPData, PGPDataType); next=2
                    error = encode_iso20_ac_PGPDataType(stream, &KeyInfoType->PGPData);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (KeyInfoType->SPKIData_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (SPKIData, SPKIDataType); next=2
                    error = encode_iso20_ac_SPKIDataType(stream, &KeyInfoType->SPKIData);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (KeyInfoType->MgmtData_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MgmtData, string); next=2

                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // string should not be found in table, so add 2
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(KeyInfoType->MgmtData.charactersLen + 2));
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_characters(stream, KeyInfoType->MgmtData.charactersLen, KeyInfoType->MgmtData.characters, iso20_ac_MgmtData_CHARACTER_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 8);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ANY, base64Binary); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)KeyInfoType->ANY.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, KeyInfoType->ANY.bytesLen, KeyInfoType->ANY.bytes, iso20_ac_anyType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            break;
        case 48:
            // Grammar: ID=48; read/write bits=4; START (KeyName), START (KeyValue), START (RetrievalMethod), START (X509Data), START (PGPData), START (SPKIData), START (MgmtData), START (ANY)
            if (KeyInfoType->KeyName_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (KeyName, string); next=2

                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // string should not be found in table, so add 2
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(KeyInfoType->KeyName.charactersLen + 2));
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_characters(stream, KeyInfoType->KeyName.charactersLen, KeyInfoType->KeyName.characters, iso20_ac_KeyName_CHARACTER_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            else if (KeyInfoType->KeyValue_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (KeyValue, KeyValueType); next=2
                    error = encode_iso20_ac_KeyValueType(stream, &KeyInfoType->KeyValue);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (KeyInfoType->RetrievalMethod_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RetrievalMethod, RetrievalMethodType); next=2
                    error = encode_iso20_ac_RetrievalMethodType(stream, &KeyInfoType->RetrievalMethod);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (KeyInfoType->X509Data_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (X509Data, X509DataType); next=2
                    error = encode_iso20_ac_X509DataType(stream, &KeyInfoType->X509Data);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (KeyInfoType->PGPData_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (PGPData, PGPDataType); next=2
                    error = encode_iso20_ac_PGPDataType(stream, &KeyInfoType->PGPData);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (KeyInfoType->SPKIData_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (SPKIData, SPKIDataType); next=2
                    error = encode_iso20_ac_SPKIDataType(stream, &KeyInfoType->SPKIData);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (KeyInfoType->MgmtData_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MgmtData, string); next=2

                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // string should not be found in table, so add 2
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(KeyInfoType->MgmtData.charactersLen + 2));
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_characters(stream, KeyInfoType->MgmtData.charactersLen, KeyInfoType->MgmtData.characters, iso20_ac_MgmtData_CHARACTER_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ANY, base64Binary); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)KeyInfoType->ANY.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, KeyInfoType->ANY.bytesLen, KeyInfoType->ANY.bytes, iso20_ac_anyType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Object; type={http://www.w3.org/2000/09/xmldsig#}ObjectType; base type=; content type=mixed;
//          abstract=False; final=False;
// Particle: Encoding, anyURI (0, 1); Id, ID (0, 1); MimeType, string (0, 1); ANY, anyType (1, 1);
static int encode_iso20_ac_ObjectType(exi_bitstream_t* stream, struct iso20_ac_ObjectType* ObjectType) {
    int grammar_id = 49;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 49:
            // Grammar: ID=49; read/write bits=3; START (Encoding), START (Id), START (MimeType), START (ANY)
            if (ObjectType->Encoding_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Encoding, anyURI); next=50

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(ObjectType->Encoding.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, ObjectType->Encoding.charactersLen, ObjectType->Encoding.characters, iso20_ac_Encoding_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 50;
                        }
                    }
                }
            }
            else if (ObjectType->Id_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Id, NCName); next=51

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(ObjectType->Id.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, ObjectType->Id.charactersLen, ObjectType->Id.characters, iso20_ac_Id_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 51;
                        }
                    }
                }
            }
            else if (ObjectType->MimeType_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MimeType, string); next=52

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(ObjectType->MimeType.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, ObjectType->MimeType.charactersLen, ObjectType->MimeType.characters, iso20_ac_MimeType_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 52;
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ANY, base64Binary); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)ObjectType->ANY.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, ObjectType->ANY.bytesLen, ObjectType->ANY.bytes, iso20_ac_anyType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            break;
        case 50:
            // Grammar: ID=50; read/write bits=2; START (Id), START (MimeType), START (ANY)
            if (ObjectType->Id_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Id, NCName); next=51

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(ObjectType->Id.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, ObjectType->Id.charactersLen, ObjectType->Id.characters, iso20_ac_Id_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 51;
                        }
                    }
                }
            }
            else if (ObjectType->MimeType_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MimeType, string); next=52

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(ObjectType->MimeType.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, ObjectType->MimeType.charactersLen, ObjectType->MimeType.characters, iso20_ac_MimeType_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 52;
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ANY, base64Binary); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)ObjectType->ANY.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, ObjectType->ANY.bytesLen, ObjectType->ANY.bytes, iso20_ac_anyType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            break;
        case 51:
            // Grammar: ID=51; read/write bits=2; START (MimeType), START (ANY)
            if (ObjectType->MimeType_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MimeType, string); next=52

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(ObjectType->MimeType.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, ObjectType->MimeType.charactersLen, ObjectType->MimeType.characters, iso20_ac_MimeType_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 52;
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ANY, base64Binary); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)ObjectType->ANY.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, ObjectType->ANY.bytesLen, ObjectType->ANY.bytes, iso20_ac_anyType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 2;
                                }
                            }
                        }
                    }
                }
            }
            break;
        case 52:
            // Grammar: ID=52; read/write bits=1; START (ANY)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (base64Binary); next=2
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)ObjectType->ANY.bytesLen);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bytes(stream, ObjectType->ANY.bytesLen, ObjectType->ANY.bytes, iso20_ac_anyType_BYTES_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}EVMaximumChargePower; type={urn:iso:std:iso:15118:-20:CommonTypes}RationalNumberType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Exponent, byte (1, 1); Value, short (1, 1);
static int encode_iso20_ac_RationalNumberType(exi_bitstream_t* stream, struct iso20_ac_RationalNumberType* RationalNumberType) {
    int grammar_id = 53;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 53:
            // Grammar: ID=53; read/write bits=1; START (Exponent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (short); next=54
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // type has min_value = -128
                    error = exi_basetypes_encoder_nbit_uint(stream, 8, RationalNumberType->Exponent + -128);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 54;
                        }
                    }
                }
            }
            break;
        case 54:
            // Grammar: ID=54; read/write bits=1; START (Value)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (int); next=2
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_integer_16(stream, RationalNumberType->Value);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 2;
                        }
                    }
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}EnergyCosts; type={urn:iso:std:iso:15118:-20:CommonTypes}DetailedCostType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Amount, RationalNumberType (1, 1); CostPerUnit, RationalNumberType (1, 1);
static int encode_iso20_ac_DetailedCostType(exi_bitstream_t* stream, struct iso20_ac_DetailedCostType* DetailedCostType) {
    int grammar_id = 55;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 55:
            // Grammar: ID=55; read/write bits=1; START (Amount)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=56
                error = encode_iso20_ac_RationalNumberType(stream, &DetailedCostType->Amount);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 56;
                }
            }
            break;
        case 56:
            // Grammar: ID=56; read/write bits=1; START (CostPerUnit)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=2
                error = encode_iso20_ac_RationalNumberType(stream, &DetailedCostType->CostPerUnit);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 2;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Signature; type={http://www.w3.org/2000/09/xmldsig#}SignatureType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); SignedInfo, SignedInfoType (1, 1); SignatureValue, SignatureValueType (1, 1); KeyInfo, KeyInfoType (0, 1); Object, ObjectType (0, 1);
static int encode_iso20_ac_SignatureType(exi_bitstream_t* stream, struct iso20_ac_SignatureType* SignatureType) {
    int grammar_id = 57;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 57:
            // Grammar: ID=57; read/write bits=2; START (Id), START (SignedInfo)
            if (SignatureType->Id_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Id, NCName); next=58

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(SignatureType->Id.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, SignatureType->Id.charactersLen, SignatureType->Id.characters, iso20_ac_Id_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 58;
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (SignedInfo, SignedInfoType); next=59
                    error = encode_iso20_ac_SignedInfoType(stream, &SignatureType->SignedInfo);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 59;
                    }
                }
            }
            break;
        case 58:
            // Grammar: ID=58; read/write bits=1; START (SignedInfo)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (SignedInfoType); next=59
                error = encode_iso20_ac_SignedInfoType(stream, &SignatureType->SignedInfo);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 59;
                }
            }
            break;
        case 59:
            // Grammar: ID=59; read/write bits=1; START (SignatureValue)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (base64Binary); next=60
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)SignatureType->SignatureValue.CONTENT.bytesLen);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bytes(stream, SignatureType->SignatureValue.CONTENT.bytesLen, SignatureType->SignatureValue.CONTENT.bytes, iso20_ac_SignatureValueType_BYTES_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 60;
                            }
                        }
                    }
                }
            }
            break;
        case 60:
            // Grammar: ID=60; read/write bits=2; START (KeyInfo), START (Object), END Element
            if (SignatureType->KeyInfo_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (KeyInfo, KeyInfoType); next=61
                    error = encode_iso20_ac_KeyInfoType(stream, &SignatureType->KeyInfo);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 61;
                    }
                }
            }
            else if (SignatureType->Object_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Object, ObjectType); next=2
                    error = encode_iso20_ac_ObjectType(stream, &SignatureType->Object);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 61:
            // Grammar: ID=61; read/write bits=2; START (Object), END Element
            if (SignatureType->Object_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Object, ObjectType); next=2
                    error = encode_iso20_ac_ObjectType(stream, &SignatureType->Object);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}TaxCosts; type={urn:iso:std:iso:15118:-20:CommonTypes}DetailedTaxType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: TaxRuleID, numericIDType (1, 1); Amount, RationalNumberType (1, 1);
static int encode_iso20_ac_DetailedTaxType(exi_bitstream_t* stream, struct iso20_ac_DetailedTaxType* DetailedTaxType) {
    int grammar_id = 62;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 62:
            // Grammar: ID=62; read/write bits=1; START (TaxRuleID)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (unsignedInt); next=63
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_uint_32(stream, DetailedTaxType->TaxRuleID);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 63;
                        }
                    }
                }
            }
            break;
        case 63:
            // Grammar: ID=63; read/write bits=1; START (Amount)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=2
                error = encode_iso20_ac_RationalNumberType(stream, &DetailedTaxType->Amount);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 2;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}Header; type={urn:iso:std:iso:15118:-20:CommonTypes}MessageHeaderType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: SessionID, sessionIDType (1, 1); TimeStamp, unsignedLong (1, 1); Signature, SignatureType (0, 1);
static int encode_iso20_ac_MessageHeaderType(exi_bitstream_t* stream, struct iso20_ac_MessageHeaderType* MessageHeaderType) {
    int grammar_id = 64;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 64:
            // Grammar: ID=64; read/write bits=1; START (SessionID)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (hexBinary); next=65
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)MessageHeaderType->SessionID.bytesLen);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bytes(stream, MessageHeaderType->SessionID.bytesLen, MessageHeaderType->SessionID.bytes, iso20_ac_sessionIDType_BYTES_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 65;
                            }
                        }
                    }
                }
            }
            break;
        case 65:
            // Grammar: ID=65; read/write bits=1; START (TimeStamp)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (nonNegativeInteger); next=66
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_uint_64(stream, MessageHeaderType->TimeStamp);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 66;
                        }
                    }
                }
            }
            break;
        case 66:
            // Grammar: ID=66; read/write bits=2; START (Signature), END Element
            if (MessageHeaderType->Signature_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Signature, SignatureType); next=2
                    error = encode_iso20_ac_SignatureType(stream, &MessageHeaderType->Signature);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SignatureProperty; type={http://www.w3.org/2000/09/xmldsig#}SignaturePropertyType; base type=; content type=mixed;
//          abstract=False; final=False; choice=True;
// Particle: Id, ID (0, 1); Target, anyURI (1, 1); ANY, anyType (0, 1);
static int encode_iso20_ac_SignaturePropertyType(exi_bitstream_t* stream, struct iso20_ac_SignaturePropertyType* SignaturePropertyType) {
    int grammar_id = 67;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 67:
            // Grammar: ID=67; read/write bits=2; START (Id), START (Target)
            if (SignaturePropertyType->Id_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Id, NCName); next=68

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(SignaturePropertyType->Id.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, SignaturePropertyType->Id.charactersLen, SignaturePropertyType->Id.characters, iso20_ac_Id_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 68;
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Target, anyURI); next=69

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(SignaturePropertyType->Target.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, SignaturePropertyType->Target.charactersLen, SignaturePropertyType->Target.characters, iso20_ac_Target_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 69;
                        }
                    }
                }
            }
            break;
        case 68:
            // Grammar: ID=68; read/write bits=1; START (Target)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (anyURI); next=69

                // string should not be found in table, so add 2
                error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(SignaturePropertyType->Target.charactersLen + 2));
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_characters(stream, SignaturePropertyType->Target.charactersLen, SignaturePropertyType->Target.characters, iso20_ac_Target_CHARACTER_SIZE);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 69;
                    }
                }
            }
            break;
        case 69:
            // Grammar: ID=69; read/write bits=1; START (ANY)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (base64Binary); next=2
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)SignaturePropertyType->ANY.bytesLen);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bytes(stream, SignaturePropertyType->ANY.bytesLen, SignaturePropertyType->ANY.bytes, iso20_ac_anyType_BYTES_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}AC_CPDReqEnergyTransferMode; type={urn:iso:std:iso:15118:-20:AC}AC_CPDReqEnergyTransferModeType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EVMaximumChargePower, RationalNumberType (1, 1); EVMaximumChargePower_L2, RationalNumberType (0, 1); EVMaximumChargePower_L3, RationalNumberType (0, 1); EVMinimumChargePower, RationalNumberType (1, 1); EVMinimumChargePower_L2, RationalNumberType (0, 1); EVMinimumChargePower_L3, RationalNumberType (0, 1);
static int encode_iso20_ac_AC_CPDReqEnergyTransferModeType(exi_bitstream_t* stream, struct iso20_ac_AC_CPDReqEnergyTransferModeType* AC_CPDReqEnergyTransferModeType) {
    int grammar_id = 70;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 70:
            // Grammar: ID=70; read/write bits=1; START (EVMaximumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=71
                error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDReqEnergyTransferModeType->EVMaximumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 71;
                }
            }
            break;
        case 71:
            // Grammar: ID=71; read/write bits=2; START (EVMaximumChargePower_L2), START (EVMaximumChargePower_L3), START (EVMinimumChargePower)
            if (AC_CPDReqEnergyTransferModeType->EVMaximumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L2, RationalNumberType); next=72
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDReqEnergyTransferModeType->EVMaximumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 72;
                    }
                }
            }
            else if (AC_CPDReqEnergyTransferModeType->EVMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L3, RationalNumberType); next=73
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDReqEnergyTransferModeType->EVMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 73;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=74
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDReqEnergyTransferModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 74;
                    }
                }
            }
            break;
        case 72:
            // Grammar: ID=72; read/write bits=2; START (EVMaximumChargePower_L3), START (EVMinimumChargePower)
            if (AC_CPDReqEnergyTransferModeType->EVMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L3, RationalNumberType); next=73
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDReqEnergyTransferModeType->EVMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 73;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=74
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDReqEnergyTransferModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 74;
                    }
                }
            }
            break;
        case 73:
            // Grammar: ID=73; read/write bits=1; START (EVMinimumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=74
                error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDReqEnergyTransferModeType->EVMinimumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 74;
                }
            }
            break;
        case 74:
            // Grammar: ID=74; read/write bits=2; START (EVMinimumChargePower_L2), START (EVMinimumChargePower_L3), END Element
            if (AC_CPDReqEnergyTransferModeType->EVMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L2, RationalNumberType); next=75
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDReqEnergyTransferModeType->EVMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 75;
                    }
                }
            }
            else if (AC_CPDReqEnergyTransferModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDReqEnergyTransferModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 75:
            // Grammar: ID=75; read/write bits=2; START (EVMinimumChargePower_L3), END Element
            if (AC_CPDReqEnergyTransferModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDReqEnergyTransferModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}DisplayParameters; type={urn:iso:std:iso:15118:-20:CommonTypes}DisplayParametersType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: PresentSOC, percentValueType (0, 1); MinimumSOC, percentValueType (0, 1); TargetSOC, percentValueType (0, 1); MaximumSOC, percentValueType (0, 1); RemainingTimeToMinimumSOC, unsignedInt (0, 1); RemainingTimeToTargetSOC, unsignedInt (0, 1); RemainingTimeToMaximumSOC, unsignedInt (0, 1); ChargingComplete, boolean (0, 1); BatteryEnergyCapacity, RationalNumberType (0, 1); InletHot, boolean (0, 1);
static int encode_iso20_ac_DisplayParametersType(exi_bitstream_t* stream, struct iso20_ac_DisplayParametersType* DisplayParametersType) {
    int grammar_id = 76;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 76:
            // Grammar: ID=76; read/write bits=4; START (PresentSOC), START (MinimumSOC), START (TargetSOC), START (MaximumSOC), START (RemainingTimeToMinimumSOC), START (RemainingTimeToTargetSOC), START (RemainingTimeToMaximumSOC), START (ChargingComplete), START (BatteryEnergyCapacity), START (InletHot), END Element
            if (DisplayParametersType->PresentSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (PresentSOC, byte); next=77
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)DisplayParametersType->PresentSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 77;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->MinimumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MinimumSOC, byte); next=78
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)DisplayParametersType->MinimumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 78;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->TargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (TargetSOC, byte); next=79
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)DisplayParametersType->TargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 79;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->MaximumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MaximumSOC, byte); next=80
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)DisplayParametersType->MaximumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 80;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->RemainingTimeToMinimumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToMinimumSOC, unsignedLong); next=81
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, DisplayParametersType->RemainingTimeToMinimumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 81;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->RemainingTimeToTargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToTargetSOC, unsignedLong); next=82
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, DisplayParametersType->RemainingTimeToTargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 82;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->RemainingTimeToMaximumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToMaximumSOC, unsignedLong); next=83
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, DisplayParametersType->RemainingTimeToMaximumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 83;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->ChargingComplete_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ChargingComplete, boolean); next=84
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bool(stream, DisplayParametersType->ChargingComplete);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 84;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->BatteryEnergyCapacity_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 8);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BatteryEnergyCapacity, RationalNumberType); next=85
                    error = encode_iso20_ac_RationalNumberType(stream, &DisplayParametersType->BatteryEnergyCapacity);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 85;
                    }
                }
            }
            else if (DisplayParametersType->InletHot_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 9);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (InletHot, boolean); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bool(stream, DisplayParametersType->InletHot);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 10);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 77:
            // Grammar: ID=77; read/write bits=4; START (MinimumSOC), START (TargetSOC), START (MaximumSOC), START (RemainingTimeToMinimumSOC), START (RemainingTimeToTargetSOC), START (RemainingTimeToMaximumSOC), START (ChargingComplete), START (BatteryEnergyCapacity), START (InletHot), END Element
            if (DisplayParametersType->MinimumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MinimumSOC, byte); next=78
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)DisplayParametersType->MinimumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 78;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->TargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (TargetSOC, byte); next=79
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)DisplayParametersType->TargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 79;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->MaximumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MaximumSOC, byte); next=80
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)DisplayParametersType->MaximumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 80;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->RemainingTimeToMinimumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToMinimumSOC, unsignedLong); next=81
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, DisplayParametersType->RemainingTimeToMinimumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 81;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->RemainingTimeToTargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToTargetSOC, unsignedLong); next=82
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, DisplayParametersType->RemainingTimeToTargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 82;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->RemainingTimeToMaximumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToMaximumSOC, unsignedLong); next=83
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, DisplayParametersType->RemainingTimeToMaximumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 83;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->ChargingComplete_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ChargingComplete, boolean); next=84
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bool(stream, DisplayParametersType->ChargingComplete);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 84;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->BatteryEnergyCapacity_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BatteryEnergyCapacity, RationalNumberType); next=85
                    error = encode_iso20_ac_RationalNumberType(stream, &DisplayParametersType->BatteryEnergyCapacity);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 85;
                    }
                }
            }
            else if (DisplayParametersType->InletHot_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 8);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (InletHot, boolean); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bool(stream, DisplayParametersType->InletHot);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 9);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 78:
            // Grammar: ID=78; read/write bits=4; START (TargetSOC), START (MaximumSOC), START (RemainingTimeToMinimumSOC), START (RemainingTimeToTargetSOC), START (RemainingTimeToMaximumSOC), START (ChargingComplete), START (BatteryEnergyCapacity), START (InletHot), END Element
            if (DisplayParametersType->TargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (TargetSOC, byte); next=79
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)DisplayParametersType->TargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 79;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->MaximumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MaximumSOC, byte); next=80
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)DisplayParametersType->MaximumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 80;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->RemainingTimeToMinimumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToMinimumSOC, unsignedLong); next=81
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, DisplayParametersType->RemainingTimeToMinimumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 81;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->RemainingTimeToTargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToTargetSOC, unsignedLong); next=82
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, DisplayParametersType->RemainingTimeToTargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 82;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->RemainingTimeToMaximumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToMaximumSOC, unsignedLong); next=83
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, DisplayParametersType->RemainingTimeToMaximumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 83;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->ChargingComplete_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ChargingComplete, boolean); next=84
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bool(stream, DisplayParametersType->ChargingComplete);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 84;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->BatteryEnergyCapacity_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BatteryEnergyCapacity, RationalNumberType); next=85
                    error = encode_iso20_ac_RationalNumberType(stream, &DisplayParametersType->BatteryEnergyCapacity);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 85;
                    }
                }
            }
            else if (DisplayParametersType->InletHot_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (InletHot, boolean); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bool(stream, DisplayParametersType->InletHot);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 8);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 79:
            // Grammar: ID=79; read/write bits=4; START (MaximumSOC), START (RemainingTimeToMinimumSOC), START (RemainingTimeToTargetSOC), START (RemainingTimeToMaximumSOC), START (ChargingComplete), START (BatteryEnergyCapacity), START (InletHot), END Element
            if (DisplayParametersType->MaximumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MaximumSOC, byte); next=80
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)DisplayParametersType->MaximumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 80;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->RemainingTimeToMinimumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToMinimumSOC, unsignedLong); next=81
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, DisplayParametersType->RemainingTimeToMinimumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 81;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->RemainingTimeToTargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToTargetSOC, unsignedLong); next=82
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, DisplayParametersType->RemainingTimeToTargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 82;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->RemainingTimeToMaximumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToMaximumSOC, unsignedLong); next=83
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, DisplayParametersType->RemainingTimeToMaximumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 83;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->ChargingComplete_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ChargingComplete, boolean); next=84
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bool(stream, DisplayParametersType->ChargingComplete);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 84;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->BatteryEnergyCapacity_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BatteryEnergyCapacity, RationalNumberType); next=85
                    error = encode_iso20_ac_RationalNumberType(stream, &DisplayParametersType->BatteryEnergyCapacity);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 85;
                    }
                }
            }
            else if (DisplayParametersType->InletHot_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (InletHot, boolean); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bool(stream, DisplayParametersType->InletHot);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 80:
            // Grammar: ID=80; read/write bits=3; START (RemainingTimeToMinimumSOC), START (RemainingTimeToTargetSOC), START (RemainingTimeToMaximumSOC), START (ChargingComplete), START (BatteryEnergyCapacity), START (InletHot), END Element
            if (DisplayParametersType->RemainingTimeToMinimumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToMinimumSOC, unsignedLong); next=81
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, DisplayParametersType->RemainingTimeToMinimumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 81;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->RemainingTimeToTargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToTargetSOC, unsignedLong); next=82
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, DisplayParametersType->RemainingTimeToTargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 82;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->RemainingTimeToMaximumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToMaximumSOC, unsignedLong); next=83
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, DisplayParametersType->RemainingTimeToMaximumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 83;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->ChargingComplete_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ChargingComplete, boolean); next=84
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bool(stream, DisplayParametersType->ChargingComplete);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 84;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->BatteryEnergyCapacity_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BatteryEnergyCapacity, RationalNumberType); next=85
                    error = encode_iso20_ac_RationalNumberType(stream, &DisplayParametersType->BatteryEnergyCapacity);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 85;
                    }
                }
            }
            else if (DisplayParametersType->InletHot_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (InletHot, boolean); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bool(stream, DisplayParametersType->InletHot);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 81:
            // Grammar: ID=81; read/write bits=3; START (RemainingTimeToTargetSOC), START (RemainingTimeToMaximumSOC), START (ChargingComplete), START (BatteryEnergyCapacity), START (InletHot), END Element
            if (DisplayParametersType->RemainingTimeToTargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToTargetSOC, unsignedLong); next=82
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, DisplayParametersType->RemainingTimeToTargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 82;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->RemainingTimeToMaximumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToMaximumSOC, unsignedLong); next=83
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, DisplayParametersType->RemainingTimeToMaximumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 83;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->ChargingComplete_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ChargingComplete, boolean); next=84
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bool(stream, DisplayParametersType->ChargingComplete);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 84;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->BatteryEnergyCapacity_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BatteryEnergyCapacity, RationalNumberType); next=85
                    error = encode_iso20_ac_RationalNumberType(stream, &DisplayParametersType->BatteryEnergyCapacity);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 85;
                    }
                }
            }
            else if (DisplayParametersType->InletHot_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (InletHot, boolean); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bool(stream, DisplayParametersType->InletHot);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 82:
            // Grammar: ID=82; read/write bits=3; START (RemainingTimeToMaximumSOC), START (ChargingComplete), START (BatteryEnergyCapacity), START (InletHot), END Element
            if (DisplayParametersType->RemainingTimeToMaximumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToMaximumSOC, unsignedLong); next=83
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, DisplayParametersType->RemainingTimeToMaximumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 83;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->ChargingComplete_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ChargingComplete, boolean); next=84
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bool(stream, DisplayParametersType->ChargingComplete);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 84;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->BatteryEnergyCapacity_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BatteryEnergyCapacity, RationalNumberType); next=85
                    error = encode_iso20_ac_RationalNumberType(stream, &DisplayParametersType->BatteryEnergyCapacity);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 85;
                    }
                }
            }
            else if (DisplayParametersType->InletHot_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (InletHot, boolean); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bool(stream, DisplayParametersType->InletHot);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 83:
            // Grammar: ID=83; read/write bits=3; START (ChargingComplete), START (BatteryEnergyCapacity), START (InletHot), END Element
            if (DisplayParametersType->ChargingComplete_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ChargingComplete, boolean); next=84
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bool(stream, DisplayParametersType->ChargingComplete);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 84;
                            }
                        }
                    }
                }
            }
            else if (DisplayParametersType->BatteryEnergyCapacity_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BatteryEnergyCapacity, RationalNumberType); next=85
                    error = encode_iso20_ac_RationalNumberType(stream, &DisplayParametersType->BatteryEnergyCapacity);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 85;
                    }
                }
            }
            else if (DisplayParametersType->InletHot_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (InletHot, boolean); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bool(stream, DisplayParametersType->InletHot);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 84:
            // Grammar: ID=84; read/write bits=2; START (BatteryEnergyCapacity), START (InletHot), END Element
            if (DisplayParametersType->BatteryEnergyCapacity_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BatteryEnergyCapacity, RationalNumberType); next=85
                    error = encode_iso20_ac_RationalNumberType(stream, &DisplayParametersType->BatteryEnergyCapacity);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 85;
                    }
                }
            }
            else if (DisplayParametersType->InletHot_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (InletHot, boolean); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bool(stream, DisplayParametersType->InletHot);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 85:
            // Grammar: ID=85; read/write bits=2; START (InletHot), END Element
            if (DisplayParametersType->InletHot_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (InletHot, boolean); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bool(stream, DisplayParametersType->InletHot);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}AC_CPDResEnergyTransferMode; type={urn:iso:std:iso:15118:-20:AC}AC_CPDResEnergyTransferModeType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EVSEMaximumChargePower, RationalNumberType (1, 1); EVSEMaximumChargePower_L2, RationalNumberType (0, 1); EVSEMaximumChargePower_L3, RationalNumberType (0, 1); EVSEMinimumChargePower, RationalNumberType (1, 1); EVSEMinimumChargePower_L2, RationalNumberType (0, 1); EVSEMinimumChargePower_L3, RationalNumberType (0, 1); EVSENominalFrequency, RationalNumberType (1, 1); MaximumPowerAsymmetry, RationalNumberType (0, 1); EVSEPowerRampLimitation, RationalNumberType (0, 1); EVSEPresentActivePower, RationalNumberType (0, 1); EVSEPresentActivePower_L2, RationalNumberType (0, 1); EVSEPresentActivePower_L3, RationalNumberType (0, 1);
static int encode_iso20_ac_AC_CPDResEnergyTransferModeType(exi_bitstream_t* stream, struct iso20_ac_AC_CPDResEnergyTransferModeType* AC_CPDResEnergyTransferModeType) {
    int grammar_id = 86;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 86:
            // Grammar: ID=86; read/write bits=1; START (EVSEMaximumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=87
                error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEMaximumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 87;
                }
            }
            break;
        case 87:
            // Grammar: ID=87; read/write bits=2; START (EVSEMaximumChargePower_L2), START (EVSEMaximumChargePower_L3), START (EVSEMinimumChargePower)
            if (AC_CPDResEnergyTransferModeType->EVSEMaximumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumChargePower_L2, RationalNumberType); next=88
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEMaximumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 88;
                    }
                }
            }
            else if (AC_CPDResEnergyTransferModeType->EVSEMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumChargePower_L3, RationalNumberType); next=89
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 89;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumChargePower, RationalNumberType); next=90
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 90;
                    }
                }
            }
            break;
        case 88:
            // Grammar: ID=88; read/write bits=2; START (EVSEMaximumChargePower_L3), START (EVSEMinimumChargePower)
            if (AC_CPDResEnergyTransferModeType->EVSEMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumChargePower_L3, RationalNumberType); next=89
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 89;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumChargePower, RationalNumberType); next=90
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 90;
                    }
                }
            }
            break;
        case 89:
            // Grammar: ID=89; read/write bits=1; START (EVSEMinimumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=90
                error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 90;
                }
            }
            break;
        case 90:
            // Grammar: ID=90; read/write bits=2; START (EVSEMinimumChargePower_L2), START (EVSEMinimumChargePower_L3), START (EVSENominalFrequency)
            if (AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumChargePower_L2, RationalNumberType); next=91
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 91;
                    }
                }
            }
            else if (AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumChargePower_L3, RationalNumberType); next=92
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 92;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSENominalFrequency, RationalNumberType); next=93
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSENominalFrequency);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 93;
                    }
                }
            }
            break;
        case 91:
            // Grammar: ID=91; read/write bits=2; START (EVSEMinimumChargePower_L3), START (EVSENominalFrequency)
            if (AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumChargePower_L3, RationalNumberType); next=92
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 92;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSENominalFrequency, RationalNumberType); next=93
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSENominalFrequency);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 93;
                    }
                }
            }
            break;
        case 92:
            // Grammar: ID=92; read/write bits=1; START (EVSENominalFrequency)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=93
                error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSENominalFrequency);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 93;
                }
            }
            break;
        case 93:
            // Grammar: ID=93; read/write bits=3; START (MaximumPowerAsymmetry), START (EVSEPowerRampLimitation), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (AC_CPDResEnergyTransferModeType->MaximumPowerAsymmetry_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MaximumPowerAsymmetry, RationalNumberType); next=94
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->MaximumPowerAsymmetry);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 94;
                    }
                }
            }
            else if (AC_CPDResEnergyTransferModeType->EVSEPowerRampLimitation_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPowerRampLimitation, RationalNumberType); next=95
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEPowerRampLimitation);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 95;
                    }
                }
            }
            else if (AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=96
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 96;
                    }
                }
            }
            else if (AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=97
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 97;
                    }
                }
            }
            else if (AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 94:
            // Grammar: ID=94; read/write bits=3; START (EVSEPowerRampLimitation), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (AC_CPDResEnergyTransferModeType->EVSEPowerRampLimitation_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPowerRampLimitation, RationalNumberType); next=95
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEPowerRampLimitation);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 95;
                    }
                }
            }
            else if (AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=96
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 96;
                    }
                }
            }
            else if (AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=97
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 97;
                    }
                }
            }
            else if (AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 95:
            // Grammar: ID=95; read/write bits=3; START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=96
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 96;
                    }
                }
            }
            else if (AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=97
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 97;
                    }
                }
            }
            else if (AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 96:
            // Grammar: ID=96; read/write bits=2; START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=97
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 97;
                    }
                }
            }
            else if (AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 97:
            // Grammar: ID=97; read/write bits=2; START (EVSEPresentActivePower_L3), END Element
            if (AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}EVSEStatus; type={urn:iso:std:iso:15118:-20:CommonTypes}EVSEStatusType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: NotificationMaxDelay, unsignedShort (1, 1); EVSENotification, evseNotificationType (1, 1);
static int encode_iso20_ac_EVSEStatusType(exi_bitstream_t* stream, struct iso20_ac_EVSEStatusType* EVSEStatusType) {
    int grammar_id = 98;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 98:
            // Grammar: ID=98; read/write bits=1; START (NotificationMaxDelay)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (unsignedInt); next=99
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_uint_16(stream, EVSEStatusType->NotificationMaxDelay);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 99;
                        }
                    }
                }
            }
            break;
        case 99:
            // Grammar: ID=99; read/write bits=1; START (EVSENotification)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (string); next=2
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_nbit_uint(stream, 3, EVSEStatusType->EVSENotification);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 2;
                        }
                    }
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}Dynamic_AC_CLReqControlMode; type={urn:iso:std:iso:15118:-20:AC}Dynamic_AC_CLReqControlModeType; base type=Dynamic_CLReqControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DepartureTime, unsignedInt (0, 1); EVTargetEnergyRequest, RationalNumberType (1, 1); EVMaximumEnergyRequest, RationalNumberType (1, 1); EVMinimumEnergyRequest, RationalNumberType (1, 1); EVMaximumChargePower, RationalNumberType (1, 1); EVMaximumChargePower_L2, RationalNumberType (0, 1); EVMaximumChargePower_L3, RationalNumberType (0, 1); EVMinimumChargePower, RationalNumberType (1, 1); EVMinimumChargePower_L2, RationalNumberType (0, 1); EVMinimumChargePower_L3, RationalNumberType (0, 1); EVPresentActivePower, RationalNumberType (1, 1); EVPresentActivePower_L2, RationalNumberType (0, 1); EVPresentActivePower_L3, RationalNumberType (0, 1); EVPresentReactivePower, RationalNumberType (1, 1); EVPresentReactivePower_L2, RationalNumberType (0, 1); EVPresentReactivePower_L3, RationalNumberType (0, 1);
static int encode_iso20_ac_Dynamic_AC_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_ac_Dynamic_AC_CLReqControlModeType* Dynamic_AC_CLReqControlModeType) {
    int grammar_id = 100;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 100:
            // Grammar: ID=100; read/write bits=2; START (DepartureTime), START (EVTargetEnergyRequest)
            if (Dynamic_AC_CLReqControlModeType->DepartureTime_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (DepartureTime, unsignedLong); next=101
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, Dynamic_AC_CLReqControlModeType->DepartureTime);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 101;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVTargetEnergyRequest, RationalNumberType); next=102
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVTargetEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 102;
                    }
                }
            }
            break;
        case 101:
            // Grammar: ID=101; read/write bits=1; START (EVTargetEnergyRequest)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=102
                error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVTargetEnergyRequest);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 102;
                }
            }
            break;
        case 102:
            // Grammar: ID=102; read/write bits=1; START (EVMaximumEnergyRequest)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=103
                error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVMaximumEnergyRequest);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 103;
                }
            }
            break;
        case 103:
            // Grammar: ID=103; read/write bits=1; START (EVMinimumEnergyRequest)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=104
                error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVMinimumEnergyRequest);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 104;
                }
            }
            break;
        case 104:
            // Grammar: ID=104; read/write bits=1; START (EVMaximumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=105
                error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVMaximumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 105;
                }
            }
            break;
        case 105:
            // Grammar: ID=105; read/write bits=2; START (EVMaximumChargePower_L2), START (EVMaximumChargePower_L3), START (EVMinimumChargePower)
            if (Dynamic_AC_CLReqControlModeType->EVMaximumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L2, RationalNumberType); next=106
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVMaximumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 106;
                    }
                }
            }
            else if (Dynamic_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L3, RationalNumberType); next=107
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 107;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=108
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 108;
                    }
                }
            }
            break;
        case 106:
            // Grammar: ID=106; read/write bits=2; START (EVMaximumChargePower_L3), START (EVMinimumChargePower)
            if (Dynamic_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L3, RationalNumberType); next=107
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 107;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=108
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 108;
                    }
                }
            }
            break;
        case 107:
            // Grammar: ID=107; read/write bits=1; START (EVMinimumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=108
                error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVMinimumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 108;
                }
            }
            break;
        case 108:
            // Grammar: ID=108; read/write bits=2; START (EVMinimumChargePower_L2), START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (Dynamic_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L2, RationalNumberType); next=109
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 109;
                    }
                }
            }
            else if (Dynamic_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=110
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 110;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=111
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 111;
                    }
                }
            }
            break;
        case 109:
            // Grammar: ID=109; read/write bits=2; START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (Dynamic_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=110
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 110;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=111
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 111;
                    }
                }
            }
            break;
        case 110:
            // Grammar: ID=110; read/write bits=1; START (EVPresentActivePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=111
                error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVPresentActivePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 111;
                }
            }
            break;
        case 111:
            // Grammar: ID=111; read/write bits=2; START (EVPresentActivePower_L2), START (EVPresentActivePower_L3), START (EVPresentReactivePower)
            if (Dynamic_AC_CLReqControlModeType->EVPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower_L2, RationalNumberType); next=112
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 112;
                    }
                }
            }
            else if (Dynamic_AC_CLReqControlModeType->EVPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower_L3, RationalNumberType); next=113
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 113;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower, RationalNumberType); next=114
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVPresentReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 114;
                    }
                }
            }
            break;
        case 112:
            // Grammar: ID=112; read/write bits=2; START (EVPresentActivePower_L3), START (EVPresentReactivePower)
            if (Dynamic_AC_CLReqControlModeType->EVPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower_L3, RationalNumberType); next=113
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 113;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower, RationalNumberType); next=114
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVPresentReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 114;
                    }
                }
            }
            break;
        case 113:
            // Grammar: ID=113; read/write bits=1; START (EVPresentReactivePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=114
                error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVPresentReactivePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 114;
                }
            }
            break;
        case 114:
            // Grammar: ID=114; read/write bits=2; START (EVPresentReactivePower_L2), START (EVPresentReactivePower_L3), END Element
            if (Dynamic_AC_CLReqControlModeType->EVPresentReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L2, RationalNumberType); next=115
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVPresentReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 115;
                    }
                }
            }
            else if (Dynamic_AC_CLReqControlModeType->EVPresentReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVPresentReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 115:
            // Grammar: ID=115; read/write bits=2; START (EVPresentReactivePower_L3), END Element
            if (Dynamic_AC_CLReqControlModeType->EVPresentReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLReqControlModeType->EVPresentReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}Scheduled_AC_CLReqControlMode; type={urn:iso:std:iso:15118:-20:AC}Scheduled_AC_CLReqControlModeType; base type=Scheduled_CLReqControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVTargetEnergyRequest, RationalNumberType (0, 1); EVMaximumEnergyRequest, RationalNumberType (0, 1); EVMinimumEnergyRequest, RationalNumberType (0, 1); EVMaximumChargePower, RationalNumberType (0, 1); EVMaximumChargePower_L2, RationalNumberType (0, 1); EVMaximumChargePower_L3, RationalNumberType (0, 1); EVMinimumChargePower, RationalNumberType (0, 1); EVMinimumChargePower_L2, RationalNumberType (0, 1); EVMinimumChargePower_L3, RationalNumberType (0, 1); EVPresentActivePower, RationalNumberType (1, 1); EVPresentActivePower_L2, RationalNumberType (0, 1); EVPresentActivePower_L3, RationalNumberType (0, 1); EVPresentReactivePower, RationalNumberType (0, 1); EVPresentReactivePower_L2, RationalNumberType (0, 1); EVPresentReactivePower_L3, RationalNumberType (0, 1);
static int encode_iso20_ac_Scheduled_AC_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_ac_Scheduled_AC_CLReqControlModeType* Scheduled_AC_CLReqControlModeType) {
    int grammar_id = 116;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 116:
            // Grammar: ID=116; read/write bits=4; START (EVTargetEnergyRequest), START (EVMaximumEnergyRequest), START (EVMinimumEnergyRequest), START (EVMaximumChargePower), START (EVMaximumChargePower_L2), START (EVMaximumChargePower_L3), START (EVMinimumChargePower), START (EVMinimumChargePower_L2), START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (Scheduled_AC_CLReqControlModeType->EVTargetEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVTargetEnergyRequest, RationalNumberType); next=117
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVTargetEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 117;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMaximumEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumEnergyRequest, RationalNumberType); next=118
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMaximumEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 118;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumEnergyRequest, RationalNumberType); next=119
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 119;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower, RationalNumberType); next=120
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMaximumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 120;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L2, RationalNumberType); next=121
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 121;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L3, RationalNumberType); next=122
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 122;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=123
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 123;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L2, RationalNumberType); next=124
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 124;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 8);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=125
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 125;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 9);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=126
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 126;
                    }
                }
            }
            break;
        case 117:
            // Grammar: ID=117; read/write bits=4; START (EVMaximumEnergyRequest), START (EVMinimumEnergyRequest), START (EVMaximumChargePower), START (EVMaximumChargePower_L2), START (EVMaximumChargePower_L3), START (EVMinimumChargePower), START (EVMinimumChargePower_L2), START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (Scheduled_AC_CLReqControlModeType->EVMaximumEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumEnergyRequest, RationalNumberType); next=118
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMaximumEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 118;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumEnergyRequest, RationalNumberType); next=119
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 119;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower, RationalNumberType); next=120
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMaximumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 120;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L2, RationalNumberType); next=121
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 121;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L3, RationalNumberType); next=122
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 122;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=123
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 123;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L2, RationalNumberType); next=124
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 124;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=125
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 125;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 8);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=126
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 126;
                    }
                }
            }
            break;
        case 118:
            // Grammar: ID=118; read/write bits=4; START (EVMinimumEnergyRequest), START (EVMaximumChargePower), START (EVMaximumChargePower_L2), START (EVMaximumChargePower_L3), START (EVMinimumChargePower), START (EVMinimumChargePower_L2), START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (Scheduled_AC_CLReqControlModeType->EVMinimumEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumEnergyRequest, RationalNumberType); next=119
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 119;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower, RationalNumberType); next=120
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMaximumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 120;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L2, RationalNumberType); next=121
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 121;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L3, RationalNumberType); next=122
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 122;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=123
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 123;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L2, RationalNumberType); next=124
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 124;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=125
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 125;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=126
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 126;
                    }
                }
            }
            break;
        case 119:
            // Grammar: ID=119; read/write bits=3; START (EVMaximumChargePower), START (EVMaximumChargePower_L2), START (EVMaximumChargePower_L3), START (EVMinimumChargePower), START (EVMinimumChargePower_L2), START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower, RationalNumberType); next=120
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMaximumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 120;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L2, RationalNumberType); next=121
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 121;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L3, RationalNumberType); next=122
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 122;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=123
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 123;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L2, RationalNumberType); next=124
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 124;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=125
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 125;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=126
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 126;
                    }
                }
            }
            break;
        case 120:
            // Grammar: ID=120; read/write bits=3; START (EVMaximumChargePower_L2), START (EVMaximumChargePower_L3), START (EVMinimumChargePower), START (EVMinimumChargePower_L2), START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L2, RationalNumberType); next=121
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 121;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L3, RationalNumberType); next=122
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 122;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=123
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 123;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L2, RationalNumberType); next=124
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 124;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=125
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 125;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=126
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 126;
                    }
                }
            }
            break;
        case 121:
            // Grammar: ID=121; read/write bits=3; START (EVMaximumChargePower_L3), START (EVMinimumChargePower), START (EVMinimumChargePower_L2), START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L3, RationalNumberType); next=122
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 122;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=123
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 123;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L2, RationalNumberType); next=124
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 124;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=125
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 125;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=126
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 126;
                    }
                }
            }
            break;
        case 122:
            // Grammar: ID=122; read/write bits=3; START (EVMinimumChargePower), START (EVMinimumChargePower_L2), START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=123
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 123;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L2, RationalNumberType); next=124
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 124;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=125
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 125;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=126
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 126;
                    }
                }
            }
            break;
        case 123:
            // Grammar: ID=123; read/write bits=2; START (EVMinimumChargePower_L2), START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L2, RationalNumberType); next=124
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 124;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=125
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 125;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=126
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 126;
                    }
                }
            }
            break;
        case 124:
            // Grammar: ID=124; read/write bits=2; START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=125
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 125;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=126
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 126;
                    }
                }
            }
            break;
        case 125:
            // Grammar: ID=125; read/write bits=1; START (EVPresentActivePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=126
                error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentActivePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 126;
                }
            }
            break;
        case 126:
            // Grammar: ID=126; read/write bits=3; START (EVPresentActivePower_L2), START (EVPresentActivePower_L3), START (EVPresentReactivePower), START (EVPresentReactivePower_L2), START (EVPresentReactivePower_L3), END Element
            if (Scheduled_AC_CLReqControlModeType->EVPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower_L2, RationalNumberType); next=127
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 127;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower_L3, RationalNumberType); next=128
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 128;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower, RationalNumberType); next=129
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 129;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L2, RationalNumberType); next=130
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 130;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 127:
            // Grammar: ID=127; read/write bits=3; START (EVPresentActivePower_L3), START (EVPresentReactivePower), START (EVPresentReactivePower_L2), START (EVPresentReactivePower_L3), END Element
            if (Scheduled_AC_CLReqControlModeType->EVPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower_L3, RationalNumberType); next=128
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 128;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower, RationalNumberType); next=129
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 129;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L2, RationalNumberType); next=130
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 130;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 128:
            // Grammar: ID=128; read/write bits=3; START (EVPresentReactivePower), START (EVPresentReactivePower_L2), START (EVPresentReactivePower_L3), END Element
            if (Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower, RationalNumberType); next=129
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 129;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L2, RationalNumberType); next=130
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 130;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 129:
            // Grammar: ID=129; read/write bits=2; START (EVPresentReactivePower_L2), START (EVPresentReactivePower_L3), END Element
            if (Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L2, RationalNumberType); next=130
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 130;
                    }
                }
            }
            else if (Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 130:
            // Grammar: ID=130; read/write bits=2; START (EVPresentReactivePower_L3), END Element
            if (Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}CLReqControlMode; type={urn:iso:std:iso:15118:-20:CommonTypes}CLReqControlModeType; base type=; content type=empty;
//          abstract=False; final=False;
static int encode_iso20_ac_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_ac_CLReqControlModeType* CLReqControlModeType) {
    // Element has no particles, so the function just returns zero
    (void)stream;
    (void)CLReqControlModeType;

    return 0;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}MeterInfo; type={urn:iso:std:iso:15118:-20:CommonTypes}MeterInfoType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: MeterID, meterIDType (1, 1); ChargedEnergyReadingWh, unsignedLong (1, 1); BPT_DischargedEnergyReadingWh, unsignedLong (0, 1); CapacitiveEnergyReadingVARh, unsignedLong (0, 1); BPT_InductiveEnergyReadingVARh, unsignedLong (0, 1); MeterSignature, meterSignatureType (0, 1); MeterStatus, short (0, 1); MeterTimestamp, unsignedLong (0, 1);
static int encode_iso20_ac_MeterInfoType(exi_bitstream_t* stream, struct iso20_ac_MeterInfoType* MeterInfoType) {
    int grammar_id = 131;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 131:
            // Grammar: ID=131; read/write bits=1; START (MeterID)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (string); next=132

                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(MeterInfoType->MeterID.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, MeterInfoType->MeterID.charactersLen, MeterInfoType->MeterID.characters, iso20_ac_MeterID_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 132;
                            }
                        }
                    }
                }
            }
            break;
        case 132:
            // Grammar: ID=132; read/write bits=1; START (ChargedEnergyReadingWh)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (nonNegativeInteger); next=133
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_uint_64(stream, MeterInfoType->ChargedEnergyReadingWh);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 133;
                        }
                    }
                }
            }
            break;
        case 133:
            // Grammar: ID=133; read/write bits=3; START (BPT_DischargedEnergyReadingWh), START (CapacitiveEnergyReadingVARh), START (BPT_InductiveEnergyReadingVARh), START (MeterSignature), START (MeterStatus), START (MeterTimestamp), END Element
            if (MeterInfoType->BPT_DischargedEnergyReadingWh_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_DischargedEnergyReadingWh, nonNegativeInteger); next=134
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_64(stream, MeterInfoType->BPT_DischargedEnergyReadingWh);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 134;
                            }
                        }
                    }
                }
            }
            else if (MeterInfoType->CapacitiveEnergyReadingVARh_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (CapacitiveEnergyReadingVARh, nonNegativeInteger); next=135
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_64(stream, MeterInfoType->CapacitiveEnergyReadingVARh);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 135;
                            }
                        }
                    }
                }
            }
            else if (MeterInfoType->BPT_InductiveEnergyReadingVARh_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_InductiveEnergyReadingVARh, nonNegativeInteger); next=136
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_64(stream, MeterInfoType->BPT_InductiveEnergyReadingVARh);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 136;
                            }
                        }
                    }
                }
            }
            else if (MeterInfoType->MeterSignature_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterSignature, base64Binary); next=137
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)MeterInfoType->MeterSignature.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, MeterInfoType->MeterSignature.bytesLen, MeterInfoType->MeterSignature.bytes, iso20_ac_meterSignatureType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 137;
                                }
                            }
                        }
                    }
                }
            }
            else if (MeterInfoType->MeterStatus_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterStatus, int); next=138
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_integer_16(stream, MeterInfoType->MeterStatus);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 138;
                            }
                        }
                    }
                }
            }
            else if (MeterInfoType->MeterTimestamp_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterTimestamp, nonNegativeInteger); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_64(stream, MeterInfoType->MeterTimestamp);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 134:
            // Grammar: ID=134; read/write bits=3; START (CapacitiveEnergyReadingVARh), START (BPT_InductiveEnergyReadingVARh), START (MeterSignature), START (MeterStatus), START (MeterTimestamp), END Element
            if (MeterInfoType->CapacitiveEnergyReadingVARh_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (CapacitiveEnergyReadingVARh, nonNegativeInteger); next=135
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_64(stream, MeterInfoType->CapacitiveEnergyReadingVARh);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 135;
                            }
                        }
                    }
                }
            }
            else if (MeterInfoType->BPT_InductiveEnergyReadingVARh_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_InductiveEnergyReadingVARh, nonNegativeInteger); next=136
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_64(stream, MeterInfoType->BPT_InductiveEnergyReadingVARh);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 136;
                            }
                        }
                    }
                }
            }
            else if (MeterInfoType->MeterSignature_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterSignature, base64Binary); next=137
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)MeterInfoType->MeterSignature.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, MeterInfoType->MeterSignature.bytesLen, MeterInfoType->MeterSignature.bytes, iso20_ac_meterSignatureType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 137;
                                }
                            }
                        }
                    }
                }
            }
            else if (MeterInfoType->MeterStatus_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterStatus, int); next=138
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_integer_16(stream, MeterInfoType->MeterStatus);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 138;
                            }
                        }
                    }
                }
            }
            else if (MeterInfoType->MeterTimestamp_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterTimestamp, nonNegativeInteger); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_64(stream, MeterInfoType->MeterTimestamp);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 135:
            // Grammar: ID=135; read/write bits=3; START (BPT_InductiveEnergyReadingVARh), START (MeterSignature), START (MeterStatus), START (MeterTimestamp), END Element
            if (MeterInfoType->BPT_InductiveEnergyReadingVARh_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_InductiveEnergyReadingVARh, nonNegativeInteger); next=136
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_64(stream, MeterInfoType->BPT_InductiveEnergyReadingVARh);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 136;
                            }
                        }
                    }
                }
            }
            else if (MeterInfoType->MeterSignature_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterSignature, base64Binary); next=137
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)MeterInfoType->MeterSignature.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, MeterInfoType->MeterSignature.bytesLen, MeterInfoType->MeterSignature.bytes, iso20_ac_meterSignatureType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 137;
                                }
                            }
                        }
                    }
                }
            }
            else if (MeterInfoType->MeterStatus_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterStatus, int); next=138
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_integer_16(stream, MeterInfoType->MeterStatus);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 138;
                            }
                        }
                    }
                }
            }
            else if (MeterInfoType->MeterTimestamp_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterTimestamp, nonNegativeInteger); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_64(stream, MeterInfoType->MeterTimestamp);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 136:
            // Grammar: ID=136; read/write bits=3; START (MeterSignature), START (MeterStatus), START (MeterTimestamp), END Element
            if (MeterInfoType->MeterSignature_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterSignature, base64Binary); next=137
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)MeterInfoType->MeterSignature.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, MeterInfoType->MeterSignature.bytesLen, MeterInfoType->MeterSignature.bytes, iso20_ac_meterSignatureType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 137;
                                }
                            }
                        }
                    }
                }
            }
            else if (MeterInfoType->MeterStatus_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterStatus, int); next=138
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_integer_16(stream, MeterInfoType->MeterStatus);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 138;
                            }
                        }
                    }
                }
            }
            else if (MeterInfoType->MeterTimestamp_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterTimestamp, nonNegativeInteger); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_64(stream, MeterInfoType->MeterTimestamp);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 137:
            // Grammar: ID=137; read/write bits=2; START (MeterStatus), START (MeterTimestamp), END Element
            if (MeterInfoType->MeterStatus_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterStatus, int); next=138
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_integer_16(stream, MeterInfoType->MeterStatus);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 138;
                            }
                        }
                    }
                }
            }
            else if (MeterInfoType->MeterTimestamp_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterTimestamp, nonNegativeInteger); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_64(stream, MeterInfoType->MeterTimestamp);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 138:
            // Grammar: ID=138; read/write bits=2; START (MeterTimestamp), END Element
            if (MeterInfoType->MeterTimestamp_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterTimestamp, nonNegativeInteger); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_64(stream, MeterInfoType->MeterTimestamp);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 2;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}Receipt; type={urn:iso:std:iso:15118:-20:CommonTypes}ReceiptType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: TimeAnchor, unsignedLong (1, 1); EnergyCosts, DetailedCostType (0, 1); OccupancyCosts, DetailedCostType (0, 1); AdditionalServicesCosts, DetailedCostType (0, 1); OverstayCosts, DetailedCostType (0, 1); TaxCosts, DetailedTaxType (0, 10);
static int encode_iso20_ac_ReceiptType(exi_bitstream_t* stream, struct iso20_ac_ReceiptType* ReceiptType) {
    int grammar_id = 139;
    int done = 0;
    int error = 0;
    uint16_t TaxCosts_currentIndex = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 139:
            // Grammar: ID=139; read/write bits=1; START (TimeAnchor)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (nonNegativeInteger); next=140
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_uint_64(stream, ReceiptType->TimeAnchor);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 140;
                        }
                    }
                }
            }
            break;
        case 140:
            // Grammar: ID=140; read/write bits=3; START (EnergyCosts), START (OccupancyCosts), START (AdditionalServicesCosts), START (OverstayCosts), START (TaxCosts), END Element
            if (ReceiptType->EnergyCosts_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EnergyCosts, DetailedCostType); next=150
                    error = encode_iso20_ac_DetailedCostType(stream, &ReceiptType->EnergyCosts);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 150;
                    }
                }
            }
            else if (ReceiptType->OccupancyCosts_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (OccupancyCosts, DetailedCostType); next=160
                    error = encode_iso20_ac_DetailedCostType(stream, &ReceiptType->OccupancyCosts);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 160;
                    }
                }
            }
            else if (ReceiptType->AdditionalServicesCosts_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AdditionalServicesCosts, DetailedCostType); next=170
                    error = encode_iso20_ac_DetailedCostType(stream, &ReceiptType->AdditionalServicesCosts);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 170;
                    }
                }
            }
            else if (ReceiptType->OverstayCosts_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (OverstayCosts, DetailedCostType); next=180
                    error = encode_iso20_ac_DetailedCostType(stream, &ReceiptType->OverstayCosts);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 180;
                    }
                }
            }
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 141:
            // Grammar: ID=141; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 142:
            // Grammar: ID=142; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 143:
            // Grammar: ID=143; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 144:
            // Grammar: ID=144; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 145:
            // Grammar: ID=145; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 146:
            // Grammar: ID=146; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 147:
            // Grammar: ID=147; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 148:
            // Grammar: ID=148; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 149:
            // Grammar: ID=149; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 150:
            // Grammar: ID=150; read/write bits=3; START (OccupancyCosts), START (AdditionalServicesCosts), START (OverstayCosts), START (TaxCosts), END Element
            if (ReceiptType->OccupancyCosts_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (OccupancyCosts, DetailedCostType); next=160
                    error = encode_iso20_ac_DetailedCostType(stream, &ReceiptType->OccupancyCosts);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 160;
                    }
                }
            }
            else if (ReceiptType->AdditionalServicesCosts_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AdditionalServicesCosts, DetailedCostType); next=170
                    error = encode_iso20_ac_DetailedCostType(stream, &ReceiptType->AdditionalServicesCosts);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 170;
                    }
                }
            }
            else if (ReceiptType->OverstayCosts_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (OverstayCosts, DetailedCostType); next=180
                    error = encode_iso20_ac_DetailedCostType(stream, &ReceiptType->OverstayCosts);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 180;
                    }
                }
            }
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 151:
            // Grammar: ID=151; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 152:
            // Grammar: ID=152; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 153:
            // Grammar: ID=153; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 154:
            // Grammar: ID=154; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 155:
            // Grammar: ID=155; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 156:
            // Grammar: ID=156; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 157:
            // Grammar: ID=157; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 158:
            // Grammar: ID=158; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 159:
            // Grammar: ID=159; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 160:
            // Grammar: ID=160; read/write bits=3; START (AdditionalServicesCosts), START (OverstayCosts), START (TaxCosts), END Element
            if (ReceiptType->AdditionalServicesCosts_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AdditionalServicesCosts, DetailedCostType); next=170
                    error = encode_iso20_ac_DetailedCostType(stream, &ReceiptType->AdditionalServicesCosts);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 170;
                    }
                }
            }
            else if (ReceiptType->OverstayCosts_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (OverstayCosts, DetailedCostType); next=180
                    error = encode_iso20_ac_DetailedCostType(stream, &ReceiptType->OverstayCosts);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 180;
                    }
                }
            }
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 161:
            // Grammar: ID=161; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 162:
            // Grammar: ID=162; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 163:
            // Grammar: ID=163; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 164:
            // Grammar: ID=164; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 165:
            // Grammar: ID=165; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 166:
            // Grammar: ID=166; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 167:
            // Grammar: ID=167; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 168:
            // Grammar: ID=168; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 169:
            // Grammar: ID=169; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 170:
            // Grammar: ID=170; read/write bits=2; START (OverstayCosts), START (TaxCosts), END Element
            if (ReceiptType->OverstayCosts_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (OverstayCosts, DetailedCostType); next=180
                    error = encode_iso20_ac_DetailedCostType(stream, &ReceiptType->OverstayCosts);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 180;
                    }
                }
            }
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 171:
            // Grammar: ID=171; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 172:
            // Grammar: ID=172; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 173:
            // Grammar: ID=173; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 174:
            // Grammar: ID=174; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 175:
            // Grammar: ID=175; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 176:
            // Grammar: ID=176; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 177:
            // Grammar: ID=177; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 178:
            // Grammar: ID=178; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 179:
            // Grammar: ID=179; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 180:
            // Grammar: ID=180; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 181:
            // Grammar: ID=181; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 182:
            // Grammar: ID=182; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 183:
            // Grammar: ID=183; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 184:
            // Grammar: ID=184; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 185:
            // Grammar: ID=185; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 186:
            // Grammar: ID=186; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 187:
            // Grammar: ID=187; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 188:
            // Grammar: ID=188; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 189:
            // Grammar: ID=189; read/write bits=2; START (TaxCosts), END Element
            // tbd optional array
            if (1 == 0)
            {
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}Dynamic_AC_CLResControlMode; type={urn:iso:std:iso:15118:-20:AC}Dynamic_AC_CLResControlModeType; base type=Dynamic_CLResControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DepartureTime, unsignedInt (0, 1); MinimumSOC, percentValueType (0, 1); TargetSOC, percentValueType (0, 1); AckMaxDelay, unsignedShort (0, 1); EVSETargetActivePower, RationalNumberType (1, 1); EVSETargetActivePower_L2, RationalNumberType (0, 1); EVSETargetActivePower_L3, RationalNumberType (0, 1); EVSETargetReactivePower, RationalNumberType (0, 1); EVSETargetReactivePower_L2, RationalNumberType (0, 1); EVSETargetReactivePower_L3, RationalNumberType (0, 1); EVSEPresentActivePower, RationalNumberType (0, 1); EVSEPresentActivePower_L2, RationalNumberType (0, 1); EVSEPresentActivePower_L3, RationalNumberType (0, 1);
static int encode_iso20_ac_Dynamic_AC_CLResControlModeType(exi_bitstream_t* stream, struct iso20_ac_Dynamic_AC_CLResControlModeType* Dynamic_AC_CLResControlModeType) {
    int grammar_id = 190;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 190:
            // Grammar: ID=190; read/write bits=3; START (DepartureTime), START (MinimumSOC), START (TargetSOC), START (AckMaxDelay), START (EVSETargetActivePower)
            if (Dynamic_AC_CLResControlModeType->DepartureTime_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (DepartureTime, unsignedLong); next=191
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, Dynamic_AC_CLResControlModeType->DepartureTime);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 191;
                            }
                        }
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->MinimumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MinimumSOC, byte); next=192
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)Dynamic_AC_CLResControlModeType->MinimumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 192;
                            }
                        }
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->TargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (TargetSOC, byte); next=193
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)Dynamic_AC_CLResControlModeType->TargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 193;
                            }
                        }
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->AckMaxDelay_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AckMaxDelay, unsignedInt); next=194
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, Dynamic_AC_CLResControlModeType->AckMaxDelay);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 194;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower, RationalNumberType); next=195
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSETargetActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 195;
                    }
                }
            }
            break;
        case 191:
            // Grammar: ID=191; read/write bits=3; START (MinimumSOC), START (TargetSOC), START (AckMaxDelay), START (EVSETargetActivePower)
            if (Dynamic_AC_CLResControlModeType->MinimumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MinimumSOC, byte); next=192
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)Dynamic_AC_CLResControlModeType->MinimumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 192;
                            }
                        }
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->TargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (TargetSOC, byte); next=193
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)Dynamic_AC_CLResControlModeType->TargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 193;
                            }
                        }
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->AckMaxDelay_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AckMaxDelay, unsignedInt); next=194
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, Dynamic_AC_CLResControlModeType->AckMaxDelay);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 194;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower, RationalNumberType); next=195
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSETargetActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 195;
                    }
                }
            }
            break;
        case 192:
            // Grammar: ID=192; read/write bits=2; START (TargetSOC), START (AckMaxDelay), START (EVSETargetActivePower)
            if (Dynamic_AC_CLResControlModeType->TargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (TargetSOC, byte); next=193
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)Dynamic_AC_CLResControlModeType->TargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 193;
                            }
                        }
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->AckMaxDelay_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AckMaxDelay, unsignedInt); next=194
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, Dynamic_AC_CLResControlModeType->AckMaxDelay);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 194;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower, RationalNumberType); next=195
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSETargetActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 195;
                    }
                }
            }
            break;
        case 193:
            // Grammar: ID=193; read/write bits=2; START (AckMaxDelay), START (EVSETargetActivePower)
            if (Dynamic_AC_CLResControlModeType->AckMaxDelay_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AckMaxDelay, unsignedInt); next=194
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, Dynamic_AC_CLResControlModeType->AckMaxDelay);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 194;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower, RationalNumberType); next=195
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSETargetActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 195;
                    }
                }
            }
            break;
        case 194:
            // Grammar: ID=194; read/write bits=1; START (EVSETargetActivePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=195
                error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSETargetActivePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 195;
                }
            }
            break;
        case 195:
            // Grammar: ID=195; read/write bits=4; START (EVSETargetActivePower_L2), START (EVSETargetActivePower_L3), START (EVSETargetReactivePower), START (EVSETargetReactivePower_L2), START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (Dynamic_AC_CLResControlModeType->EVSETargetActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower_L2, RationalNumberType); next=196
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSETargetActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 196;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSETargetActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower_L3, RationalNumberType); next=197
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSETargetActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 197;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower, RationalNumberType); next=198
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSETargetReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 198;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L2, RationalNumberType); next=199
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 199;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=200
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 200;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=201
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 201;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=202
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 202;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 8);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 196:
            // Grammar: ID=196; read/write bits=4; START (EVSETargetActivePower_L3), START (EVSETargetReactivePower), START (EVSETargetReactivePower_L2), START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (Dynamic_AC_CLResControlModeType->EVSETargetActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower_L3, RationalNumberType); next=197
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSETargetActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 197;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower, RationalNumberType); next=198
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSETargetReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 198;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L2, RationalNumberType); next=199
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 199;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=200
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 200;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=201
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 201;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=202
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 202;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 197:
            // Grammar: ID=197; read/write bits=3; START (EVSETargetReactivePower), START (EVSETargetReactivePower_L2), START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower, RationalNumberType); next=198
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSETargetReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 198;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L2, RationalNumberType); next=199
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 199;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=200
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 200;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=201
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 201;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=202
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 202;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 198:
            // Grammar: ID=198; read/write bits=3; START (EVSETargetReactivePower_L2), START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L2, RationalNumberType); next=199
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 199;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=200
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 200;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=201
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 201;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=202
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 202;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 199:
            // Grammar: ID=199; read/write bits=3; START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=200
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 200;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=201
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 201;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=202
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 202;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 200:
            // Grammar: ID=200; read/write bits=3; START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=201
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 201;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=202
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 202;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 201:
            // Grammar: ID=201; read/write bits=2; START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=202
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 202;
                    }
                }
            }
            else if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 202:
            // Grammar: ID=202; read/write bits=2; START (EVSEPresentActivePower_L3), END Element
            if (Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}Scheduled_AC_CLResControlMode; type={urn:iso:std:iso:15118:-20:AC}Scheduled_AC_CLResControlModeType; base type=Scheduled_CLResControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVSETargetActivePower, RationalNumberType (0, 1); EVSETargetActivePower_L2, RationalNumberType (0, 1); EVSETargetActivePower_L3, RationalNumberType (0, 1); EVSETargetReactivePower, RationalNumberType (0, 1); EVSETargetReactivePower_L2, RationalNumberType (0, 1); EVSETargetReactivePower_L3, RationalNumberType (0, 1); EVSEPresentActivePower, RationalNumberType (0, 1); EVSEPresentActivePower_L2, RationalNumberType (0, 1); EVSEPresentActivePower_L3, RationalNumberType (0, 1);
static int encode_iso20_ac_Scheduled_AC_CLResControlModeType(exi_bitstream_t* stream, struct iso20_ac_Scheduled_AC_CLResControlModeType* Scheduled_AC_CLResControlModeType) {
    int grammar_id = 203;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 203:
            // Grammar: ID=203; read/write bits=4; START (EVSETargetActivePower), START (EVSETargetActivePower_L2), START (EVSETargetActivePower_L3), START (EVSETargetReactivePower), START (EVSETargetReactivePower_L2), START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (Scheduled_AC_CLResControlModeType->EVSETargetActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower, RationalNumberType); next=204
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 204;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower_L2, RationalNumberType); next=205
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 205;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower_L3, RationalNumberType); next=206
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 206;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower, RationalNumberType); next=207
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 207;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L2, RationalNumberType); next=208
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 208;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=209
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 209;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=210
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 210;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=211
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 211;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 8);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 9);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 204:
            // Grammar: ID=204; read/write bits=4; START (EVSETargetActivePower_L2), START (EVSETargetActivePower_L3), START (EVSETargetReactivePower), START (EVSETargetReactivePower_L2), START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower_L2, RationalNumberType); next=205
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 205;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower_L3, RationalNumberType); next=206
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 206;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower, RationalNumberType); next=207
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 207;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L2, RationalNumberType); next=208
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 208;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=209
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 209;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=210
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 210;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=211
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 211;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 8);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 205:
            // Grammar: ID=205; read/write bits=4; START (EVSETargetActivePower_L3), START (EVSETargetReactivePower), START (EVSETargetReactivePower_L2), START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower_L3, RationalNumberType); next=206
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 206;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower, RationalNumberType); next=207
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 207;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L2, RationalNumberType); next=208
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 208;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=209
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 209;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=210
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 210;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=211
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 211;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 206:
            // Grammar: ID=206; read/write bits=3; START (EVSETargetReactivePower), START (EVSETargetReactivePower_L2), START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower, RationalNumberType); next=207
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 207;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L2, RationalNumberType); next=208
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 208;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=209
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 209;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=210
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 210;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=211
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 211;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 207:
            // Grammar: ID=207; read/write bits=3; START (EVSETargetReactivePower_L2), START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L2, RationalNumberType); next=208
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 208;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=209
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 209;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=210
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 210;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=211
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 211;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 208:
            // Grammar: ID=208; read/write bits=3; START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=209
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 209;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=210
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 210;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=211
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 211;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 209:
            // Grammar: ID=209; read/write bits=3; START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=210
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 210;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=211
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 211;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 210:
            // Grammar: ID=210; read/write bits=2; START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=211
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 211;
                    }
                }
            }
            else if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 211:
            // Grammar: ID=211; read/write bits=2; START (EVSEPresentActivePower_L3), END Element
            if (Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}CLResControlMode; type={urn:iso:std:iso:15118:-20:CommonTypes}CLResControlModeType; base type=; content type=empty;
//          abstract=False; final=False;
static int encode_iso20_ac_CLResControlModeType(exi_bitstream_t* stream, struct iso20_ac_CLResControlModeType* CLResControlModeType) {
    // Element has no particles, so the function just returns zero
    (void)stream;
    (void)CLResControlModeType;

    return 0;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}BPT_AC_CPDReqEnergyTransferMode; type={urn:iso:std:iso:15118:-20:AC}BPT_AC_CPDReqEnergyTransferModeType; base type=AC_CPDReqEnergyTransferModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVMaximumChargePower, RationalNumberType (1, 1); EVMaximumChargePower_L2, RationalNumberType (0, 1); EVMaximumChargePower_L3, RationalNumberType (0, 1); EVMinimumChargePower, RationalNumberType (1, 1); EVMinimumChargePower_L2, RationalNumberType (0, 1); EVMinimumChargePower_L3, RationalNumberType (0, 1); EVMaximumDischargePower, RationalNumberType (1, 1); EVMaximumDischargePower_L2, RationalNumberType (0, 1); EVMaximumDischargePower_L3, RationalNumberType (0, 1); EVMinimumDischargePower, RationalNumberType (1, 1); EVMinimumDischargePower_L2, RationalNumberType (0, 1); EVMinimumDischargePower_L3, RationalNumberType (0, 1);
static int encode_iso20_ac_BPT_AC_CPDReqEnergyTransferModeType(exi_bitstream_t* stream, struct iso20_ac_BPT_AC_CPDReqEnergyTransferModeType* BPT_AC_CPDReqEnergyTransferModeType) {
    int grammar_id = 212;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 212:
            // Grammar: ID=212; read/write bits=1; START (EVMaximumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=213
                error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMaximumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 213;
                }
            }
            break;
        case 213:
            // Grammar: ID=213; read/write bits=2; START (EVMaximumChargePower_L2), START (EVMaximumChargePower_L3), START (EVMinimumChargePower)
            if (BPT_AC_CPDReqEnergyTransferModeType->EVMaximumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L2, RationalNumberType); next=214
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMaximumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 214;
                    }
                }
            }
            else if (BPT_AC_CPDReqEnergyTransferModeType->EVMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L3, RationalNumberType); next=215
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 215;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=216
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 216;
                    }
                }
            }
            break;
        case 214:
            // Grammar: ID=214; read/write bits=2; START (EVMaximumChargePower_L3), START (EVMinimumChargePower)
            if (BPT_AC_CPDReqEnergyTransferModeType->EVMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L3, RationalNumberType); next=215
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 215;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=216
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 216;
                    }
                }
            }
            break;
        case 215:
            // Grammar: ID=215; read/write bits=1; START (EVMinimumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=216
                error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMinimumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 216;
                }
            }
            break;
        case 216:
            // Grammar: ID=216; read/write bits=2; START (EVMinimumChargePower_L2), START (EVMinimumChargePower_L3), START (EVMaximumDischargePower)
            if (BPT_AC_CPDReqEnergyTransferModeType->EVMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L2, RationalNumberType); next=217
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 217;
                    }
                }
            }
            else if (BPT_AC_CPDReqEnergyTransferModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=218
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 218;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower, RationalNumberType); next=219
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 219;
                    }
                }
            }
            break;
        case 217:
            // Grammar: ID=217; read/write bits=2; START (EVMinimumChargePower_L3), START (EVMaximumDischargePower)
            if (BPT_AC_CPDReqEnergyTransferModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=218
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 218;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower, RationalNumberType); next=219
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 219;
                    }
                }
            }
            break;
        case 218:
            // Grammar: ID=218; read/write bits=1; START (EVMaximumDischargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=219
                error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMaximumDischargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 219;
                }
            }
            break;
        case 219:
            // Grammar: ID=219; read/write bits=2; START (EVMaximumDischargePower_L2), START (EVMaximumDischargePower_L3), START (EVMinimumDischargePower)
            if (BPT_AC_CPDReqEnergyTransferModeType->EVMaximumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L2, RationalNumberType); next=220
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMaximumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 220;
                    }
                }
            }
            else if (BPT_AC_CPDReqEnergyTransferModeType->EVMaximumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L3, RationalNumberType); next=221
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMaximumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 221;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower, RationalNumberType); next=222
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 222;
                    }
                }
            }
            break;
        case 220:
            // Grammar: ID=220; read/write bits=2; START (EVMaximumDischargePower_L3), START (EVMinimumDischargePower)
            if (BPT_AC_CPDReqEnergyTransferModeType->EVMaximumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L3, RationalNumberType); next=221
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMaximumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 221;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower, RationalNumberType); next=222
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 222;
                    }
                }
            }
            break;
        case 221:
            // Grammar: ID=221; read/write bits=1; START (EVMinimumDischargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=222
                error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMinimumDischargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 222;
                }
            }
            break;
        case 222:
            // Grammar: ID=222; read/write bits=2; START (EVMinimumDischargePower_L2), START (EVMinimumDischargePower_L3), END Element
            if (BPT_AC_CPDReqEnergyTransferModeType->EVMinimumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L2, RationalNumberType); next=223
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMinimumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 223;
                    }
                }
            }
            else if (BPT_AC_CPDReqEnergyTransferModeType->EVMinimumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMinimumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 223:
            // Grammar: ID=223; read/write bits=2; START (EVMinimumDischargePower_L3), END Element
            if (BPT_AC_CPDReqEnergyTransferModeType->EVMinimumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDReqEnergyTransferModeType->EVMinimumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}AC_ChargeParameterDiscoveryReq; type={urn:iso:std:iso:15118:-20:AC}AC_ChargeParameterDiscoveryReqType; base type=ChargeParameterDiscoveryReqType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); AC_CPDReqEnergyTransferMode, AC_CPDReqEnergyTransferModeType (0, 1); BPT_AC_CPDReqEnergyTransferMode, BPT_AC_CPDReqEnergyTransferModeType (0, 1);
static int encode_iso20_ac_AC_ChargeParameterDiscoveryReqType(exi_bitstream_t* stream, struct iso20_ac_AC_ChargeParameterDiscoveryReqType* AC_ChargeParameterDiscoveryReqType) {
    int grammar_id = 224;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 224:
            // Grammar: ID=224; read/write bits=1; START (Header)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (MessageHeaderType); next=225
                error = encode_iso20_ac_MessageHeaderType(stream, &AC_ChargeParameterDiscoveryReqType->Header);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 225;
                }
            }
            break;
        case 225:
            // Grammar: ID=225; read/write bits=2; START (AC_CPDReqEnergyTransferMode), START (BPT_AC_CPDReqEnergyTransferMode)
            if (AC_ChargeParameterDiscoveryReqType->AC_CPDReqEnergyTransferMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AC_CPDReqEnergyTransferMode, AC_CPDReqEnergyTransferModeType); next=2
                    error = encode_iso20_ac_AC_CPDReqEnergyTransferModeType(stream, &AC_ChargeParameterDiscoveryReqType->AC_CPDReqEnergyTransferMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_AC_CPDReqEnergyTransferMode, AC_CPDReqEnergyTransferModeType); next=2
                    error = encode_iso20_ac_BPT_AC_CPDReqEnergyTransferModeType(stream, &AC_ChargeParameterDiscoveryReqType->BPT_AC_CPDReqEnergyTransferMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}BPT_AC_CPDResEnergyTransferMode; type={urn:iso:std:iso:15118:-20:AC}BPT_AC_CPDResEnergyTransferModeType; base type=AC_CPDResEnergyTransferModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVSEMaximumChargePower, RationalNumberType (1, 1); EVSEMaximumChargePower_L2, RationalNumberType (0, 1); EVSEMaximumChargePower_L3, RationalNumberType (0, 1); EVSEMinimumChargePower, RationalNumberType (1, 1); EVSEMinimumChargePower_L2, RationalNumberType (0, 1); EVSEMinimumChargePower_L3, RationalNumberType (0, 1); EVSENominalFrequency, RationalNumberType (1, 1); MaximumPowerAsymmetry, RationalNumberType (0, 1); EVSEPowerRampLimitation, RationalNumberType (0, 1); EVSEPresentActivePower, RationalNumberType (0, 1); EVSEPresentActivePower_L2, RationalNumberType (0, 1); EVSEPresentActivePower_L3, RationalNumberType (0, 1); EVSEMaximumDischargePower, RationalNumberType (1, 1); EVSEMaximumDischargePower_L2, RationalNumberType (0, 1); EVSEMaximumDischargePower_L3, RationalNumberType (0, 1); EVSEMinimumDischargePower, RationalNumberType (1, 1); EVSEMinimumDischargePower_L2, RationalNumberType (0, 1); EVSEMinimumDischargePower_L3, RationalNumberType (0, 1);
static int encode_iso20_ac_BPT_AC_CPDResEnergyTransferModeType(exi_bitstream_t* stream, struct iso20_ac_BPT_AC_CPDResEnergyTransferModeType* BPT_AC_CPDResEnergyTransferModeType) {
    int grammar_id = 226;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 226:
            // Grammar: ID=226; read/write bits=1; START (EVSEMaximumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=227
                error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 227;
                }
            }
            break;
        case 227:
            // Grammar: ID=227; read/write bits=2; START (EVSEMaximumChargePower_L2), START (EVSEMaximumChargePower_L3), START (EVSEMinimumChargePower)
            if (BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumChargePower_L2, RationalNumberType); next=228
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 228;
                    }
                }
            }
            else if (BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumChargePower_L3, RationalNumberType); next=229
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 229;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumChargePower, RationalNumberType); next=230
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 230;
                    }
                }
            }
            break;
        case 228:
            // Grammar: ID=228; read/write bits=2; START (EVSEMaximumChargePower_L3), START (EVSEMinimumChargePower)
            if (BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumChargePower_L3, RationalNumberType); next=229
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 229;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumChargePower, RationalNumberType); next=230
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 230;
                    }
                }
            }
            break;
        case 229:
            // Grammar: ID=229; read/write bits=1; START (EVSEMinimumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=230
                error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 230;
                }
            }
            break;
        case 230:
            // Grammar: ID=230; read/write bits=2; START (EVSEMinimumChargePower_L2), START (EVSEMinimumChargePower_L3), START (EVSENominalFrequency)
            if (BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumChargePower_L2, RationalNumberType); next=231
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 231;
                    }
                }
            }
            else if (BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumChargePower_L3, RationalNumberType); next=232
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 232;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSENominalFrequency, RationalNumberType); next=233
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSENominalFrequency);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 233;
                    }
                }
            }
            break;
        case 231:
            // Grammar: ID=231; read/write bits=2; START (EVSEMinimumChargePower_L3), START (EVSENominalFrequency)
            if (BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumChargePower_L3, RationalNumberType); next=232
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 232;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSENominalFrequency, RationalNumberType); next=233
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSENominalFrequency);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 233;
                    }
                }
            }
            break;
        case 232:
            // Grammar: ID=232; read/write bits=1; START (EVSENominalFrequency)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=233
                error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSENominalFrequency);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 233;
                }
            }
            break;
        case 233:
            // Grammar: ID=233; read/write bits=3; START (MaximumPowerAsymmetry), START (EVSEPowerRampLimitation), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), START (EVSEMaximumDischargePower)
            if (BPT_AC_CPDResEnergyTransferModeType->MaximumPowerAsymmetry_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MaximumPowerAsymmetry, RationalNumberType); next=234
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->MaximumPowerAsymmetry);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 234;
                    }
                }
            }
            else if (BPT_AC_CPDResEnergyTransferModeType->EVSEPowerRampLimitation_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPowerRampLimitation, RationalNumberType); next=235
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEPowerRampLimitation);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 235;
                    }
                }
            }
            else if (BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=236
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 236;
                    }
                }
            }
            else if (BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=237
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 237;
                    }
                }
            }
            else if (BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=238
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 238;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargePower, RationalNumberType); next=239
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 239;
                    }
                }
            }
            break;
        case 234:
            // Grammar: ID=234; read/write bits=3; START (EVSEPowerRampLimitation), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), START (EVSEMaximumDischargePower)
            if (BPT_AC_CPDResEnergyTransferModeType->EVSEPowerRampLimitation_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPowerRampLimitation, RationalNumberType); next=235
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEPowerRampLimitation);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 235;
                    }
                }
            }
            else if (BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=236
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 236;
                    }
                }
            }
            else if (BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=237
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 237;
                    }
                }
            }
            else if (BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=238
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 238;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargePower, RationalNumberType); next=239
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 239;
                    }
                }
            }
            break;
        case 235:
            // Grammar: ID=235; read/write bits=3; START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), START (EVSEMaximumDischargePower)
            if (BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=236
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 236;
                    }
                }
            }
            else if (BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=237
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 237;
                    }
                }
            }
            else if (BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=238
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 238;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargePower, RationalNumberType); next=239
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 239;
                    }
                }
            }
            break;
        case 236:
            // Grammar: ID=236; read/write bits=2; START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), START (EVSEMaximumDischargePower)
            if (BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=237
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 237;
                    }
                }
            }
            else if (BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=238
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 238;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargePower, RationalNumberType); next=239
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 239;
                    }
                }
            }
            break;
        case 237:
            // Grammar: ID=237; read/write bits=2; START (EVSEPresentActivePower_L3), START (EVSEMaximumDischargePower)
            if (BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=238
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 238;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargePower, RationalNumberType); next=239
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 239;
                    }
                }
            }
            break;
        case 238:
            // Grammar: ID=238; read/write bits=1; START (EVSEMaximumDischargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=239
                error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumDischargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 239;
                }
            }
            break;
        case 239:
            // Grammar: ID=239; read/write bits=2; START (EVSEMaximumDischargePower_L2), START (EVSEMaximumDischargePower_L3), START (EVSEMinimumDischargePower)
            if (BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargePower_L2, RationalNumberType); next=240
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 240;
                    }
                }
            }
            else if (BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargePower_L3, RationalNumberType); next=241
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 241;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumDischargePower, RationalNumberType); next=242
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 242;
                    }
                }
            }
            break;
        case 240:
            // Grammar: ID=240; read/write bits=2; START (EVSEMaximumDischargePower_L3), START (EVSEMinimumDischargePower)
            if (BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargePower_L3, RationalNumberType); next=241
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMaximumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 241;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumDischargePower, RationalNumberType); next=242
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 242;
                    }
                }
            }
            break;
        case 241:
            // Grammar: ID=241; read/write bits=1; START (EVSEMinimumDischargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=242
                error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumDischargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 242;
                }
            }
            break;
        case 242:
            // Grammar: ID=242; read/write bits=2; START (EVSEMinimumDischargePower_L2), START (EVSEMinimumDischargePower_L3), END Element
            if (BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumDischargePower_L2, RationalNumberType); next=243
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 243;
                    }
                }
            }
            else if (BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumDischargePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 243:
            // Grammar: ID=243; read/write bits=2; START (EVSEMinimumDischargePower_L3), END Element
            if (BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumDischargePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_AC_CPDResEnergyTransferModeType->EVSEMinimumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}AC_ChargeParameterDiscoveryRes; type={urn:iso:std:iso:15118:-20:AC}AC_ChargeParameterDiscoveryResType; base type=ChargeParameterDiscoveryResType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); AC_CPDResEnergyTransferMode, AC_CPDResEnergyTransferModeType (0, 1); BPT_AC_CPDResEnergyTransferMode, BPT_AC_CPDResEnergyTransferModeType (0, 1);
static int encode_iso20_ac_AC_ChargeParameterDiscoveryResType(exi_bitstream_t* stream, struct iso20_ac_AC_ChargeParameterDiscoveryResType* AC_ChargeParameterDiscoveryResType) {
    int grammar_id = 244;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 244:
            // Grammar: ID=244; read/write bits=1; START (Header)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (MessageHeaderType); next=245
                error = encode_iso20_ac_MessageHeaderType(stream, &AC_ChargeParameterDiscoveryResType->Header);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 245;
                }
            }
            break;
        case 245:
            // Grammar: ID=245; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (string); next=246
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_nbit_uint(stream, 6, AC_ChargeParameterDiscoveryResType->ResponseCode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 246;
                        }
                    }
                }
            }
            break;
        case 246:
            // Grammar: ID=246; read/write bits=2; START (AC_CPDResEnergyTransferMode), START (BPT_AC_CPDResEnergyTransferMode)
            if (AC_ChargeParameterDiscoveryResType->AC_CPDResEnergyTransferMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AC_CPDResEnergyTransferMode, AC_CPDResEnergyTransferModeType); next=2
                    error = encode_iso20_ac_AC_CPDResEnergyTransferModeType(stream, &AC_ChargeParameterDiscoveryResType->AC_CPDResEnergyTransferMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_AC_CPDResEnergyTransferMode, AC_CPDResEnergyTransferModeType); next=2
                    error = encode_iso20_ac_BPT_AC_CPDResEnergyTransferModeType(stream, &AC_ChargeParameterDiscoveryResType->BPT_AC_CPDResEnergyTransferMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}BPT_Scheduled_AC_CLReqControlMode; type={urn:iso:std:iso:15118:-20:AC}BPT_Scheduled_AC_CLReqControlModeType; base type=Scheduled_AC_CLReqControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVTargetEnergyRequest, RationalNumberType (0, 1); EVMaximumEnergyRequest, RationalNumberType (0, 1); EVMinimumEnergyRequest, RationalNumberType (0, 1); EVMaximumChargePower, RationalNumberType (0, 1); EVMaximumChargePower_L2, RationalNumberType (0, 1); EVMaximumChargePower_L3, RationalNumberType (0, 1); EVMinimumChargePower, RationalNumberType (0, 1); EVMinimumChargePower_L2, RationalNumberType (0, 1); EVMinimumChargePower_L3, RationalNumberType (0, 1); EVPresentActivePower, RationalNumberType (1, 1); EVPresentActivePower_L2, RationalNumberType (0, 1); EVPresentActivePower_L3, RationalNumberType (0, 1); EVPresentReactivePower, RationalNumberType (0, 1); EVPresentReactivePower_L2, RationalNumberType (0, 1); EVPresentReactivePower_L3, RationalNumberType (0, 1); EVMaximumDischargePower, RationalNumberType (0, 1); EVMaximumDischargePower_L2, RationalNumberType (0, 1); EVMaximumDischargePower_L3, RationalNumberType (0, 1); EVMinimumDischargePower, RationalNumberType (0, 1); EVMinimumDischargePower_L2, RationalNumberType (0, 1); EVMinimumDischargePower_L3, RationalNumberType (0, 1);
static int encode_iso20_ac_BPT_Scheduled_AC_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_ac_BPT_Scheduled_AC_CLReqControlModeType* BPT_Scheduled_AC_CLReqControlModeType) {
    int grammar_id = 247;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 247:
            // Grammar: ID=247; read/write bits=4; START (EVTargetEnergyRequest), START (EVMaximumEnergyRequest), START (EVMinimumEnergyRequest), START (EVMaximumChargePower), START (EVMaximumChargePower_L2), START (EVMaximumChargePower_L3), START (EVMinimumChargePower), START (EVMinimumChargePower_L2), START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (BPT_Scheduled_AC_CLReqControlModeType->EVTargetEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVTargetEnergyRequest, RationalNumberType); next=248
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVTargetEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 248;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumEnergyRequest, RationalNumberType); next=249
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 249;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumEnergyRequest, RationalNumberType); next=250
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 250;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower, RationalNumberType); next=251
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 251;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L2, RationalNumberType); next=252
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 252;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L3, RationalNumberType); next=253
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 253;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=254
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 254;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L2, RationalNumberType); next=255
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 255;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 8);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=256
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 256;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 9);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=257
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 257;
                    }
                }
            }
            break;
        case 248:
            // Grammar: ID=248; read/write bits=4; START (EVMaximumEnergyRequest), START (EVMinimumEnergyRequest), START (EVMaximumChargePower), START (EVMaximumChargePower_L2), START (EVMaximumChargePower_L3), START (EVMinimumChargePower), START (EVMinimumChargePower_L2), START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumEnergyRequest, RationalNumberType); next=249
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 249;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumEnergyRequest, RationalNumberType); next=250
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 250;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower, RationalNumberType); next=251
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 251;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L2, RationalNumberType); next=252
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 252;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L3, RationalNumberType); next=253
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 253;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=254
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 254;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L2, RationalNumberType); next=255
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 255;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=256
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 256;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 8);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=257
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 257;
                    }
                }
            }
            break;
        case 249:
            // Grammar: ID=249; read/write bits=4; START (EVMinimumEnergyRequest), START (EVMaximumChargePower), START (EVMaximumChargePower_L2), START (EVMaximumChargePower_L3), START (EVMinimumChargePower), START (EVMinimumChargePower_L2), START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumEnergyRequest, RationalNumberType); next=250
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 250;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower, RationalNumberType); next=251
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 251;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L2, RationalNumberType); next=252
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 252;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L3, RationalNumberType); next=253
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 253;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=254
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 254;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L2, RationalNumberType); next=255
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 255;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=256
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 256;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=257
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 257;
                    }
                }
            }
            break;
        case 250:
            // Grammar: ID=250; read/write bits=3; START (EVMaximumChargePower), START (EVMaximumChargePower_L2), START (EVMaximumChargePower_L3), START (EVMinimumChargePower), START (EVMinimumChargePower_L2), START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower, RationalNumberType); next=251
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 251;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L2, RationalNumberType); next=252
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 252;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L3, RationalNumberType); next=253
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 253;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=254
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 254;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L2, RationalNumberType); next=255
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 255;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=256
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 256;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=257
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 257;
                    }
                }
            }
            break;
        case 251:
            // Grammar: ID=251; read/write bits=3; START (EVMaximumChargePower_L2), START (EVMaximumChargePower_L3), START (EVMinimumChargePower), START (EVMinimumChargePower_L2), START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L2, RationalNumberType); next=252
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 252;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L3, RationalNumberType); next=253
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 253;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=254
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 254;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L2, RationalNumberType); next=255
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 255;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=256
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 256;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=257
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 257;
                    }
                }
            }
            break;
        case 252:
            // Grammar: ID=252; read/write bits=3; START (EVMaximumChargePower_L3), START (EVMinimumChargePower), START (EVMinimumChargePower_L2), START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L3, RationalNumberType); next=253
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 253;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=254
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 254;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L2, RationalNumberType); next=255
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 255;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=256
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 256;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=257
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 257;
                    }
                }
            }
            break;
        case 253:
            // Grammar: ID=253; read/write bits=3; START (EVMinimumChargePower), START (EVMinimumChargePower_L2), START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=254
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 254;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L2, RationalNumberType); next=255
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 255;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=256
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 256;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=257
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 257;
                    }
                }
            }
            break;
        case 254:
            // Grammar: ID=254; read/write bits=2; START (EVMinimumChargePower_L2), START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L2, RationalNumberType); next=255
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 255;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=256
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 256;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=257
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 257;
                    }
                }
            }
            break;
        case 255:
            // Grammar: ID=255; read/write bits=2; START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=256
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 256;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=257
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 257;
                    }
                }
            }
            break;
        case 256:
            // Grammar: ID=256; read/write bits=1; START (EVPresentActivePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=257
                error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentActivePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 257;
                }
            }
            break;
        case 257:
            // Grammar: ID=257; read/write bits=4; START (EVPresentActivePower_L2), START (EVPresentActivePower_L3), START (EVPresentReactivePower), START (EVPresentReactivePower_L2), START (EVPresentReactivePower_L3), START (EVMaximumDischargePower), START (EVMaximumDischargePower_L2), START (EVMaximumDischargePower_L3), START (EVMinimumDischargePower), START (EVMinimumDischargePower_L2), START (EVMinimumDischargePower_L3), END Element
            if (BPT_Scheduled_AC_CLReqControlModeType->EVPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower_L2, RationalNumberType); next=258
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 258;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower_L3, RationalNumberType); next=259
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 259;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower, RationalNumberType); next=260
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 260;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L2, RationalNumberType); next=261
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 261;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L3, RationalNumberType); next=262
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 262;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower, RationalNumberType); next=263
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 263;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L2, RationalNumberType); next=264
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 264;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L3, RationalNumberType); next=265
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 265;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 8);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower, RationalNumberType); next=266
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 266;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 9);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L2, RationalNumberType); next=267
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 267;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 10);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 11);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 258:
            // Grammar: ID=258; read/write bits=4; START (EVPresentActivePower_L3), START (EVPresentReactivePower), START (EVPresentReactivePower_L2), START (EVPresentReactivePower_L3), START (EVMaximumDischargePower), START (EVMaximumDischargePower_L2), START (EVMaximumDischargePower_L3), START (EVMinimumDischargePower), START (EVMinimumDischargePower_L2), START (EVMinimumDischargePower_L3), END Element
            if (BPT_Scheduled_AC_CLReqControlModeType->EVPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower_L3, RationalNumberType); next=259
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 259;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower, RationalNumberType); next=260
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 260;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L2, RationalNumberType); next=261
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 261;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L3, RationalNumberType); next=262
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 262;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower, RationalNumberType); next=263
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 263;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L2, RationalNumberType); next=264
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 264;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L3, RationalNumberType); next=265
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 265;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower, RationalNumberType); next=266
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 266;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 8);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L2, RationalNumberType); next=267
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 267;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 9);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 10);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 259:
            // Grammar: ID=259; read/write bits=4; START (EVPresentReactivePower), START (EVPresentReactivePower_L2), START (EVPresentReactivePower_L3), START (EVMaximumDischargePower), START (EVMaximumDischargePower_L2), START (EVMaximumDischargePower_L3), START (EVMinimumDischargePower), START (EVMinimumDischargePower_L2), START (EVMinimumDischargePower_L3), END Element
            if (BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower, RationalNumberType); next=260
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 260;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L2, RationalNumberType); next=261
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 261;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L3, RationalNumberType); next=262
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 262;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower, RationalNumberType); next=263
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 263;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L2, RationalNumberType); next=264
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 264;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L3, RationalNumberType); next=265
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 265;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower, RationalNumberType); next=266
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 266;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L2, RationalNumberType); next=267
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 267;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 8);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 9);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 260:
            // Grammar: ID=260; read/write bits=4; START (EVPresentReactivePower_L2), START (EVPresentReactivePower_L3), START (EVMaximumDischargePower), START (EVMaximumDischargePower_L2), START (EVMaximumDischargePower_L3), START (EVMinimumDischargePower), START (EVMinimumDischargePower_L2), START (EVMinimumDischargePower_L3), END Element
            if (BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L2, RationalNumberType); next=261
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 261;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L3, RationalNumberType); next=262
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 262;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower, RationalNumberType); next=263
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 263;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L2, RationalNumberType); next=264
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 264;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L3, RationalNumberType); next=265
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 265;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower, RationalNumberType); next=266
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 266;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L2, RationalNumberType); next=267
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 267;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 8);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 261:
            // Grammar: ID=261; read/write bits=4; START (EVPresentReactivePower_L3), START (EVMaximumDischargePower), START (EVMaximumDischargePower_L2), START (EVMaximumDischargePower_L3), START (EVMinimumDischargePower), START (EVMinimumDischargePower_L2), START (EVMinimumDischargePower_L3), END Element
            if (BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L3, RationalNumberType); next=262
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVPresentReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 262;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower, RationalNumberType); next=263
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 263;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L2, RationalNumberType); next=264
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 264;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L3, RationalNumberType); next=265
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 265;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower, RationalNumberType); next=266
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 266;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L2, RationalNumberType); next=267
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 267;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 262:
            // Grammar: ID=262; read/write bits=3; START (EVMaximumDischargePower), START (EVMaximumDischargePower_L2), START (EVMaximumDischargePower_L3), START (EVMinimumDischargePower), START (EVMinimumDischargePower_L2), START (EVMinimumDischargePower_L3), END Element
            if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower, RationalNumberType); next=263
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 263;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L2, RationalNumberType); next=264
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 264;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L3, RationalNumberType); next=265
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 265;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower, RationalNumberType); next=266
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 266;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L2, RationalNumberType); next=267
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 267;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 263:
            // Grammar: ID=263; read/write bits=3; START (EVMaximumDischargePower_L2), START (EVMaximumDischargePower_L3), START (EVMinimumDischargePower), START (EVMinimumDischargePower_L2), START (EVMinimumDischargePower_L3), END Element
            if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L2, RationalNumberType); next=264
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 264;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L3, RationalNumberType); next=265
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 265;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower, RationalNumberType); next=266
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 266;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L2, RationalNumberType); next=267
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 267;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 264:
            // Grammar: ID=264; read/write bits=3; START (EVMaximumDischargePower_L3), START (EVMinimumDischargePower), START (EVMinimumDischargePower_L2), START (EVMinimumDischargePower_L3), END Element
            if (BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L3, RationalNumberType); next=265
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMaximumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 265;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower, RationalNumberType); next=266
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 266;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L2, RationalNumberType); next=267
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 267;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 265:
            // Grammar: ID=265; read/write bits=3; START (EVMinimumDischargePower), START (EVMinimumDischargePower_L2), START (EVMinimumDischargePower_L3), END Element
            if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower, RationalNumberType); next=266
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 266;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L2, RationalNumberType); next=267
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 267;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 266:
            // Grammar: ID=266; read/write bits=2; START (EVMinimumDischargePower_L2), START (EVMinimumDischargePower_L3), END Element
            if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L2, RationalNumberType); next=267
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 267;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 267:
            // Grammar: ID=267; read/write bits=2; START (EVMinimumDischargePower_L3), END Element
            if (BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLReqControlModeType->EVMinimumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}BPT_Scheduled_AC_CLResControlMode; type={urn:iso:std:iso:15118:-20:AC}BPT_Scheduled_AC_CLResControlModeType; base type=Scheduled_AC_CLResControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVSETargetActivePower, RationalNumberType (0, 1); EVSETargetActivePower_L2, RationalNumberType (0, 1); EVSETargetActivePower_L3, RationalNumberType (0, 1); EVSETargetReactivePower, RationalNumberType (0, 1); EVSETargetReactivePower_L2, RationalNumberType (0, 1); EVSETargetReactivePower_L3, RationalNumberType (0, 1); EVSEPresentActivePower, RationalNumberType (0, 1); EVSEPresentActivePower_L2, RationalNumberType (0, 1); EVSEPresentActivePower_L3, RationalNumberType (0, 1);
static int encode_iso20_ac_BPT_Scheduled_AC_CLResControlModeType(exi_bitstream_t* stream, struct iso20_ac_BPT_Scheduled_AC_CLResControlModeType* BPT_Scheduled_AC_CLResControlModeType) {
    int grammar_id = 268;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 268:
            // Grammar: ID=268; read/write bits=4; START (EVSETargetActivePower), START (EVSETargetActivePower_L2), START (EVSETargetActivePower_L3), START (EVSETargetReactivePower), START (EVSETargetReactivePower_L2), START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower, RationalNumberType); next=269
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 269;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower_L2, RationalNumberType); next=270
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 270;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower_L3, RationalNumberType); next=271
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 271;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower, RationalNumberType); next=272
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 272;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L2, RationalNumberType); next=273
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 273;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=274
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 274;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=275
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 275;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=276
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 276;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 8);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 9);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 269:
            // Grammar: ID=269; read/write bits=4; START (EVSETargetActivePower_L2), START (EVSETargetActivePower_L3), START (EVSETargetReactivePower), START (EVSETargetReactivePower_L2), START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower_L2, RationalNumberType); next=270
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 270;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower_L3, RationalNumberType); next=271
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 271;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower, RationalNumberType); next=272
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 272;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L2, RationalNumberType); next=273
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 273;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=274
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 274;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=275
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 275;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=276
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 276;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 8);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 270:
            // Grammar: ID=270; read/write bits=4; START (EVSETargetActivePower_L3), START (EVSETargetReactivePower), START (EVSETargetReactivePower_L2), START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower_L3, RationalNumberType); next=271
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 271;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower, RationalNumberType); next=272
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 272;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L2, RationalNumberType); next=273
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 273;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=274
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 274;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=275
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 275;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=276
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 276;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 271:
            // Grammar: ID=271; read/write bits=3; START (EVSETargetReactivePower), START (EVSETargetReactivePower_L2), START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower, RationalNumberType); next=272
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 272;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L2, RationalNumberType); next=273
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 273;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=274
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 274;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=275
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 275;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=276
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 276;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 272:
            // Grammar: ID=272; read/write bits=3; START (EVSETargetReactivePower_L2), START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L2, RationalNumberType); next=273
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 273;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=274
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 274;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=275
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 275;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=276
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 276;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 273:
            // Grammar: ID=273; read/write bits=3; START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=274
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 274;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=275
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 275;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=276
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 276;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 274:
            // Grammar: ID=274; read/write bits=3; START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=275
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 275;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=276
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 276;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 275:
            // Grammar: ID=275; read/write bits=2; START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=276
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 276;
                    }
                }
            }
            else if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 276:
            // Grammar: ID=276; read/write bits=2; START (EVSEPresentActivePower_L3), END Element
            if (BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Scheduled_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}BPT_Dynamic_AC_CLReqControlMode; type={urn:iso:std:iso:15118:-20:AC}BPT_Dynamic_AC_CLReqControlModeType; base type=Dynamic_AC_CLReqControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DepartureTime, unsignedInt (0, 1); EVTargetEnergyRequest, RationalNumberType (1, 1); EVMaximumEnergyRequest, RationalNumberType (1, 1); EVMinimumEnergyRequest, RationalNumberType (1, 1); EVMaximumChargePower, RationalNumberType (1, 1); EVMaximumChargePower_L2, RationalNumberType (0, 1); EVMaximumChargePower_L3, RationalNumberType (0, 1); EVMinimumChargePower, RationalNumberType (1, 1); EVMinimumChargePower_L2, RationalNumberType (0, 1); EVMinimumChargePower_L3, RationalNumberType (0, 1); EVPresentActivePower, RationalNumberType (1, 1); EVPresentActivePower_L2, RationalNumberType (0, 1); EVPresentActivePower_L3, RationalNumberType (0, 1); EVPresentReactivePower, RationalNumberType (1, 1); EVPresentReactivePower_L2, RationalNumberType (0, 1); EVPresentReactivePower_L3, RationalNumberType (0, 1); EVMaximumDischargePower, RationalNumberType (1, 1); EVMaximumDischargePower_L2, RationalNumberType (0, 1); EVMaximumDischargePower_L3, RationalNumberType (0, 1); EVMinimumDischargePower, RationalNumberType (1, 1); EVMinimumDischargePower_L2, RationalNumberType (0, 1); EVMinimumDischargePower_L3, RationalNumberType (0, 1); EVMaximumV2XEnergyRequest, RationalNumberType (0, 1); EVMinimumV2XEnergyRequest, RationalNumberType (0, 1);
static int encode_iso20_ac_BPT_Dynamic_AC_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_ac_BPT_Dynamic_AC_CLReqControlModeType* BPT_Dynamic_AC_CLReqControlModeType) {
    int grammar_id = 277;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 277:
            // Grammar: ID=277; read/write bits=2; START (DepartureTime), START (EVTargetEnergyRequest)
            if (BPT_Dynamic_AC_CLReqControlModeType->DepartureTime_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (DepartureTime, unsignedLong); next=278
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, BPT_Dynamic_AC_CLReqControlModeType->DepartureTime);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 278;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVTargetEnergyRequest, RationalNumberType); next=279
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVTargetEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 279;
                    }
                }
            }
            break;
        case 278:
            // Grammar: ID=278; read/write bits=1; START (EVTargetEnergyRequest)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=279
                error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVTargetEnergyRequest);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 279;
                }
            }
            break;
        case 279:
            // Grammar: ID=279; read/write bits=1; START (EVMaximumEnergyRequest)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=280
                error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMaximumEnergyRequest);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 280;
                }
            }
            break;
        case 280:
            // Grammar: ID=280; read/write bits=1; START (EVMinimumEnergyRequest)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=281
                error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMinimumEnergyRequest);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 281;
                }
            }
            break;
        case 281:
            // Grammar: ID=281; read/write bits=1; START (EVMaximumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=282
                error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMaximumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 282;
                }
            }
            break;
        case 282:
            // Grammar: ID=282; read/write bits=2; START (EVMaximumChargePower_L2), START (EVMaximumChargePower_L3), START (EVMinimumChargePower)
            if (BPT_Dynamic_AC_CLReqControlModeType->EVMaximumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L2, RationalNumberType); next=283
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMaximumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 283;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L3, RationalNumberType); next=284
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 284;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=285
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 285;
                    }
                }
            }
            break;
        case 283:
            // Grammar: ID=283; read/write bits=2; START (EVMaximumChargePower_L3), START (EVMinimumChargePower)
            if (BPT_Dynamic_AC_CLReqControlModeType->EVMaximumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower_L3, RationalNumberType); next=284
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMaximumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 284;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=285
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 285;
                    }
                }
            }
            break;
        case 284:
            // Grammar: ID=284; read/write bits=1; START (EVMinimumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=285
                error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMinimumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 285;
                }
            }
            break;
        case 285:
            // Grammar: ID=285; read/write bits=2; START (EVMinimumChargePower_L2), START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (BPT_Dynamic_AC_CLReqControlModeType->EVMinimumChargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L2, RationalNumberType); next=286
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMinimumChargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 286;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=287
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 287;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=288
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 288;
                    }
                }
            }
            break;
        case 286:
            // Grammar: ID=286; read/write bits=2; START (EVMinimumChargePower_L3), START (EVPresentActivePower)
            if (BPT_Dynamic_AC_CLReqControlModeType->EVMinimumChargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower_L3, RationalNumberType); next=287
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMinimumChargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 287;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower, RationalNumberType); next=288
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 288;
                    }
                }
            }
            break;
        case 287:
            // Grammar: ID=287; read/write bits=1; START (EVPresentActivePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=288
                error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVPresentActivePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 288;
                }
            }
            break;
        case 288:
            // Grammar: ID=288; read/write bits=2; START (EVPresentActivePower_L2), START (EVPresentActivePower_L3), START (EVPresentReactivePower)
            if (BPT_Dynamic_AC_CLReqControlModeType->EVPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower_L2, RationalNumberType); next=289
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 289;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLReqControlModeType->EVPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower_L3, RationalNumberType); next=290
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 290;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower, RationalNumberType); next=291
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVPresentReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 291;
                    }
                }
            }
            break;
        case 289:
            // Grammar: ID=289; read/write bits=2; START (EVPresentActivePower_L3), START (EVPresentReactivePower)
            if (BPT_Dynamic_AC_CLReqControlModeType->EVPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentActivePower_L3, RationalNumberType); next=290
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 290;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower, RationalNumberType); next=291
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVPresentReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 291;
                    }
                }
            }
            break;
        case 290:
            // Grammar: ID=290; read/write bits=1; START (EVPresentReactivePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=291
                error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVPresentReactivePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 291;
                }
            }
            break;
        case 291:
            // Grammar: ID=291; read/write bits=2; START (EVPresentReactivePower_L2), START (EVPresentReactivePower_L3), START (EVMaximumDischargePower)
            if (BPT_Dynamic_AC_CLReqControlModeType->EVPresentReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L2, RationalNumberType); next=292
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVPresentReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 292;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLReqControlModeType->EVPresentReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L3, RationalNumberType); next=293
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVPresentReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 293;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower, RationalNumberType); next=294
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 294;
                    }
                }
            }
            break;
        case 292:
            // Grammar: ID=292; read/write bits=2; START (EVPresentReactivePower_L3), START (EVMaximumDischargePower)
            if (BPT_Dynamic_AC_CLReqControlModeType->EVPresentReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVPresentReactivePower_L3, RationalNumberType); next=293
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVPresentReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 293;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower, RationalNumberType); next=294
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 294;
                    }
                }
            }
            break;
        case 293:
            // Grammar: ID=293; read/write bits=1; START (EVMaximumDischargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=294
                error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMaximumDischargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 294;
                }
            }
            break;
        case 294:
            // Grammar: ID=294; read/write bits=2; START (EVMaximumDischargePower_L2), START (EVMaximumDischargePower_L3), START (EVMinimumDischargePower)
            if (BPT_Dynamic_AC_CLReqControlModeType->EVMaximumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L2, RationalNumberType); next=295
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMaximumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 295;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLReqControlModeType->EVMaximumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L3, RationalNumberType); next=296
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMaximumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 296;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower, RationalNumberType); next=297
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 297;
                    }
                }
            }
            break;
        case 295:
            // Grammar: ID=295; read/write bits=2; START (EVMaximumDischargePower_L3), START (EVMinimumDischargePower)
            if (BPT_Dynamic_AC_CLReqControlModeType->EVMaximumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower_L3, RationalNumberType); next=296
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMaximumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 296;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower, RationalNumberType); next=297
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 297;
                    }
                }
            }
            break;
        case 296:
            // Grammar: ID=296; read/write bits=1; START (EVMinimumDischargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=297
                error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMinimumDischargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 297;
                }
            }
            break;
        case 297:
            // Grammar: ID=297; read/write bits=3; START (EVMinimumDischargePower_L2), START (EVMinimumDischargePower_L3), START (EVMaximumV2XEnergyRequest), START (EVMinimumV2XEnergyRequest), END Element
            if (BPT_Dynamic_AC_CLReqControlModeType->EVMinimumDischargePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L2, RationalNumberType); next=298
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMinimumDischargePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 298;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLReqControlModeType->EVMinimumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L3, RationalNumberType); next=299
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMinimumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 299;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLReqControlModeType->EVMaximumV2XEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumV2XEnergyRequest, RationalNumberType); next=300
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMaximumV2XEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 300;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLReqControlModeType->EVMinimumV2XEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumV2XEnergyRequest, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMinimumV2XEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 298:
            // Grammar: ID=298; read/write bits=3; START (EVMinimumDischargePower_L3), START (EVMaximumV2XEnergyRequest), START (EVMinimumV2XEnergyRequest), END Element
            if (BPT_Dynamic_AC_CLReqControlModeType->EVMinimumDischargePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower_L3, RationalNumberType); next=299
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMinimumDischargePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 299;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLReqControlModeType->EVMaximumV2XEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumV2XEnergyRequest, RationalNumberType); next=300
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMaximumV2XEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 300;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLReqControlModeType->EVMinimumV2XEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumV2XEnergyRequest, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMinimumV2XEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 299:
            // Grammar: ID=299; read/write bits=2; START (EVMaximumV2XEnergyRequest), START (EVMinimumV2XEnergyRequest), END Element
            if (BPT_Dynamic_AC_CLReqControlModeType->EVMaximumV2XEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumV2XEnergyRequest, RationalNumberType); next=300
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMaximumV2XEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 300;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLReqControlModeType->EVMinimumV2XEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumV2XEnergyRequest, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMinimumV2XEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 300:
            // Grammar: ID=300; read/write bits=2; START (EVMinimumV2XEnergyRequest), END Element
            if (BPT_Dynamic_AC_CLReqControlModeType->EVMinimumV2XEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumV2XEnergyRequest, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLReqControlModeType->EVMinimumV2XEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}AC_ChargeLoopReq; type={urn:iso:std:iso:15118:-20:AC}AC_ChargeLoopReqType; base type=ChargeLoopReqType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); DisplayParameters, DisplayParametersType (0, 1); MeterInfoRequested, boolean (1, 1); BPT_Dynamic_AC_CLReqControlMode, BPT_Dynamic_AC_CLReqControlModeType (0, 1); BPT_Scheduled_AC_CLReqControlMode, BPT_Scheduled_AC_CLReqControlModeType (0, 1); CLReqControlMode, CLReqControlModeType (0, 1); Dynamic_AC_CLReqControlMode, Dynamic_AC_CLReqControlModeType (0, 1); Scheduled_AC_CLReqControlMode, Scheduled_AC_CLReqControlModeType (0, 1);
static int encode_iso20_ac_AC_ChargeLoopReqType(exi_bitstream_t* stream, struct iso20_ac_AC_ChargeLoopReqType* AC_ChargeLoopReqType) {
    int grammar_id = 301;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 301:
            // Grammar: ID=301; read/write bits=1; START (Header)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (MessageHeaderType); next=302
                error = encode_iso20_ac_MessageHeaderType(stream, &AC_ChargeLoopReqType->Header);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 302;
                }
            }
            break;
        case 302:
            // Grammar: ID=302; read/write bits=2; START (DisplayParameters), START (MeterInfoRequested)
            if (AC_ChargeLoopReqType->DisplayParameters_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (DisplayParameters, DisplayParametersType); next=303
                    error = encode_iso20_ac_DisplayParametersType(stream, &AC_ChargeLoopReqType->DisplayParameters);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 303;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterInfoRequested, boolean); next=304
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bool(stream, AC_ChargeLoopReqType->MeterInfoRequested);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 304;
                            }
                        }
                    }
                }
            }
            break;
        case 303:
            // Grammar: ID=303; read/write bits=1; START (MeterInfoRequested)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (boolean); next=304
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_bool(stream, AC_ChargeLoopReqType->MeterInfoRequested);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 304;
                        }
                    }
                }
            }
            break;
        case 304:
            // Grammar: ID=304; read/write bits=3; START (BPT_Dynamic_AC_CLReqControlMode), START (BPT_Scheduled_AC_CLReqControlMode), START (CLReqControlMode), START (Dynamic_AC_CLReqControlMode), START (Scheduled_AC_CLReqControlMode)
            if (AC_ChargeLoopReqType->BPT_Dynamic_AC_CLReqControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_Dynamic_AC_CLReqControlMode, Dynamic_AC_CLReqControlModeType); next=305
                    error = encode_iso20_ac_BPT_Dynamic_AC_CLReqControlModeType(stream, &AC_ChargeLoopReqType->BPT_Dynamic_AC_CLReqControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 305;
                    }
                }
            }
            else if (AC_ChargeLoopReqType->BPT_Scheduled_AC_CLReqControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_Scheduled_AC_CLReqControlMode, Scheduled_AC_CLReqControlModeType); next=305
                    error = encode_iso20_ac_BPT_Scheduled_AC_CLReqControlModeType(stream, &AC_ChargeLoopReqType->BPT_Scheduled_AC_CLReqControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 305;
                    }
                }
            }
            else if (AC_ChargeLoopReqType->CLReqControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (CLReqControlMode, CLReqControlModeType); next=2
                    error = encode_iso20_ac_CLReqControlModeType(stream, &AC_ChargeLoopReqType->CLReqControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (AC_ChargeLoopReqType->Dynamic_AC_CLReqControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Dynamic_AC_CLReqControlMode, Dynamic_CLReqControlModeType); next=2
                    error = encode_iso20_ac_Dynamic_AC_CLReqControlModeType(stream, &AC_ChargeLoopReqType->Dynamic_AC_CLReqControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Scheduled_AC_CLReqControlMode, Scheduled_CLReqControlModeType); next=2
                    error = encode_iso20_ac_Scheduled_AC_CLReqControlModeType(stream, &AC_ChargeLoopReqType->Scheduled_AC_CLReqControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            break;
        case 305:
            // Grammar: ID=305; read/write bits=2; START (CLReqControlMode), START (Dynamic_AC_CLReqControlMode), START (Scheduled_AC_CLReqControlMode)
            if (AC_ChargeLoopReqType->CLReqControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (CLReqControlMode, CLReqControlModeType); next=2
                    error = encode_iso20_ac_CLReqControlModeType(stream, &AC_ChargeLoopReqType->CLReqControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (AC_ChargeLoopReqType->Dynamic_AC_CLReqControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Dynamic_AC_CLReqControlMode, Dynamic_CLReqControlModeType); next=2
                    error = encode_iso20_ac_Dynamic_AC_CLReqControlModeType(stream, &AC_ChargeLoopReqType->Dynamic_AC_CLReqControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Scheduled_AC_CLReqControlMode, Scheduled_CLReqControlModeType); next=2
                    error = encode_iso20_ac_Scheduled_AC_CLReqControlModeType(stream, &AC_ChargeLoopReqType->Scheduled_AC_CLReqControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}BPT_Dynamic_AC_CLResControlMode; type={urn:iso:std:iso:15118:-20:AC}BPT_Dynamic_AC_CLResControlModeType; base type=Dynamic_AC_CLResControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DepartureTime, unsignedInt (0, 1); MinimumSOC, percentValueType (0, 1); TargetSOC, percentValueType (0, 1); AckMaxDelay, unsignedShort (0, 1); EVSETargetActivePower, RationalNumberType (1, 1); EVSETargetActivePower_L2, RationalNumberType (0, 1); EVSETargetActivePower_L3, RationalNumberType (0, 1); EVSETargetReactivePower, RationalNumberType (0, 1); EVSETargetReactivePower_L2, RationalNumberType (0, 1); EVSETargetReactivePower_L3, RationalNumberType (0, 1); EVSEPresentActivePower, RationalNumberType (0, 1); EVSEPresentActivePower_L2, RationalNumberType (0, 1); EVSEPresentActivePower_L3, RationalNumberType (0, 1);
static int encode_iso20_ac_BPT_Dynamic_AC_CLResControlModeType(exi_bitstream_t* stream, struct iso20_ac_BPT_Dynamic_AC_CLResControlModeType* BPT_Dynamic_AC_CLResControlModeType) {
    int grammar_id = 306;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 306:
            // Grammar: ID=306; read/write bits=3; START (DepartureTime), START (MinimumSOC), START (TargetSOC), START (AckMaxDelay), START (EVSETargetActivePower)
            if (BPT_Dynamic_AC_CLResControlModeType->DepartureTime_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (DepartureTime, unsignedLong); next=307
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, BPT_Dynamic_AC_CLResControlModeType->DepartureTime);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 307;
                            }
                        }
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->MinimumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MinimumSOC, byte); next=308
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)BPT_Dynamic_AC_CLResControlModeType->MinimumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 308;
                            }
                        }
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->TargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (TargetSOC, byte); next=309
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)BPT_Dynamic_AC_CLResControlModeType->TargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 309;
                            }
                        }
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->AckMaxDelay_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AckMaxDelay, unsignedInt); next=310
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, BPT_Dynamic_AC_CLResControlModeType->AckMaxDelay);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 310;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower, RationalNumberType); next=311
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSETargetActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 311;
                    }
                }
            }
            break;
        case 307:
            // Grammar: ID=307; read/write bits=3; START (MinimumSOC), START (TargetSOC), START (AckMaxDelay), START (EVSETargetActivePower)
            if (BPT_Dynamic_AC_CLResControlModeType->MinimumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MinimumSOC, byte); next=308
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)BPT_Dynamic_AC_CLResControlModeType->MinimumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 308;
                            }
                        }
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->TargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (TargetSOC, byte); next=309
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)BPT_Dynamic_AC_CLResControlModeType->TargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 309;
                            }
                        }
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->AckMaxDelay_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AckMaxDelay, unsignedInt); next=310
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, BPT_Dynamic_AC_CLResControlModeType->AckMaxDelay);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 310;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower, RationalNumberType); next=311
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSETargetActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 311;
                    }
                }
            }
            break;
        case 308:
            // Grammar: ID=308; read/write bits=2; START (TargetSOC), START (AckMaxDelay), START (EVSETargetActivePower)
            if (BPT_Dynamic_AC_CLResControlModeType->TargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (TargetSOC, byte); next=309
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)BPT_Dynamic_AC_CLResControlModeType->TargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 309;
                            }
                        }
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->AckMaxDelay_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AckMaxDelay, unsignedInt); next=310
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, BPT_Dynamic_AC_CLResControlModeType->AckMaxDelay);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 310;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower, RationalNumberType); next=311
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSETargetActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 311;
                    }
                }
            }
            break;
        case 309:
            // Grammar: ID=309; read/write bits=2; START (AckMaxDelay), START (EVSETargetActivePower)
            if (BPT_Dynamic_AC_CLResControlModeType->AckMaxDelay_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AckMaxDelay, unsignedInt); next=310
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, BPT_Dynamic_AC_CLResControlModeType->AckMaxDelay);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 310;
                            }
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower, RationalNumberType); next=311
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSETargetActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 311;
                    }
                }
            }
            break;
        case 310:
            // Grammar: ID=310; read/write bits=1; START (EVSETargetActivePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=311
                error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSETargetActivePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 311;
                }
            }
            break;
        case 311:
            // Grammar: ID=311; read/write bits=4; START (EVSETargetActivePower_L2), START (EVSETargetActivePower_L3), START (EVSETargetReactivePower), START (EVSETargetReactivePower_L2), START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (BPT_Dynamic_AC_CLResControlModeType->EVSETargetActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower_L2, RationalNumberType); next=312
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSETargetActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 312;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSETargetActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower_L3, RationalNumberType); next=313
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSETargetActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 313;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower, RationalNumberType); next=314
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 314;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L2, RationalNumberType); next=315
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 315;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=316
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 316;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=317
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 317;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=318
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 318;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 8);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 312:
            // Grammar: ID=312; read/write bits=4; START (EVSETargetActivePower_L3), START (EVSETargetReactivePower), START (EVSETargetReactivePower_L2), START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (BPT_Dynamic_AC_CLResControlModeType->EVSETargetActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetActivePower_L3, RationalNumberType); next=313
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSETargetActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 313;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower, RationalNumberType); next=314
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 314;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L2, RationalNumberType); next=315
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 315;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=316
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 316;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=317
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 317;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=318
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 318;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 313:
            // Grammar: ID=313; read/write bits=3; START (EVSETargetReactivePower), START (EVSETargetReactivePower_L2), START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower, RationalNumberType); next=314
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 314;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L2, RationalNumberType); next=315
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 315;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=316
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 316;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=317
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 317;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=318
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 318;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 314:
            // Grammar: ID=314; read/write bits=3; START (EVSETargetReactivePower_L2), START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L2, RationalNumberType); next=315
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 315;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=316
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 316;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=317
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 317;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=318
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 318;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 315:
            // Grammar: ID=315; read/write bits=3; START (EVSETargetReactivePower_L3), START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetReactivePower_L3, RationalNumberType); next=316
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSETargetReactivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 316;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=317
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 317;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=318
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 318;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 316:
            // Grammar: ID=316; read/write bits=3; START (EVSEPresentActivePower), START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower, RationalNumberType); next=317
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 317;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=318
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 318;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 317:
            // Grammar: ID=317; read/write bits=2; START (EVSEPresentActivePower_L2), START (EVSEPresentActivePower_L3), END Element
            if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L2, RationalNumberType); next=318
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L2);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 318;
                    }
                }
            }
            else if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 318:
            // Grammar: ID=318; read/write bits=2; START (EVSEPresentActivePower_L3), END Element
            if (BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentActivePower_L3, RationalNumberType); next=2
                    error = encode_iso20_ac_RationalNumberType(stream, &BPT_Dynamic_AC_CLResControlModeType->EVSEPresentActivePower_L3);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:AC}AC_ChargeLoopRes; type={urn:iso:std:iso:15118:-20:AC}AC_ChargeLoopResType; base type=ChargeLoopResType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); EVSEStatus, EVSEStatusType (0, 1); MeterInfo, MeterInfoType (0, 1); Receipt, ReceiptType (0, 1); EVSETargetFrequency, RationalNumberType (0, 1); BPT_Dynamic_AC_CLResControlMode, BPT_Dynamic_AC_CLResControlModeType (0, 1); BPT_Scheduled_AC_CLResControlMode, BPT_Scheduled_AC_CLResControlModeType (0, 1); CLResControlMode, CLResControlModeType (0, 1); Dynamic_AC_CLResControlMode, Dynamic_AC_CLResControlModeType (0, 1); Scheduled_AC_CLResControlMode, Scheduled_AC_CLResControlModeType (0, 1);
static int encode_iso20_ac_AC_ChargeLoopResType(exi_bitstream_t* stream, struct iso20_ac_AC_ChargeLoopResType* AC_ChargeLoopResType) {
    int grammar_id = 319;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 319:
            // Grammar: ID=319; read/write bits=1; START (Header)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (MessageHeaderType); next=320
                error = encode_iso20_ac_MessageHeaderType(stream, &AC_ChargeLoopResType->Header);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 320;
                }
            }
            break;
        case 320:
            // Grammar: ID=320; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (string); next=321
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_nbit_uint(stream, 6, AC_ChargeLoopResType->ResponseCode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 321;
                        }
                    }
                }
            }
            break;
        case 321:
            // Grammar: ID=321; read/write bits=4; START (EVSEStatus), START (MeterInfo), START (Receipt), START (EVSETargetFrequency), START (BPT_Dynamic_AC_CLResControlMode), START (BPT_Scheduled_AC_CLResControlMode), START (CLResControlMode), START (Dynamic_AC_CLResControlMode), START (Scheduled_AC_CLResControlMode)
            if (AC_ChargeLoopResType->EVSEStatus_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEStatus, EVSEStatusType); next=322
                    error = encode_iso20_ac_EVSEStatusType(stream, &AC_ChargeLoopResType->EVSEStatus);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 322;
                    }
                }
            }
            else if (AC_ChargeLoopResType->MeterInfo_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterInfo, MeterInfoType); next=323
                    error = encode_iso20_ac_MeterInfoType(stream, &AC_ChargeLoopResType->MeterInfo);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 323;
                    }
                }
            }
            else if (AC_ChargeLoopResType->Receipt_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Receipt, ReceiptType); next=324
                    error = encode_iso20_ac_ReceiptType(stream, &AC_ChargeLoopResType->Receipt);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 324;
                    }
                }
            }
            else if (AC_ChargeLoopResType->EVSETargetFrequency_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetFrequency, RationalNumberType); next=325
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_ChargeLoopResType->EVSETargetFrequency);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 325;
                    }
                }
            }
            else if (AC_ChargeLoopResType->BPT_Dynamic_AC_CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_Dynamic_AC_CLResControlMode, Dynamic_AC_CLResControlModeType); next=326
                    error = encode_iso20_ac_BPT_Dynamic_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->BPT_Dynamic_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 326;
                    }
                }
            }
            else if (AC_ChargeLoopResType->BPT_Scheduled_AC_CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_Scheduled_AC_CLResControlMode, Scheduled_AC_CLResControlModeType); next=326
                    error = encode_iso20_ac_BPT_Scheduled_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->BPT_Scheduled_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 326;
                    }
                }
            }
            else if (AC_ChargeLoopResType->CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (CLResControlMode, CLResControlModeType); next=2
                    error = encode_iso20_ac_CLResControlModeType(stream, &AC_ChargeLoopResType->CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (AC_ChargeLoopResType->Dynamic_AC_CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Dynamic_AC_CLResControlMode, Dynamic_CLResControlModeType); next=2
                    error = encode_iso20_ac_Dynamic_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->Dynamic_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 8);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Scheduled_AC_CLResControlMode, Scheduled_CLResControlModeType); next=2
                    error = encode_iso20_ac_Scheduled_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->Scheduled_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            break;
        case 322:
            // Grammar: ID=322; read/write bits=4; START (MeterInfo), START (Receipt), START (EVSETargetFrequency), START (BPT_Dynamic_AC_CLResControlMode), START (BPT_Scheduled_AC_CLResControlMode), START (CLResControlMode), START (Dynamic_AC_CLResControlMode), START (Scheduled_AC_CLResControlMode)
            if (AC_ChargeLoopResType->MeterInfo_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterInfo, MeterInfoType); next=323
                    error = encode_iso20_ac_MeterInfoType(stream, &AC_ChargeLoopResType->MeterInfo);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 323;
                    }
                }
            }
            else if (AC_ChargeLoopResType->Receipt_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Receipt, ReceiptType); next=324
                    error = encode_iso20_ac_ReceiptType(stream, &AC_ChargeLoopResType->Receipt);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 324;
                    }
                }
            }
            else if (AC_ChargeLoopResType->EVSETargetFrequency_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetFrequency, RationalNumberType); next=325
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_ChargeLoopResType->EVSETargetFrequency);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 325;
                    }
                }
            }
            else if (AC_ChargeLoopResType->BPT_Dynamic_AC_CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_Dynamic_AC_CLResControlMode, Dynamic_AC_CLResControlModeType); next=326
                    error = encode_iso20_ac_BPT_Dynamic_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->BPT_Dynamic_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 326;
                    }
                }
            }
            else if (AC_ChargeLoopResType->BPT_Scheduled_AC_CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_Scheduled_AC_CLResControlMode, Scheduled_AC_CLResControlModeType); next=326
                    error = encode_iso20_ac_BPT_Scheduled_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->BPT_Scheduled_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 326;
                    }
                }
            }
            else if (AC_ChargeLoopResType->CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (CLResControlMode, CLResControlModeType); next=2
                    error = encode_iso20_ac_CLResControlModeType(stream, &AC_ChargeLoopResType->CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (AC_ChargeLoopResType->Dynamic_AC_CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Dynamic_AC_CLResControlMode, Dynamic_CLResControlModeType); next=2
                    error = encode_iso20_ac_Dynamic_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->Dynamic_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Scheduled_AC_CLResControlMode, Scheduled_CLResControlModeType); next=2
                    error = encode_iso20_ac_Scheduled_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->Scheduled_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            break;
        case 323:
            // Grammar: ID=323; read/write bits=3; START (Receipt), START (EVSETargetFrequency), START (BPT_Dynamic_AC_CLResControlMode), START (BPT_Scheduled_AC_CLResControlMode), START (CLResControlMode), START (Dynamic_AC_CLResControlMode), START (Scheduled_AC_CLResControlMode)
            if (AC_ChargeLoopResType->Receipt_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Receipt, ReceiptType); next=324
                    error = encode_iso20_ac_ReceiptType(stream, &AC_ChargeLoopResType->Receipt);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 324;
                    }
                }
            }
            else if (AC_ChargeLoopResType->EVSETargetFrequency_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetFrequency, RationalNumberType); next=325
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_ChargeLoopResType->EVSETargetFrequency);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 325;
                    }
                }
            }
            else if (AC_ChargeLoopResType->BPT_Dynamic_AC_CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_Dynamic_AC_CLResControlMode, Dynamic_AC_CLResControlModeType); next=326
                    error = encode_iso20_ac_BPT_Dynamic_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->BPT_Dynamic_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 326;
                    }
                }
            }
            else if (AC_ChargeLoopResType->BPT_Scheduled_AC_CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_Scheduled_AC_CLResControlMode, Scheduled_AC_CLResControlModeType); next=326
                    error = encode_iso20_ac_BPT_Scheduled_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->BPT_Scheduled_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 326;
                    }
                }
            }
            else if (AC_ChargeLoopResType->CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (CLResControlMode, CLResControlModeType); next=2
                    error = encode_iso20_ac_CLResControlModeType(stream, &AC_ChargeLoopResType->CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (AC_ChargeLoopResType->Dynamic_AC_CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Dynamic_AC_CLResControlMode, Dynamic_CLResControlModeType); next=2
                    error = encode_iso20_ac_Dynamic_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->Dynamic_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Scheduled_AC_CLResControlMode, Scheduled_CLResControlModeType); next=2
                    error = encode_iso20_ac_Scheduled_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->Scheduled_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            break;
        case 324:
            // Grammar: ID=324; read/write bits=3; START (EVSETargetFrequency), START (BPT_Dynamic_AC_CLResControlMode), START (BPT_Scheduled_AC_CLResControlMode), START (CLResControlMode), START (Dynamic_AC_CLResControlMode), START (Scheduled_AC_CLResControlMode)
            if (AC_ChargeLoopResType->EVSETargetFrequency_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSETargetFrequency, RationalNumberType); next=325
                    error = encode_iso20_ac_RationalNumberType(stream, &AC_ChargeLoopResType->EVSETargetFrequency);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 325;
                    }
                }
            }
            else if (AC_ChargeLoopResType->BPT_Dynamic_AC_CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_Dynamic_AC_CLResControlMode, Dynamic_AC_CLResControlModeType); next=326
                    error = encode_iso20_ac_BPT_Dynamic_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->BPT_Dynamic_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 326;
                    }
                }
            }
            else if (AC_ChargeLoopResType->BPT_Scheduled_AC_CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_Scheduled_AC_CLResControlMode, Scheduled_AC_CLResControlModeType); next=326
                    error = encode_iso20_ac_BPT_Scheduled_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->BPT_Scheduled_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 326;
                    }
                }
            }
            else if (AC_ChargeLoopResType->CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (CLResControlMode, CLResControlModeType); next=2
                    error = encode_iso20_ac_CLResControlModeType(stream, &AC_ChargeLoopResType->CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (AC_ChargeLoopResType->Dynamic_AC_CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Dynamic_AC_CLResControlMode, Dynamic_CLResControlModeType); next=2
                    error = encode_iso20_ac_Dynamic_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->Dynamic_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Scheduled_AC_CLResControlMode, Scheduled_CLResControlModeType); next=2
                    error = encode_iso20_ac_Scheduled_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->Scheduled_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            break;
        case 325:
            // Grammar: ID=325; read/write bits=3; START (BPT_Dynamic_AC_CLResControlMode), START (BPT_Scheduled_AC_CLResControlMode), START (CLResControlMode), START (Dynamic_AC_CLResControlMode), START (Scheduled_AC_CLResControlMode)
            if (AC_ChargeLoopResType->BPT_Dynamic_AC_CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_Dynamic_AC_CLResControlMode, Dynamic_AC_CLResControlModeType); next=326
                    error = encode_iso20_ac_BPT_Dynamic_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->BPT_Dynamic_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 326;
                    }
                }
            }
            else if (AC_ChargeLoopResType->BPT_Scheduled_AC_CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_Scheduled_AC_CLResControlMode, Scheduled_AC_CLResControlModeType); next=326
                    error = encode_iso20_ac_BPT_Scheduled_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->BPT_Scheduled_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 326;
                    }
                }
            }
            else if (AC_ChargeLoopResType->CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (CLResControlMode, CLResControlModeType); next=2
                    error = encode_iso20_ac_CLResControlModeType(stream, &AC_ChargeLoopResType->CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (AC_ChargeLoopResType->Dynamic_AC_CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Dynamic_AC_CLResControlMode, Dynamic_CLResControlModeType); next=2
                    error = encode_iso20_ac_Dynamic_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->Dynamic_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Scheduled_AC_CLResControlMode, Scheduled_CLResControlModeType); next=2
                    error = encode_iso20_ac_Scheduled_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->Scheduled_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            break;
        case 326:
            // Grammar: ID=326; read/write bits=2; START (CLResControlMode), START (Dynamic_AC_CLResControlMode), START (Scheduled_AC_CLResControlMode)
            if (AC_ChargeLoopResType->CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (CLResControlMode, CLResControlModeType); next=2
                    error = encode_iso20_ac_CLResControlModeType(stream, &AC_ChargeLoopResType->CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (AC_ChargeLoopResType->Dynamic_AC_CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Dynamic_AC_CLResControlMode, Dynamic_CLResControlModeType); next=2
                    error = encode_iso20_ac_Dynamic_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->Dynamic_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Scheduled_AC_CLResControlMode, Scheduled_CLResControlModeType); next=2
                    error = encode_iso20_ac_Scheduled_AC_CLResControlModeType(stream, &AC_ChargeLoopResType->Scheduled_AC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Manifest; type={http://www.w3.org/2000/09/xmldsig#}ManifestType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); Reference, ReferenceType (1, 1);
static int encode_iso20_ac_ManifestType(exi_bitstream_t* stream, struct iso20_ac_ManifestType* ManifestType) {
    int grammar_id = 327;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 327:
            // Grammar: ID=327; read/write bits=2; START (Id), START (Reference)
            if (ManifestType->Id_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Id, NCName); next=328

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(ManifestType->Id.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, ManifestType->Id.charactersLen, ManifestType->Id.characters, iso20_ac_Id_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 328;
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Reference, ReferenceType); next=2
                    error = encode_iso20_ac_ReferenceType(stream, &ManifestType->Reference);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            break;
        case 328:
            // Grammar: ID=328; read/write bits=1; START (Reference)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (ReferenceType); next=2
                error = encode_iso20_ac_ReferenceType(stream, &ManifestType->Reference);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 2;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}SignatureProperties; type={http://www.w3.org/2000/09/xmldsig#}SignaturePropertiesType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); SignatureProperty, SignaturePropertyType (1, 1);
static int encode_iso20_ac_SignaturePropertiesType(exi_bitstream_t* stream, struct iso20_ac_SignaturePropertiesType* SignaturePropertiesType) {
    int grammar_id = 329;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 329:
            // Grammar: ID=329; read/write bits=2; START (Id), START (SignatureProperty)
            if (SignaturePropertiesType->Id_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Id, NCName); next=330

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(SignaturePropertiesType->Id.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, SignaturePropertiesType->Id.charactersLen, SignaturePropertiesType->Id.characters, iso20_ac_Id_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 330;
                        }
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (SignatureProperty, SignaturePropertyType); next=2
                    error = encode_iso20_ac_SignaturePropertyType(stream, &SignaturePropertiesType->SignatureProperty);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            break;
        case 330:
            // Grammar: ID=330; read/write bits=1; START (SignatureProperty)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (SignaturePropertyType); next=2
                error = encode_iso20_ac_SignaturePropertyType(stream, &SignaturePropertiesType->SignatureProperty);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 2;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: END Element; set next=3
                done = 1;
                grammar_id = 3;
            }
            break;
        default:
            error = EXI_ERROR__UNKNOWN_GRAMMAR_ID;
            break;
        }

        if (error)
        {
            done = 1;
        }
    }
    return error;
}


// main function for encoding
int encode_iso20_ac_exiDocument(exi_bitstream_t* stream, struct iso20_ac_exiDocument* exiDoc)
{
    int error = exi_header_write(stream);

    if (error == EXI_ERROR__NO_ERROR)
    {
        if (exiDoc->AC_CPDReqEnergyTransferMode_isUsed == 1)
        {
            // encode event 0
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_AC_CPDReqEnergyTransferModeType(stream, &exiDoc->AC_CPDReqEnergyTransferMode);
            }
        }
        else if (exiDoc->AC_CPDResEnergyTransferMode_isUsed == 1)
        {
            // encode event 1
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 1);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_AC_CPDResEnergyTransferModeType(stream, &exiDoc->AC_CPDResEnergyTransferMode);
            }
        }
        else if (exiDoc->AC_ChargeLoopReq_isUsed == 1)
        {
            // encode event 2
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 2);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_AC_ChargeLoopReqType(stream, &exiDoc->AC_ChargeLoopReq);
            }
        }
        else if (exiDoc->AC_ChargeLoopRes_isUsed == 1)
        {
            // encode event 3
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 3);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_AC_ChargeLoopResType(stream, &exiDoc->AC_ChargeLoopRes);
            }
        }
        else if (exiDoc->AC_ChargeParameterDiscoveryReq_isUsed == 1)
        {
            // encode event 4
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 4);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_AC_ChargeParameterDiscoveryReqType(stream, &exiDoc->AC_ChargeParameterDiscoveryReq);
            }
        }
        else if (exiDoc->AC_ChargeParameterDiscoveryRes_isUsed == 1)
        {
            // encode event 5
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 5);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_AC_ChargeParameterDiscoveryResType(stream, &exiDoc->AC_ChargeParameterDiscoveryRes);
            }
        }
        else if (exiDoc->BPT_AC_CPDReqEnergyTransferMode_isUsed == 1)
        {
            // encode event 6
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 6);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_BPT_AC_CPDReqEnergyTransferModeType(stream, &exiDoc->BPT_AC_CPDReqEnergyTransferMode);
            }
        }
        else if (exiDoc->BPT_AC_CPDResEnergyTransferMode_isUsed == 1)
        {
            // encode event 7
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 7);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_BPT_AC_CPDResEnergyTransferModeType(stream, &exiDoc->BPT_AC_CPDResEnergyTransferMode);
            }
        }
        else if (exiDoc->BPT_Dynamic_AC_CLReqControlMode_isUsed == 1)
        {
            // encode event 8
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 8);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_BPT_Dynamic_AC_CLReqControlModeType(stream, &exiDoc->BPT_Dynamic_AC_CLReqControlMode);
            }
        }
        else if (exiDoc->BPT_Dynamic_AC_CLResControlMode_isUsed == 1)
        {
            // encode event 9
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 9);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_BPT_Dynamic_AC_CLResControlModeType(stream, &exiDoc->BPT_Dynamic_AC_CLResControlMode);
            }
        }
        else if (exiDoc->BPT_Scheduled_AC_CLReqControlMode_isUsed == 1)
        {
            // encode event 10
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 10);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_BPT_Scheduled_AC_CLReqControlModeType(stream, &exiDoc->BPT_Scheduled_AC_CLReqControlMode);
            }
        }
        else if (exiDoc->BPT_Scheduled_AC_CLResControlMode_isUsed == 1)
        {
            // encode event 11
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 11);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_BPT_Scheduled_AC_CLResControlModeType(stream, &exiDoc->BPT_Scheduled_AC_CLResControlMode);
            }
        }
        else if (exiDoc->CLReqControlMode_isUsed == 1)
        {
            // encode event 12
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 12);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_CLReqControlModeType(stream, &exiDoc->CLReqControlMode);
            }
        }
        else if (exiDoc->CLResControlMode_isUsed == 1)
        {
            // encode event 13
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 13);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_CLResControlModeType(stream, &exiDoc->CLResControlMode);
            }
        }
        else if (exiDoc->CanonicalizationMethod_isUsed == 1)
        {
            // encode event 14
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 14);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_CanonicalizationMethodType(stream, &exiDoc->CanonicalizationMethod);
            }
        }
        else if (exiDoc->DSAKeyValue_isUsed == 1)
        {
            // encode event 15
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 15);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_DSAKeyValueType(stream, &exiDoc->DSAKeyValue);
            }
        }
        else if (exiDoc->DigestMethod_isUsed == 1)
        {
            // encode event 16
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 16);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_DigestMethodType(stream, &exiDoc->DigestMethod);
            }
        }
        // simple type! encode_iso20_ac_DigestValue;
        else if (exiDoc->Dynamic_AC_CLReqControlMode_isUsed == 1)
        {
            // encode event 18
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 18);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_Dynamic_AC_CLReqControlModeType(stream, &exiDoc->Dynamic_AC_CLReqControlMode);
            }
        }
        else if (exiDoc->Dynamic_AC_CLResControlMode_isUsed == 1)
        {
            // encode event 19
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 19);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_Dynamic_AC_CLResControlModeType(stream, &exiDoc->Dynamic_AC_CLResControlMode);
            }
        }
        else if (exiDoc->KeyInfo_isUsed == 1)
        {
            // encode event 20
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 20);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_KeyInfoType(stream, &exiDoc->KeyInfo);
            }
        }
        // simple type! encode_iso20_ac_KeyName;
        else if (exiDoc->KeyValue_isUsed == 1)
        {
            // encode event 22
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 22);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_KeyValueType(stream, &exiDoc->KeyValue);
            }
        }
        else if (exiDoc->Manifest_isUsed == 1)
        {
            // encode event 23
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 23);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_ManifestType(stream, &exiDoc->Manifest);
            }
        }
        // simple type! encode_iso20_ac_MgmtData;
        else if (exiDoc->Object_isUsed == 1)
        {
            // encode event 25
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 25);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_ObjectType(stream, &exiDoc->Object);
            }
        }
        else if (exiDoc->PGPData_isUsed == 1)
        {
            // encode event 26
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 26);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_PGPDataType(stream, &exiDoc->PGPData);
            }
        }
        else if (exiDoc->RSAKeyValue_isUsed == 1)
        {
            // encode event 27
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 27);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_RSAKeyValueType(stream, &exiDoc->RSAKeyValue);
            }
        }
        else if (exiDoc->Reference_isUsed == 1)
        {
            // encode event 28
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 28);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_ReferenceType(stream, &exiDoc->Reference);
            }
        }
        else if (exiDoc->RetrievalMethod_isUsed == 1)
        {
            // encode event 29
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 29);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_RetrievalMethodType(stream, &exiDoc->RetrievalMethod);
            }
        }
        else if (exiDoc->SPKIData_isUsed == 1)
        {
            // encode event 30
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 30);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_SPKIDataType(stream, &exiDoc->SPKIData);
            }
        }
        else if (exiDoc->Scheduled_AC_CLReqControlMode_isUsed == 1)
        {
            // encode event 31
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 31);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_Scheduled_AC_CLReqControlModeType(stream, &exiDoc->Scheduled_AC_CLReqControlMode);
            }
        }
        else if (exiDoc->Scheduled_AC_CLResControlMode_isUsed == 1)
        {
            // encode event 32
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 32);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_Scheduled_AC_CLResControlModeType(stream, &exiDoc->Scheduled_AC_CLResControlMode);
            }
        }
        else if (exiDoc->SignatureMethod_isUsed == 1)
        {
            // encode event 33
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 33);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_SignatureMethodType(stream, &exiDoc->SignatureMethod);
            }
        }
        else if (exiDoc->SignatureProperties_isUsed == 1)
        {
            // encode event 34
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 34);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_SignaturePropertiesType(stream, &exiDoc->SignatureProperties);
            }
        }
        else if (exiDoc->SignatureProperty_isUsed == 1)
        {
            // encode event 35
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 35);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_SignaturePropertyType(stream, &exiDoc->SignatureProperty);
            }
        }
        else if (exiDoc->Signature_isUsed == 1)
        {
            // encode event 36
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 36);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_SignatureType(stream, &exiDoc->Signature);
            }
        }
        else if (exiDoc->SignatureValue_isUsed == 1)
        {
            // encode event 37
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 37);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_SignatureValueType(stream, &exiDoc->SignatureValue);
            }
        }
        else if (exiDoc->SignedInfo_isUsed == 1)
        {
            // encode event 38
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 38);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_SignedInfoType(stream, &exiDoc->SignedInfo);
            }
        }
        else if (exiDoc->Transform_isUsed == 1)
        {
            // encode event 39
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 39);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_TransformType(stream, &exiDoc->Transform);
            }
        }
        else if (exiDoc->Transforms_isUsed == 1)
        {
            // encode event 40
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 40);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_TransformsType(stream, &exiDoc->Transforms);
            }
        }
        else if (exiDoc->X509Data_isUsed == 1)
        {
            // encode event 41
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 41);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_ac_X509DataType(stream, &exiDoc->X509Data);
            }
        }
        else
        {
            error = EXI_ERROR__UNKNOWN_EVENT_FOR_ENCODING;
        }
    }

    return error;
}

