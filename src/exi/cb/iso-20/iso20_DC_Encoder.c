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
  * @file iso20_DC_Encoder.c
  * @brief Description goes here
  *
  **/
#include <stdint.h>

#include "common/exi_basetypes.h"
#include "common/exi_basetypes_encoder.h"
#include "common/exi_error_codes.h"
#include "common/exi_header.h"
#include "iso20_DC_Datatypes.h"
#include "iso20_DC_Encoder.h"



static int encode_iso20_dc_TransformType(exi_bitstream_t* stream, struct iso20_dc_TransformType* TransformType);
static int encode_iso20_dc_TransformsType(exi_bitstream_t* stream, struct iso20_dc_TransformsType* TransformsType);
static int encode_iso20_dc_DSAKeyValueType(exi_bitstream_t* stream, struct iso20_dc_DSAKeyValueType* DSAKeyValueType);
static int encode_iso20_dc_X509IssuerSerialType(exi_bitstream_t* stream, struct iso20_dc_X509IssuerSerialType* X509IssuerSerialType);
static int encode_iso20_dc_DigestMethodType(exi_bitstream_t* stream, struct iso20_dc_DigestMethodType* DigestMethodType);
static int encode_iso20_dc_RSAKeyValueType(exi_bitstream_t* stream, struct iso20_dc_RSAKeyValueType* RSAKeyValueType);
static int encode_iso20_dc_CanonicalizationMethodType(exi_bitstream_t* stream, struct iso20_dc_CanonicalizationMethodType* CanonicalizationMethodType);
static int encode_iso20_dc_SignatureMethodType(exi_bitstream_t* stream, struct iso20_dc_SignatureMethodType* SignatureMethodType);
static int encode_iso20_dc_KeyValueType(exi_bitstream_t* stream, struct iso20_dc_KeyValueType* KeyValueType);
static int encode_iso20_dc_ReferenceType(exi_bitstream_t* stream, struct iso20_dc_ReferenceType* ReferenceType);
static int encode_iso20_dc_RetrievalMethodType(exi_bitstream_t* stream, struct iso20_dc_RetrievalMethodType* RetrievalMethodType);
static int encode_iso20_dc_X509DataType(exi_bitstream_t* stream, struct iso20_dc_X509DataType* X509DataType);
static int encode_iso20_dc_PGPDataType(exi_bitstream_t* stream, struct iso20_dc_PGPDataType* PGPDataType);
static int encode_iso20_dc_SPKIDataType(exi_bitstream_t* stream, struct iso20_dc_SPKIDataType* SPKIDataType);
static int encode_iso20_dc_SignedInfoType(exi_bitstream_t* stream, struct iso20_dc_SignedInfoType* SignedInfoType);
static int encode_iso20_dc_SignatureValueType(exi_bitstream_t* stream, struct iso20_dc_SignatureValueType* SignatureValueType);
static int encode_iso20_dc_KeyInfoType(exi_bitstream_t* stream, struct iso20_dc_KeyInfoType* KeyInfoType);
static int encode_iso20_dc_ObjectType(exi_bitstream_t* stream, struct iso20_dc_ObjectType* ObjectType);
static int encode_iso20_dc_RationalNumberType(exi_bitstream_t* stream, struct iso20_dc_RationalNumberType* RationalNumberType);
static int encode_iso20_dc_DetailedCostType(exi_bitstream_t* stream, struct iso20_dc_DetailedCostType* DetailedCostType);
static int encode_iso20_dc_SignatureType(exi_bitstream_t* stream, struct iso20_dc_SignatureType* SignatureType);
static int encode_iso20_dc_DetailedTaxType(exi_bitstream_t* stream, struct iso20_dc_DetailedTaxType* DetailedTaxType);
static int encode_iso20_dc_MessageHeaderType(exi_bitstream_t* stream, struct iso20_dc_MessageHeaderType* MessageHeaderType);
static int encode_iso20_dc_SignaturePropertyType(exi_bitstream_t* stream, struct iso20_dc_SignaturePropertyType* SignaturePropertyType);
static int encode_iso20_dc_DC_CPDReqEnergyTransferModeType(exi_bitstream_t* stream, struct iso20_dc_DC_CPDReqEnergyTransferModeType* DC_CPDReqEnergyTransferModeType);
static int encode_iso20_dc_DisplayParametersType(exi_bitstream_t* stream, struct iso20_dc_DisplayParametersType* DisplayParametersType);
static int encode_iso20_dc_DC_CPDResEnergyTransferModeType(exi_bitstream_t* stream, struct iso20_dc_DC_CPDResEnergyTransferModeType* DC_CPDResEnergyTransferModeType);
static int encode_iso20_dc_EVSEStatusType(exi_bitstream_t* stream, struct iso20_dc_EVSEStatusType* EVSEStatusType);
static int encode_iso20_dc_MeterInfoType(exi_bitstream_t* stream, struct iso20_dc_MeterInfoType* MeterInfoType);
static int encode_iso20_dc_Scheduled_DC_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_dc_Scheduled_DC_CLReqControlModeType* Scheduled_DC_CLReqControlModeType);
static int encode_iso20_dc_Dynamic_DC_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_dc_Dynamic_DC_CLReqControlModeType* Dynamic_DC_CLReqControlModeType);
static int encode_iso20_dc_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_dc_CLReqControlModeType* CLReqControlModeType);
static int encode_iso20_dc_ReceiptType(exi_bitstream_t* stream, struct iso20_dc_ReceiptType* ReceiptType);
static int encode_iso20_dc_Scheduled_DC_CLResControlModeType(exi_bitstream_t* stream, struct iso20_dc_Scheduled_DC_CLResControlModeType* Scheduled_DC_CLResControlModeType);
static int encode_iso20_dc_Dynamic_DC_CLResControlModeType(exi_bitstream_t* stream, struct iso20_dc_Dynamic_DC_CLResControlModeType* Dynamic_DC_CLResControlModeType);
static int encode_iso20_dc_CLResControlModeType(exi_bitstream_t* stream, struct iso20_dc_CLResControlModeType* CLResControlModeType);
static int encode_iso20_dc_DC_CableCheckReqType(exi_bitstream_t* stream, struct iso20_dc_DC_CableCheckReqType* DC_CableCheckReqType);
static int encode_iso20_dc_DC_CableCheckResType(exi_bitstream_t* stream, struct iso20_dc_DC_CableCheckResType* DC_CableCheckResType);
static int encode_iso20_dc_DC_PreChargeReqType(exi_bitstream_t* stream, struct iso20_dc_DC_PreChargeReqType* DC_PreChargeReqType);
static int encode_iso20_dc_DC_PreChargeResType(exi_bitstream_t* stream, struct iso20_dc_DC_PreChargeResType* DC_PreChargeResType);
static int encode_iso20_dc_DC_WeldingDetectionReqType(exi_bitstream_t* stream, struct iso20_dc_DC_WeldingDetectionReqType* DC_WeldingDetectionReqType);
static int encode_iso20_dc_DC_WeldingDetectionResType(exi_bitstream_t* stream, struct iso20_dc_DC_WeldingDetectionResType* DC_WeldingDetectionResType);
static int encode_iso20_dc_BPT_DC_CPDReqEnergyTransferModeType(exi_bitstream_t* stream, struct iso20_dc_BPT_DC_CPDReqEnergyTransferModeType* BPT_DC_CPDReqEnergyTransferModeType);
static int encode_iso20_dc_DC_ChargeParameterDiscoveryReqType(exi_bitstream_t* stream, struct iso20_dc_DC_ChargeParameterDiscoveryReqType* DC_ChargeParameterDiscoveryReqType);
static int encode_iso20_dc_BPT_DC_CPDResEnergyTransferModeType(exi_bitstream_t* stream, struct iso20_dc_BPT_DC_CPDResEnergyTransferModeType* BPT_DC_CPDResEnergyTransferModeType);
static int encode_iso20_dc_DC_ChargeParameterDiscoveryResType(exi_bitstream_t* stream, struct iso20_dc_DC_ChargeParameterDiscoveryResType* DC_ChargeParameterDiscoveryResType);
static int encode_iso20_dc_BPT_Scheduled_DC_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_dc_BPT_Scheduled_DC_CLReqControlModeType* BPT_Scheduled_DC_CLReqControlModeType);
static int encode_iso20_dc_BPT_Scheduled_DC_CLResControlModeType(exi_bitstream_t* stream, struct iso20_dc_BPT_Scheduled_DC_CLResControlModeType* BPT_Scheduled_DC_CLResControlModeType);
static int encode_iso20_dc_BPT_Dynamic_DC_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_dc_BPT_Dynamic_DC_CLReqControlModeType* BPT_Dynamic_DC_CLReqControlModeType);
static int encode_iso20_dc_DC_ChargeLoopReqType(exi_bitstream_t* stream, struct iso20_dc_DC_ChargeLoopReqType* DC_ChargeLoopReqType);
static int encode_iso20_dc_BPT_Dynamic_DC_CLResControlModeType(exi_bitstream_t* stream, struct iso20_dc_BPT_Dynamic_DC_CLResControlModeType* BPT_Dynamic_DC_CLResControlModeType);
static int encode_iso20_dc_DC_ChargeLoopResType(exi_bitstream_t* stream, struct iso20_dc_DC_ChargeLoopResType* DC_ChargeLoopResType);
static int encode_iso20_dc_ManifestType(exi_bitstream_t* stream, struct iso20_dc_ManifestType* ManifestType);
static int encode_iso20_dc_SignaturePropertiesType(exi_bitstream_t* stream, struct iso20_dc_SignaturePropertiesType* SignaturePropertiesType);

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Transform; type={http://www.w3.org/2000/09/xmldsig#}TransformType; base type=; content type=mixed;
//          abstract=False; final=False; choice=True;
// Particle: Algorithm, anyURI (1, 1); ANY, anyType (0, 1); XPath, string (0, 1);
static int encode_iso20_dc_TransformType(exi_bitstream_t* stream, struct iso20_dc_TransformType* TransformType) {
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
                    error = exi_basetypes_encoder_characters(stream, TransformType->Algorithm.charactersLen, TransformType->Algorithm.characters, iso20_dc_Algorithm_CHARACTER_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, TransformType->ANY.bytesLen, TransformType->ANY.bytes, iso20_dc_anyType_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_characters(stream, TransformType->XPath.charactersLen, TransformType->XPath.characters, iso20_dc_XPath_CHARACTER_SIZE);
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
static int encode_iso20_dc_TransformsType(exi_bitstream_t* stream, struct iso20_dc_TransformsType* TransformsType) {
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
                error = encode_iso20_dc_TransformType(stream, &TransformsType->Transform);
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
static int encode_iso20_dc_DSAKeyValueType(exi_bitstream_t* stream, struct iso20_dc_DSAKeyValueType* DSAKeyValueType) {
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
                            error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->P.bytesLen, DSAKeyValueType->P.bytes, iso20_dc_CryptoBinary_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->G.bytesLen, DSAKeyValueType->G.bytes, iso20_dc_CryptoBinary_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->Y.bytesLen, DSAKeyValueType->Y.bytes, iso20_dc_CryptoBinary_BYTES_SIZE);
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
                        error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->Q.bytesLen, DSAKeyValueType->Q.bytes, iso20_dc_CryptoBinary_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->G.bytesLen, DSAKeyValueType->G.bytes, iso20_dc_CryptoBinary_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->Y.bytesLen, DSAKeyValueType->Y.bytes, iso20_dc_CryptoBinary_BYTES_SIZE);
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
                        error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->Y.bytesLen, DSAKeyValueType->Y.bytes, iso20_dc_CryptoBinary_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->J.bytesLen, DSAKeyValueType->J.bytes, iso20_dc_CryptoBinary_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->Seed.bytesLen, DSAKeyValueType->Seed.bytes, iso20_dc_CryptoBinary_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->Seed.bytesLen, DSAKeyValueType->Seed.bytes, iso20_dc_CryptoBinary_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, DSAKeyValueType->PgenCounter.bytesLen, DSAKeyValueType->PgenCounter.bytes, iso20_dc_CryptoBinary_BYTES_SIZE);
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
static int encode_iso20_dc_X509IssuerSerialType(exi_bitstream_t* stream, struct iso20_dc_X509IssuerSerialType* X509IssuerSerialType) {
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
                        error = exi_basetypes_encoder_characters(stream, X509IssuerSerialType->X509IssuerName.charactersLen, X509IssuerSerialType->X509IssuerName.characters, iso20_dc_X509IssuerName_CHARACTER_SIZE);
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
static int encode_iso20_dc_DigestMethodType(exi_bitstream_t* stream, struct iso20_dc_DigestMethodType* DigestMethodType) {
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
                    error = exi_basetypes_encoder_characters(stream, DigestMethodType->Algorithm.charactersLen, DigestMethodType->Algorithm.characters, iso20_dc_Algorithm_CHARACTER_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, DigestMethodType->ANY.bytesLen, DigestMethodType->ANY.bytes, iso20_dc_anyType_BYTES_SIZE);
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
static int encode_iso20_dc_RSAKeyValueType(exi_bitstream_t* stream, struct iso20_dc_RSAKeyValueType* RSAKeyValueType) {
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
                        error = exi_basetypes_encoder_bytes(stream, RSAKeyValueType->Modulus.bytesLen, RSAKeyValueType->Modulus.bytes, iso20_dc_CryptoBinary_BYTES_SIZE);
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
                        error = exi_basetypes_encoder_bytes(stream, RSAKeyValueType->Exponent.bytesLen, RSAKeyValueType->Exponent.bytes, iso20_dc_CryptoBinary_BYTES_SIZE);
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
static int encode_iso20_dc_CanonicalizationMethodType(exi_bitstream_t* stream, struct iso20_dc_CanonicalizationMethodType* CanonicalizationMethodType) {
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
                    error = exi_basetypes_encoder_characters(stream, CanonicalizationMethodType->Algorithm.charactersLen, CanonicalizationMethodType->Algorithm.characters, iso20_dc_Algorithm_CHARACTER_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, CanonicalizationMethodType->ANY.bytesLen, CanonicalizationMethodType->ANY.bytes, iso20_dc_anyType_BYTES_SIZE);
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
static int encode_iso20_dc_SignatureMethodType(exi_bitstream_t* stream, struct iso20_dc_SignatureMethodType* SignatureMethodType) {
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
                    error = exi_basetypes_encoder_characters(stream, SignatureMethodType->Algorithm.charactersLen, SignatureMethodType->Algorithm.characters, iso20_dc_Algorithm_CHARACTER_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, SignatureMethodType->ANY.bytesLen, SignatureMethodType->ANY.bytes, iso20_dc_anyType_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, SignatureMethodType->ANY.bytesLen, SignatureMethodType->ANY.bytes, iso20_dc_anyType_BYTES_SIZE);
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
static int encode_iso20_dc_KeyValueType(exi_bitstream_t* stream, struct iso20_dc_KeyValueType* KeyValueType) {
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
                    error = encode_iso20_dc_DSAKeyValueType(stream, &KeyValueType->DSAKeyValue);
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
                    error = encode_iso20_dc_RSAKeyValueType(stream, &KeyValueType->RSAKeyValue);
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
                            error = exi_basetypes_encoder_bytes(stream, KeyValueType->ANY.bytesLen, KeyValueType->ANY.bytes, iso20_dc_anyType_BYTES_SIZE);
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
static int encode_iso20_dc_ReferenceType(exi_bitstream_t* stream, struct iso20_dc_ReferenceType* ReferenceType) {
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
                        error = exi_basetypes_encoder_characters(stream, ReferenceType->Id.charactersLen, ReferenceType->Id.characters, iso20_dc_Id_CHARACTER_SIZE);
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
                        error = exi_basetypes_encoder_characters(stream, ReferenceType->Type.charactersLen, ReferenceType->Type.characters, iso20_dc_Type_CHARACTER_SIZE);
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
                        error = exi_basetypes_encoder_characters(stream, ReferenceType->URI.charactersLen, ReferenceType->URI.characters, iso20_dc_URI_CHARACTER_SIZE);
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
                    error = encode_iso20_dc_TransformsType(stream, &ReferenceType->Transforms);
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
                    error = encode_iso20_dc_DigestMethodType(stream, &ReferenceType->DigestMethod);
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
                        error = exi_basetypes_encoder_characters(stream, ReferenceType->Type.charactersLen, ReferenceType->Type.characters, iso20_dc_Type_CHARACTER_SIZE);
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
                        error = exi_basetypes_encoder_characters(stream, ReferenceType->URI.charactersLen, ReferenceType->URI.characters, iso20_dc_URI_CHARACTER_SIZE);
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
                    error = encode_iso20_dc_TransformsType(stream, &ReferenceType->Transforms);
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
                    error = encode_iso20_dc_DigestMethodType(stream, &ReferenceType->DigestMethod);
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
                        error = exi_basetypes_encoder_characters(stream, ReferenceType->URI.charactersLen, ReferenceType->URI.characters, iso20_dc_URI_CHARACTER_SIZE);
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
                    error = encode_iso20_dc_TransformsType(stream, &ReferenceType->Transforms);
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
                    error = encode_iso20_dc_DigestMethodType(stream, &ReferenceType->DigestMethod);
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
                    error = encode_iso20_dc_TransformsType(stream, &ReferenceType->Transforms);
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
                    error = encode_iso20_dc_DigestMethodType(stream, &ReferenceType->DigestMethod);
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
                error = encode_iso20_dc_DigestMethodType(stream, &ReferenceType->DigestMethod);
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
                        error = exi_basetypes_encoder_bytes(stream, ReferenceType->DigestValue.bytesLen, ReferenceType->DigestValue.bytes, iso20_dc_DigestValueType_BYTES_SIZE);
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
static int encode_iso20_dc_RetrievalMethodType(exi_bitstream_t* stream, struct iso20_dc_RetrievalMethodType* RetrievalMethodType) {
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
                        error = exi_basetypes_encoder_characters(stream, RetrievalMethodType->Type.charactersLen, RetrievalMethodType->Type.characters, iso20_dc_Type_CHARACTER_SIZE);
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
                        error = exi_basetypes_encoder_characters(stream, RetrievalMethodType->URI.charactersLen, RetrievalMethodType->URI.characters, iso20_dc_URI_CHARACTER_SIZE);
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
                    error = encode_iso20_dc_TransformsType(stream, &RetrievalMethodType->Transforms);
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
                        error = exi_basetypes_encoder_characters(stream, RetrievalMethodType->URI.charactersLen, RetrievalMethodType->URI.characters, iso20_dc_URI_CHARACTER_SIZE);
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
                    error = encode_iso20_dc_TransformsType(stream, &RetrievalMethodType->Transforms);
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
                    error = encode_iso20_dc_TransformsType(stream, &RetrievalMethodType->Transforms);
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
static int encode_iso20_dc_X509DataType(exi_bitstream_t* stream, struct iso20_dc_X509DataType* X509DataType) {
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
                    error = encode_iso20_dc_X509IssuerSerialType(stream, &X509DataType->X509IssuerSerial);
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
                            error = exi_basetypes_encoder_bytes(stream, X509DataType->X509SKI.bytesLen, X509DataType->X509SKI.bytes, iso20_dc_base64Binary_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_characters(stream, X509DataType->X509SubjectName.charactersLen, X509DataType->X509SubjectName.characters, iso20_dc_X509SubjectName_CHARACTER_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, X509DataType->X509Certificate.bytesLen, X509DataType->X509Certificate.bytes, iso20_dc_base64Binary_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, X509DataType->X509CRL.bytesLen, X509DataType->X509CRL.bytes, iso20_dc_base64Binary_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, X509DataType->ANY.bytesLen, X509DataType->ANY.bytes, iso20_dc_anyType_BYTES_SIZE);
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
static int encode_iso20_dc_PGPDataType(exi_bitstream_t* stream, struct iso20_dc_PGPDataType* PGPDataType) {
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
                        error = exi_basetypes_encoder_bytes(stream, PGPDataType->choice_1.PGPKeyID.bytesLen, PGPDataType->choice_1.PGPKeyID.bytes, iso20_dc_base64Binary_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, PGPDataType->choice_1.PGPKeyPacket.bytesLen, PGPDataType->choice_1.PGPKeyPacket.bytes, iso20_dc_base64Binary_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, PGPDataType->choice_1.ANY.bytesLen, PGPDataType->choice_1.ANY.bytes, iso20_dc_anyType_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, PGPDataType->choice_2.PGPKeyPacket.bytesLen, PGPDataType->choice_2.PGPKeyPacket.bytes, iso20_dc_base64Binary_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, PGPDataType->choice_1.ANY.bytesLen, PGPDataType->choice_1.ANY.bytes, iso20_dc_anyType_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, PGPDataType->choice_2.PGPKeyPacket.bytesLen, PGPDataType->choice_2.PGPKeyPacket.bytes, iso20_dc_base64Binary_BYTES_SIZE);
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
                        error = exi_basetypes_encoder_bytes(stream, PGPDataType->choice_2.PGPKeyPacket.bytesLen, PGPDataType->choice_2.PGPKeyPacket.bytes, iso20_dc_base64Binary_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, PGPDataType->choice_2.ANY.bytesLen, PGPDataType->choice_2.ANY.bytes, iso20_dc_anyType_BYTES_SIZE);
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
static int encode_iso20_dc_SPKIDataType(exi_bitstream_t* stream, struct iso20_dc_SPKIDataType* SPKIDataType) {
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
                        error = exi_basetypes_encoder_bytes(stream, SPKIDataType->SPKISexp.bytesLen, SPKIDataType->SPKISexp.bytes, iso20_dc_base64Binary_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, SPKIDataType->ANY.bytesLen, SPKIDataType->ANY.bytes, iso20_dc_anyType_BYTES_SIZE);
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
static int encode_iso20_dc_SignedInfoType(exi_bitstream_t* stream, struct iso20_dc_SignedInfoType* SignedInfoType) {
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
                        error = exi_basetypes_encoder_characters(stream, SignedInfoType->Id.charactersLen, SignedInfoType->Id.characters, iso20_dc_Id_CHARACTER_SIZE);
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
                    error = encode_iso20_dc_CanonicalizationMethodType(stream, &SignedInfoType->CanonicalizationMethod);
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
                error = encode_iso20_dc_CanonicalizationMethodType(stream, &SignedInfoType->CanonicalizationMethod);
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
                error = encode_iso20_dc_SignatureMethodType(stream, &SignedInfoType->SignatureMethod);
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
                error = encode_iso20_dc_ReferenceType(stream, &SignedInfoType->Reference);
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
static int encode_iso20_dc_SignatureValueType(exi_bitstream_t* stream, struct iso20_dc_SignatureValueType* SignatureValueType) {
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
                        error = exi_basetypes_encoder_characters(stream, SignatureValueType->Id.charactersLen, SignatureValueType->Id.characters, iso20_dc_Id_CHARACTER_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, SignatureValueType->CONTENT.bytesLen, SignatureValueType->CONTENT.bytes, iso20_dc_SignatureValueType_BYTES_SIZE);
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
                        error = exi_basetypes_encoder_bytes(stream, SignatureValueType->CONTENT.bytesLen, SignatureValueType->CONTENT.bytes, iso20_dc_SignatureValueType_BYTES_SIZE);
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
static int encode_iso20_dc_KeyInfoType(exi_bitstream_t* stream, struct iso20_dc_KeyInfoType* KeyInfoType) {
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
                        error = exi_basetypes_encoder_characters(stream, KeyInfoType->Id.charactersLen, KeyInfoType->Id.characters, iso20_dc_Id_CHARACTER_SIZE);
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
                            error = exi_basetypes_encoder_characters(stream, KeyInfoType->KeyName.charactersLen, KeyInfoType->KeyName.characters, iso20_dc_KeyName_CHARACTER_SIZE);
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
                    error = encode_iso20_dc_KeyValueType(stream, &KeyInfoType->KeyValue);
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
                    error = encode_iso20_dc_RetrievalMethodType(stream, &KeyInfoType->RetrievalMethod);
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
                    error = encode_iso20_dc_X509DataType(stream, &KeyInfoType->X509Data);
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
                    error = encode_iso20_dc_PGPDataType(stream, &KeyInfoType->PGPData);
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
                    error = encode_iso20_dc_SPKIDataType(stream, &KeyInfoType->SPKIData);
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
                            error = exi_basetypes_encoder_characters(stream, KeyInfoType->MgmtData.charactersLen, KeyInfoType->MgmtData.characters, iso20_dc_MgmtData_CHARACTER_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, KeyInfoType->ANY.bytesLen, KeyInfoType->ANY.bytes, iso20_dc_anyType_BYTES_SIZE);
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
                            error = exi_basetypes_encoder_characters(stream, KeyInfoType->KeyName.charactersLen, KeyInfoType->KeyName.characters, iso20_dc_KeyName_CHARACTER_SIZE);
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
                    error = encode_iso20_dc_KeyValueType(stream, &KeyInfoType->KeyValue);
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
                    error = encode_iso20_dc_RetrievalMethodType(stream, &KeyInfoType->RetrievalMethod);
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
                    error = encode_iso20_dc_X509DataType(stream, &KeyInfoType->X509Data);
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
                    error = encode_iso20_dc_PGPDataType(stream, &KeyInfoType->PGPData);
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
                    error = encode_iso20_dc_SPKIDataType(stream, &KeyInfoType->SPKIData);
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
                            error = exi_basetypes_encoder_characters(stream, KeyInfoType->MgmtData.charactersLen, KeyInfoType->MgmtData.characters, iso20_dc_MgmtData_CHARACTER_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, KeyInfoType->ANY.bytesLen, KeyInfoType->ANY.bytes, iso20_dc_anyType_BYTES_SIZE);
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
static int encode_iso20_dc_ObjectType(exi_bitstream_t* stream, struct iso20_dc_ObjectType* ObjectType) {
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
                        error = exi_basetypes_encoder_characters(stream, ObjectType->Encoding.charactersLen, ObjectType->Encoding.characters, iso20_dc_Encoding_CHARACTER_SIZE);
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
                        error = exi_basetypes_encoder_characters(stream, ObjectType->Id.charactersLen, ObjectType->Id.characters, iso20_dc_Id_CHARACTER_SIZE);
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
                        error = exi_basetypes_encoder_characters(stream, ObjectType->MimeType.charactersLen, ObjectType->MimeType.characters, iso20_dc_MimeType_CHARACTER_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, ObjectType->ANY.bytesLen, ObjectType->ANY.bytes, iso20_dc_anyType_BYTES_SIZE);
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
                        error = exi_basetypes_encoder_characters(stream, ObjectType->Id.charactersLen, ObjectType->Id.characters, iso20_dc_Id_CHARACTER_SIZE);
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
                        error = exi_basetypes_encoder_characters(stream, ObjectType->MimeType.charactersLen, ObjectType->MimeType.characters, iso20_dc_MimeType_CHARACTER_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, ObjectType->ANY.bytesLen, ObjectType->ANY.bytes, iso20_dc_anyType_BYTES_SIZE);
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
                        error = exi_basetypes_encoder_characters(stream, ObjectType->MimeType.charactersLen, ObjectType->MimeType.characters, iso20_dc_MimeType_CHARACTER_SIZE);
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
                            error = exi_basetypes_encoder_bytes(stream, ObjectType->ANY.bytesLen, ObjectType->ANY.bytes, iso20_dc_anyType_BYTES_SIZE);
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
                        error = exi_basetypes_encoder_bytes(stream, ObjectType->ANY.bytesLen, ObjectType->ANY.bytes, iso20_dc_anyType_BYTES_SIZE);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}EVMaximumChargePower; type={urn:iso:std:iso:15118:-20:CommonTypes}RationalNumberType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Exponent, byte (1, 1); Value, short (1, 1);
static int encode_iso20_dc_RationalNumberType(exi_bitstream_t* stream, struct iso20_dc_RationalNumberType* RationalNumberType) {
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
static int encode_iso20_dc_DetailedCostType(exi_bitstream_t* stream, struct iso20_dc_DetailedCostType* DetailedCostType) {
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
                error = encode_iso20_dc_RationalNumberType(stream, &DetailedCostType->Amount);
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
                error = encode_iso20_dc_RationalNumberType(stream, &DetailedCostType->CostPerUnit);
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
static int encode_iso20_dc_SignatureType(exi_bitstream_t* stream, struct iso20_dc_SignatureType* SignatureType) {
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
                        error = exi_basetypes_encoder_characters(stream, SignatureType->Id.charactersLen, SignatureType->Id.characters, iso20_dc_Id_CHARACTER_SIZE);
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
                    error = encode_iso20_dc_SignedInfoType(stream, &SignatureType->SignedInfo);
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
                error = encode_iso20_dc_SignedInfoType(stream, &SignatureType->SignedInfo);
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
                        error = exi_basetypes_encoder_bytes(stream, SignatureType->SignatureValue.CONTENT.bytesLen, SignatureType->SignatureValue.CONTENT.bytes, iso20_dc_SignatureValueType_BYTES_SIZE);
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
                    error = encode_iso20_dc_KeyInfoType(stream, &SignatureType->KeyInfo);
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
                    error = encode_iso20_dc_ObjectType(stream, &SignatureType->Object);
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
                    error = encode_iso20_dc_ObjectType(stream, &SignatureType->Object);
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
static int encode_iso20_dc_DetailedTaxType(exi_bitstream_t* stream, struct iso20_dc_DetailedTaxType* DetailedTaxType) {
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
                error = encode_iso20_dc_RationalNumberType(stream, &DetailedTaxType->Amount);
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
static int encode_iso20_dc_MessageHeaderType(exi_bitstream_t* stream, struct iso20_dc_MessageHeaderType* MessageHeaderType) {
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
                        error = exi_basetypes_encoder_bytes(stream, MessageHeaderType->SessionID.bytesLen, MessageHeaderType->SessionID.bytes, iso20_dc_sessionIDType_BYTES_SIZE);
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
                    error = encode_iso20_dc_SignatureType(stream, &MessageHeaderType->Signature);
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
static int encode_iso20_dc_SignaturePropertyType(exi_bitstream_t* stream, struct iso20_dc_SignaturePropertyType* SignaturePropertyType) {
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
                        error = exi_basetypes_encoder_characters(stream, SignaturePropertyType->Id.charactersLen, SignaturePropertyType->Id.characters, iso20_dc_Id_CHARACTER_SIZE);
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
                        error = exi_basetypes_encoder_characters(stream, SignaturePropertyType->Target.charactersLen, SignaturePropertyType->Target.characters, iso20_dc_Target_CHARACTER_SIZE);
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
                    error = exi_basetypes_encoder_characters(stream, SignaturePropertyType->Target.charactersLen, SignaturePropertyType->Target.characters, iso20_dc_Target_CHARACTER_SIZE);
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
                        error = exi_basetypes_encoder_bytes(stream, SignaturePropertyType->ANY.bytesLen, SignaturePropertyType->ANY.bytes, iso20_dc_anyType_BYTES_SIZE);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}DC_CPDReqEnergyTransferMode; type={urn:iso:std:iso:15118:-20:DC}DC_CPDReqEnergyTransferModeType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EVMaximumChargePower, RationalNumberType (1, 1); EVMinimumChargePower, RationalNumberType (1, 1); EVMaximumChargeCurrent, RationalNumberType (1, 1); EVMinimumChargeCurrent, RationalNumberType (1, 1); EVMaximumVoltage, RationalNumberType (1, 1); EVMinimumVoltage, RationalNumberType (1, 1); TargetSOC, percentValueType (0, 1);
static int encode_iso20_dc_DC_CPDReqEnergyTransferModeType(exi_bitstream_t* stream, struct iso20_dc_DC_CPDReqEnergyTransferModeType* DC_CPDReqEnergyTransferModeType) {
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
                error = encode_iso20_dc_RationalNumberType(stream, &DC_CPDReqEnergyTransferModeType->EVMaximumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 71;
                }
            }
            break;
        case 71:
            // Grammar: ID=71; read/write bits=1; START (EVMinimumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=72
                error = encode_iso20_dc_RationalNumberType(stream, &DC_CPDReqEnergyTransferModeType->EVMinimumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 72;
                }
            }
            break;
        case 72:
            // Grammar: ID=72; read/write bits=1; START (EVMaximumChargeCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=73
                error = encode_iso20_dc_RationalNumberType(stream, &DC_CPDReqEnergyTransferModeType->EVMaximumChargeCurrent);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 73;
                }
            }
            break;
        case 73:
            // Grammar: ID=73; read/write bits=1; START (EVMinimumChargeCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=74
                error = encode_iso20_dc_RationalNumberType(stream, &DC_CPDReqEnergyTransferModeType->EVMinimumChargeCurrent);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 74;
                }
            }
            break;
        case 74:
            // Grammar: ID=74; read/write bits=1; START (EVMaximumVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=75
                error = encode_iso20_dc_RationalNumberType(stream, &DC_CPDReqEnergyTransferModeType->EVMaximumVoltage);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 75;
                }
            }
            break;
        case 75:
            // Grammar: ID=75; read/write bits=1; START (EVMinimumVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=76
                error = encode_iso20_dc_RationalNumberType(stream, &DC_CPDReqEnergyTransferModeType->EVMinimumVoltage);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 76;
                }
            }
            break;
        case 76:
            // Grammar: ID=76; read/write bits=2; START (TargetSOC), END Element
            if (DC_CPDReqEnergyTransferModeType->TargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (TargetSOC, byte); next=2
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)DC_CPDReqEnergyTransferModeType->TargetSOC);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}DisplayParameters; type={urn:iso:std:iso:15118:-20:CommonTypes}DisplayParametersType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: PresentSOC, percentValueType (0, 1); MinimumSOC, percentValueType (0, 1); TargetSOC, percentValueType (0, 1); MaximumSOC, percentValueType (0, 1); RemainingTimeToMinimumSOC, unsignedInt (0, 1); RemainingTimeToTargetSOC, unsignedInt (0, 1); RemainingTimeToMaximumSOC, unsignedInt (0, 1); ChargingComplete, boolean (0, 1); BatteryEnergyCapacity, RationalNumberType (0, 1); InletHot, boolean (0, 1);
static int encode_iso20_dc_DisplayParametersType(exi_bitstream_t* stream, struct iso20_dc_DisplayParametersType* DisplayParametersType) {
    int grammar_id = 77;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 77:
            // Grammar: ID=77; read/write bits=4; START (PresentSOC), START (MinimumSOC), START (TargetSOC), START (MaximumSOC), START (RemainingTimeToMinimumSOC), START (RemainingTimeToTargetSOC), START (RemainingTimeToMaximumSOC), START (ChargingComplete), START (BatteryEnergyCapacity), START (InletHot), END Element
            if (DisplayParametersType->PresentSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (PresentSOC, byte); next=78
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
                                grammar_id = 78;
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
                    // Event: START (MinimumSOC, byte); next=79
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
                                grammar_id = 79;
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
                    // Event: START (TargetSOC, byte); next=80
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
                                grammar_id = 80;
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
                    // Event: START (MaximumSOC, byte); next=81
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
                                grammar_id = 81;
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
                    // Event: START (RemainingTimeToMinimumSOC, unsignedLong); next=82
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
                                grammar_id = 82;
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
                    // Event: START (RemainingTimeToTargetSOC, unsignedLong); next=83
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
                                grammar_id = 83;
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
                    // Event: START (RemainingTimeToMaximumSOC, unsignedLong); next=84
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
                                grammar_id = 84;
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
                    // Event: START (ChargingComplete, boolean); next=85
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
                                grammar_id = 85;
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
                    // Event: START (BatteryEnergyCapacity, RationalNumberType); next=86
                    error = encode_iso20_dc_RationalNumberType(stream, &DisplayParametersType->BatteryEnergyCapacity);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 86;
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
        case 78:
            // Grammar: ID=78; read/write bits=4; START (MinimumSOC), START (TargetSOC), START (MaximumSOC), START (RemainingTimeToMinimumSOC), START (RemainingTimeToTargetSOC), START (RemainingTimeToMaximumSOC), START (ChargingComplete), START (BatteryEnergyCapacity), START (InletHot), END Element
            if (DisplayParametersType->MinimumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MinimumSOC, byte); next=79
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
                                grammar_id = 79;
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
                    // Event: START (TargetSOC, byte); next=80
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
                                grammar_id = 80;
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
                    // Event: START (MaximumSOC, byte); next=81
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
                                grammar_id = 81;
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
                    // Event: START (RemainingTimeToMinimumSOC, unsignedLong); next=82
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
                                grammar_id = 82;
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
                    // Event: START (RemainingTimeToTargetSOC, unsignedLong); next=83
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
                                grammar_id = 83;
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
                    // Event: START (RemainingTimeToMaximumSOC, unsignedLong); next=84
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
                                grammar_id = 84;
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
                    // Event: START (ChargingComplete, boolean); next=85
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
                                grammar_id = 85;
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
                    // Event: START (BatteryEnergyCapacity, RationalNumberType); next=86
                    error = encode_iso20_dc_RationalNumberType(stream, &DisplayParametersType->BatteryEnergyCapacity);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 86;
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
        case 79:
            // Grammar: ID=79; read/write bits=4; START (TargetSOC), START (MaximumSOC), START (RemainingTimeToMinimumSOC), START (RemainingTimeToTargetSOC), START (RemainingTimeToMaximumSOC), START (ChargingComplete), START (BatteryEnergyCapacity), START (InletHot), END Element
            if (DisplayParametersType->TargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (TargetSOC, byte); next=80
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
                                grammar_id = 80;
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
                    // Event: START (MaximumSOC, byte); next=81
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
                                grammar_id = 81;
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
                    // Event: START (RemainingTimeToMinimumSOC, unsignedLong); next=82
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
                                grammar_id = 82;
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
                    // Event: START (RemainingTimeToTargetSOC, unsignedLong); next=83
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
                                grammar_id = 83;
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
                    // Event: START (RemainingTimeToMaximumSOC, unsignedLong); next=84
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
                                grammar_id = 84;
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
                    // Event: START (ChargingComplete, boolean); next=85
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
                                grammar_id = 85;
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
                    // Event: START (BatteryEnergyCapacity, RationalNumberType); next=86
                    error = encode_iso20_dc_RationalNumberType(stream, &DisplayParametersType->BatteryEnergyCapacity);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 86;
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
        case 80:
            // Grammar: ID=80; read/write bits=4; START (MaximumSOC), START (RemainingTimeToMinimumSOC), START (RemainingTimeToTargetSOC), START (RemainingTimeToMaximumSOC), START (ChargingComplete), START (BatteryEnergyCapacity), START (InletHot), END Element
            if (DisplayParametersType->MaximumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MaximumSOC, byte); next=81
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
                                grammar_id = 81;
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
                    // Event: START (RemainingTimeToMinimumSOC, unsignedLong); next=82
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
                                grammar_id = 82;
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
                    // Event: START (RemainingTimeToTargetSOC, unsignedLong); next=83
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
                                grammar_id = 83;
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
                    // Event: START (RemainingTimeToMaximumSOC, unsignedLong); next=84
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
                                grammar_id = 84;
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
                    // Event: START (ChargingComplete, boolean); next=85
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
                                grammar_id = 85;
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
                    // Event: START (BatteryEnergyCapacity, RationalNumberType); next=86
                    error = encode_iso20_dc_RationalNumberType(stream, &DisplayParametersType->BatteryEnergyCapacity);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 86;
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
        case 81:
            // Grammar: ID=81; read/write bits=3; START (RemainingTimeToMinimumSOC), START (RemainingTimeToTargetSOC), START (RemainingTimeToMaximumSOC), START (ChargingComplete), START (BatteryEnergyCapacity), START (InletHot), END Element
            if (DisplayParametersType->RemainingTimeToMinimumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToMinimumSOC, unsignedLong); next=82
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
                                grammar_id = 82;
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
                    // Event: START (RemainingTimeToTargetSOC, unsignedLong); next=83
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
                                grammar_id = 83;
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
                    // Event: START (RemainingTimeToMaximumSOC, unsignedLong); next=84
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
                                grammar_id = 84;
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
                    // Event: START (ChargingComplete, boolean); next=85
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
                                grammar_id = 85;
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
                    // Event: START (BatteryEnergyCapacity, RationalNumberType); next=86
                    error = encode_iso20_dc_RationalNumberType(stream, &DisplayParametersType->BatteryEnergyCapacity);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 86;
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
        case 82:
            // Grammar: ID=82; read/write bits=3; START (RemainingTimeToTargetSOC), START (RemainingTimeToMaximumSOC), START (ChargingComplete), START (BatteryEnergyCapacity), START (InletHot), END Element
            if (DisplayParametersType->RemainingTimeToTargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToTargetSOC, unsignedLong); next=83
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
                                grammar_id = 83;
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
                    // Event: START (RemainingTimeToMaximumSOC, unsignedLong); next=84
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
                                grammar_id = 84;
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
                    // Event: START (ChargingComplete, boolean); next=85
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
                                grammar_id = 85;
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
                    // Event: START (BatteryEnergyCapacity, RationalNumberType); next=86
                    error = encode_iso20_dc_RationalNumberType(stream, &DisplayParametersType->BatteryEnergyCapacity);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 86;
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
        case 83:
            // Grammar: ID=83; read/write bits=3; START (RemainingTimeToMaximumSOC), START (ChargingComplete), START (BatteryEnergyCapacity), START (InletHot), END Element
            if (DisplayParametersType->RemainingTimeToMaximumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (RemainingTimeToMaximumSOC, unsignedLong); next=84
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
                                grammar_id = 84;
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
                    // Event: START (ChargingComplete, boolean); next=85
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
                                grammar_id = 85;
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
                    // Event: START (BatteryEnergyCapacity, RationalNumberType); next=86
                    error = encode_iso20_dc_RationalNumberType(stream, &DisplayParametersType->BatteryEnergyCapacity);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 86;
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
        case 84:
            // Grammar: ID=84; read/write bits=3; START (ChargingComplete), START (BatteryEnergyCapacity), START (InletHot), END Element
            if (DisplayParametersType->ChargingComplete_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (ChargingComplete, boolean); next=85
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
                                grammar_id = 85;
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
                    // Event: START (BatteryEnergyCapacity, RationalNumberType); next=86
                    error = encode_iso20_dc_RationalNumberType(stream, &DisplayParametersType->BatteryEnergyCapacity);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 86;
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
        case 85:
            // Grammar: ID=85; read/write bits=2; START (BatteryEnergyCapacity), START (InletHot), END Element
            if (DisplayParametersType->BatteryEnergyCapacity_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BatteryEnergyCapacity, RationalNumberType); next=86
                    error = encode_iso20_dc_RationalNumberType(stream, &DisplayParametersType->BatteryEnergyCapacity);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 86;
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
        case 86:
            // Grammar: ID=86; read/write bits=2; START (InletHot), END Element
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}DC_CPDResEnergyTransferMode; type={urn:iso:std:iso:15118:-20:DC}DC_CPDResEnergyTransferModeType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EVSEMaximumChargePower, RationalNumberType (1, 1); EVSEMinimumChargePower, RationalNumberType (1, 1); EVSEMaximumChargeCurrent, RationalNumberType (1, 1); EVSEMinimumChargeCurrent, RationalNumberType (1, 1); EVSEMaximumVoltage, RationalNumberType (1, 1); EVSEMinimumVoltage, RationalNumberType (1, 1); EVSEPowerRampLimitation, RationalNumberType (0, 1);
static int encode_iso20_dc_DC_CPDResEnergyTransferModeType(exi_bitstream_t* stream, struct iso20_dc_DC_CPDResEnergyTransferModeType* DC_CPDResEnergyTransferModeType) {
    int grammar_id = 87;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 87:
            // Grammar: ID=87; read/write bits=1; START (EVSEMaximumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=88
                error = encode_iso20_dc_RationalNumberType(stream, &DC_CPDResEnergyTransferModeType->EVSEMaximumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 88;
                }
            }
            break;
        case 88:
            // Grammar: ID=88; read/write bits=1; START (EVSEMinimumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=89
                error = encode_iso20_dc_RationalNumberType(stream, &DC_CPDResEnergyTransferModeType->EVSEMinimumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 89;
                }
            }
            break;
        case 89:
            // Grammar: ID=89; read/write bits=1; START (EVSEMaximumChargeCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=90
                error = encode_iso20_dc_RationalNumberType(stream, &DC_CPDResEnergyTransferModeType->EVSEMaximumChargeCurrent);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 90;
                }
            }
            break;
        case 90:
            // Grammar: ID=90; read/write bits=1; START (EVSEMinimumChargeCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=91
                error = encode_iso20_dc_RationalNumberType(stream, &DC_CPDResEnergyTransferModeType->EVSEMinimumChargeCurrent);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 91;
                }
            }
            break;
        case 91:
            // Grammar: ID=91; read/write bits=1; START (EVSEMaximumVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=92
                error = encode_iso20_dc_RationalNumberType(stream, &DC_CPDResEnergyTransferModeType->EVSEMaximumVoltage);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 92;
                }
            }
            break;
        case 92:
            // Grammar: ID=92; read/write bits=1; START (EVSEMinimumVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=93
                error = encode_iso20_dc_RationalNumberType(stream, &DC_CPDResEnergyTransferModeType->EVSEMinimumVoltage);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 93;
                }
            }
            break;
        case 93:
            // Grammar: ID=93; read/write bits=2; START (EVSEPowerRampLimitation), END Element
            if (DC_CPDResEnergyTransferModeType->EVSEPowerRampLimitation_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPowerRampLimitation, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &DC_CPDResEnergyTransferModeType->EVSEPowerRampLimitation);
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
static int encode_iso20_dc_EVSEStatusType(exi_bitstream_t* stream, struct iso20_dc_EVSEStatusType* EVSEStatusType) {
    int grammar_id = 94;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 94:
            // Grammar: ID=94; read/write bits=1; START (NotificationMaxDelay)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (unsignedInt); next=95
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
                            grammar_id = 95;
                        }
                    }
                }
            }
            break;
        case 95:
            // Grammar: ID=95; read/write bits=1; START (EVSENotification)
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}MeterInfo; type={urn:iso:std:iso:15118:-20:CommonTypes}MeterInfoType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: MeterID, meterIDType (1, 1); ChargedEnergyReadingWh, unsignedLong (1, 1); BPT_DischargedEnergyReadingWh, unsignedLong (0, 1); CapacitiveEnergyReadingVARh, unsignedLong (0, 1); BPT_InductiveEnergyReadingVARh, unsignedLong (0, 1); MeterSignature, meterSignatureType (0, 1); MeterStatus, short (0, 1); MeterTimestamp, unsignedLong (0, 1);
static int encode_iso20_dc_MeterInfoType(exi_bitstream_t* stream, struct iso20_dc_MeterInfoType* MeterInfoType) {
    int grammar_id = 96;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 96:
            // Grammar: ID=96; read/write bits=1; START (MeterID)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (string); next=97

                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(MeterInfoType->MeterID.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, MeterInfoType->MeterID.charactersLen, MeterInfoType->MeterID.characters, iso20_dc_MeterID_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 97;
                            }
                        }
                    }
                }
            }
            break;
        case 97:
            // Grammar: ID=97; read/write bits=1; START (ChargedEnergyReadingWh)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (nonNegativeInteger); next=98
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
                            grammar_id = 98;
                        }
                    }
                }
            }
            break;
        case 98:
            // Grammar: ID=98; read/write bits=3; START (BPT_DischargedEnergyReadingWh), START (CapacitiveEnergyReadingVARh), START (BPT_InductiveEnergyReadingVARh), START (MeterSignature), START (MeterStatus), START (MeterTimestamp), END Element
            if (MeterInfoType->BPT_DischargedEnergyReadingWh_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_DischargedEnergyReadingWh, nonNegativeInteger); next=99
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
                                grammar_id = 99;
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
                    // Event: START (CapacitiveEnergyReadingVARh, nonNegativeInteger); next=100
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
                                grammar_id = 100;
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
                    // Event: START (BPT_InductiveEnergyReadingVARh, nonNegativeInteger); next=101
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
                                grammar_id = 101;
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
                    // Event: START (MeterSignature, base64Binary); next=102
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)MeterInfoType->MeterSignature.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, MeterInfoType->MeterSignature.bytesLen, MeterInfoType->MeterSignature.bytes, iso20_dc_meterSignatureType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 102;
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
                    // Event: START (MeterStatus, int); next=103
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
                                grammar_id = 103;
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
        case 99:
            // Grammar: ID=99; read/write bits=3; START (CapacitiveEnergyReadingVARh), START (BPT_InductiveEnergyReadingVARh), START (MeterSignature), START (MeterStatus), START (MeterTimestamp), END Element
            if (MeterInfoType->CapacitiveEnergyReadingVARh_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (CapacitiveEnergyReadingVARh, nonNegativeInteger); next=100
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
                                grammar_id = 100;
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
                    // Event: START (BPT_InductiveEnergyReadingVARh, nonNegativeInteger); next=101
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
                                grammar_id = 101;
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
                    // Event: START (MeterSignature, base64Binary); next=102
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)MeterInfoType->MeterSignature.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, MeterInfoType->MeterSignature.bytesLen, MeterInfoType->MeterSignature.bytes, iso20_dc_meterSignatureType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 102;
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
                    // Event: START (MeterStatus, int); next=103
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
                                grammar_id = 103;
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
        case 100:
            // Grammar: ID=100; read/write bits=3; START (BPT_InductiveEnergyReadingVARh), START (MeterSignature), START (MeterStatus), START (MeterTimestamp), END Element
            if (MeterInfoType->BPT_InductiveEnergyReadingVARh_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_InductiveEnergyReadingVARh, nonNegativeInteger); next=101
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
                                grammar_id = 101;
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
                    // Event: START (MeterSignature, base64Binary); next=102
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)MeterInfoType->MeterSignature.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, MeterInfoType->MeterSignature.bytesLen, MeterInfoType->MeterSignature.bytes, iso20_dc_meterSignatureType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 102;
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
                    // Event: START (MeterStatus, int); next=103
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
                                grammar_id = 103;
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
        case 101:
            // Grammar: ID=101; read/write bits=3; START (MeterSignature), START (MeterStatus), START (MeterTimestamp), END Element
            if (MeterInfoType->MeterSignature_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterSignature, base64Binary); next=102
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, (uint16_t)MeterInfoType->MeterSignature.bytesLen);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            error = exi_basetypes_encoder_bytes(stream, MeterInfoType->MeterSignature.bytesLen, MeterInfoType->MeterSignature.bytes, iso20_dc_meterSignatureType_BYTES_SIZE);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                // encode END Element
                                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                                if (error == EXI_ERROR__NO_ERROR)
                                {
                                    grammar_id = 102;
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
                    // Event: START (MeterStatus, int); next=103
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
                                grammar_id = 103;
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
        case 102:
            // Grammar: ID=102; read/write bits=2; START (MeterStatus), START (MeterTimestamp), END Element
            if (MeterInfoType->MeterStatus_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterStatus, int); next=103
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
                                grammar_id = 103;
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
        case 103:
            // Grammar: ID=103; read/write bits=2; START (MeterTimestamp), END Element
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}Scheduled_DC_CLReqControlMode; type={urn:iso:std:iso:15118:-20:DC}Scheduled_DC_CLReqControlModeType; base type=Scheduled_CLReqControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVTargetEnergyRequest, RationalNumberType (0, 1); EVMaximumEnergyRequest, RationalNumberType (0, 1); EVMinimumEnergyRequest, RationalNumberType (0, 1); EVTargetCurrent, RationalNumberType (1, 1); EVTargetVoltage, RationalNumberType (1, 1); EVMaximumChargePower, RationalNumberType (0, 1); EVMinimumChargePower, RationalNumberType (0, 1); EVMaximumChargeCurrent, RationalNumberType (0, 1); EVMaximumVoltage, RationalNumberType (0, 1); EVMinimumVoltage, RationalNumberType (0, 1);
static int encode_iso20_dc_Scheduled_DC_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_dc_Scheduled_DC_CLReqControlModeType* Scheduled_DC_CLReqControlModeType) {
    int grammar_id = 104;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 104:
            // Grammar: ID=104; read/write bits=3; START (EVTargetEnergyRequest), START (EVMaximumEnergyRequest), START (EVMinimumEnergyRequest), START (EVTargetCurrent)
            if (Scheduled_DC_CLReqControlModeType->EVTargetEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVTargetEnergyRequest, RationalNumberType); next=105
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVTargetEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 105;
                    }
                }
            }
            else if (Scheduled_DC_CLReqControlModeType->EVMaximumEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumEnergyRequest, RationalNumberType); next=106
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVMaximumEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 106;
                    }
                }
            }
            else if (Scheduled_DC_CLReqControlModeType->EVMinimumEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumEnergyRequest, RationalNumberType); next=107
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVMinimumEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 107;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVTargetCurrent, RationalNumberType); next=108
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVTargetCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 108;
                    }
                }
            }
            break;
        case 105:
            // Grammar: ID=105; read/write bits=2; START (EVMaximumEnergyRequest), START (EVMinimumEnergyRequest), START (EVTargetCurrent)
            if (Scheduled_DC_CLReqControlModeType->EVMaximumEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumEnergyRequest, RationalNumberType); next=106
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVMaximumEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 106;
                    }
                }
            }
            else if (Scheduled_DC_CLReqControlModeType->EVMinimumEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumEnergyRequest, RationalNumberType); next=107
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVMinimumEnergyRequest);
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
                    // Event: START (EVTargetCurrent, RationalNumberType); next=108
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVTargetCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 108;
                    }
                }
            }
            break;
        case 106:
            // Grammar: ID=106; read/write bits=2; START (EVMinimumEnergyRequest), START (EVTargetCurrent)
            if (Scheduled_DC_CLReqControlModeType->EVMinimumEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumEnergyRequest, RationalNumberType); next=107
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVMinimumEnergyRequest);
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
                    // Event: START (EVTargetCurrent, RationalNumberType); next=108
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVTargetCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 108;
                    }
                }
            }
            break;
        case 107:
            // Grammar: ID=107; read/write bits=1; START (EVTargetCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=108
                error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVTargetCurrent);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 108;
                }
            }
            break;
        case 108:
            // Grammar: ID=108; read/write bits=1; START (EVTargetVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=109
                error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVTargetVoltage);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 109;
                }
            }
            break;
        case 109:
            // Grammar: ID=109; read/write bits=3; START (EVMaximumChargePower), START (EVMinimumChargePower), START (EVMaximumChargeCurrent), START (EVMaximumVoltage), START (EVMinimumVoltage), END Element
            if (Scheduled_DC_CLReqControlModeType->EVMaximumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower, RationalNumberType); next=110
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVMaximumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 110;
                    }
                }
            }
            else if (Scheduled_DC_CLReqControlModeType->EVMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=111
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 111;
                    }
                }
            }
            else if (Scheduled_DC_CLReqControlModeType->EVMaximumChargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargeCurrent, RationalNumberType); next=112
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVMaximumChargeCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 112;
                    }
                }
            }
            else if (Scheduled_DC_CLReqControlModeType->EVMaximumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumVoltage, RationalNumberType); next=113
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVMaximumVoltage);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 113;
                    }
                }
            }
            else if (Scheduled_DC_CLReqControlModeType->EVMinimumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumVoltage, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVMinimumVoltage);
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
        case 110:
            // Grammar: ID=110; read/write bits=3; START (EVMinimumChargePower), START (EVMaximumChargeCurrent), START (EVMaximumVoltage), START (EVMinimumVoltage), END Element
            if (Scheduled_DC_CLReqControlModeType->EVMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=111
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 111;
                    }
                }
            }
            else if (Scheduled_DC_CLReqControlModeType->EVMaximumChargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargeCurrent, RationalNumberType); next=112
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVMaximumChargeCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 112;
                    }
                }
            }
            else if (Scheduled_DC_CLReqControlModeType->EVMaximumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumVoltage, RationalNumberType); next=113
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVMaximumVoltage);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 113;
                    }
                }
            }
            else if (Scheduled_DC_CLReqControlModeType->EVMinimumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumVoltage, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVMinimumVoltage);
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
        case 111:
            // Grammar: ID=111; read/write bits=3; START (EVMaximumChargeCurrent), START (EVMaximumVoltage), START (EVMinimumVoltage), END Element
            if (Scheduled_DC_CLReqControlModeType->EVMaximumChargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargeCurrent, RationalNumberType); next=112
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVMaximumChargeCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 112;
                    }
                }
            }
            else if (Scheduled_DC_CLReqControlModeType->EVMaximumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumVoltage, RationalNumberType); next=113
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVMaximumVoltage);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 113;
                    }
                }
            }
            else if (Scheduled_DC_CLReqControlModeType->EVMinimumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumVoltage, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVMinimumVoltage);
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
        case 112:
            // Grammar: ID=112; read/write bits=2; START (EVMaximumVoltage), START (EVMinimumVoltage), END Element
            if (Scheduled_DC_CLReqControlModeType->EVMaximumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumVoltage, RationalNumberType); next=113
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVMaximumVoltage);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 113;
                    }
                }
            }
            else if (Scheduled_DC_CLReqControlModeType->EVMinimumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumVoltage, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVMinimumVoltage);
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
        case 113:
            // Grammar: ID=113; read/write bits=2; START (EVMinimumVoltage), END Element
            if (Scheduled_DC_CLReqControlModeType->EVMinimumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumVoltage, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLReqControlModeType->EVMinimumVoltage);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}Dynamic_DC_CLReqControlMode; type={urn:iso:std:iso:15118:-20:DC}Dynamic_DC_CLReqControlModeType; base type=Dynamic_CLReqControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DepartureTime, unsignedInt (0, 1); EVTargetEnergyRequest, RationalNumberType (1, 1); EVMaximumEnergyRequest, RationalNumberType (1, 1); EVMinimumEnergyRequest, RationalNumberType (1, 1); EVMaximumChargePower, RationalNumberType (1, 1); EVMinimumChargePower, RationalNumberType (1, 1); EVMaximumChargeCurrent, RationalNumberType (1, 1); EVMaximumVoltage, RationalNumberType (1, 1); EVMinimumVoltage, RationalNumberType (1, 1);
static int encode_iso20_dc_Dynamic_DC_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_dc_Dynamic_DC_CLReqControlModeType* Dynamic_DC_CLReqControlModeType) {
    int grammar_id = 114;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 114:
            // Grammar: ID=114; read/write bits=2; START (DepartureTime), START (EVTargetEnergyRequest)
            if (Dynamic_DC_CLReqControlModeType->DepartureTime_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (DepartureTime, unsignedLong); next=115
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, Dynamic_DC_CLReqControlModeType->DepartureTime);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 115;
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
                    // Event: START (EVTargetEnergyRequest, RationalNumberType); next=116
                    error = encode_iso20_dc_RationalNumberType(stream, &Dynamic_DC_CLReqControlModeType->EVTargetEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 116;
                    }
                }
            }
            break;
        case 115:
            // Grammar: ID=115; read/write bits=1; START (EVTargetEnergyRequest)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=116
                error = encode_iso20_dc_RationalNumberType(stream, &Dynamic_DC_CLReqControlModeType->EVTargetEnergyRequest);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 116;
                }
            }
            break;
        case 116:
            // Grammar: ID=116; read/write bits=1; START (EVMaximumEnergyRequest)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=117
                error = encode_iso20_dc_RationalNumberType(stream, &Dynamic_DC_CLReqControlModeType->EVMaximumEnergyRequest);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 117;
                }
            }
            break;
        case 117:
            // Grammar: ID=117; read/write bits=1; START (EVMinimumEnergyRequest)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=118
                error = encode_iso20_dc_RationalNumberType(stream, &Dynamic_DC_CLReqControlModeType->EVMinimumEnergyRequest);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 118;
                }
            }
            break;
        case 118:
            // Grammar: ID=118; read/write bits=1; START (EVMaximumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=119
                error = encode_iso20_dc_RationalNumberType(stream, &Dynamic_DC_CLReqControlModeType->EVMaximumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 119;
                }
            }
            break;
        case 119:
            // Grammar: ID=119; read/write bits=1; START (EVMinimumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=120
                error = encode_iso20_dc_RationalNumberType(stream, &Dynamic_DC_CLReqControlModeType->EVMinimumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 120;
                }
            }
            break;
        case 120:
            // Grammar: ID=120; read/write bits=1; START (EVMaximumChargeCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=121
                error = encode_iso20_dc_RationalNumberType(stream, &Dynamic_DC_CLReqControlModeType->EVMaximumChargeCurrent);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 121;
                }
            }
            break;
        case 121:
            // Grammar: ID=121; read/write bits=1; START (EVMaximumVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=122
                error = encode_iso20_dc_RationalNumberType(stream, &Dynamic_DC_CLReqControlModeType->EVMaximumVoltage);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 122;
                }
            }
            break;
        case 122:
            // Grammar: ID=122; read/write bits=1; START (EVMinimumVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=2
                error = encode_iso20_dc_RationalNumberType(stream, &Dynamic_DC_CLReqControlModeType->EVMinimumVoltage);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}CLReqControlMode; type={urn:iso:std:iso:15118:-20:CommonTypes}CLReqControlModeType; base type=; content type=empty;
//          abstract=False; final=False;
static int encode_iso20_dc_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_dc_CLReqControlModeType* CLReqControlModeType) {
    // Element has no particles, so the function just returns zero
    (void)stream;
    (void)CLReqControlModeType;

    return 0;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}Receipt; type={urn:iso:std:iso:15118:-20:CommonTypes}ReceiptType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: TimeAnchor, unsignedLong (1, 1); EnergyCosts, DetailedCostType (0, 1); OccupancyCosts, DetailedCostType (0, 1); AdditionalServicesCosts, DetailedCostType (0, 1); OverstayCosts, DetailedCostType (0, 1); TaxCosts, DetailedTaxType (0, 10);
static int encode_iso20_dc_ReceiptType(exi_bitstream_t* stream, struct iso20_dc_ReceiptType* ReceiptType) {
    int grammar_id = 123;
    int done = 0;
    int error = 0;
    uint16_t TaxCosts_currentIndex = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 123:
            // Grammar: ID=123; read/write bits=1; START (TimeAnchor)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (nonNegativeInteger); next=124
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
                            grammar_id = 124;
                        }
                    }
                }
            }
            break;
        case 124:
            // Grammar: ID=124; read/write bits=3; START (EnergyCosts), START (OccupancyCosts), START (AdditionalServicesCosts), START (OverstayCosts), START (TaxCosts), END Element
            if (ReceiptType->EnergyCosts_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EnergyCosts, DetailedCostType); next=134
                    error = encode_iso20_dc_DetailedCostType(stream, &ReceiptType->EnergyCosts);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 134;
                    }
                }
            }
            else if (ReceiptType->OccupancyCosts_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (OccupancyCosts, DetailedCostType); next=144
                    error = encode_iso20_dc_DetailedCostType(stream, &ReceiptType->OccupancyCosts);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 144;
                    }
                }
            }
            else if (ReceiptType->AdditionalServicesCosts_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AdditionalServicesCosts, DetailedCostType); next=154
                    error = encode_iso20_dc_DetailedCostType(stream, &ReceiptType->AdditionalServicesCosts);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 154;
                    }
                }
            }
            else if (ReceiptType->OverstayCosts_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (OverstayCosts, DetailedCostType); next=164
                    error = encode_iso20_dc_DetailedCostType(stream, &ReceiptType->OverstayCosts);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 164;
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
        case 125:
            // Grammar: ID=125; read/write bits=2; START (TaxCosts), END Element
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
        case 126:
            // Grammar: ID=126; read/write bits=2; START (TaxCosts), END Element
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
        case 127:
            // Grammar: ID=127; read/write bits=2; START (TaxCosts), END Element
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
        case 128:
            // Grammar: ID=128; read/write bits=2; START (TaxCosts), END Element
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
        case 129:
            // Grammar: ID=129; read/write bits=2; START (TaxCosts), END Element
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
        case 130:
            // Grammar: ID=130; read/write bits=2; START (TaxCosts), END Element
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
        case 131:
            // Grammar: ID=131; read/write bits=2; START (TaxCosts), END Element
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
        case 132:
            // Grammar: ID=132; read/write bits=2; START (TaxCosts), END Element
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
        case 133:
            // Grammar: ID=133; read/write bits=2; START (TaxCosts), END Element
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
        case 134:
            // Grammar: ID=134; read/write bits=3; START (OccupancyCosts), START (AdditionalServicesCosts), START (OverstayCosts), START (TaxCosts), END Element
            if (ReceiptType->OccupancyCosts_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (OccupancyCosts, DetailedCostType); next=144
                    error = encode_iso20_dc_DetailedCostType(stream, &ReceiptType->OccupancyCosts);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 144;
                    }
                }
            }
            else if (ReceiptType->AdditionalServicesCosts_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AdditionalServicesCosts, DetailedCostType); next=154
                    error = encode_iso20_dc_DetailedCostType(stream, &ReceiptType->AdditionalServicesCosts);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 154;
                    }
                }
            }
            else if (ReceiptType->OverstayCosts_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (OverstayCosts, DetailedCostType); next=164
                    error = encode_iso20_dc_DetailedCostType(stream, &ReceiptType->OverstayCosts);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 164;
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
        case 135:
            // Grammar: ID=135; read/write bits=2; START (TaxCosts), END Element
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
        case 136:
            // Grammar: ID=136; read/write bits=2; START (TaxCosts), END Element
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
        case 137:
            // Grammar: ID=137; read/write bits=2; START (TaxCosts), END Element
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
        case 138:
            // Grammar: ID=138; read/write bits=2; START (TaxCosts), END Element
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
        case 139:
            // Grammar: ID=139; read/write bits=2; START (TaxCosts), END Element
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
        case 140:
            // Grammar: ID=140; read/write bits=2; START (TaxCosts), END Element
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
            // Grammar: ID=144; read/write bits=3; START (AdditionalServicesCosts), START (OverstayCosts), START (TaxCosts), END Element
            if (ReceiptType->AdditionalServicesCosts_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AdditionalServicesCosts, DetailedCostType); next=154
                    error = encode_iso20_dc_DetailedCostType(stream, &ReceiptType->AdditionalServicesCosts);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 154;
                    }
                }
            }
            else if (ReceiptType->OverstayCosts_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (OverstayCosts, DetailedCostType); next=164
                    error = encode_iso20_dc_DetailedCostType(stream, &ReceiptType->OverstayCosts);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 164;
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
            // Grammar: ID=150; read/write bits=2; START (TaxCosts), END Element
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
            // Grammar: ID=154; read/write bits=2; START (OverstayCosts), START (TaxCosts), END Element
            if (ReceiptType->OverstayCosts_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (OverstayCosts, DetailedCostType); next=164
                    error = encode_iso20_dc_DetailedCostType(stream, &ReceiptType->OverstayCosts);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 164;
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
            // Grammar: ID=160; read/write bits=2; START (TaxCosts), END Element
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
            // Grammar: ID=170; read/write bits=2; START (TaxCosts), END Element
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}Scheduled_DC_CLResControlMode; type={urn:iso:std:iso:15118:-20:DC}Scheduled_DC_CLResControlModeType; base type=Scheduled_CLResControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVSEMaximumChargePower, RationalNumberType (0, 1); EVSEMinimumChargePower, RationalNumberType (0, 1); EVSEMaximumChargeCurrent, RationalNumberType (0, 1); EVSEMaximumVoltage, RationalNumberType (0, 1);
static int encode_iso20_dc_Scheduled_DC_CLResControlModeType(exi_bitstream_t* stream, struct iso20_dc_Scheduled_DC_CLResControlModeType* Scheduled_DC_CLResControlModeType) {
    int grammar_id = 174;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 174:
            // Grammar: ID=174; read/write bits=3; START (EVSEMaximumChargePower), START (EVSEMinimumChargePower), START (EVSEMaximumChargeCurrent), START (EVSEMaximumVoltage), END Element
            if (Scheduled_DC_CLResControlModeType->EVSEMaximumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumChargePower, RationalNumberType); next=175
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLResControlModeType->EVSEMaximumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 175;
                    }
                }
            }
            else if (Scheduled_DC_CLResControlModeType->EVSEMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumChargePower, RationalNumberType); next=176
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLResControlModeType->EVSEMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 176;
                    }
                }
            }
            else if (Scheduled_DC_CLResControlModeType->EVSEMaximumChargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumChargeCurrent, RationalNumberType); next=177
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLResControlModeType->EVSEMaximumChargeCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 177;
                    }
                }
            }
            else if (Scheduled_DC_CLResControlModeType->EVSEMaximumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumVoltage, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLResControlModeType->EVSEMaximumVoltage);
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
        case 175:
            // Grammar: ID=175; read/write bits=3; START (EVSEMinimumChargePower), START (EVSEMaximumChargeCurrent), START (EVSEMaximumVoltage), END Element
            if (Scheduled_DC_CLResControlModeType->EVSEMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumChargePower, RationalNumberType); next=176
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLResControlModeType->EVSEMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 176;
                    }
                }
            }
            else if (Scheduled_DC_CLResControlModeType->EVSEMaximumChargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumChargeCurrent, RationalNumberType); next=177
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLResControlModeType->EVSEMaximumChargeCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 177;
                    }
                }
            }
            else if (Scheduled_DC_CLResControlModeType->EVSEMaximumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumVoltage, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLResControlModeType->EVSEMaximumVoltage);
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
        case 176:
            // Grammar: ID=176; read/write bits=2; START (EVSEMaximumChargeCurrent), START (EVSEMaximumVoltage), END Element
            if (Scheduled_DC_CLResControlModeType->EVSEMaximumChargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumChargeCurrent, RationalNumberType); next=177
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLResControlModeType->EVSEMaximumChargeCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 177;
                    }
                }
            }
            else if (Scheduled_DC_CLResControlModeType->EVSEMaximumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumVoltage, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLResControlModeType->EVSEMaximumVoltage);
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
        case 177:
            // Grammar: ID=177; read/write bits=2; START (EVSEMaximumVoltage), END Element
            if (Scheduled_DC_CLResControlModeType->EVSEMaximumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumVoltage, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &Scheduled_DC_CLResControlModeType->EVSEMaximumVoltage);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}Dynamic_DC_CLResControlMode; type={urn:iso:std:iso:15118:-20:DC}Dynamic_DC_CLResControlModeType; base type=Dynamic_CLResControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DepartureTime, unsignedInt (0, 1); MinimumSOC, percentValueType (0, 1); TargetSOC, percentValueType (0, 1); AckMaxDelay, unsignedShort (0, 1); EVSEMaximumChargePower, RationalNumberType (1, 1); EVSEMinimumChargePower, RationalNumberType (1, 1); EVSEMaximumChargeCurrent, RationalNumberType (1, 1); EVSEMaximumVoltage, RationalNumberType (1, 1);
static int encode_iso20_dc_Dynamic_DC_CLResControlModeType(exi_bitstream_t* stream, struct iso20_dc_Dynamic_DC_CLResControlModeType* Dynamic_DC_CLResControlModeType) {
    int grammar_id = 178;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 178:
            // Grammar: ID=178; read/write bits=3; START (DepartureTime), START (MinimumSOC), START (TargetSOC), START (AckMaxDelay), START (EVSEMaximumChargePower)
            if (Dynamic_DC_CLResControlModeType->DepartureTime_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (DepartureTime, unsignedLong); next=179
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, Dynamic_DC_CLResControlModeType->DepartureTime);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 179;
                            }
                        }
                    }
                }
            }
            else if (Dynamic_DC_CLResControlModeType->MinimumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MinimumSOC, byte); next=180
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)Dynamic_DC_CLResControlModeType->MinimumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 180;
                            }
                        }
                    }
                }
            }
            else if (Dynamic_DC_CLResControlModeType->TargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (TargetSOC, byte); next=181
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)Dynamic_DC_CLResControlModeType->TargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 181;
                            }
                        }
                    }
                }
            }
            else if (Dynamic_DC_CLResControlModeType->AckMaxDelay_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AckMaxDelay, unsignedInt); next=182
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, Dynamic_DC_CLResControlModeType->AckMaxDelay);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 182;
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
                    // Event: START (EVSEMaximumChargePower, RationalNumberType); next=183
                    error = encode_iso20_dc_RationalNumberType(stream, &Dynamic_DC_CLResControlModeType->EVSEMaximumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 183;
                    }
                }
            }
            break;
        case 179:
            // Grammar: ID=179; read/write bits=3; START (MinimumSOC), START (TargetSOC), START (AckMaxDelay), START (EVSEMaximumChargePower)
            if (Dynamic_DC_CLResControlModeType->MinimumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MinimumSOC, byte); next=180
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)Dynamic_DC_CLResControlModeType->MinimumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 180;
                            }
                        }
                    }
                }
            }
            else if (Dynamic_DC_CLResControlModeType->TargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (TargetSOC, byte); next=181
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)Dynamic_DC_CLResControlModeType->TargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 181;
                            }
                        }
                    }
                }
            }
            else if (Dynamic_DC_CLResControlModeType->AckMaxDelay_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AckMaxDelay, unsignedInt); next=182
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, Dynamic_DC_CLResControlModeType->AckMaxDelay);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 182;
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
                    // Event: START (EVSEMaximumChargePower, RationalNumberType); next=183
                    error = encode_iso20_dc_RationalNumberType(stream, &Dynamic_DC_CLResControlModeType->EVSEMaximumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 183;
                    }
                }
            }
            break;
        case 180:
            // Grammar: ID=180; read/write bits=2; START (TargetSOC), START (AckMaxDelay), START (EVSEMaximumChargePower)
            if (Dynamic_DC_CLResControlModeType->TargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (TargetSOC, byte); next=181
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)Dynamic_DC_CLResControlModeType->TargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 181;
                            }
                        }
                    }
                }
            }
            else if (Dynamic_DC_CLResControlModeType->AckMaxDelay_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AckMaxDelay, unsignedInt); next=182
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, Dynamic_DC_CLResControlModeType->AckMaxDelay);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 182;
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
                    // Event: START (EVSEMaximumChargePower, RationalNumberType); next=183
                    error = encode_iso20_dc_RationalNumberType(stream, &Dynamic_DC_CLResControlModeType->EVSEMaximumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 183;
                    }
                }
            }
            break;
        case 181:
            // Grammar: ID=181; read/write bits=2; START (AckMaxDelay), START (EVSEMaximumChargePower)
            if (Dynamic_DC_CLResControlModeType->AckMaxDelay_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AckMaxDelay, unsignedInt); next=182
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, Dynamic_DC_CLResControlModeType->AckMaxDelay);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 182;
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
                    // Event: START (EVSEMaximumChargePower, RationalNumberType); next=183
                    error = encode_iso20_dc_RationalNumberType(stream, &Dynamic_DC_CLResControlModeType->EVSEMaximumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 183;
                    }
                }
            }
            break;
        case 182:
            // Grammar: ID=182; read/write bits=1; START (EVSEMaximumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=183
                error = encode_iso20_dc_RationalNumberType(stream, &Dynamic_DC_CLResControlModeType->EVSEMaximumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 183;
                }
            }
            break;
        case 183:
            // Grammar: ID=183; read/write bits=1; START (EVSEMinimumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=184
                error = encode_iso20_dc_RationalNumberType(stream, &Dynamic_DC_CLResControlModeType->EVSEMinimumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 184;
                }
            }
            break;
        case 184:
            // Grammar: ID=184; read/write bits=1; START (EVSEMaximumChargeCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=185
                error = encode_iso20_dc_RationalNumberType(stream, &Dynamic_DC_CLResControlModeType->EVSEMaximumChargeCurrent);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 185;
                }
            }
            break;
        case 185:
            // Grammar: ID=185; read/write bits=1; START (EVSEMaximumVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=2
                error = encode_iso20_dc_RationalNumberType(stream, &Dynamic_DC_CLResControlModeType->EVSEMaximumVoltage);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}CLResControlMode; type={urn:iso:std:iso:15118:-20:CommonTypes}CLResControlModeType; base type=; content type=empty;
//          abstract=False; final=False;
static int encode_iso20_dc_CLResControlModeType(exi_bitstream_t* stream, struct iso20_dc_CLResControlModeType* CLResControlModeType) {
    // Element has no particles, so the function just returns zero
    (void)stream;
    (void)CLResControlModeType;

    return 0;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}DC_CableCheckReq; type={urn:iso:std:iso:15118:-20:DC}DC_CableCheckReqType; base type=V2GRequestType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1);
static int encode_iso20_dc_DC_CableCheckReqType(exi_bitstream_t* stream, struct iso20_dc_DC_CableCheckReqType* DC_CableCheckReqType) {
    int grammar_id = 186;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 186:
            // Grammar: ID=186; read/write bits=1; START (Header)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (MessageHeaderType); next=2
                error = encode_iso20_dc_MessageHeaderType(stream, &DC_CableCheckReqType->Header);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}DC_CableCheckRes; type={urn:iso:std:iso:15118:-20:DC}DC_CableCheckResType; base type=V2GResponseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); EVSEProcessing, processingType (1, 1);
static int encode_iso20_dc_DC_CableCheckResType(exi_bitstream_t* stream, struct iso20_dc_DC_CableCheckResType* DC_CableCheckResType) {
    int grammar_id = 187;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 187:
            // Grammar: ID=187; read/write bits=1; START (Header)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (MessageHeaderType); next=188
                error = encode_iso20_dc_MessageHeaderType(stream, &DC_CableCheckResType->Header);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 188;
                }
            }
            break;
        case 188:
            // Grammar: ID=188; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (string); next=189
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_nbit_uint(stream, 6, DC_CableCheckResType->ResponseCode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 189;
                        }
                    }
                }
            }
            break;
        case 189:
            // Grammar: ID=189; read/write bits=1; START (EVSEProcessing)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (string); next=2
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_nbit_uint(stream, 2, DC_CableCheckResType->EVSEProcessing);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}DC_PreChargeReq; type={urn:iso:std:iso:15118:-20:DC}DC_PreChargeReqType; base type=V2GRequestType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); EVProcessing, processingType (1, 1); EVPresentVoltage, RationalNumberType (1, 1); EVTargetVoltage, RationalNumberType (1, 1);
static int encode_iso20_dc_DC_PreChargeReqType(exi_bitstream_t* stream, struct iso20_dc_DC_PreChargeReqType* DC_PreChargeReqType) {
    int grammar_id = 190;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 190:
            // Grammar: ID=190; read/write bits=1; START (Header)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (MessageHeaderType); next=191
                error = encode_iso20_dc_MessageHeaderType(stream, &DC_PreChargeReqType->Header);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 191;
                }
            }
            break;
        case 191:
            // Grammar: ID=191; read/write bits=1; START (EVProcessing)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (string); next=192
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_nbit_uint(stream, 2, DC_PreChargeReqType->EVProcessing);
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
            break;
        case 192:
            // Grammar: ID=192; read/write bits=1; START (EVPresentVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=193
                error = encode_iso20_dc_RationalNumberType(stream, &DC_PreChargeReqType->EVPresentVoltage);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 193;
                }
            }
            break;
        case 193:
            // Grammar: ID=193; read/write bits=1; START (EVTargetVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=2
                error = encode_iso20_dc_RationalNumberType(stream, &DC_PreChargeReqType->EVTargetVoltage);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}DC_PreChargeRes; type={urn:iso:std:iso:15118:-20:DC}DC_PreChargeResType; base type=V2GResponseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); EVSEPresentVoltage, RationalNumberType (1, 1);
static int encode_iso20_dc_DC_PreChargeResType(exi_bitstream_t* stream, struct iso20_dc_DC_PreChargeResType* DC_PreChargeResType) {
    int grammar_id = 194;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 194:
            // Grammar: ID=194; read/write bits=1; START (Header)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (MessageHeaderType); next=195
                error = encode_iso20_dc_MessageHeaderType(stream, &DC_PreChargeResType->Header);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 195;
                }
            }
            break;
        case 195:
            // Grammar: ID=195; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (string); next=196
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_nbit_uint(stream, 6, DC_PreChargeResType->ResponseCode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 196;
                        }
                    }
                }
            }
            break;
        case 196:
            // Grammar: ID=196; read/write bits=1; START (EVSEPresentVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=2
                error = encode_iso20_dc_RationalNumberType(stream, &DC_PreChargeResType->EVSEPresentVoltage);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}DC_WeldingDetectionReq; type={urn:iso:std:iso:15118:-20:DC}DC_WeldingDetectionReqType; base type=V2GRequestType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); EVProcessing, processingType (1, 1);
static int encode_iso20_dc_DC_WeldingDetectionReqType(exi_bitstream_t* stream, struct iso20_dc_DC_WeldingDetectionReqType* DC_WeldingDetectionReqType) {
    int grammar_id = 197;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 197:
            // Grammar: ID=197; read/write bits=1; START (Header)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (MessageHeaderType); next=198
                error = encode_iso20_dc_MessageHeaderType(stream, &DC_WeldingDetectionReqType->Header);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 198;
                }
            }
            break;
        case 198:
            // Grammar: ID=198; read/write bits=1; START (EVProcessing)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (string); next=2
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_nbit_uint(stream, 2, DC_WeldingDetectionReqType->EVProcessing);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}DC_WeldingDetectionRes; type={urn:iso:std:iso:15118:-20:DC}DC_WeldingDetectionResType; base type=V2GResponseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); EVSEPresentVoltage, RationalNumberType (1, 1);
static int encode_iso20_dc_DC_WeldingDetectionResType(exi_bitstream_t* stream, struct iso20_dc_DC_WeldingDetectionResType* DC_WeldingDetectionResType) {
    int grammar_id = 199;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 199:
            // Grammar: ID=199; read/write bits=1; START (Header)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (MessageHeaderType); next=200
                error = encode_iso20_dc_MessageHeaderType(stream, &DC_WeldingDetectionResType->Header);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 200;
                }
            }
            break;
        case 200:
            // Grammar: ID=200; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (string); next=201
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_nbit_uint(stream, 6, DC_WeldingDetectionResType->ResponseCode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 201;
                        }
                    }
                }
            }
            break;
        case 201:
            // Grammar: ID=201; read/write bits=1; START (EVSEPresentVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=2
                error = encode_iso20_dc_RationalNumberType(stream, &DC_WeldingDetectionResType->EVSEPresentVoltage);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}BPT_DC_CPDReqEnergyTransferMode; type={urn:iso:std:iso:15118:-20:DC}BPT_DC_CPDReqEnergyTransferModeType; base type=DC_CPDReqEnergyTransferModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVMaximumChargePower, RationalNumberType (1, 1); EVMinimumChargePower, RationalNumberType (1, 1); EVMaximumChargeCurrent, RationalNumberType (1, 1); EVMinimumChargeCurrent, RationalNumberType (1, 1); EVMaximumVoltage, RationalNumberType (1, 1); EVMinimumVoltage, RationalNumberType (1, 1); TargetSOC, percentValueType (0, 1); EVMaximumDischargePower, RationalNumberType (1, 1); EVMinimumDischargePower, RationalNumberType (1, 1); EVMaximumDischargeCurrent, RationalNumberType (1, 1); EVMinimumDischargeCurrent, RationalNumberType (1, 1);
static int encode_iso20_dc_BPT_DC_CPDReqEnergyTransferModeType(exi_bitstream_t* stream, struct iso20_dc_BPT_DC_CPDReqEnergyTransferModeType* BPT_DC_CPDReqEnergyTransferModeType) {
    int grammar_id = 202;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 202:
            // Grammar: ID=202; read/write bits=1; START (EVMaximumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=203
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDReqEnergyTransferModeType->EVMaximumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 203;
                }
            }
            break;
        case 203:
            // Grammar: ID=203; read/write bits=1; START (EVMinimumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=204
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDReqEnergyTransferModeType->EVMinimumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 204;
                }
            }
            break;
        case 204:
            // Grammar: ID=204; read/write bits=1; START (EVMaximumChargeCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=205
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDReqEnergyTransferModeType->EVMaximumChargeCurrent);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 205;
                }
            }
            break;
        case 205:
            // Grammar: ID=205; read/write bits=1; START (EVMinimumChargeCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=206
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDReqEnergyTransferModeType->EVMinimumChargeCurrent);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 206;
                }
            }
            break;
        case 206:
            // Grammar: ID=206; read/write bits=1; START (EVMaximumVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=207
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDReqEnergyTransferModeType->EVMaximumVoltage);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 207;
                }
            }
            break;
        case 207:
            // Grammar: ID=207; read/write bits=1; START (EVMinimumVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=208
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDReqEnergyTransferModeType->EVMinimumVoltage);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 208;
                }
            }
            break;
        case 208:
            // Grammar: ID=208; read/write bits=2; START (TargetSOC), START (EVMaximumDischargePower)
            if (BPT_DC_CPDReqEnergyTransferModeType->TargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (TargetSOC, byte); next=209
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)BPT_DC_CPDReqEnergyTransferModeType->TargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 209;
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
                    // Event: START (EVMaximumDischargePower, RationalNumberType); next=210
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDReqEnergyTransferModeType->EVMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 210;
                    }
                }
            }
            break;
        case 209:
            // Grammar: ID=209; read/write bits=1; START (EVMaximumDischargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=210
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDReqEnergyTransferModeType->EVMaximumDischargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 210;
                }
            }
            break;
        case 210:
            // Grammar: ID=210; read/write bits=1; START (EVMinimumDischargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=211
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDReqEnergyTransferModeType->EVMinimumDischargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 211;
                }
            }
            break;
        case 211:
            // Grammar: ID=211; read/write bits=1; START (EVMaximumDischargeCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=212
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDReqEnergyTransferModeType->EVMaximumDischargeCurrent);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 212;
                }
            }
            break;
        case 212:
            // Grammar: ID=212; read/write bits=1; START (EVMinimumDischargeCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=2
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDReqEnergyTransferModeType->EVMinimumDischargeCurrent);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}DC_ChargeParameterDiscoveryReq; type={urn:iso:std:iso:15118:-20:DC}DC_ChargeParameterDiscoveryReqType; base type=ChargeParameterDiscoveryReqType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); BPT_DC_CPDReqEnergyTransferMode, BPT_DC_CPDReqEnergyTransferModeType (0, 1); DC_CPDReqEnergyTransferMode, DC_CPDReqEnergyTransferModeType (0, 1);
static int encode_iso20_dc_DC_ChargeParameterDiscoveryReqType(exi_bitstream_t* stream, struct iso20_dc_DC_ChargeParameterDiscoveryReqType* DC_ChargeParameterDiscoveryReqType) {
    int grammar_id = 213;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 213:
            // Grammar: ID=213; read/write bits=1; START (Header)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (MessageHeaderType); next=214
                error = encode_iso20_dc_MessageHeaderType(stream, &DC_ChargeParameterDiscoveryReqType->Header);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 214;
                }
            }
            break;
        case 214:
            // Grammar: ID=214; read/write bits=2; START (BPT_DC_CPDReqEnergyTransferMode), START (DC_CPDReqEnergyTransferMode)
            if (DC_ChargeParameterDiscoveryReqType->BPT_DC_CPDReqEnergyTransferMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_DC_CPDReqEnergyTransferMode, DC_CPDReqEnergyTransferModeType); next=2
                    error = encode_iso20_dc_BPT_DC_CPDReqEnergyTransferModeType(stream, &DC_ChargeParameterDiscoveryReqType->BPT_DC_CPDReqEnergyTransferMode);
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
                    // Event: START (DC_CPDReqEnergyTransferMode, DC_CPDReqEnergyTransferModeType); next=2
                    error = encode_iso20_dc_DC_CPDReqEnergyTransferModeType(stream, &DC_ChargeParameterDiscoveryReqType->DC_CPDReqEnergyTransferMode);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}BPT_DC_CPDResEnergyTransferMode; type={urn:iso:std:iso:15118:-20:DC}BPT_DC_CPDResEnergyTransferModeType; base type=DC_CPDResEnergyTransferModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVSEMaximumChargePower, RationalNumberType (1, 1); EVSEMinimumChargePower, RationalNumberType (1, 1); EVSEMaximumChargeCurrent, RationalNumberType (1, 1); EVSEMinimumChargeCurrent, RationalNumberType (1, 1); EVSEMaximumVoltage, RationalNumberType (1, 1); EVSEMinimumVoltage, RationalNumberType (1, 1); EVSEPowerRampLimitation, RationalNumberType (0, 1); EVSEMaximumDischargePower, RationalNumberType (1, 1); EVSEMinimumDischargePower, RationalNumberType (1, 1); EVSEMaximumDischargeCurrent, RationalNumberType (1, 1); EVSEMinimumDischargeCurrent, RationalNumberType (1, 1);
static int encode_iso20_dc_BPT_DC_CPDResEnergyTransferModeType(exi_bitstream_t* stream, struct iso20_dc_BPT_DC_CPDResEnergyTransferModeType* BPT_DC_CPDResEnergyTransferModeType) {
    int grammar_id = 215;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 215:
            // Grammar: ID=215; read/write bits=1; START (EVSEMaximumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=216
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDResEnergyTransferModeType->EVSEMaximumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 216;
                }
            }
            break;
        case 216:
            // Grammar: ID=216; read/write bits=1; START (EVSEMinimumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=217
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDResEnergyTransferModeType->EVSEMinimumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 217;
                }
            }
            break;
        case 217:
            // Grammar: ID=217; read/write bits=1; START (EVSEMaximumChargeCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=218
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDResEnergyTransferModeType->EVSEMaximumChargeCurrent);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 218;
                }
            }
            break;
        case 218:
            // Grammar: ID=218; read/write bits=1; START (EVSEMinimumChargeCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=219
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDResEnergyTransferModeType->EVSEMinimumChargeCurrent);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 219;
                }
            }
            break;
        case 219:
            // Grammar: ID=219; read/write bits=1; START (EVSEMaximumVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=220
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDResEnergyTransferModeType->EVSEMaximumVoltage);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 220;
                }
            }
            break;
        case 220:
            // Grammar: ID=220; read/write bits=1; START (EVSEMinimumVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=221
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDResEnergyTransferModeType->EVSEMinimumVoltage);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 221;
                }
            }
            break;
        case 221:
            // Grammar: ID=221; read/write bits=2; START (EVSEPowerRampLimitation), START (EVSEMaximumDischargePower)
            if (BPT_DC_CPDResEnergyTransferModeType->EVSEPowerRampLimitation_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPowerRampLimitation, RationalNumberType); next=222
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDResEnergyTransferModeType->EVSEPowerRampLimitation);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 222;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargePower, RationalNumberType); next=223
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDResEnergyTransferModeType->EVSEMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 223;
                    }
                }
            }
            break;
        case 222:
            // Grammar: ID=222; read/write bits=1; START (EVSEMaximumDischargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=223
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDResEnergyTransferModeType->EVSEMaximumDischargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 223;
                }
            }
            break;
        case 223:
            // Grammar: ID=223; read/write bits=1; START (EVSEMinimumDischargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=224
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDResEnergyTransferModeType->EVSEMinimumDischargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 224;
                }
            }
            break;
        case 224:
            // Grammar: ID=224; read/write bits=1; START (EVSEMaximumDischargeCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=225
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDResEnergyTransferModeType->EVSEMaximumDischargeCurrent);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 225;
                }
            }
            break;
        case 225:
            // Grammar: ID=225; read/write bits=1; START (EVSEMinimumDischargeCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=2
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_DC_CPDResEnergyTransferModeType->EVSEMinimumDischargeCurrent);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}DC_ChargeParameterDiscoveryRes; type={urn:iso:std:iso:15118:-20:DC}DC_ChargeParameterDiscoveryResType; base type=ChargeParameterDiscoveryResType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); BPT_DC_CPDResEnergyTransferMode, BPT_DC_CPDResEnergyTransferModeType (0, 1); DC_CPDResEnergyTransferMode, DC_CPDResEnergyTransferModeType (0, 1);
static int encode_iso20_dc_DC_ChargeParameterDiscoveryResType(exi_bitstream_t* stream, struct iso20_dc_DC_ChargeParameterDiscoveryResType* DC_ChargeParameterDiscoveryResType) {
    int grammar_id = 226;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 226:
            // Grammar: ID=226; read/write bits=1; START (Header)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (MessageHeaderType); next=227
                error = encode_iso20_dc_MessageHeaderType(stream, &DC_ChargeParameterDiscoveryResType->Header);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 227;
                }
            }
            break;
        case 227:
            // Grammar: ID=227; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (string); next=228
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_nbit_uint(stream, 6, DC_ChargeParameterDiscoveryResType->ResponseCode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 228;
                        }
                    }
                }
            }
            break;
        case 228:
            // Grammar: ID=228; read/write bits=2; START (BPT_DC_CPDResEnergyTransferMode), START (DC_CPDResEnergyTransferMode)
            if (DC_ChargeParameterDiscoveryResType->BPT_DC_CPDResEnergyTransferMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_DC_CPDResEnergyTransferMode, DC_CPDResEnergyTransferModeType); next=2
                    error = encode_iso20_dc_BPT_DC_CPDResEnergyTransferModeType(stream, &DC_ChargeParameterDiscoveryResType->BPT_DC_CPDResEnergyTransferMode);
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
                    // Event: START (DC_CPDResEnergyTransferMode, DC_CPDResEnergyTransferModeType); next=2
                    error = encode_iso20_dc_DC_CPDResEnergyTransferModeType(stream, &DC_ChargeParameterDiscoveryResType->DC_CPDResEnergyTransferMode);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}BPT_Scheduled_DC_CLReqControlMode; type={urn:iso:std:iso:15118:-20:DC}BPT_Scheduled_DC_CLReqControlModeType; base type=Scheduled_DC_CLReqControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVTargetEnergyRequest, RationalNumberType (0, 1); EVMaximumEnergyRequest, RationalNumberType (0, 1); EVMinimumEnergyRequest, RationalNumberType (0, 1); EVTargetCurrent, RationalNumberType (1, 1); EVTargetVoltage, RationalNumberType (1, 1); EVMaximumChargePower, RationalNumberType (0, 1); EVMinimumChargePower, RationalNumberType (0, 1); EVMaximumChargeCurrent, RationalNumberType (0, 1); EVMaximumVoltage, RationalNumberType (0, 1); EVMinimumVoltage, RationalNumberType (0, 1); EVMaximumDischargePower, RationalNumberType (0, 1); EVMinimumDischargePower, RationalNumberType (0, 1); EVMaximumDischargeCurrent, RationalNumberType (0, 1);
static int encode_iso20_dc_BPT_Scheduled_DC_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_dc_BPT_Scheduled_DC_CLReqControlModeType* BPT_Scheduled_DC_CLReqControlModeType) {
    int grammar_id = 229;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 229:
            // Grammar: ID=229; read/write bits=3; START (EVTargetEnergyRequest), START (EVMaximumEnergyRequest), START (EVMinimumEnergyRequest), START (EVTargetCurrent)
            if (BPT_Scheduled_DC_CLReqControlModeType->EVTargetEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVTargetEnergyRequest, RationalNumberType); next=230
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVTargetEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 230;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumEnergyRequest, RationalNumberType); next=231
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 231;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMinimumEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumEnergyRequest, RationalNumberType); next=232
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMinimumEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 232;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVTargetCurrent, RationalNumberType); next=233
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVTargetCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 233;
                    }
                }
            }
            break;
        case 230:
            // Grammar: ID=230; read/write bits=2; START (EVMaximumEnergyRequest), START (EVMinimumEnergyRequest), START (EVTargetCurrent)
            if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumEnergyRequest, RationalNumberType); next=231
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 231;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMinimumEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumEnergyRequest, RationalNumberType); next=232
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMinimumEnergyRequest);
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
                    // Event: START (EVTargetCurrent, RationalNumberType); next=233
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVTargetCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 233;
                    }
                }
            }
            break;
        case 231:
            // Grammar: ID=231; read/write bits=2; START (EVMinimumEnergyRequest), START (EVTargetCurrent)
            if (BPT_Scheduled_DC_CLReqControlModeType->EVMinimumEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumEnergyRequest, RationalNumberType); next=232
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMinimumEnergyRequest);
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
                    // Event: START (EVTargetCurrent, RationalNumberType); next=233
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVTargetCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 233;
                    }
                }
            }
            break;
        case 232:
            // Grammar: ID=232; read/write bits=1; START (EVTargetCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=233
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVTargetCurrent);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 233;
                }
            }
            break;
        case 233:
            // Grammar: ID=233; read/write bits=1; START (EVTargetVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=234
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVTargetVoltage);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 234;
                }
            }
            break;
        case 234:
            // Grammar: ID=234; read/write bits=4; START (EVMaximumChargePower), START (EVMinimumChargePower), START (EVMaximumChargeCurrent), START (EVMaximumVoltage), START (EVMinimumVoltage), START (EVMaximumDischargePower), START (EVMinimumDischargePower), START (EVMaximumDischargeCurrent), END Element
            if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargePower, RationalNumberType); next=235
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 235;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=236
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 236;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumChargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargeCurrent, RationalNumberType); next=237
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumChargeCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 237;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumVoltage, RationalNumberType); next=238
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumVoltage);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 238;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMinimumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumVoltage, RationalNumberType); next=239
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMinimumVoltage);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 239;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower, RationalNumberType); next=240
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 240;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower, RationalNumberType); next=241
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 241;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargeCurrent, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargeCurrent);
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
        case 235:
            // Grammar: ID=235; read/write bits=4; START (EVMinimumChargePower), START (EVMaximumChargeCurrent), START (EVMaximumVoltage), START (EVMinimumVoltage), START (EVMaximumDischargePower), START (EVMinimumDischargePower), START (EVMaximumDischargeCurrent), END Element
            if (BPT_Scheduled_DC_CLReqControlModeType->EVMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumChargePower, RationalNumberType); next=236
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 236;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumChargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargeCurrent, RationalNumberType); next=237
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumChargeCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 237;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumVoltage, RationalNumberType); next=238
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumVoltage);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 238;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMinimumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumVoltage, RationalNumberType); next=239
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMinimumVoltage);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 239;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower, RationalNumberType); next=240
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 240;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower, RationalNumberType); next=241
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 241;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargeCurrent, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargeCurrent);
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
        case 236:
            // Grammar: ID=236; read/write bits=3; START (EVMaximumChargeCurrent), START (EVMaximumVoltage), START (EVMinimumVoltage), START (EVMaximumDischargePower), START (EVMinimumDischargePower), START (EVMaximumDischargeCurrent), END Element
            if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumChargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumChargeCurrent, RationalNumberType); next=237
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumChargeCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 237;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumVoltage, RationalNumberType); next=238
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumVoltage);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 238;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMinimumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumVoltage, RationalNumberType); next=239
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMinimumVoltage);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 239;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower, RationalNumberType); next=240
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 240;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower, RationalNumberType); next=241
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 241;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargeCurrent, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargeCurrent);
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
        case 237:
            // Grammar: ID=237; read/write bits=3; START (EVMaximumVoltage), START (EVMinimumVoltage), START (EVMaximumDischargePower), START (EVMinimumDischargePower), START (EVMaximumDischargeCurrent), END Element
            if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumVoltage, RationalNumberType); next=238
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumVoltage);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 238;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMinimumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumVoltage, RationalNumberType); next=239
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMinimumVoltage);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 239;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower, RationalNumberType); next=240
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 240;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower, RationalNumberType); next=241
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 241;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargeCurrent, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargeCurrent);
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
        case 238:
            // Grammar: ID=238; read/write bits=3; START (EVMinimumVoltage), START (EVMaximumDischargePower), START (EVMinimumDischargePower), START (EVMaximumDischargeCurrent), END Element
            if (BPT_Scheduled_DC_CLReqControlModeType->EVMinimumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumVoltage, RationalNumberType); next=239
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMinimumVoltage);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 239;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower, RationalNumberType); next=240
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 240;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower, RationalNumberType); next=241
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 241;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargeCurrent, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargeCurrent);
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
        case 239:
            // Grammar: ID=239; read/write bits=3; START (EVMaximumDischargePower), START (EVMinimumDischargePower), START (EVMaximumDischargeCurrent), END Element
            if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargePower, RationalNumberType); next=240
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 240;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower, RationalNumberType); next=241
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 241;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargeCurrent, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargeCurrent);
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
        case 240:
            // Grammar: ID=240; read/write bits=2; START (EVMinimumDischargePower), START (EVMaximumDischargeCurrent), END Element
            if (BPT_Scheduled_DC_CLReqControlModeType->EVMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumDischargePower, RationalNumberType); next=241
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 241;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargeCurrent, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargeCurrent);
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
        case 241:
            // Grammar: ID=241; read/write bits=2; START (EVMaximumDischargeCurrent), END Element
            if (BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumDischargeCurrent, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLReqControlModeType->EVMaximumDischargeCurrent);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}BPT_Scheduled_DC_CLResControlMode; type={urn:iso:std:iso:15118:-20:DC}BPT_Scheduled_DC_CLResControlModeType; base type=Scheduled_DC_CLResControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: EVSEMaximumChargePower, RationalNumberType (0, 1); EVSEMinimumChargePower, RationalNumberType (0, 1); EVSEMaximumChargeCurrent, RationalNumberType (0, 1); EVSEMaximumVoltage, RationalNumberType (0, 1); EVSEMaximumDischargePower, RationalNumberType (0, 1); EVSEMinimumDischargePower, RationalNumberType (0, 1); EVSEMaximumDischargeCurrent, RationalNumberType (0, 1); EVSEMinimumVoltage, RationalNumberType (0, 1);
static int encode_iso20_dc_BPT_Scheduled_DC_CLResControlModeType(exi_bitstream_t* stream, struct iso20_dc_BPT_Scheduled_DC_CLResControlModeType* BPT_Scheduled_DC_CLResControlModeType) {
    int grammar_id = 242;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 242:
            // Grammar: ID=242; read/write bits=4; START (EVSEMaximumChargePower), START (EVSEMinimumChargePower), START (EVSEMaximumChargeCurrent), START (EVSEMaximumVoltage), START (EVSEMaximumDischargePower), START (EVSEMinimumDischargePower), START (EVSEMaximumDischargeCurrent), START (EVSEMinimumVoltage), END Element
            if (BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumChargePower, RationalNumberType); next=243
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 243;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumChargePower, RationalNumberType); next=244
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 244;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumChargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumChargeCurrent, RationalNumberType); next=245
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumChargeCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 245;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumVoltage, RationalNumberType); next=246
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumVoltage);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 246;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargePower, RationalNumberType); next=247
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 247;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumDischargePower, RationalNumberType); next=248
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 248;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargeCurrent, RationalNumberType); next=249
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargeCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 249;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 7);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumVoltage, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumVoltage);
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
        case 243:
            // Grammar: ID=243; read/write bits=4; START (EVSEMinimumChargePower), START (EVSEMaximumChargeCurrent), START (EVSEMaximumVoltage), START (EVSEMaximumDischargePower), START (EVSEMinimumDischargePower), START (EVSEMaximumDischargeCurrent), START (EVSEMinimumVoltage), END Element
            if (BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumChargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumChargePower, RationalNumberType); next=244
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 244;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumChargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumChargeCurrent, RationalNumberType); next=245
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumChargeCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 245;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumVoltage, RationalNumberType); next=246
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumVoltage);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 246;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargePower, RationalNumberType); next=247
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 247;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumDischargePower, RationalNumberType); next=248
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 248;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargeCurrent, RationalNumberType); next=249
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargeCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 249;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 4, 6);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumVoltage, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumVoltage);
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
        case 244:
            // Grammar: ID=244; read/write bits=3; START (EVSEMaximumChargeCurrent), START (EVSEMaximumVoltage), START (EVSEMaximumDischargePower), START (EVSEMinimumDischargePower), START (EVSEMaximumDischargeCurrent), START (EVSEMinimumVoltage), END Element
            if (BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumChargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumChargeCurrent, RationalNumberType); next=245
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumChargeCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 245;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumVoltage, RationalNumberType); next=246
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumVoltage);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 246;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargePower, RationalNumberType); next=247
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 247;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumDischargePower, RationalNumberType); next=248
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 248;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargeCurrent, RationalNumberType); next=249
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargeCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 249;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 5);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumVoltage, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumVoltage);
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
        case 245:
            // Grammar: ID=245; read/write bits=3; START (EVSEMaximumVoltage), START (EVSEMaximumDischargePower), START (EVSEMinimumDischargePower), START (EVSEMaximumDischargeCurrent), START (EVSEMinimumVoltage), END Element
            if (BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumVoltage, RationalNumberType); next=246
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumVoltage);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 246;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargePower, RationalNumberType); next=247
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 247;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumDischargePower, RationalNumberType); next=248
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 248;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargeCurrent, RationalNumberType); next=249
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargeCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 249;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 4);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumVoltage, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumVoltage);
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
        case 246:
            // Grammar: ID=246; read/write bits=3; START (EVSEMaximumDischargePower), START (EVSEMinimumDischargePower), START (EVSEMaximumDischargeCurrent), START (EVSEMinimumVoltage), END Element
            if (BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargePower, RationalNumberType); next=247
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 247;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumDischargePower, RationalNumberType); next=248
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 248;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargeCurrent, RationalNumberType); next=249
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargeCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 249;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumVoltage, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumVoltage);
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
        case 247:
            // Grammar: ID=247; read/write bits=3; START (EVSEMinimumDischargePower), START (EVSEMaximumDischargeCurrent), START (EVSEMinimumVoltage), END Element
            if (BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumDischargePower_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumDischargePower, RationalNumberType); next=248
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumDischargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 248;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargeCurrent, RationalNumberType); next=249
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargeCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 249;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumVoltage, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumVoltage);
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
        case 248:
            // Grammar: ID=248; read/write bits=2; START (EVSEMaximumDischargeCurrent), START (EVSEMinimumVoltage), END Element
            if (BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargeCurrent_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMaximumDischargeCurrent, RationalNumberType); next=249
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMaximumDischargeCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 249;
                    }
                }
            }
            else if (BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumVoltage, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumVoltage);
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
        case 249:
            // Grammar: ID=249; read/write bits=2; START (EVSEMinimumVoltage), END Element
            if (BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumVoltage_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEMinimumVoltage, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Scheduled_DC_CLResControlModeType->EVSEMinimumVoltage);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}BPT_Dynamic_DC_CLReqControlMode; type={urn:iso:std:iso:15118:-20:DC}BPT_Dynamic_DC_CLReqControlModeType; base type=Dynamic_DC_CLReqControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DepartureTime, unsignedInt (0, 1); EVTargetEnergyRequest, RationalNumberType (1, 1); EVMaximumEnergyRequest, RationalNumberType (1, 1); EVMinimumEnergyRequest, RationalNumberType (1, 1); EVMaximumChargePower, RationalNumberType (1, 1); EVMinimumChargePower, RationalNumberType (1, 1); EVMaximumChargeCurrent, RationalNumberType (1, 1); EVMaximumVoltage, RationalNumberType (1, 1); EVMinimumVoltage, RationalNumberType (1, 1); EVMaximumDischargePower, RationalNumberType (1, 1); EVMinimumDischargePower, RationalNumberType (1, 1); EVMaximumDischargeCurrent, RationalNumberType (1, 1); EVMaximumV2XEnergyRequest, RationalNumberType (0, 1); EVMinimumV2XEnergyRequest, RationalNumberType (0, 1);
static int encode_iso20_dc_BPT_Dynamic_DC_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_dc_BPT_Dynamic_DC_CLReqControlModeType* BPT_Dynamic_DC_CLReqControlModeType) {
    int grammar_id = 250;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 250:
            // Grammar: ID=250; read/write bits=2; START (DepartureTime), START (EVTargetEnergyRequest)
            if (BPT_Dynamic_DC_CLReqControlModeType->DepartureTime_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (DepartureTime, unsignedLong); next=251
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, BPT_Dynamic_DC_CLReqControlModeType->DepartureTime);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 251;
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
                    // Event: START (EVTargetEnergyRequest, RationalNumberType); next=252
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLReqControlModeType->EVTargetEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 252;
                    }
                }
            }
            break;
        case 251:
            // Grammar: ID=251; read/write bits=1; START (EVTargetEnergyRequest)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=252
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLReqControlModeType->EVTargetEnergyRequest);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 252;
                }
            }
            break;
        case 252:
            // Grammar: ID=252; read/write bits=1; START (EVMaximumEnergyRequest)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=253
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLReqControlModeType->EVMaximumEnergyRequest);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 253;
                }
            }
            break;
        case 253:
            // Grammar: ID=253; read/write bits=1; START (EVMinimumEnergyRequest)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=254
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLReqControlModeType->EVMinimumEnergyRequest);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 254;
                }
            }
            break;
        case 254:
            // Grammar: ID=254; read/write bits=1; START (EVMaximumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=255
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLReqControlModeType->EVMaximumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 255;
                }
            }
            break;
        case 255:
            // Grammar: ID=255; read/write bits=1; START (EVMinimumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=256
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLReqControlModeType->EVMinimumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 256;
                }
            }
            break;
        case 256:
            // Grammar: ID=256; read/write bits=1; START (EVMaximumChargeCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=257
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLReqControlModeType->EVMaximumChargeCurrent);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 257;
                }
            }
            break;
        case 257:
            // Grammar: ID=257; read/write bits=1; START (EVMaximumVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=258
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLReqControlModeType->EVMaximumVoltage);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 258;
                }
            }
            break;
        case 258:
            // Grammar: ID=258; read/write bits=1; START (EVMinimumVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=259
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLReqControlModeType->EVMinimumVoltage);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 259;
                }
            }
            break;
        case 259:
            // Grammar: ID=259; read/write bits=1; START (EVMaximumDischargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=260
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLReqControlModeType->EVMaximumDischargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 260;
                }
            }
            break;
        case 260:
            // Grammar: ID=260; read/write bits=1; START (EVMinimumDischargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=261
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLReqControlModeType->EVMinimumDischargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 261;
                }
            }
            break;
        case 261:
            // Grammar: ID=261; read/write bits=1; START (EVMaximumDischargeCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=262
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLReqControlModeType->EVMaximumDischargeCurrent);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 262;
                }
            }
            break;
        case 262:
            // Grammar: ID=262; read/write bits=2; START (EVMaximumV2XEnergyRequest), START (EVMinimumV2XEnergyRequest), END Element
            if (BPT_Dynamic_DC_CLReqControlModeType->EVMaximumV2XEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMaximumV2XEnergyRequest, RationalNumberType); next=263
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLReqControlModeType->EVMaximumV2XEnergyRequest);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 263;
                    }
                }
            }
            else if (BPT_Dynamic_DC_CLReqControlModeType->EVMinimumV2XEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumV2XEnergyRequest, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLReqControlModeType->EVMinimumV2XEnergyRequest);
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
        case 263:
            // Grammar: ID=263; read/write bits=2; START (EVMinimumV2XEnergyRequest), END Element
            if (BPT_Dynamic_DC_CLReqControlModeType->EVMinimumV2XEnergyRequest_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVMinimumV2XEnergyRequest, RationalNumberType); next=2
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLReqControlModeType->EVMinimumV2XEnergyRequest);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}DC_ChargeLoopReq; type={urn:iso:std:iso:15118:-20:DC}DC_ChargeLoopReqType; base type=ChargeLoopReqType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); DisplayParameters, DisplayParametersType (0, 1); MeterInfoRequested, boolean (1, 1); EVPresentVoltage, RationalNumberType (1, 1); BPT_Dynamic_DC_CLReqControlMode, BPT_Dynamic_DC_CLReqControlModeType (0, 1); BPT_Scheduled_DC_CLReqControlMode, BPT_Scheduled_DC_CLReqControlModeType (0, 1); CLReqControlMode, CLReqControlModeType (0, 1); Dynamic_DC_CLReqControlMode, Dynamic_DC_CLReqControlModeType (0, 1); Scheduled_DC_CLReqControlMode, Scheduled_DC_CLReqControlModeType (0, 1);
static int encode_iso20_dc_DC_ChargeLoopReqType(exi_bitstream_t* stream, struct iso20_dc_DC_ChargeLoopReqType* DC_ChargeLoopReqType) {
    int grammar_id = 264;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 264:
            // Grammar: ID=264; read/write bits=1; START (Header)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (MessageHeaderType); next=265
                error = encode_iso20_dc_MessageHeaderType(stream, &DC_ChargeLoopReqType->Header);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 265;
                }
            }
            break;
        case 265:
            // Grammar: ID=265; read/write bits=2; START (DisplayParameters), START (MeterInfoRequested)
            if (DC_ChargeLoopReqType->DisplayParameters_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (DisplayParameters, DisplayParametersType); next=266
                    error = encode_iso20_dc_DisplayParametersType(stream, &DC_ChargeLoopReqType->DisplayParameters);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 266;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterInfoRequested, boolean); next=267
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_bool(stream, DC_ChargeLoopReqType->MeterInfoRequested);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 267;
                            }
                        }
                    }
                }
            }
            break;
        case 266:
            // Grammar: ID=266; read/write bits=1; START (MeterInfoRequested)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (boolean); next=267
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_bool(stream, DC_ChargeLoopReqType->MeterInfoRequested);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 267;
                        }
                    }
                }
            }
            break;
        case 267:
            // Grammar: ID=267; read/write bits=1; START (EVPresentVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=268
                error = encode_iso20_dc_RationalNumberType(stream, &DC_ChargeLoopReqType->EVPresentVoltage);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 268;
                }
            }
            break;
        case 268:
            // Grammar: ID=268; read/write bits=3; START (BPT_Dynamic_DC_CLReqControlMode), START (BPT_Scheduled_DC_CLReqControlMode), START (CLReqControlMode), START (Dynamic_DC_CLReqControlMode), START (Scheduled_DC_CLReqControlMode)
            if (DC_ChargeLoopReqType->BPT_Dynamic_DC_CLReqControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_Dynamic_DC_CLReqControlMode, Dynamic_DC_CLReqControlModeType); next=269
                    error = encode_iso20_dc_BPT_Dynamic_DC_CLReqControlModeType(stream, &DC_ChargeLoopReqType->BPT_Dynamic_DC_CLReqControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 269;
                    }
                }
            }
            else if (DC_ChargeLoopReqType->BPT_Scheduled_DC_CLReqControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_Scheduled_DC_CLReqControlMode, Scheduled_DC_CLReqControlModeType); next=269
                    error = encode_iso20_dc_BPT_Scheduled_DC_CLReqControlModeType(stream, &DC_ChargeLoopReqType->BPT_Scheduled_DC_CLReqControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 269;
                    }
                }
            }
            else if (DC_ChargeLoopReqType->CLReqControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (CLReqControlMode, CLReqControlModeType); next=2
                    error = encode_iso20_dc_CLReqControlModeType(stream, &DC_ChargeLoopReqType->CLReqControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (DC_ChargeLoopReqType->Dynamic_DC_CLReqControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Dynamic_DC_CLReqControlMode, Dynamic_CLReqControlModeType); next=2
                    error = encode_iso20_dc_Dynamic_DC_CLReqControlModeType(stream, &DC_ChargeLoopReqType->Dynamic_DC_CLReqControlMode);
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
                    // Event: START (Scheduled_DC_CLReqControlMode, Scheduled_CLReqControlModeType); next=2
                    error = encode_iso20_dc_Scheduled_DC_CLReqControlModeType(stream, &DC_ChargeLoopReqType->Scheduled_DC_CLReqControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            break;
        case 269:
            // Grammar: ID=269; read/write bits=2; START (CLReqControlMode), START (Dynamic_DC_CLReqControlMode), START (Scheduled_DC_CLReqControlMode)
            if (DC_ChargeLoopReqType->CLReqControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (CLReqControlMode, CLReqControlModeType); next=2
                    error = encode_iso20_dc_CLReqControlModeType(stream, &DC_ChargeLoopReqType->CLReqControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (DC_ChargeLoopReqType->Dynamic_DC_CLReqControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Dynamic_DC_CLReqControlMode, Dynamic_CLReqControlModeType); next=2
                    error = encode_iso20_dc_Dynamic_DC_CLReqControlModeType(stream, &DC_ChargeLoopReqType->Dynamic_DC_CLReqControlMode);
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
                    // Event: START (Scheduled_DC_CLReqControlMode, Scheduled_CLReqControlModeType); next=2
                    error = encode_iso20_dc_Scheduled_DC_CLReqControlModeType(stream, &DC_ChargeLoopReqType->Scheduled_DC_CLReqControlMode);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}BPT_Dynamic_DC_CLResControlMode; type={urn:iso:std:iso:15118:-20:DC}BPT_Dynamic_DC_CLResControlModeType; base type=Dynamic_DC_CLResControlModeType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: DepartureTime, unsignedInt (0, 1); MinimumSOC, percentValueType (0, 1); TargetSOC, percentValueType (0, 1); AckMaxDelay, unsignedShort (0, 1); EVSEMaximumChargePower, RationalNumberType (1, 1); EVSEMinimumChargePower, RationalNumberType (1, 1); EVSEMaximumChargeCurrent, RationalNumberType (1, 1); EVSEMaximumVoltage, RationalNumberType (1, 1); EVSEMaximumDischargePower, RationalNumberType (1, 1); EVSEMinimumDischargePower, RationalNumberType (1, 1); EVSEMaximumDischargeCurrent, RationalNumberType (1, 1); EVSEMinimumVoltage, RationalNumberType (1, 1);
static int encode_iso20_dc_BPT_Dynamic_DC_CLResControlModeType(exi_bitstream_t* stream, struct iso20_dc_BPT_Dynamic_DC_CLResControlModeType* BPT_Dynamic_DC_CLResControlModeType) {
    int grammar_id = 270;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 270:
            // Grammar: ID=270; read/write bits=3; START (DepartureTime), START (MinimumSOC), START (TargetSOC), START (AckMaxDelay), START (EVSEMaximumChargePower)
            if (BPT_Dynamic_DC_CLResControlModeType->DepartureTime_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (DepartureTime, unsignedLong); next=271
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_32(stream, BPT_Dynamic_DC_CLResControlModeType->DepartureTime);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 271;
                            }
                        }
                    }
                }
            }
            else if (BPT_Dynamic_DC_CLResControlModeType->MinimumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MinimumSOC, byte); next=272
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)BPT_Dynamic_DC_CLResControlModeType->MinimumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 272;
                            }
                        }
                    }
                }
            }
            else if (BPT_Dynamic_DC_CLResControlModeType->TargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (TargetSOC, byte); next=273
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)BPT_Dynamic_DC_CLResControlModeType->TargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 273;
                            }
                        }
                    }
                }
            }
            else if (BPT_Dynamic_DC_CLResControlModeType->AckMaxDelay_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AckMaxDelay, unsignedInt); next=274
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, BPT_Dynamic_DC_CLResControlModeType->AckMaxDelay);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 274;
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
                    // Event: START (EVSEMaximumChargePower, RationalNumberType); next=275
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLResControlModeType->EVSEMaximumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 275;
                    }
                }
            }
            break;
        case 271:
            // Grammar: ID=271; read/write bits=3; START (MinimumSOC), START (TargetSOC), START (AckMaxDelay), START (EVSEMaximumChargePower)
            if (BPT_Dynamic_DC_CLResControlModeType->MinimumSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MinimumSOC, byte); next=272
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)BPT_Dynamic_DC_CLResControlModeType->MinimumSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 272;
                            }
                        }
                    }
                }
            }
            else if (BPT_Dynamic_DC_CLResControlModeType->TargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (TargetSOC, byte); next=273
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)BPT_Dynamic_DC_CLResControlModeType->TargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 273;
                            }
                        }
                    }
                }
            }
            else if (BPT_Dynamic_DC_CLResControlModeType->AckMaxDelay_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AckMaxDelay, unsignedInt); next=274
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, BPT_Dynamic_DC_CLResControlModeType->AckMaxDelay);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 274;
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
                    // Event: START (EVSEMaximumChargePower, RationalNumberType); next=275
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLResControlModeType->EVSEMaximumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 275;
                    }
                }
            }
            break;
        case 272:
            // Grammar: ID=272; read/write bits=2; START (TargetSOC), START (AckMaxDelay), START (EVSEMaximumChargePower)
            if (BPT_Dynamic_DC_CLResControlModeType->TargetSOC_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (TargetSOC, byte); next=273
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_nbit_uint(stream, 7, (uint32_t)BPT_Dynamic_DC_CLResControlModeType->TargetSOC);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 273;
                            }
                        }
                    }
                }
            }
            else if (BPT_Dynamic_DC_CLResControlModeType->AckMaxDelay_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AckMaxDelay, unsignedInt); next=274
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, BPT_Dynamic_DC_CLResControlModeType->AckMaxDelay);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 274;
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
                    // Event: START (EVSEMaximumChargePower, RationalNumberType); next=275
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLResControlModeType->EVSEMaximumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 275;
                    }
                }
            }
            break;
        case 273:
            // Grammar: ID=273; read/write bits=2; START (AckMaxDelay), START (EVSEMaximumChargePower)
            if (BPT_Dynamic_DC_CLResControlModeType->AckMaxDelay_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (AckMaxDelay, unsignedInt); next=274
                    error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_uint_16(stream, BPT_Dynamic_DC_CLResControlModeType->AckMaxDelay);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            // encode END Element
                            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                            if (error == EXI_ERROR__NO_ERROR)
                            {
                                grammar_id = 274;
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
                    // Event: START (EVSEMaximumChargePower, RationalNumberType); next=275
                    error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLResControlModeType->EVSEMaximumChargePower);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 275;
                    }
                }
            }
            break;
        case 274:
            // Grammar: ID=274; read/write bits=1; START (EVSEMaximumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=275
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLResControlModeType->EVSEMaximumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 275;
                }
            }
            break;
        case 275:
            // Grammar: ID=275; read/write bits=1; START (EVSEMinimumChargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=276
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLResControlModeType->EVSEMinimumChargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 276;
                }
            }
            break;
        case 276:
            // Grammar: ID=276; read/write bits=1; START (EVSEMaximumChargeCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=277
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLResControlModeType->EVSEMaximumChargeCurrent);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 277;
                }
            }
            break;
        case 277:
            // Grammar: ID=277; read/write bits=1; START (EVSEMaximumVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=278
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLResControlModeType->EVSEMaximumVoltage);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 278;
                }
            }
            break;
        case 278:
            // Grammar: ID=278; read/write bits=1; START (EVSEMaximumDischargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=279
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLResControlModeType->EVSEMaximumDischargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 279;
                }
            }
            break;
        case 279:
            // Grammar: ID=279; read/write bits=1; START (EVSEMinimumDischargePower)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=280
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLResControlModeType->EVSEMinimumDischargePower);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 280;
                }
            }
            break;
        case 280:
            // Grammar: ID=280; read/write bits=1; START (EVSEMaximumDischargeCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=281
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLResControlModeType->EVSEMaximumDischargeCurrent);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 281;
                }
            }
            break;
        case 281:
            // Grammar: ID=281; read/write bits=1; START (EVSEMinimumVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=2
                error = encode_iso20_dc_RationalNumberType(stream, &BPT_Dynamic_DC_CLResControlModeType->EVSEMinimumVoltage);
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:DC}DC_ChargeLoopRes; type={urn:iso:std:iso:15118:-20:DC}DC_ChargeLoopResType; base type=ChargeLoopResType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); EVSEStatus, EVSEStatusType (0, 1); MeterInfo, MeterInfoType (0, 1); Receipt, ReceiptType (0, 1); EVSEPresentCurrent, RationalNumberType (1, 1); EVSEPresentVoltage, RationalNumberType (1, 1); EVSEPowerLimitAchieved, boolean (1, 1); EVSECurrentLimitAchieved, boolean (1, 1); EVSEVoltageLimitAchieved, boolean (1, 1); BPT_Dynamic_DC_CLResControlMode, BPT_Dynamic_DC_CLResControlModeType (0, 1); BPT_Scheduled_DC_CLResControlMode, BPT_Scheduled_DC_CLResControlModeType (0, 1); CLResControlMode, CLResControlModeType (0, 1); Dynamic_DC_CLResControlMode, Dynamic_DC_CLResControlModeType (0, 1); Scheduled_DC_CLResControlMode, Scheduled_DC_CLResControlModeType (0, 1);
static int encode_iso20_dc_DC_ChargeLoopResType(exi_bitstream_t* stream, struct iso20_dc_DC_ChargeLoopResType* DC_ChargeLoopResType) {
    int grammar_id = 282;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 282:
            // Grammar: ID=282; read/write bits=1; START (Header)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (MessageHeaderType); next=283
                error = encode_iso20_dc_MessageHeaderType(stream, &DC_ChargeLoopResType->Header);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 283;
                }
            }
            break;
        case 283:
            // Grammar: ID=283; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (string); next=284
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_nbit_uint(stream, 6, DC_ChargeLoopResType->ResponseCode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 284;
                        }
                    }
                }
            }
            break;
        case 284:
            // Grammar: ID=284; read/write bits=3; START (EVSEStatus), START (MeterInfo), START (Receipt), START (EVSEPresentCurrent)
            if (DC_ChargeLoopResType->EVSEStatus_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEStatus, EVSEStatusType); next=285
                    error = encode_iso20_dc_EVSEStatusType(stream, &DC_ChargeLoopResType->EVSEStatus);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 285;
                    }
                }
            }
            else if (DC_ChargeLoopResType->MeterInfo_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterInfo, MeterInfoType); next=286
                    error = encode_iso20_dc_MeterInfoType(stream, &DC_ChargeLoopResType->MeterInfo);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 286;
                    }
                }
            }
            else if (DC_ChargeLoopResType->Receipt_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Receipt, ReceiptType); next=287
                    error = encode_iso20_dc_ReceiptType(stream, &DC_ChargeLoopResType->Receipt);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 287;
                    }
                }
            }
            else
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (EVSEPresentCurrent, RationalNumberType); next=288
                    error = encode_iso20_dc_RationalNumberType(stream, &DC_ChargeLoopResType->EVSEPresentCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 288;
                    }
                }
            }
            break;
        case 285:
            // Grammar: ID=285; read/write bits=2; START (MeterInfo), START (Receipt), START (EVSEPresentCurrent)
            if (DC_ChargeLoopResType->MeterInfo_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (MeterInfo, MeterInfoType); next=286
                    error = encode_iso20_dc_MeterInfoType(stream, &DC_ChargeLoopResType->MeterInfo);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 286;
                    }
                }
            }
            else if (DC_ChargeLoopResType->Receipt_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Receipt, ReceiptType); next=287
                    error = encode_iso20_dc_ReceiptType(stream, &DC_ChargeLoopResType->Receipt);
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
                    // Event: START (EVSEPresentCurrent, RationalNumberType); next=288
                    error = encode_iso20_dc_RationalNumberType(stream, &DC_ChargeLoopResType->EVSEPresentCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 288;
                    }
                }
            }
            break;
        case 286:
            // Grammar: ID=286; read/write bits=2; START (Receipt), START (EVSEPresentCurrent)
            if (DC_ChargeLoopResType->Receipt_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Receipt, ReceiptType); next=287
                    error = encode_iso20_dc_ReceiptType(stream, &DC_ChargeLoopResType->Receipt);
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
                    // Event: START (EVSEPresentCurrent, RationalNumberType); next=288
                    error = encode_iso20_dc_RationalNumberType(stream, &DC_ChargeLoopResType->EVSEPresentCurrent);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 288;
                    }
                }
            }
            break;
        case 287:
            // Grammar: ID=287; read/write bits=1; START (EVSEPresentCurrent)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=288
                error = encode_iso20_dc_RationalNumberType(stream, &DC_ChargeLoopResType->EVSEPresentCurrent);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 288;
                }
            }
            break;
        case 288:
            // Grammar: ID=288; read/write bits=1; START (EVSEPresentVoltage)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (RationalNumberType); next=289
                error = encode_iso20_dc_RationalNumberType(stream, &DC_ChargeLoopResType->EVSEPresentVoltage);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    grammar_id = 289;
                }
            }
            break;
        case 289:
            // Grammar: ID=289; read/write bits=1; START (EVSEPowerLimitAchieved)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (boolean); next=290
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_bool(stream, DC_ChargeLoopResType->EVSEPowerLimitAchieved);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 290;
                        }
                    }
                }
            }
            break;
        case 290:
            // Grammar: ID=290; read/write bits=1; START (EVSECurrentLimitAchieved)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (boolean); next=291
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_bool(stream, DC_ChargeLoopResType->EVSECurrentLimitAchieved);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 291;
                        }
                    }
                }
            }
            break;
        case 291:
            // Grammar: ID=291; read/write bits=1; START (EVSEVoltageLimitAchieved)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (boolean); next=292
                error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    error = exi_basetypes_encoder_bool(stream, DC_ChargeLoopResType->EVSEVoltageLimitAchieved);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        // encode END Element
                        error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 292;
                        }
                    }
                }
            }
            break;
        case 292:
            // Grammar: ID=292; read/write bits=3; START (BPT_Dynamic_DC_CLResControlMode), START (BPT_Scheduled_DC_CLResControlMode), START (CLResControlMode), START (Dynamic_DC_CLResControlMode), START (Scheduled_DC_CLResControlMode)
            if (DC_ChargeLoopResType->BPT_Dynamic_DC_CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_Dynamic_DC_CLResControlMode, Dynamic_DC_CLResControlModeType); next=293
                    error = encode_iso20_dc_BPT_Dynamic_DC_CLResControlModeType(stream, &DC_ChargeLoopResType->BPT_Dynamic_DC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 293;
                    }
                }
            }
            else if (DC_ChargeLoopResType->BPT_Scheduled_DC_CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (BPT_Scheduled_DC_CLResControlMode, Scheduled_DC_CLResControlModeType); next=293
                    error = encode_iso20_dc_BPT_Scheduled_DC_CLResControlModeType(stream, &DC_ChargeLoopResType->BPT_Scheduled_DC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 293;
                    }
                }
            }
            else if (DC_ChargeLoopResType->CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 2);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (CLResControlMode, CLResControlModeType); next=2
                    error = encode_iso20_dc_CLResControlModeType(stream, &DC_ChargeLoopResType->CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (DC_ChargeLoopResType->Dynamic_DC_CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 3, 3);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Dynamic_DC_CLResControlMode, Dynamic_CLResControlModeType); next=2
                    error = encode_iso20_dc_Dynamic_DC_CLResControlModeType(stream, &DC_ChargeLoopResType->Dynamic_DC_CLResControlMode);
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
                    // Event: START (Scheduled_DC_CLResControlMode, Scheduled_CLResControlModeType); next=2
                    error = encode_iso20_dc_Scheduled_DC_CLResControlModeType(stream, &DC_ChargeLoopResType->Scheduled_DC_CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            break;
        case 293:
            // Grammar: ID=293; read/write bits=2; START (CLResControlMode), START (Dynamic_DC_CLResControlMode), START (Scheduled_DC_CLResControlMode)
            if (DC_ChargeLoopResType->CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (CLResControlMode, CLResControlModeType); next=2
                    error = encode_iso20_dc_CLResControlModeType(stream, &DC_ChargeLoopResType->CLResControlMode);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            else if (DC_ChargeLoopResType->Dynamic_DC_CLResControlMode_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 1);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Dynamic_DC_CLResControlMode, Dynamic_CLResControlModeType); next=2
                    error = encode_iso20_dc_Dynamic_DC_CLResControlModeType(stream, &DC_ChargeLoopResType->Dynamic_DC_CLResControlMode);
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
                    // Event: START (Scheduled_DC_CLResControlMode, Scheduled_CLResControlModeType); next=2
                    error = encode_iso20_dc_Scheduled_DC_CLResControlModeType(stream, &DC_ChargeLoopResType->Scheduled_DC_CLResControlMode);
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
static int encode_iso20_dc_ManifestType(exi_bitstream_t* stream, struct iso20_dc_ManifestType* ManifestType) {
    int grammar_id = 294;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 294:
            // Grammar: ID=294; read/write bits=2; START (Id), START (Reference)
            if (ManifestType->Id_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Id, NCName); next=295

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(ManifestType->Id.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, ManifestType->Id.charactersLen, ManifestType->Id.characters, iso20_dc_Id_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 295;
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
                    error = encode_iso20_dc_ReferenceType(stream, &ManifestType->Reference);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            break;
        case 295:
            // Grammar: ID=295; read/write bits=1; START (Reference)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (ReferenceType); next=2
                error = encode_iso20_dc_ReferenceType(stream, &ManifestType->Reference);
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
static int encode_iso20_dc_SignaturePropertiesType(exi_bitstream_t* stream, struct iso20_dc_SignaturePropertiesType* SignaturePropertiesType) {
    int grammar_id = 296;
    int done = 0;
    int error = 0;

    while(!done)
    {
        switch(grammar_id)
        {
        case 296:
            // Grammar: ID=296; read/write bits=2; START (Id), START (SignatureProperty)
            if (SignaturePropertiesType->Id_isUsed == 1u)
            {
                error = exi_basetypes_encoder_nbit_uint(stream, 2, 0);
                if (error == EXI_ERROR__NO_ERROR)
                {
                    // Event: START (Id, NCName); next=297

                    // string should not be found in table, so add 2
                    error = exi_basetypes_encoder_uint_16(stream, (uint16_t)(SignaturePropertiesType->Id.charactersLen + 2));
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        error = exi_basetypes_encoder_characters(stream, SignaturePropertiesType->Id.charactersLen, SignaturePropertiesType->Id.characters, iso20_dc_Id_CHARACTER_SIZE);
                        if (error == EXI_ERROR__NO_ERROR)
                        {
                            grammar_id = 297;
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
                    error = encode_iso20_dc_SignaturePropertyType(stream, &SignaturePropertiesType->SignatureProperty);
                    if (error == EXI_ERROR__NO_ERROR)
                    {
                        grammar_id = 2;
                    }
                }
            }
            break;
        case 297:
            // Grammar: ID=297; read/write bits=1; START (SignatureProperty)
            error = exi_basetypes_encoder_nbit_uint(stream, 1, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                // Event: START (SignaturePropertyType); next=2
                error = encode_iso20_dc_SignaturePropertyType(stream, &SignaturePropertiesType->SignatureProperty);
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
int encode_iso20_dc_exiDocument(exi_bitstream_t* stream, struct iso20_dc_exiDocument* exiDoc)
{
    int error = exi_header_write(stream);

    if (error == EXI_ERROR__NO_ERROR)
    {
        if (exiDoc->BPT_DC_CPDReqEnergyTransferMode_isUsed == 1)
        {
            // encode event 0
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 0);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_BPT_DC_CPDReqEnergyTransferModeType(stream, &exiDoc->BPT_DC_CPDReqEnergyTransferMode);
            }
        }
        else if (exiDoc->BPT_DC_CPDResEnergyTransferMode_isUsed == 1)
        {
            // encode event 1
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 1);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_BPT_DC_CPDResEnergyTransferModeType(stream, &exiDoc->BPT_DC_CPDResEnergyTransferMode);
            }
        }
        else if (exiDoc->BPT_Dynamic_DC_CLReqControlMode_isUsed == 1)
        {
            // encode event 2
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 2);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_BPT_Dynamic_DC_CLReqControlModeType(stream, &exiDoc->BPT_Dynamic_DC_CLReqControlMode);
            }
        }
        else if (exiDoc->BPT_Dynamic_DC_CLResControlMode_isUsed == 1)
        {
            // encode event 3
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 3);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_BPT_Dynamic_DC_CLResControlModeType(stream, &exiDoc->BPT_Dynamic_DC_CLResControlMode);
            }
        }
        else if (exiDoc->BPT_Scheduled_DC_CLReqControlMode_isUsed == 1)
        {
            // encode event 4
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 4);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_BPT_Scheduled_DC_CLReqControlModeType(stream, &exiDoc->BPT_Scheduled_DC_CLReqControlMode);
            }
        }
        else if (exiDoc->BPT_Scheduled_DC_CLResControlMode_isUsed == 1)
        {
            // encode event 5
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 5);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_BPT_Scheduled_DC_CLResControlModeType(stream, &exiDoc->BPT_Scheduled_DC_CLResControlMode);
            }
        }
        else if (exiDoc->CLReqControlMode_isUsed == 1)
        {
            // encode event 6
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 6);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_CLReqControlModeType(stream, &exiDoc->CLReqControlMode);
            }
        }
        else if (exiDoc->CLResControlMode_isUsed == 1)
        {
            // encode event 7
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 7);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_CLResControlModeType(stream, &exiDoc->CLResControlMode);
            }
        }
        else if (exiDoc->CanonicalizationMethod_isUsed == 1)
        {
            // encode event 8
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 8);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_CanonicalizationMethodType(stream, &exiDoc->CanonicalizationMethod);
            }
        }
        else if (exiDoc->DC_CPDReqEnergyTransferMode_isUsed == 1)
        {
            // encode event 9
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 9);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_DC_CPDReqEnergyTransferModeType(stream, &exiDoc->DC_CPDReqEnergyTransferMode);
            }
        }
        else if (exiDoc->DC_CPDResEnergyTransferMode_isUsed == 1)
        {
            // encode event 10
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 10);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_DC_CPDResEnergyTransferModeType(stream, &exiDoc->DC_CPDResEnergyTransferMode);
            }
        }
        else if (exiDoc->DC_CableCheckReq_isUsed == 1)
        {
            // encode event 11
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 11);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_DC_CableCheckReqType(stream, &exiDoc->DC_CableCheckReq);
            }
        }
        else if (exiDoc->DC_CableCheckRes_isUsed == 1)
        {
            // encode event 12
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 12);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_DC_CableCheckResType(stream, &exiDoc->DC_CableCheckRes);
            }
        }
        else if (exiDoc->DC_ChargeLoopReq_isUsed == 1)
        {
            // encode event 13
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 13);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_DC_ChargeLoopReqType(stream, &exiDoc->DC_ChargeLoopReq);
            }
        }
        else if (exiDoc->DC_ChargeLoopRes_isUsed == 1)
        {
            // encode event 14
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 14);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_DC_ChargeLoopResType(stream, &exiDoc->DC_ChargeLoopRes);
            }
        }
        else if (exiDoc->DC_ChargeParameterDiscoveryReq_isUsed == 1)
        {
            // encode event 15
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 15);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_DC_ChargeParameterDiscoveryReqType(stream, &exiDoc->DC_ChargeParameterDiscoveryReq);
            }
        }
        else if (exiDoc->DC_ChargeParameterDiscoveryRes_isUsed == 1)
        {
            // encode event 16
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 16);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_DC_ChargeParameterDiscoveryResType(stream, &exiDoc->DC_ChargeParameterDiscoveryRes);
            }
        }
        else if (exiDoc->DC_PreChargeReq_isUsed == 1)
        {
            // encode event 17
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 17);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_DC_PreChargeReqType(stream, &exiDoc->DC_PreChargeReq);
            }
        }
        else if (exiDoc->DC_PreChargeRes_isUsed == 1)
        {
            // encode event 18
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 18);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_DC_PreChargeResType(stream, &exiDoc->DC_PreChargeRes);
            }
        }
        else if (exiDoc->DC_WeldingDetectionReq_isUsed == 1)
        {
            // encode event 19
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 19);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_DC_WeldingDetectionReqType(stream, &exiDoc->DC_WeldingDetectionReq);
            }
        }
        else if (exiDoc->DC_WeldingDetectionRes_isUsed == 1)
        {
            // encode event 20
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 20);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_DC_WeldingDetectionResType(stream, &exiDoc->DC_WeldingDetectionRes);
            }
        }
        else if (exiDoc->DSAKeyValue_isUsed == 1)
        {
            // encode event 21
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 21);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_DSAKeyValueType(stream, &exiDoc->DSAKeyValue);
            }
        }
        else if (exiDoc->DigestMethod_isUsed == 1)
        {
            // encode event 22
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 22);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_DigestMethodType(stream, &exiDoc->DigestMethod);
            }
        }
        // simple type! encode_iso20_dc_DigestValue;
        else if (exiDoc->Dynamic_DC_CLReqControlMode_isUsed == 1)
        {
            // encode event 24
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 24);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_Dynamic_DC_CLReqControlModeType(stream, &exiDoc->Dynamic_DC_CLReqControlMode);
            }
        }
        else if (exiDoc->Dynamic_DC_CLResControlMode_isUsed == 1)
        {
            // encode event 25
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 25);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_Dynamic_DC_CLResControlModeType(stream, &exiDoc->Dynamic_DC_CLResControlMode);
            }
        }
        else if (exiDoc->KeyInfo_isUsed == 1)
        {
            // encode event 26
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 26);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_KeyInfoType(stream, &exiDoc->KeyInfo);
            }
        }
        // simple type! encode_iso20_dc_KeyName;
        else if (exiDoc->KeyValue_isUsed == 1)
        {
            // encode event 28
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 28);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_KeyValueType(stream, &exiDoc->KeyValue);
            }
        }
        else if (exiDoc->Manifest_isUsed == 1)
        {
            // encode event 29
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 29);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_ManifestType(stream, &exiDoc->Manifest);
            }
        }
        // simple type! encode_iso20_dc_MgmtData;
        else if (exiDoc->Object_isUsed == 1)
        {
            // encode event 31
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 31);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_ObjectType(stream, &exiDoc->Object);
            }
        }
        else if (exiDoc->PGPData_isUsed == 1)
        {
            // encode event 32
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 32);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_PGPDataType(stream, &exiDoc->PGPData);
            }
        }
        else if (exiDoc->RSAKeyValue_isUsed == 1)
        {
            // encode event 33
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 33);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_RSAKeyValueType(stream, &exiDoc->RSAKeyValue);
            }
        }
        else if (exiDoc->Reference_isUsed == 1)
        {
            // encode event 34
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 34);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_ReferenceType(stream, &exiDoc->Reference);
            }
        }
        else if (exiDoc->RetrievalMethod_isUsed == 1)
        {
            // encode event 35
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 35);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_RetrievalMethodType(stream, &exiDoc->RetrievalMethod);
            }
        }
        else if (exiDoc->SPKIData_isUsed == 1)
        {
            // encode event 36
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 36);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_SPKIDataType(stream, &exiDoc->SPKIData);
            }
        }
        else if (exiDoc->Scheduled_DC_CLReqControlMode_isUsed == 1)
        {
            // encode event 37
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 37);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_Scheduled_DC_CLReqControlModeType(stream, &exiDoc->Scheduled_DC_CLReqControlMode);
            }
        }
        else if (exiDoc->Scheduled_DC_CLResControlMode_isUsed == 1)
        {
            // encode event 38
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 38);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_Scheduled_DC_CLResControlModeType(stream, &exiDoc->Scheduled_DC_CLResControlMode);
            }
        }
        else if (exiDoc->SignatureMethod_isUsed == 1)
        {
            // encode event 39
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 39);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_SignatureMethodType(stream, &exiDoc->SignatureMethod);
            }
        }
        else if (exiDoc->SignatureProperties_isUsed == 1)
        {
            // encode event 40
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 40);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_SignaturePropertiesType(stream, &exiDoc->SignatureProperties);
            }
        }
        else if (exiDoc->SignatureProperty_isUsed == 1)
        {
            // encode event 41
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 41);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_SignaturePropertyType(stream, &exiDoc->SignatureProperty);
            }
        }
        else if (exiDoc->Signature_isUsed == 1)
        {
            // encode event 42
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 42);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_SignatureType(stream, &exiDoc->Signature);
            }
        }
        else if (exiDoc->SignatureValue_isUsed == 1)
        {
            // encode event 43
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 43);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_SignatureValueType(stream, &exiDoc->SignatureValue);
            }
        }
        else if (exiDoc->SignedInfo_isUsed == 1)
        {
            // encode event 44
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 44);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_SignedInfoType(stream, &exiDoc->SignedInfo);
            }
        }
        else if (exiDoc->Transform_isUsed == 1)
        {
            // encode event 45
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 45);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_TransformType(stream, &exiDoc->Transform);
            }
        }
        else if (exiDoc->Transforms_isUsed == 1)
        {
            // encode event 46
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 46);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_TransformsType(stream, &exiDoc->Transforms);
            }
        }
        else if (exiDoc->X509Data_isUsed == 1)
        {
            // encode event 47
            error = exi_basetypes_encoder_nbit_uint(stream, 6, 47);
            if (error == EXI_ERROR__NO_ERROR)
            {
                error = encode_iso20_dc_X509DataType(stream, &exiDoc->X509Data);
            }
        }
        else
        {
            error = EXI_ERROR__UNKNOWN_EVENT_FOR_ENCODING;
        }
    }

    return error;
}

