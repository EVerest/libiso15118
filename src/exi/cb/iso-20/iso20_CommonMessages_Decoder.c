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
  * @file iso20_CommonMessages_Decoder.c
  * @brief Description goes here
  *
  **/
#include <stdint.h>

#include "common/exi_basetypes.h"
#include "common/exi_types_decoder.h"
#include "common/exi_basetypes_decoder.h"
#include "common/exi_error_codes.h"
#include "common/exi_header.h"
#include "iso20_CommonMessages_Datatypes.h"
#include "iso20_CommonMessages_Decoder.h"



static int decode_iso20_TransformType(exi_bitstream_t* stream, struct iso20_TransformType* TransformType);
static int decode_iso20_TransformsType(exi_bitstream_t* stream, struct iso20_TransformsType* TransformsType);
static int decode_iso20_DSAKeyValueType(exi_bitstream_t* stream, struct iso20_DSAKeyValueType* DSAKeyValueType);
static int decode_iso20_X509IssuerSerialType(exi_bitstream_t* stream, struct iso20_X509IssuerSerialType* X509IssuerSerialType);
static int decode_iso20_DigestMethodType(exi_bitstream_t* stream, struct iso20_DigestMethodType* DigestMethodType);
static int decode_iso20_RSAKeyValueType(exi_bitstream_t* stream, struct iso20_RSAKeyValueType* RSAKeyValueType);
static int decode_iso20_CanonicalizationMethodType(exi_bitstream_t* stream, struct iso20_CanonicalizationMethodType* CanonicalizationMethodType);
static int decode_iso20_PriceLevelScheduleEntryType(exi_bitstream_t* stream, struct iso20_PriceLevelScheduleEntryType* PriceLevelScheduleEntryType);
static int decode_iso20_SignatureMethodType(exi_bitstream_t* stream, struct iso20_SignatureMethodType* SignatureMethodType);
static int decode_iso20_KeyValueType(exi_bitstream_t* stream, struct iso20_KeyValueType* KeyValueType);
static int decode_iso20_ReferenceType(exi_bitstream_t* stream, struct iso20_ReferenceType* ReferenceType);
static int decode_iso20_RetrievalMethodType(exi_bitstream_t* stream, struct iso20_RetrievalMethodType* RetrievalMethodType);
static int decode_iso20_X509DataType(exi_bitstream_t* stream, struct iso20_X509DataType* X509DataType);
static int decode_iso20_PGPDataType(exi_bitstream_t* stream, struct iso20_PGPDataType* PGPDataType);
static int decode_iso20_RationalNumberType(exi_bitstream_t* stream, struct iso20_RationalNumberType* RationalNumberType);
static int decode_iso20_PowerScheduleEntryType(exi_bitstream_t* stream, struct iso20_PowerScheduleEntryType* PowerScheduleEntryType);
static int decode_iso20_EVPriceRuleType(exi_bitstream_t* stream, struct iso20_EVPriceRuleType* EVPriceRuleType);
static int decode_iso20_EVPowerScheduleEntryType(exi_bitstream_t* stream, struct iso20_EVPowerScheduleEntryType* EVPowerScheduleEntryType);
static int decode_iso20_EVPriceRuleStackType(exi_bitstream_t* stream, struct iso20_EVPriceRuleStackType* EVPriceRuleStackType);
static int decode_iso20_PriceRuleType(exi_bitstream_t* stream, struct iso20_PriceRuleType* PriceRuleType);
static int decode_iso20_PowerScheduleEntryListType(exi_bitstream_t* stream, struct iso20_PowerScheduleEntryListType* PowerScheduleEntryListType);
static int decode_iso20_TaxRuleType(exi_bitstream_t* stream, struct iso20_TaxRuleType* TaxRuleType);
static int decode_iso20_PriceRuleStackType(exi_bitstream_t* stream, struct iso20_PriceRuleStackType* PriceRuleStackType);
static int decode_iso20_AdditionalServiceType(exi_bitstream_t* stream, struct iso20_AdditionalServiceType* AdditionalServiceType);
static int decode_iso20_PowerScheduleType(exi_bitstream_t* stream, struct iso20_PowerScheduleType* PowerScheduleType);
static int decode_iso20_EVPowerScheduleEntryListType(exi_bitstream_t* stream, struct iso20_EVPowerScheduleEntryListType* EVPowerScheduleEntryListType);
static int decode_iso20_OverstayRuleType(exi_bitstream_t* stream, struct iso20_OverstayRuleType* OverstayRuleType);
static int decode_iso20_EVPriceRuleStackListType(exi_bitstream_t* stream, struct iso20_EVPriceRuleStackListType* EVPriceRuleStackListType);
static int decode_iso20_SPKIDataType(exi_bitstream_t* stream, struct iso20_SPKIDataType* SPKIDataType);
static int decode_iso20_SignedInfoType(exi_bitstream_t* stream, struct iso20_SignedInfoType* SignedInfoType);
static int decode_iso20_EVPowerScheduleType(exi_bitstream_t* stream, struct iso20_EVPowerScheduleType* EVPowerScheduleType);
static int decode_iso20_SignatureValueType(exi_bitstream_t* stream, struct iso20_SignatureValueType* SignatureValueType);
static int decode_iso20_SubCertificatesType(exi_bitstream_t* stream, struct iso20_SubCertificatesType* SubCertificatesType);
static int decode_iso20_ParameterType(exi_bitstream_t* stream, struct iso20_ParameterType* ParameterType);
static int decode_iso20_EVAbsolutePriceScheduleType(exi_bitstream_t* stream, struct iso20_EVAbsolutePriceScheduleType* EVAbsolutePriceScheduleType);
static int decode_iso20_DetailedCostType(exi_bitstream_t* stream, struct iso20_DetailedCostType* DetailedCostType);
static int decode_iso20_KeyInfoType(exi_bitstream_t* stream, struct iso20_KeyInfoType* KeyInfoType);
static int decode_iso20_ObjectType(exi_bitstream_t* stream, struct iso20_ObjectType* ObjectType);
static int decode_iso20_PriceLevelScheduleEntryListType(exi_bitstream_t* stream, struct iso20_PriceLevelScheduleEntryListType* PriceLevelScheduleEntryListType);
static int decode_iso20_DetailedTaxType(exi_bitstream_t* stream, struct iso20_DetailedTaxType* DetailedTaxType);
static int decode_iso20_TaxRuleListType(exi_bitstream_t* stream, struct iso20_TaxRuleListType* TaxRuleListType);
static int decode_iso20_PriceRuleStackListType(exi_bitstream_t* stream, struct iso20_PriceRuleStackListType* PriceRuleStackListType);
static int decode_iso20_OverstayRuleListType(exi_bitstream_t* stream, struct iso20_OverstayRuleListType* OverstayRuleListType);
static int decode_iso20_AdditionalServiceListType(exi_bitstream_t* stream, struct iso20_AdditionalServiceListType* AdditionalServiceListType);
static int decode_iso20_ServiceType(exi_bitstream_t* stream, struct iso20_ServiceType* ServiceType);
static int decode_iso20_ParameterSetType(exi_bitstream_t* stream, struct iso20_ParameterSetType* ParameterSetType);
static int decode_iso20_SupportedProvidersListType(exi_bitstream_t* stream, struct iso20_SupportedProvidersListType* SupportedProvidersListType);
static int decode_iso20_ContractCertificateChainType(exi_bitstream_t* stream, struct iso20_ContractCertificateChainType* ContractCertificateChainType);
static int decode_iso20_Dynamic_EVPPTControlModeType(exi_bitstream_t* stream, struct iso20_Dynamic_EVPPTControlModeType* Dynamic_EVPPTControlModeType);
static int decode_iso20_MeterInfoType(exi_bitstream_t* stream, struct iso20_MeterInfoType* MeterInfoType);
static int decode_iso20_SignatureType(exi_bitstream_t* stream, struct iso20_SignatureType* SignatureType);
static int decode_iso20_Scheduled_EVPPTControlModeType(exi_bitstream_t* stream, struct iso20_Scheduled_EVPPTControlModeType* Scheduled_EVPPTControlModeType);
static int decode_iso20_ReceiptType(exi_bitstream_t* stream, struct iso20_ReceiptType* ReceiptType);
static int decode_iso20_AbsolutePriceScheduleType(exi_bitstream_t* stream, struct iso20_AbsolutePriceScheduleType* AbsolutePriceScheduleType);
static int decode_iso20_EVPowerProfileEntryListType(exi_bitstream_t* stream, struct iso20_EVPowerProfileEntryListType* EVPowerProfileEntryListType);
static int decode_iso20_Dynamic_SMDTControlModeType(exi_bitstream_t* stream, struct iso20_Dynamic_SMDTControlModeType* Dynamic_SMDTControlModeType);
static int decode_iso20_EVEnergyOfferType(exi_bitstream_t* stream, struct iso20_EVEnergyOfferType* EVEnergyOfferType);
static int decode_iso20_PriceLevelScheduleType(exi_bitstream_t* stream, struct iso20_PriceLevelScheduleType* PriceLevelScheduleType);
static int decode_iso20_ChargingScheduleType(exi_bitstream_t* stream, struct iso20_ChargingScheduleType* ChargingScheduleType);
static int decode_iso20_ScheduleTupleType(exi_bitstream_t* stream, struct iso20_ScheduleTupleType* ScheduleTupleType);
static int decode_iso20_Scheduled_SMDTControlModeType(exi_bitstream_t* stream, struct iso20_Scheduled_SMDTControlModeType* Scheduled_SMDTControlModeType);
static int decode_iso20_MessageHeaderType(exi_bitstream_t* stream, struct iso20_MessageHeaderType* MessageHeaderType);
static int decode_iso20_SignaturePropertyType(exi_bitstream_t* stream, struct iso20_SignaturePropertyType* SignaturePropertyType);
static int decode_iso20_ServiceIDListType(exi_bitstream_t* stream, struct iso20_ServiceIDListType* ServiceIDListType);
static int decode_iso20_SelectedServiceType(exi_bitstream_t* stream, struct iso20_SelectedServiceType* SelectedServiceType);
static int decode_iso20_SignedMeteringDataType(exi_bitstream_t* stream, struct iso20_SignedMeteringDataType* SignedMeteringDataType);
static int decode_iso20_SignedCertificateChainType(exi_bitstream_t* stream, struct iso20_SignedCertificateChainType* SignedCertificateChainType);
static int decode_iso20_EIM_AReqAuthorizationModeType(exi_bitstream_t* stream, struct iso20_EIM_AReqAuthorizationModeType* EIM_AReqAuthorizationModeType);
static int decode_iso20_SelectedServiceListType(exi_bitstream_t* stream, struct iso20_SelectedServiceListType* SelectedServiceListType);
static int decode_iso20_Dynamic_SEReqControlModeType(exi_bitstream_t* stream, struct iso20_Dynamic_SEReqControlModeType* Dynamic_SEReqControlModeType);
static int decode_iso20_EVSEStatusType(exi_bitstream_t* stream, struct iso20_EVSEStatusType* EVSEStatusType);
static int decode_iso20_ListOfRootCertificateIDsType(exi_bitstream_t* stream, struct iso20_ListOfRootCertificateIDsType* ListOfRootCertificateIDsType);
static int decode_iso20_PnC_AReqAuthorizationModeType(exi_bitstream_t* stream, struct iso20_PnC_AReqAuthorizationModeType* PnC_AReqAuthorizationModeType);
static int decode_iso20_ServiceListType(exi_bitstream_t* stream, struct iso20_ServiceListType* ServiceListType);
static int decode_iso20_ServiceParameterListType(exi_bitstream_t* stream, struct iso20_ServiceParameterListType* ServiceParameterListType);
static int decode_iso20_Scheduled_SEReqControlModeType(exi_bitstream_t* stream, struct iso20_Scheduled_SEReqControlModeType* Scheduled_SEReqControlModeType);
static int decode_iso20_EVPowerProfileType(exi_bitstream_t* stream, struct iso20_EVPowerProfileType* EVPowerProfileType);
static int decode_iso20_CertificateChainType(exi_bitstream_t* stream, struct iso20_CertificateChainType* CertificateChainType);
static int decode_iso20_EIM_ASResAuthorizationModeType(exi_bitstream_t* stream, struct iso20_EIM_ASResAuthorizationModeType* EIM_ASResAuthorizationModeType);
static int decode_iso20_Dynamic_SEResControlModeType(exi_bitstream_t* stream, struct iso20_Dynamic_SEResControlModeType* Dynamic_SEResControlModeType);
static int decode_iso20_EMAIDListType(exi_bitstream_t* stream, struct iso20_EMAIDListType* EMAIDListType);
static int decode_iso20_SignedInstallationDataType(exi_bitstream_t* stream, struct iso20_SignedInstallationDataType* SignedInstallationDataType);
static int decode_iso20_PnC_ASResAuthorizationModeType(exi_bitstream_t* stream, struct iso20_PnC_ASResAuthorizationModeType* PnC_ASResAuthorizationModeType);
static int decode_iso20_Scheduled_SEResControlModeType(exi_bitstream_t* stream, struct iso20_Scheduled_SEResControlModeType* Scheduled_SEResControlModeType);
static int decode_iso20_SessionSetupReqType(exi_bitstream_t* stream, struct iso20_SessionSetupReqType* SessionSetupReqType);
static int decode_iso20_SessionSetupResType(exi_bitstream_t* stream, struct iso20_SessionSetupResType* SessionSetupResType);
static int decode_iso20_AuthorizationSetupReqType(exi_bitstream_t* stream, struct iso20_AuthorizationSetupReqType* AuthorizationSetupReqType);
static int decode_iso20_AuthorizationSetupResType(exi_bitstream_t* stream, struct iso20_AuthorizationSetupResType* AuthorizationSetupResType);
static int decode_iso20_AuthorizationReqType(exi_bitstream_t* stream, struct iso20_AuthorizationReqType* AuthorizationReqType);
static int decode_iso20_AuthorizationResType(exi_bitstream_t* stream, struct iso20_AuthorizationResType* AuthorizationResType);
static int decode_iso20_ServiceDiscoveryReqType(exi_bitstream_t* stream, struct iso20_ServiceDiscoveryReqType* ServiceDiscoveryReqType);
static int decode_iso20_ServiceDiscoveryResType(exi_bitstream_t* stream, struct iso20_ServiceDiscoveryResType* ServiceDiscoveryResType);
static int decode_iso20_ServiceDetailReqType(exi_bitstream_t* stream, struct iso20_ServiceDetailReqType* ServiceDetailReqType);
static int decode_iso20_ServiceDetailResType(exi_bitstream_t* stream, struct iso20_ServiceDetailResType* ServiceDetailResType);
static int decode_iso20_ServiceSelectionReqType(exi_bitstream_t* stream, struct iso20_ServiceSelectionReqType* ServiceSelectionReqType);
static int decode_iso20_ServiceSelectionResType(exi_bitstream_t* stream, struct iso20_ServiceSelectionResType* ServiceSelectionResType);
static int decode_iso20_ScheduleExchangeReqType(exi_bitstream_t* stream, struct iso20_ScheduleExchangeReqType* ScheduleExchangeReqType);
static int decode_iso20_ScheduleExchangeResType(exi_bitstream_t* stream, struct iso20_ScheduleExchangeResType* ScheduleExchangeResType);
static int decode_iso20_PowerDeliveryReqType(exi_bitstream_t* stream, struct iso20_PowerDeliveryReqType* PowerDeliveryReqType);
static int decode_iso20_PowerDeliveryResType(exi_bitstream_t* stream, struct iso20_PowerDeliveryResType* PowerDeliveryResType);
static int decode_iso20_MeteringConfirmationReqType(exi_bitstream_t* stream, struct iso20_MeteringConfirmationReqType* MeteringConfirmationReqType);
static int decode_iso20_MeteringConfirmationResType(exi_bitstream_t* stream, struct iso20_MeteringConfirmationResType* MeteringConfirmationResType);
static int decode_iso20_SessionStopReqType(exi_bitstream_t* stream, struct iso20_SessionStopReqType* SessionStopReqType);
static int decode_iso20_SessionStopResType(exi_bitstream_t* stream, struct iso20_SessionStopResType* SessionStopResType);
static int decode_iso20_CertificateInstallationReqType(exi_bitstream_t* stream, struct iso20_CertificateInstallationReqType* CertificateInstallationReqType);
static int decode_iso20_CertificateInstallationResType(exi_bitstream_t* stream, struct iso20_CertificateInstallationResType* CertificateInstallationResType);
static int decode_iso20_VehicleCheckInReqType(exi_bitstream_t* stream, struct iso20_VehicleCheckInReqType* VehicleCheckInReqType);
static int decode_iso20_VehicleCheckInResType(exi_bitstream_t* stream, struct iso20_VehicleCheckInResType* VehicleCheckInResType);
static int decode_iso20_VehicleCheckOutReqType(exi_bitstream_t* stream, struct iso20_VehicleCheckOutReqType* VehicleCheckOutReqType);
static int decode_iso20_VehicleCheckOutResType(exi_bitstream_t* stream, struct iso20_VehicleCheckOutResType* VehicleCheckOutResType);
static int decode_iso20_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_CLReqControlModeType* CLReqControlModeType);
static int decode_iso20_CLResControlModeType(exi_bitstream_t* stream, struct iso20_CLResControlModeType* CLResControlModeType);
static int decode_iso20_ManifestType(exi_bitstream_t* stream, struct iso20_ManifestType* ManifestType);
static int decode_iso20_SignaturePropertiesType(exi_bitstream_t* stream, struct iso20_SignaturePropertiesType* SignaturePropertiesType);

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Transform; type={http://www.w3.org/2000/09/xmldsig#}TransformType; base type=; content type=mixed;
//          abstract=False; final=False; choice=True;
// Particle: Algorithm, anyURI (1, 1); ANY, anyType (0, 1); XPath, string (0, 1);
static int decode_iso20_TransformType(exi_bitstream_t* stream, struct iso20_TransformType* TransformType) {
    int grammar_id = 0;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_TransformType(TransformType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 0:
            // Grammar: ID=0; read/write bits=1; START (Algorithm)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Algorithm, anyURI (anyURI)); next=1
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &TransformType->Algorithm.charactersLen);
                    if (error == 0)
                    {
                        if (TransformType->Algorithm.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            TransformType->Algorithm.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, TransformType->Algorithm.charactersLen, TransformType->Algorithm.characters, iso20_Algorithm_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    grammar_id = 1;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 1:
            // Grammar: ID=1; read/write bits=2; END Element, START (ANY), START (XPath)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &TransformType->ANY.bytesLen, &TransformType->ANY.bytes[0], iso20_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        TransformType->ANY_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: START (XPath, string (string)); next=2
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &TransformType->XPath.charactersLen);
                            if (error == 0)
                            {
                                if (TransformType->XPath.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    TransformType->XPath.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, TransformType->XPath.charactersLen, TransformType->XPath.characters, iso20_XPath_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                TransformType->XPath_isUsed = 1u;
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_TransformsType(exi_bitstream_t* stream, struct iso20_TransformsType* TransformsType) {
    int grammar_id = 4;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_TransformsType(TransformsType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 4:
            // Grammar: ID=4; read/write bits=1; START (Transform)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Transform, TransformType (TransformType)); next=5
                    // decode: element
                    error = decode_iso20_TransformType(stream, &TransformsType->Transform);
                    if (error == 0)
                    {
                        grammar_id = 5;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 5:
            // Grammar: ID=5; read/write bits=2; END Element, START (Transform)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Transform, TransformType (TransformType)); next=2
                    // decode: element
                    error = decode_iso20_TransformType(stream, &TransformsType->Transform);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_DSAKeyValueType(exi_bitstream_t* stream, struct iso20_DSAKeyValueType* DSAKeyValueType) {
    int grammar_id = 6;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_DSAKeyValueType(DSAKeyValueType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 6:
            // Grammar: ID=6; read/write bits=2; START (P), START (G), START (Y)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (P, CryptoBinary (base64Binary)); next=7
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->P.bytesLen, &DSAKeyValueType->P.bytes[0], iso20_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->P_isUsed = 1u;
                        grammar_id = 7;
                    }
                    break;
                case 1:
                    // Event: START (G, CryptoBinary (base64Binary)); next=9
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->G.bytesLen, &DSAKeyValueType->G.bytes[0], iso20_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->G_isUsed = 1u;
                        grammar_id = 9;
                    }
                    break;
                case 2:
                    // Event: START (Y, CryptoBinary (base64Binary)); next=10
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->Y.bytesLen, &DSAKeyValueType->Y.bytes[0], iso20_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 10;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 7:
            // Grammar: ID=7; read/write bits=1; START (Q)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Q, CryptoBinary (base64Binary)); next=8
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->Q.bytesLen, &DSAKeyValueType->Q.bytes[0], iso20_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->Q_isUsed = 1u;
                        grammar_id = 8;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 8:
            // Grammar: ID=8; read/write bits=2; START (G), START (Y)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (G, CryptoBinary (base64Binary)); next=9
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->G.bytesLen, &DSAKeyValueType->G.bytes[0], iso20_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->G_isUsed = 1u;
                        grammar_id = 9;
                    }
                    break;
                case 1:
                    // Event: START (Y, CryptoBinary (base64Binary)); next=10
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->Y.bytesLen, &DSAKeyValueType->Y.bytes[0], iso20_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 10;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 9:
            // Grammar: ID=9; read/write bits=1; START (Y)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Y, CryptoBinary (base64Binary)); next=10
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->Y.bytesLen, &DSAKeyValueType->Y.bytes[0], iso20_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 10;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 10:
            // Grammar: ID=10; read/write bits=2; END Element, START (J), START (Seed)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (J, CryptoBinary (base64Binary)); next=11
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->J.bytesLen, &DSAKeyValueType->J.bytes[0], iso20_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->J_isUsed = 1u;
                        grammar_id = 11;
                    }
                    break;
                case 1:
                    // Event: START (Seed, CryptoBinary (base64Binary)); next=12
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->Seed.bytesLen, &DSAKeyValueType->Seed.bytes[0], iso20_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->Seed_isUsed = 1u;
                        grammar_id = 12;
                    }
                    break;
                case 2:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 11:
            // Grammar: ID=11; read/write bits=2; END Element, START (Seed)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Seed, CryptoBinary (base64Binary)); next=12
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->Seed.bytesLen, &DSAKeyValueType->Seed.bytes[0], iso20_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->Seed_isUsed = 1u;
                        grammar_id = 12;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 12:
            // Grammar: ID=12; read/write bits=2; END Element, START (PgenCounter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PgenCounter, CryptoBinary (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DSAKeyValueType->PgenCounter.bytesLen, &DSAKeyValueType->PgenCounter.bytes[0], iso20_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        DSAKeyValueType->PgenCounter_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_X509IssuerSerialType(exi_bitstream_t* stream, struct iso20_X509IssuerSerialType* X509IssuerSerialType) {
    int grammar_id = 13;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_X509IssuerSerialType(X509IssuerSerialType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 13:
            // Grammar: ID=13; read/write bits=1; START (X509IssuerName)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (X509IssuerName, string (string)); next=14
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &X509IssuerSerialType->X509IssuerName.charactersLen);
                            if (error == 0)
                            {
                                if (X509IssuerSerialType->X509IssuerName.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    X509IssuerSerialType->X509IssuerName.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, X509IssuerSerialType->X509IssuerName.charactersLen, X509IssuerSerialType->X509IssuerName.characters, iso20_X509IssuerName_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 14;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 14:
            // Grammar: ID=14; read/write bits=1; START (X509SerialNumber)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (X509SerialNumber, integer (decimal)); next=2
                    // decode: int
                    error = decode_exi_type_integer32(stream, &X509IssuerSerialType->X509SerialNumber);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_DigestMethodType(exi_bitstream_t* stream, struct iso20_DigestMethodType* DigestMethodType) {
    int grammar_id = 15;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_DigestMethodType(DigestMethodType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 15:
            // Grammar: ID=15; read/write bits=1; START (Algorithm)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Algorithm, anyURI (anyURI)); next=16
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &DigestMethodType->Algorithm.charactersLen);
                    if (error == 0)
                    {
                        if (DigestMethodType->Algorithm.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            DigestMethodType->Algorithm.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, DigestMethodType->Algorithm.charactersLen, DigestMethodType->Algorithm.characters, iso20_Algorithm_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    grammar_id = 16;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 16:
            // Grammar: ID=16; read/write bits=2; END Element, START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &DigestMethodType->ANY.bytesLen, &DigestMethodType->ANY.bytes[0], iso20_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        DigestMethodType->ANY_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_RSAKeyValueType(exi_bitstream_t* stream, struct iso20_RSAKeyValueType* RSAKeyValueType) {
    int grammar_id = 17;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_RSAKeyValueType(RSAKeyValueType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 17:
            // Grammar: ID=17; read/write bits=1; START (Modulus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Modulus, CryptoBinary (base64Binary)); next=18
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &RSAKeyValueType->Modulus.bytesLen, &RSAKeyValueType->Modulus.bytes[0], iso20_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 18;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 18:
            // Grammar: ID=18; read/write bits=1; START (Exponent)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Exponent, CryptoBinary (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &RSAKeyValueType->Exponent.bytesLen, &RSAKeyValueType->Exponent.bytes[0], iso20_CryptoBinary_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_CanonicalizationMethodType(exi_bitstream_t* stream, struct iso20_CanonicalizationMethodType* CanonicalizationMethodType) {
    int grammar_id = 19;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_CanonicalizationMethodType(CanonicalizationMethodType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 19:
            // Grammar: ID=19; read/write bits=1; START (Algorithm)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Algorithm, anyURI (anyURI)); next=20
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &CanonicalizationMethodType->Algorithm.charactersLen);
                    if (error == 0)
                    {
                        if (CanonicalizationMethodType->Algorithm.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            CanonicalizationMethodType->Algorithm.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, CanonicalizationMethodType->Algorithm.charactersLen, CanonicalizationMethodType->Algorithm.characters, iso20_Algorithm_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    grammar_id = 20;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 20:
            // Grammar: ID=20; read/write bits=2; END Element, START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &CanonicalizationMethodType->ANY.bytesLen, &CanonicalizationMethodType->ANY.bytes[0], iso20_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        CanonicalizationMethodType->ANY_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}PriceLevelScheduleEntry; type={urn:iso:std:iso:15118:-20:CommonMessages}PriceLevelScheduleEntryType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Duration, unsignedInt (1, 1); PriceLevel, unsignedByte (1, 1);
static int decode_iso20_PriceLevelScheduleEntryType(exi_bitstream_t* stream, struct iso20_PriceLevelScheduleEntryType* PriceLevelScheduleEntryType) {
    int grammar_id = 21;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_PriceLevelScheduleEntryType(PriceLevelScheduleEntryType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 21:
            // Grammar: ID=21; read/write bits=1; START (Duration)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Duration, unsignedInt (unsignedLong)); next=22
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &PriceLevelScheduleEntryType->Duration);
                    if (error == 0)
                    {
                        grammar_id = 22;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 22:
            // Grammar: ID=22; read/write bits=1; START (PriceLevel)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PriceLevel, unsignedByte (unsignedShort)); next=2
                    // decode: unsigned byte (restricted integer)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 8, &value);
                            if (error == 0)
                            {
                                PriceLevelScheduleEntryType->PriceLevel = (uint8_t)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_SignatureMethodType(exi_bitstream_t* stream, struct iso20_SignatureMethodType* SignatureMethodType) {
    int grammar_id = 23;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_SignatureMethodType(SignatureMethodType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 23:
            // Grammar: ID=23; read/write bits=1; START (Algorithm)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Algorithm, anyURI (anyURI)); next=24
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &SignatureMethodType->Algorithm.charactersLen);
                    if (error == 0)
                    {
                        if (SignatureMethodType->Algorithm.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            SignatureMethodType->Algorithm.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, SignatureMethodType->Algorithm.charactersLen, SignatureMethodType->Algorithm.characters, iso20_Algorithm_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    grammar_id = 24;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 24:
            // Grammar: ID=24; read/write bits=2; END Element, START (HMACOutputLength), START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (HMACOutputLength, HMACOutputLengthType (integer)); next=25
                    // decode: int
                    error = decode_exi_type_integer32(stream, &SignatureMethodType->HMACOutputLength);
                    if (error == 0)
                    {
                        SignatureMethodType->HMACOutputLength_isUsed = 1u;
                        grammar_id = 25;
                    }
                    break;
                case 1:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SignatureMethodType->ANY.bytesLen, &SignatureMethodType->ANY.bytes[0], iso20_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        SignatureMethodType->ANY_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 2:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 25:
            // Grammar: ID=25; read/write bits=2; END Element, START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SignatureMethodType->ANY.bytesLen, &SignatureMethodType->ANY.bytes[0], iso20_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        SignatureMethodType->ANY_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_KeyValueType(exi_bitstream_t* stream, struct iso20_KeyValueType* KeyValueType) {
    int grammar_id = 26;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_KeyValueType(KeyValueType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 26:
            // Grammar: ID=26; read/write bits=2; START (DSAKeyValue), START (RSAKeyValue), START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DSAKeyValue, DSAKeyValueType (DSAKeyValueType)); next=2
                    // decode: element
                    error = decode_iso20_DSAKeyValueType(stream, &KeyValueType->DSAKeyValue);
                    if (error == 0)
                    {
                        KeyValueType->DSAKeyValue_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: START (RSAKeyValue, RSAKeyValueType (RSAKeyValueType)); next=2
                    // decode: element
                    error = decode_iso20_RSAKeyValueType(stream, &KeyValueType->RSAKeyValue);
                    if (error == 0)
                    {
                        KeyValueType->RSAKeyValue_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 2:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &KeyValueType->ANY.bytesLen, &KeyValueType->ANY.bytes[0], iso20_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        KeyValueType->ANY_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_ReferenceType(exi_bitstream_t* stream, struct iso20_ReferenceType* ReferenceType) {
    int grammar_id = 27;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ReferenceType(ReferenceType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 27:
            // Grammar: ID=27; read/write bits=3; START (Id), START (Type), START (URI), START (Transforms), START (DigestMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=28
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ReferenceType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (ReferenceType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ReferenceType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ReferenceType->Id.charactersLen, ReferenceType->Id.characters, iso20_Id_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ReferenceType->Id_isUsed = 1u;
                    grammar_id = 28;
                    break;
                case 1:
                    // Event: START (Type, anyURI (anyURI)); next=29
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ReferenceType->Type.charactersLen);
                    if (error == 0)
                    {
                        if (ReferenceType->Type.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ReferenceType->Type.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ReferenceType->Type.charactersLen, ReferenceType->Type.characters, iso20_Type_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ReferenceType->Type_isUsed = 1u;
                    grammar_id = 29;
                    break;
                case 2:
                    // Event: START (URI, anyURI (anyURI)); next=30
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ReferenceType->URI.charactersLen);
                    if (error == 0)
                    {
                        if (ReferenceType->URI.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ReferenceType->URI.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ReferenceType->URI.charactersLen, ReferenceType->URI.characters, iso20_URI_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ReferenceType->URI_isUsed = 1u;
                    grammar_id = 30;
                    break;
                case 3:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=31
                    // decode: element
                    error = decode_iso20_TransformsType(stream, &ReferenceType->Transforms);
                    if (error == 0)
                    {
                        ReferenceType->Transforms_isUsed = 1u;
                        grammar_id = 31;
                    }
                    break;
                case 4:
                    // Event: START (DigestMethod, DigestMethodType (DigestMethodType)); next=32
                    // decode: element
                    error = decode_iso20_DigestMethodType(stream, &ReferenceType->DigestMethod);
                    if (error == 0)
                    {
                        grammar_id = 32;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 28:
            // Grammar: ID=28; read/write bits=3; START (Type), START (URI), START (Transforms), START (DigestMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Type, anyURI (anyURI)); next=29
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ReferenceType->Type.charactersLen);
                    if (error == 0)
                    {
                        if (ReferenceType->Type.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ReferenceType->Type.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ReferenceType->Type.charactersLen, ReferenceType->Type.characters, iso20_Type_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ReferenceType->Type_isUsed = 1u;
                    grammar_id = 29;
                    break;
                case 1:
                    // Event: START (URI, anyURI (anyURI)); next=30
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ReferenceType->URI.charactersLen);
                    if (error == 0)
                    {
                        if (ReferenceType->URI.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ReferenceType->URI.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ReferenceType->URI.charactersLen, ReferenceType->URI.characters, iso20_URI_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ReferenceType->URI_isUsed = 1u;
                    grammar_id = 30;
                    break;
                case 2:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=31
                    // decode: element
                    error = decode_iso20_TransformsType(stream, &ReferenceType->Transforms);
                    if (error == 0)
                    {
                        ReferenceType->Transforms_isUsed = 1u;
                        grammar_id = 31;
                    }
                    break;
                case 3:
                    // Event: START (DigestMethod, DigestMethodType (DigestMethodType)); next=32
                    // decode: element
                    error = decode_iso20_DigestMethodType(stream, &ReferenceType->DigestMethod);
                    if (error == 0)
                    {
                        grammar_id = 32;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 29:
            // Grammar: ID=29; read/write bits=2; START (URI), START (Transforms), START (DigestMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (URI, anyURI (anyURI)); next=30
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ReferenceType->URI.charactersLen);
                    if (error == 0)
                    {
                        if (ReferenceType->URI.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ReferenceType->URI.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ReferenceType->URI.charactersLen, ReferenceType->URI.characters, iso20_URI_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ReferenceType->URI_isUsed = 1u;
                    grammar_id = 30;
                    break;
                case 1:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=31
                    // decode: element
                    error = decode_iso20_TransformsType(stream, &ReferenceType->Transforms);
                    if (error == 0)
                    {
                        ReferenceType->Transforms_isUsed = 1u;
                        grammar_id = 31;
                    }
                    break;
                case 2:
                    // Event: START (DigestMethod, DigestMethodType (DigestMethodType)); next=32
                    // decode: element
                    error = decode_iso20_DigestMethodType(stream, &ReferenceType->DigestMethod);
                    if (error == 0)
                    {
                        grammar_id = 32;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 30:
            // Grammar: ID=30; read/write bits=2; START (Transforms), START (DigestMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=31
                    // decode: element
                    error = decode_iso20_TransformsType(stream, &ReferenceType->Transforms);
                    if (error == 0)
                    {
                        ReferenceType->Transforms_isUsed = 1u;
                        grammar_id = 31;
                    }
                    break;
                case 1:
                    // Event: START (DigestMethod, DigestMethodType (DigestMethodType)); next=32
                    // decode: element
                    error = decode_iso20_DigestMethodType(stream, &ReferenceType->DigestMethod);
                    if (error == 0)
                    {
                        grammar_id = 32;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 31:
            // Grammar: ID=31; read/write bits=1; START (DigestMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DigestMethod, DigestMethodType (DigestMethodType)); next=32
                    // decode: element
                    error = decode_iso20_DigestMethodType(stream, &ReferenceType->DigestMethod);
                    if (error == 0)
                    {
                        grammar_id = 32;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 32:
            // Grammar: ID=32; read/write bits=1; START (DigestValue)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DigestValue, DigestValueType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &ReferenceType->DigestValue.bytesLen, &ReferenceType->DigestValue.bytes[0], iso20_DigestValueType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_RetrievalMethodType(exi_bitstream_t* stream, struct iso20_RetrievalMethodType* RetrievalMethodType) {
    int grammar_id = 33;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_RetrievalMethodType(RetrievalMethodType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 33:
            // Grammar: ID=33; read/write bits=3; END Element, START (Type), START (URI), START (Transforms)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Type, anyURI (anyURI)); next=34
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &RetrievalMethodType->Type.charactersLen);
                    if (error == 0)
                    {
                        if (RetrievalMethodType->Type.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            RetrievalMethodType->Type.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, RetrievalMethodType->Type.charactersLen, RetrievalMethodType->Type.characters, iso20_Type_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    RetrievalMethodType->Type_isUsed = 1u;
                    grammar_id = 34;
                    break;
                case 1:
                    // Event: START (URI, anyURI (anyURI)); next=35
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &RetrievalMethodType->URI.charactersLen);
                    if (error == 0)
                    {
                        if (RetrievalMethodType->URI.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            RetrievalMethodType->URI.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, RetrievalMethodType->URI.charactersLen, RetrievalMethodType->URI.characters, iso20_URI_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    RetrievalMethodType->URI_isUsed = 1u;
                    grammar_id = 35;
                    break;
                case 2:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=2
                    // decode: element
                    error = decode_iso20_TransformsType(stream, &RetrievalMethodType->Transforms);
                    if (error == 0)
                    {
                        RetrievalMethodType->Transforms_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 3:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 34:
            // Grammar: ID=34; read/write bits=2; END Element, START (URI), START (Transforms)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (URI, anyURI (anyURI)); next=35
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &RetrievalMethodType->URI.charactersLen);
                    if (error == 0)
                    {
                        if (RetrievalMethodType->URI.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            RetrievalMethodType->URI.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, RetrievalMethodType->URI.charactersLen, RetrievalMethodType->URI.characters, iso20_URI_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    RetrievalMethodType->URI_isUsed = 1u;
                    grammar_id = 35;
                    break;
                case 1:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=2
                    // decode: element
                    error = decode_iso20_TransformsType(stream, &RetrievalMethodType->Transforms);
                    if (error == 0)
                    {
                        RetrievalMethodType->Transforms_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 2:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 35:
            // Grammar: ID=35; read/write bits=2; END Element, START (Transforms)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Transforms, TransformsType (TransformsType)); next=2
                    // decode: element
                    error = decode_iso20_TransformsType(stream, &RetrievalMethodType->Transforms);
                    if (error == 0)
                    {
                        RetrievalMethodType->Transforms_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_X509DataType(exi_bitstream_t* stream, struct iso20_X509DataType* X509DataType) {
    int grammar_id = 36;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_X509DataType(X509DataType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 36:
            // Grammar: ID=36; read/write bits=3; START (X509IssuerSerial), START (X509SKI), START (X509SubjectName), START (X509Certificate), START (X509CRL), START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (X509IssuerSerial, X509IssuerSerialType (X509IssuerSerialType)); next=2
                    // decode: element
                    error = decode_iso20_X509IssuerSerialType(stream, &X509DataType->X509IssuerSerial);
                    if (error == 0)
                    {
                        X509DataType->X509IssuerSerial_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: START (X509SKI, base64Binary (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &X509DataType->X509SKI.bytesLen, &X509DataType->X509SKI.bytes[0], iso20_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        X509DataType->X509SKI_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 2:
                    // Event: START (X509SubjectName, string (string)); next=2
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &X509DataType->X509SubjectName.charactersLen);
                            if (error == 0)
                            {
                                if (X509DataType->X509SubjectName.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    X509DataType->X509SubjectName.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, X509DataType->X509SubjectName.charactersLen, X509DataType->X509SubjectName.characters, iso20_X509SubjectName_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                X509DataType->X509SubjectName_isUsed = 1u;
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 3:
                    // Event: START (X509Certificate, base64Binary (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &X509DataType->X509Certificate.bytesLen, &X509DataType->X509Certificate.bytes[0], iso20_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        X509DataType->X509Certificate_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 4:
                    // Event: START (X509CRL, base64Binary (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &X509DataType->X509CRL.bytesLen, &X509DataType->X509CRL.bytes[0], iso20_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        X509DataType->X509CRL_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 5:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &X509DataType->ANY.bytesLen, &X509DataType->ANY.bytes[0], iso20_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        X509DataType->ANY_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_PGPDataType(exi_bitstream_t* stream, struct iso20_PGPDataType* PGPDataType) {
    int grammar_id = 37;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_PGPDataType(PGPDataType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 37:
            // Grammar: ID=37; read/write bits=1; START (PGPKeyID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PGPKeyID, base64Binary (base64Binary)); next=38
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PGPDataType->choice_1.PGPKeyID.bytesLen, &PGPDataType->choice_1.PGPKeyID.bytes[0], iso20_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 38;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 38:
            // Grammar: ID=38; read/write bits=2; START (PGPKeyPacket), START (ANY), START (PGPKeyPacket)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PGPKeyPacket, base64Binary (base64Binary)); next=39
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PGPDataType->choice_1.PGPKeyPacket.bytesLen, &PGPDataType->choice_1.PGPKeyPacket.bytes[0], iso20_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        PGPDataType->choice_1.PGPKeyPacket_isUsed = 1u;
                        grammar_id = 39;
                    }
                    break;
                case 1:
                    // Event: START (ANY, anyType (base64Binary)); next=40
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PGPDataType->choice_1.ANY.bytesLen, &PGPDataType->choice_1.ANY.bytes[0], iso20_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        PGPDataType->choice_1.ANY_isUsed = 1u;
                        grammar_id = 40;
                    }
                    break;
                case 2:
                    // Event: START (PGPKeyPacket, base64Binary (base64Binary)); next=41
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PGPDataType->choice_2.PGPKeyPacket.bytesLen, &PGPDataType->choice_2.PGPKeyPacket.bytes[0], iso20_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 41;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 39:
            // Grammar: ID=39; read/write bits=2; START (ANY), START (PGPKeyPacket)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ANY, anyType (base64Binary)); next=40
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PGPDataType->choice_1.ANY.bytesLen, &PGPDataType->choice_1.ANY.bytes[0], iso20_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        PGPDataType->choice_1.ANY_isUsed = 1u;
                        grammar_id = 40;
                    }
                    break;
                case 1:
                    // Event: START (PGPKeyPacket, base64Binary (base64Binary)); next=41
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PGPDataType->choice_2.PGPKeyPacket.bytesLen, &PGPDataType->choice_2.PGPKeyPacket.bytes[0], iso20_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 41;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 40:
            // Grammar: ID=40; read/write bits=1; START (PGPKeyPacket)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PGPKeyPacket, base64Binary (base64Binary)); next=41
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PGPDataType->choice_2.PGPKeyPacket.bytesLen, &PGPDataType->choice_2.PGPKeyPacket.bytes[0], iso20_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 41;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 41:
            // Grammar: ID=41; read/write bits=2; END Element, START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PGPDataType->choice_2.ANY.bytesLen, &PGPDataType->choice_2.ANY.bytes[0], iso20_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        PGPDataType->choice_2.ANY_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}rationalNumber; type={urn:iso:std:iso:15118:-20:CommonTypes}RationalNumberType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Exponent, byte (1, 1); Value, short (1, 1);
static int decode_iso20_RationalNumberType(exi_bitstream_t* stream, struct iso20_RationalNumberType* RationalNumberType) {
    int grammar_id = 42;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_RationalNumberType(RationalNumberType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 42:
            // Grammar: ID=42; read/write bits=1; START (Exponent)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Exponent, byte (short)); next=43
                    // decode: byte (restricted integer)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 8, &value);
                            if (error == 0)
                            {
                                // type has min_value = -128
                                RationalNumberType->Exponent = (int8_t)(value + -128);
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 43;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 43:
            // Grammar: ID=43; read/write bits=1; START (Value)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Value, short (int)); next=2
                    // decode: short
                    error = decode_exi_type_integer16(stream, &RationalNumberType->Value);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}PowerScheduleEntry; type={urn:iso:std:iso:15118:-20:CommonMessages}PowerScheduleEntryType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Duration, unsignedInt (1, 1); Power, RationalNumberType (1, 1); Power_L2, RationalNumberType (0, 1); Power_L3, RationalNumberType (0, 1);
static int decode_iso20_PowerScheduleEntryType(exi_bitstream_t* stream, struct iso20_PowerScheduleEntryType* PowerScheduleEntryType) {
    int grammar_id = 44;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_PowerScheduleEntryType(PowerScheduleEntryType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 44:
            // Grammar: ID=44; read/write bits=1; START (Duration)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Duration, unsignedInt (unsignedLong)); next=45
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &PowerScheduleEntryType->Duration);
                    if (error == 0)
                    {
                        grammar_id = 45;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 45:
            // Grammar: ID=45; read/write bits=1; START (Power)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Power, RationalNumberType (RationalNumberType)); next=46
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &PowerScheduleEntryType->Power);
                    if (error == 0)
                    {
                        grammar_id = 46;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 46:
            // Grammar: ID=46; read/write bits=2; END Element, START (Power_L2), START (Power_L3)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Power_L2, RationalNumberType (RationalNumberType)); next=47
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &PowerScheduleEntryType->Power_L2);
                    if (error == 0)
                    {
                        PowerScheduleEntryType->Power_L2_isUsed = 1u;
                        grammar_id = 47;
                    }
                    break;
                case 1:
                    // Event: START (Power_L3, RationalNumberType (RationalNumberType)); next=2
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &PowerScheduleEntryType->Power_L3);
                    if (error == 0)
                    {
                        PowerScheduleEntryType->Power_L3_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 2:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 47:
            // Grammar: ID=47; read/write bits=2; END Element, START (Power_L3)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Power_L3, RationalNumberType (RationalNumberType)); next=2
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &PowerScheduleEntryType->Power_L3);
                    if (error == 0)
                    {
                        PowerScheduleEntryType->Power_L3_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}EVPriceRule; type={urn:iso:std:iso:15118:-20:CommonMessages}EVPriceRuleType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EnergyFee, RationalNumberType (1, 1); PowerRangeStart, RationalNumberType (1, 1);
static int decode_iso20_EVPriceRuleType(exi_bitstream_t* stream, struct iso20_EVPriceRuleType* EVPriceRuleType) {
    int grammar_id = 48;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_EVPriceRuleType(EVPriceRuleType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 48:
            // Grammar: ID=48; read/write bits=1; START (EnergyFee)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EnergyFee, RationalNumberType (RationalNumberType)); next=49
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &EVPriceRuleType->EnergyFee);
                    if (error == 0)
                    {
                        grammar_id = 49;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 49:
            // Grammar: ID=49; read/write bits=1; START (PowerRangeStart)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PowerRangeStart, RationalNumberType (RationalNumberType)); next=2
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &EVPriceRuleType->PowerRangeStart);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}EVPowerScheduleEntry; type={urn:iso:std:iso:15118:-20:CommonMessages}EVPowerScheduleEntryType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Duration, unsignedInt (1, 1); Power, RationalNumberType (1, 1);
static int decode_iso20_EVPowerScheduleEntryType(exi_bitstream_t* stream, struct iso20_EVPowerScheduleEntryType* EVPowerScheduleEntryType) {
    int grammar_id = 50;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_EVPowerScheduleEntryType(EVPowerScheduleEntryType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 50:
            // Grammar: ID=50; read/write bits=1; START (Duration)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Duration, unsignedInt (unsignedLong)); next=51
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &EVPowerScheduleEntryType->Duration);
                    if (error == 0)
                    {
                        grammar_id = 51;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 51:
            // Grammar: ID=51; read/write bits=1; START (Power)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Power, RationalNumberType (RationalNumberType)); next=2
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &EVPowerScheduleEntryType->Power);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}EVPriceRuleStack; type={urn:iso:std:iso:15118:-20:CommonMessages}EVPriceRuleStackType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Duration, unsignedInt (1, 1); EVPriceRule, EVPriceRuleType (1, 8);
static int decode_iso20_EVPriceRuleStackType(exi_bitstream_t* stream, struct iso20_EVPriceRuleStackType* EVPriceRuleStackType) {
    int grammar_id = 52;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_EVPriceRuleStackType(EVPriceRuleStackType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 52:
            // Grammar: ID=52; read/write bits=1; START (Duration)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Duration, unsignedInt (unsignedLong)); next=53
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &EVPriceRuleStackType->Duration);
                    if (error == 0)
                    {
                        grammar_id = 53;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 53:
            // Grammar: ID=53; read/write bits=1; START (EVPriceRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVPriceRule, EVPriceRuleType (EVPriceRuleType)); next=54
                    // decode: element array
                    if (EVPriceRuleStackType->EVPriceRule.arrayLen < iso20_EVPriceRuleType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_EVPriceRuleType(stream, &EVPriceRuleStackType->EVPriceRule.array[EVPriceRuleStackType->EVPriceRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 54;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 54:
            // Grammar: ID=54; read/write bits=2; END Element, START (EVPriceRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVPriceRule, EVPriceRuleType (EVPriceRuleType)); next=55
                    // decode: element array
                    if (EVPriceRuleStackType->EVPriceRule.arrayLen < iso20_EVPriceRuleType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_EVPriceRuleType(stream, &EVPriceRuleStackType->EVPriceRule.array[EVPriceRuleStackType->EVPriceRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 55;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 55:
            // Grammar: ID=55; read/write bits=2; END Element, START (EVPriceRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVPriceRule, EVPriceRuleType (EVPriceRuleType)); next=56
                    // decode: element array
                    if (EVPriceRuleStackType->EVPriceRule.arrayLen < iso20_EVPriceRuleType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_EVPriceRuleType(stream, &EVPriceRuleStackType->EVPriceRule.array[EVPriceRuleStackType->EVPriceRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 56;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 56:
            // Grammar: ID=56; read/write bits=2; END Element, START (EVPriceRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVPriceRule, EVPriceRuleType (EVPriceRuleType)); next=57
                    // decode: element array
                    if (EVPriceRuleStackType->EVPriceRule.arrayLen < iso20_EVPriceRuleType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_EVPriceRuleType(stream, &EVPriceRuleStackType->EVPriceRule.array[EVPriceRuleStackType->EVPriceRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 57;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 57:
            // Grammar: ID=57; read/write bits=2; END Element, START (EVPriceRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVPriceRule, EVPriceRuleType (EVPriceRuleType)); next=58
                    // decode: element array
                    if (EVPriceRuleStackType->EVPriceRule.arrayLen < iso20_EVPriceRuleType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_EVPriceRuleType(stream, &EVPriceRuleStackType->EVPriceRule.array[EVPriceRuleStackType->EVPriceRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 58;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 58:
            // Grammar: ID=58; read/write bits=2; END Element, START (EVPriceRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVPriceRule, EVPriceRuleType (EVPriceRuleType)); next=59
                    // decode: element array
                    if (EVPriceRuleStackType->EVPriceRule.arrayLen < iso20_EVPriceRuleType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_EVPriceRuleType(stream, &EVPriceRuleStackType->EVPriceRule.array[EVPriceRuleStackType->EVPriceRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 59;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 59:
            // Grammar: ID=59; read/write bits=2; END Element, START (EVPriceRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVPriceRule, EVPriceRuleType (EVPriceRuleType)); next=60
                    // decode: element array
                    if (EVPriceRuleStackType->EVPriceRule.arrayLen < iso20_EVPriceRuleType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_EVPriceRuleType(stream, &EVPriceRuleStackType->EVPriceRule.array[EVPriceRuleStackType->EVPriceRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 60;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 60:
            // Grammar: ID=60; read/write bits=2; END Element, START (EVPriceRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVPriceRule, EVPriceRuleType (EVPriceRuleType)); next=2
                    // decode: element array
                    if (EVPriceRuleStackType->EVPriceRule.arrayLen < iso20_EVPriceRuleType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_EVPriceRuleType(stream, &EVPriceRuleStackType->EVPriceRule.array[EVPriceRuleStackType->EVPriceRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 2;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}PriceRule; type={urn:iso:std:iso:15118:-20:CommonMessages}PriceRuleType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EnergyFee, RationalNumberType (1, 1); ParkingFee, RationalNumberType (0, 1); ParkingFeePeriod, unsignedInt (0, 1); CarbonDioxideEmission, unsignedShort (0, 1); RenewableGenerationPercentage, unsignedByte (0, 1); PowerRangeStart, RationalNumberType (1, 1);
static int decode_iso20_PriceRuleType(exi_bitstream_t* stream, struct iso20_PriceRuleType* PriceRuleType) {
    int grammar_id = 61;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_PriceRuleType(PriceRuleType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 61:
            // Grammar: ID=61; read/write bits=1; START (EnergyFee)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EnergyFee, RationalNumberType (RationalNumberType)); next=62
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &PriceRuleType->EnergyFee);
                    if (error == 0)
                    {
                        grammar_id = 62;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 62:
            // Grammar: ID=62; read/write bits=3; START (ParkingFee), START (ParkingFeePeriod), START (CarbonDioxideEmission), START (RenewableGenerationPercentage), START (PowerRangeStart)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ParkingFee, RationalNumberType (RationalNumberType)); next=63
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &PriceRuleType->ParkingFee);
                    if (error == 0)
                    {
                        PriceRuleType->ParkingFee_isUsed = 1u;
                        grammar_id = 63;
                    }
                    break;
                case 1:
                    // Event: START (ParkingFeePeriod, unsignedInt (unsignedLong)); next=64
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &PriceRuleType->ParkingFeePeriod);
                    if (error == 0)
                    {
                        PriceRuleType->ParkingFeePeriod_isUsed = 1u;
                        grammar_id = 64;
                    }
                    break;
                case 2:
                    // Event: START (CarbonDioxideEmission, unsignedShort (unsignedInt)); next=65
                    // decode: unsigned short
                    error = decode_exi_type_uint16(stream, &PriceRuleType->CarbonDioxideEmission);
                    if (error == 0)
                    {
                        PriceRuleType->CarbonDioxideEmission_isUsed = 1u;
                        grammar_id = 65;
                    }
                    break;
                case 3:
                    // Event: START (RenewableGenerationPercentage, unsignedByte (unsignedShort)); next=66
                    // decode: unsigned byte (restricted integer)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 8, &value);
                            if (error == 0)
                            {
                                PriceRuleType->RenewableGenerationPercentage = (uint8_t)value;
                                PriceRuleType->RenewableGenerationPercentage_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 66;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 4:
                    // Event: START (PowerRangeStart, RationalNumberType (RationalNumberType)); next=2
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &PriceRuleType->PowerRangeStart);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 63:
            // Grammar: ID=63; read/write bits=3; START (ParkingFeePeriod), START (CarbonDioxideEmission), START (RenewableGenerationPercentage), START (PowerRangeStart)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ParkingFeePeriod, unsignedInt (unsignedLong)); next=64
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &PriceRuleType->ParkingFeePeriod);
                    if (error == 0)
                    {
                        PriceRuleType->ParkingFeePeriod_isUsed = 1u;
                        grammar_id = 64;
                    }
                    break;
                case 1:
                    // Event: START (CarbonDioxideEmission, unsignedShort (unsignedInt)); next=65
                    // decode: unsigned short
                    error = decode_exi_type_uint16(stream, &PriceRuleType->CarbonDioxideEmission);
                    if (error == 0)
                    {
                        PriceRuleType->CarbonDioxideEmission_isUsed = 1u;
                        grammar_id = 65;
                    }
                    break;
                case 2:
                    // Event: START (RenewableGenerationPercentage, unsignedByte (unsignedShort)); next=66
                    // decode: unsigned byte (restricted integer)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 8, &value);
                            if (error == 0)
                            {
                                PriceRuleType->RenewableGenerationPercentage = (uint8_t)value;
                                PriceRuleType->RenewableGenerationPercentage_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 66;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 3:
                    // Event: START (PowerRangeStart, RationalNumberType (RationalNumberType)); next=2
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &PriceRuleType->PowerRangeStart);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 64:
            // Grammar: ID=64; read/write bits=2; START (CarbonDioxideEmission), START (RenewableGenerationPercentage), START (PowerRangeStart)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (CarbonDioxideEmission, unsignedShort (unsignedInt)); next=65
                    // decode: unsigned short
                    error = decode_exi_type_uint16(stream, &PriceRuleType->CarbonDioxideEmission);
                    if (error == 0)
                    {
                        PriceRuleType->CarbonDioxideEmission_isUsed = 1u;
                        grammar_id = 65;
                    }
                    break;
                case 1:
                    // Event: START (RenewableGenerationPercentage, unsignedByte (unsignedShort)); next=66
                    // decode: unsigned byte (restricted integer)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 8, &value);
                            if (error == 0)
                            {
                                PriceRuleType->RenewableGenerationPercentage = (uint8_t)value;
                                PriceRuleType->RenewableGenerationPercentage_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 66;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: START (PowerRangeStart, RationalNumberType (RationalNumberType)); next=2
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &PriceRuleType->PowerRangeStart);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 65:
            // Grammar: ID=65; read/write bits=2; START (RenewableGenerationPercentage), START (PowerRangeStart)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RenewableGenerationPercentage, unsignedByte (unsignedShort)); next=66
                    // decode: unsigned byte (restricted integer)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 8, &value);
                            if (error == 0)
                            {
                                PriceRuleType->RenewableGenerationPercentage = (uint8_t)value;
                                PriceRuleType->RenewableGenerationPercentage_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 66;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (PowerRangeStart, RationalNumberType (RationalNumberType)); next=2
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &PriceRuleType->PowerRangeStart);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 66:
            // Grammar: ID=66; read/write bits=1; START (PowerRangeStart)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PowerRangeStart, RationalNumberType (RationalNumberType)); next=2
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &PriceRuleType->PowerRangeStart);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}PowerScheduleEntries; type={urn:iso:std:iso:15118:-20:CommonMessages}PowerScheduleEntryListType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: PowerScheduleEntry, PowerScheduleEntryType (1, 1024);
static int decode_iso20_PowerScheduleEntryListType(exi_bitstream_t* stream, struct iso20_PowerScheduleEntryListType* PowerScheduleEntryListType) {
    int grammar_id = 67;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_PowerScheduleEntryListType(PowerScheduleEntryListType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 67:
            // Grammar: ID=67; read/write bits=1; START (PowerScheduleEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PowerScheduleEntry, PowerScheduleEntryType (PowerScheduleEntryType)); next=68
                    // decode: element array
                    if (PowerScheduleEntryListType->PowerScheduleEntry.arrayLen < iso20_PowerScheduleEntryType_1024_ARRAY_SIZE)
                    {
                        error = decode_iso20_PowerScheduleEntryType(stream, &PowerScheduleEntryListType->PowerScheduleEntry.array[PowerScheduleEntryListType->PowerScheduleEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 68;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 68:
            // Grammar: ID=68; read/write bits=2; END Element, LOOP (PowerScheduleEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case -1:
                    // Event: LOOP (PowerScheduleEntry, PowerScheduleEntryType (PowerScheduleEntryType)); next=3
                    // decode: element array
                    if (PowerScheduleEntryListType->PowerScheduleEntry.arrayLen < iso20_PowerScheduleEntryType_1024_ARRAY_SIZE)
                    {
                        error = decode_iso20_PowerScheduleEntryType(stream, &PowerScheduleEntryListType->PowerScheduleEntry.array[PowerScheduleEntryListType->PowerScheduleEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}TaxRule; type={urn:iso:std:iso:15118:-20:CommonMessages}TaxRuleType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: TaxRuleID, numericIDType (1, 1); TaxRuleName, nameType (0, 1); TaxRate, RationalNumberType (1, 1); TaxIncludedInPrice, boolean (0, 1); AppliesToEnergyFee, boolean (1, 1); AppliesToParkingFee, boolean (1, 1); AppliesToOverstayFee, boolean (1, 1); AppliesMinimumMaximumCost, boolean (1, 1);
static int decode_iso20_TaxRuleType(exi_bitstream_t* stream, struct iso20_TaxRuleType* TaxRuleType) {
    int grammar_id = 69;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_TaxRuleType(TaxRuleType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 69:
            // Grammar: ID=69; read/write bits=1; START (TaxRuleID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxRuleID, numericIDType (unsignedInt)); next=70
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &TaxRuleType->TaxRuleID);
                    if (error == 0)
                    {
                        grammar_id = 70;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 70:
            // Grammar: ID=70; read/write bits=2; START (TaxRuleName), START (TaxRate)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxRuleName, nameType (string)); next=71
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &TaxRuleType->TaxRuleName.charactersLen);
                            if (error == 0)
                            {
                                if (TaxRuleType->TaxRuleName.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    TaxRuleType->TaxRuleName.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, TaxRuleType->TaxRuleName.charactersLen, TaxRuleType->TaxRuleName.characters, iso20_TaxRuleName_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                TaxRuleType->TaxRuleName_isUsed = 1u;
                                grammar_id = 71;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (TaxRate, RationalNumberType (RationalNumberType)); next=72
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &TaxRuleType->TaxRate);
                    if (error == 0)
                    {
                        grammar_id = 72;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 71:
            // Grammar: ID=71; read/write bits=1; START (TaxRate)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxRate, RationalNumberType (RationalNumberType)); next=72
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &TaxRuleType->TaxRate);
                    if (error == 0)
                    {
                        grammar_id = 72;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 72:
            // Grammar: ID=72; read/write bits=2; START (TaxIncludedInPrice), START (AppliesToEnergyFee)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxIncludedInPrice, boolean (boolean)); next=73
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                TaxRuleType->TaxIncludedInPrice = value;
                                TaxRuleType->TaxIncludedInPrice_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 73;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (AppliesToEnergyFee, boolean (boolean)); next=74
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                TaxRuleType->AppliesToEnergyFee = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 74;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 73:
            // Grammar: ID=73; read/write bits=1; START (AppliesToEnergyFee)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AppliesToEnergyFee, boolean (boolean)); next=74
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                TaxRuleType->AppliesToEnergyFee = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 74;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 74:
            // Grammar: ID=74; read/write bits=1; START (AppliesToParkingFee)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AppliesToParkingFee, boolean (boolean)); next=75
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                TaxRuleType->AppliesToParkingFee = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 75;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 75:
            // Grammar: ID=75; read/write bits=1; START (AppliesToOverstayFee)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AppliesToOverstayFee, boolean (boolean)); next=76
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                TaxRuleType->AppliesToOverstayFee = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 76;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 76:
            // Grammar: ID=76; read/write bits=1; START (AppliesMinimumMaximumCost)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AppliesMinimumMaximumCost, boolean (boolean)); next=2
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                TaxRuleType->AppliesMinimumMaximumCost = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}PriceRuleStack; type={urn:iso:std:iso:15118:-20:CommonMessages}PriceRuleStackType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Duration, unsignedInt (1, 1); PriceRule, PriceRuleType (1, 8);
static int decode_iso20_PriceRuleStackType(exi_bitstream_t* stream, struct iso20_PriceRuleStackType* PriceRuleStackType) {
    int grammar_id = 77;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_PriceRuleStackType(PriceRuleStackType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 77:
            // Grammar: ID=77; read/write bits=1; START (Duration)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Duration, unsignedInt (unsignedLong)); next=78
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &PriceRuleStackType->Duration);
                    if (error == 0)
                    {
                        grammar_id = 78;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 78:
            // Grammar: ID=78; read/write bits=1; START (PriceRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PriceRule, PriceRuleType (PriceRuleType)); next=79
                    // decode: element array
                    if (PriceRuleStackType->PriceRule.arrayLen < iso20_PriceRuleType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_PriceRuleType(stream, &PriceRuleStackType->PriceRule.array[PriceRuleStackType->PriceRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 79;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 79:
            // Grammar: ID=79; read/write bits=2; END Element, START (PriceRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PriceRule, PriceRuleType (PriceRuleType)); next=80
                    // decode: element array
                    if (PriceRuleStackType->PriceRule.arrayLen < iso20_PriceRuleType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_PriceRuleType(stream, &PriceRuleStackType->PriceRule.array[PriceRuleStackType->PriceRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 80;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 80:
            // Grammar: ID=80; read/write bits=2; END Element, START (PriceRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PriceRule, PriceRuleType (PriceRuleType)); next=81
                    // decode: element array
                    if (PriceRuleStackType->PriceRule.arrayLen < iso20_PriceRuleType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_PriceRuleType(stream, &PriceRuleStackType->PriceRule.array[PriceRuleStackType->PriceRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 81;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 81:
            // Grammar: ID=81; read/write bits=2; END Element, START (PriceRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PriceRule, PriceRuleType (PriceRuleType)); next=82
                    // decode: element array
                    if (PriceRuleStackType->PriceRule.arrayLen < iso20_PriceRuleType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_PriceRuleType(stream, &PriceRuleStackType->PriceRule.array[PriceRuleStackType->PriceRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 82;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 82:
            // Grammar: ID=82; read/write bits=2; END Element, START (PriceRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PriceRule, PriceRuleType (PriceRuleType)); next=83
                    // decode: element array
                    if (PriceRuleStackType->PriceRule.arrayLen < iso20_PriceRuleType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_PriceRuleType(stream, &PriceRuleStackType->PriceRule.array[PriceRuleStackType->PriceRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 83;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 83:
            // Grammar: ID=83; read/write bits=2; END Element, START (PriceRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PriceRule, PriceRuleType (PriceRuleType)); next=84
                    // decode: element array
                    if (PriceRuleStackType->PriceRule.arrayLen < iso20_PriceRuleType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_PriceRuleType(stream, &PriceRuleStackType->PriceRule.array[PriceRuleStackType->PriceRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 84;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 84:
            // Grammar: ID=84; read/write bits=2; END Element, START (PriceRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PriceRule, PriceRuleType (PriceRuleType)); next=85
                    // decode: element array
                    if (PriceRuleStackType->PriceRule.arrayLen < iso20_PriceRuleType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_PriceRuleType(stream, &PriceRuleStackType->PriceRule.array[PriceRuleStackType->PriceRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 85;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 85:
            // Grammar: ID=85; read/write bits=2; END Element, START (PriceRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PriceRule, PriceRuleType (PriceRuleType)); next=2
                    // decode: element array
                    if (PriceRuleStackType->PriceRule.arrayLen < iso20_PriceRuleType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_PriceRuleType(stream, &PriceRuleStackType->PriceRule.array[PriceRuleStackType->PriceRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 2;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}AdditionalService; type={urn:iso:std:iso:15118:-20:CommonMessages}AdditionalServiceType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: ServiceName, nameType (1, 1); ServiceFee, RationalNumberType (1, 1);
static int decode_iso20_AdditionalServiceType(exi_bitstream_t* stream, struct iso20_AdditionalServiceType* AdditionalServiceType) {
    int grammar_id = 86;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_AdditionalServiceType(AdditionalServiceType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 86:
            // Grammar: ID=86; read/write bits=1; START (ServiceName)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceName, nameType (string)); next=87
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &AdditionalServiceType->ServiceName.charactersLen);
                            if (error == 0)
                            {
                                if (AdditionalServiceType->ServiceName.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    AdditionalServiceType->ServiceName.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, AdditionalServiceType->ServiceName.charactersLen, AdditionalServiceType->ServiceName.characters, iso20_ServiceName_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 87;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 87:
            // Grammar: ID=87; read/write bits=1; START (ServiceFee)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceFee, RationalNumberType (RationalNumberType)); next=2
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &AdditionalServiceType->ServiceFee);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}PowerSchedule; type={urn:iso:std:iso:15118:-20:CommonMessages}PowerScheduleType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: TimeAnchor, unsignedLong (1, 1); AvailableEnergy, RationalNumberType (0, 1); PowerTolerance, RationalNumberType (0, 1); PowerScheduleEntries, PowerScheduleEntryListType (1, 1);
static int decode_iso20_PowerScheduleType(exi_bitstream_t* stream, struct iso20_PowerScheduleType* PowerScheduleType) {
    int grammar_id = 88;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_PowerScheduleType(PowerScheduleType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 88:
            // Grammar: ID=88; read/write bits=1; START (TimeAnchor)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TimeAnchor, unsignedLong (nonNegativeInteger)); next=89
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &PowerScheduleType->TimeAnchor);
                    if (error == 0)
                    {
                        grammar_id = 89;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 89:
            // Grammar: ID=89; read/write bits=2; START (AvailableEnergy), START (PowerTolerance), START (PowerScheduleEntries)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AvailableEnergy, RationalNumberType (RationalNumberType)); next=90
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &PowerScheduleType->AvailableEnergy);
                    if (error == 0)
                    {
                        PowerScheduleType->AvailableEnergy_isUsed = 1u;
                        grammar_id = 90;
                    }
                    break;
                case 1:
                    // Event: START (PowerTolerance, RationalNumberType (RationalNumberType)); next=91
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &PowerScheduleType->PowerTolerance);
                    if (error == 0)
                    {
                        PowerScheduleType->PowerTolerance_isUsed = 1u;
                        grammar_id = 91;
                    }
                    break;
                case 2:
                    // Event: START (PowerScheduleEntries, PowerScheduleEntryListType (PowerScheduleEntryListType)); next=2
                    // decode: element
                    error = decode_iso20_PowerScheduleEntryListType(stream, &PowerScheduleType->PowerScheduleEntries);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 90:
            // Grammar: ID=90; read/write bits=2; START (PowerTolerance), START (PowerScheduleEntries)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PowerTolerance, RationalNumberType (RationalNumberType)); next=91
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &PowerScheduleType->PowerTolerance);
                    if (error == 0)
                    {
                        PowerScheduleType->PowerTolerance_isUsed = 1u;
                        grammar_id = 91;
                    }
                    break;
                case 1:
                    // Event: START (PowerScheduleEntries, PowerScheduleEntryListType (PowerScheduleEntryListType)); next=2
                    // decode: element
                    error = decode_iso20_PowerScheduleEntryListType(stream, &PowerScheduleType->PowerScheduleEntries);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 91:
            // Grammar: ID=91; read/write bits=1; START (PowerScheduleEntries)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PowerScheduleEntries, PowerScheduleEntryListType (PowerScheduleEntryListType)); next=2
                    // decode: element
                    error = decode_iso20_PowerScheduleEntryListType(stream, &PowerScheduleType->PowerScheduleEntries);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}EVPowerScheduleEntries; type={urn:iso:std:iso:15118:-20:CommonMessages}EVPowerScheduleEntryListType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EVPowerScheduleEntry, EVPowerScheduleEntryType (1, 1024);
static int decode_iso20_EVPowerScheduleEntryListType(exi_bitstream_t* stream, struct iso20_EVPowerScheduleEntryListType* EVPowerScheduleEntryListType) {
    int grammar_id = 92;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_EVPowerScheduleEntryListType(EVPowerScheduleEntryListType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 92:
            // Grammar: ID=92; read/write bits=1; START (EVPowerScheduleEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVPowerScheduleEntry, EVPowerScheduleEntryType (EVPowerScheduleEntryType)); next=93
                    // decode: element array
                    if (EVPowerScheduleEntryListType->EVPowerScheduleEntry.arrayLen < iso20_EVPowerScheduleEntryType_1024_ARRAY_SIZE)
                    {
                        error = decode_iso20_EVPowerScheduleEntryType(stream, &EVPowerScheduleEntryListType->EVPowerScheduleEntry.array[EVPowerScheduleEntryListType->EVPowerScheduleEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 93;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 93:
            // Grammar: ID=93; read/write bits=2; END Element, LOOP (EVPowerScheduleEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case -1 + 1:
                    // Event: LOOP (EVPowerScheduleEntry, EVPowerScheduleEntryType (EVPowerScheduleEntryType)); next=3
                    // decode: element array
                    if (EVPowerScheduleEntryListType->EVPowerScheduleEntry.arrayLen < iso20_EVPowerScheduleEntryType_1024_ARRAY_SIZE)
                    {
                        error = decode_iso20_EVPowerScheduleEntryType(stream, &EVPowerScheduleEntryListType->EVPowerScheduleEntry.array[EVPowerScheduleEntryListType->EVPowerScheduleEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;
                case 0 + 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}OverstayRule; type={urn:iso:std:iso:15118:-20:CommonMessages}OverstayRuleType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: OverstayRuleDescription, descriptionType (0, 1); StartTime, unsignedInt (1, 1); OverstayFee, RationalNumberType (1, 1); OverstayFeePeriod, unsignedInt (1, 1);
static int decode_iso20_OverstayRuleType(exi_bitstream_t* stream, struct iso20_OverstayRuleType* OverstayRuleType) {
    int grammar_id = 94;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_OverstayRuleType(OverstayRuleType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 94:
            // Grammar: ID=94; read/write bits=2; START (OverstayRuleDescription), START (StartTime)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OverstayRuleDescription, descriptionType (string)); next=95
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &OverstayRuleType->OverstayRuleDescription.charactersLen);
                            if (error == 0)
                            {
                                if (OverstayRuleType->OverstayRuleDescription.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    OverstayRuleType->OverstayRuleDescription.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, OverstayRuleType->OverstayRuleDescription.charactersLen, OverstayRuleType->OverstayRuleDescription.characters, iso20_OverstayRuleDescription_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                OverstayRuleType->OverstayRuleDescription_isUsed = 1u;
                                grammar_id = 95;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (StartTime, unsignedInt (unsignedLong)); next=96
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &OverstayRuleType->StartTime);
                    if (error == 0)
                    {
                        grammar_id = 96;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 95:
            // Grammar: ID=95; read/write bits=1; START (StartTime)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (StartTime, unsignedInt (unsignedLong)); next=96
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &OverstayRuleType->StartTime);
                    if (error == 0)
                    {
                        grammar_id = 96;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 96:
            // Grammar: ID=96; read/write bits=1; START (OverstayFee)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OverstayFee, RationalNumberType (RationalNumberType)); next=97
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &OverstayRuleType->OverstayFee);
                    if (error == 0)
                    {
                        grammar_id = 97;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 97:
            // Grammar: ID=97; read/write bits=1; START (OverstayFeePeriod)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OverstayFeePeriod, unsignedInt (unsignedLong)); next=2
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &OverstayRuleType->OverstayFeePeriod);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}EVPriceRuleStacks; type={urn:iso:std:iso:15118:-20:CommonMessages}EVPriceRuleStackListType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EVPriceRuleStack, EVPriceRuleStackType (1, 1024);
static int decode_iso20_EVPriceRuleStackListType(exi_bitstream_t* stream, struct iso20_EVPriceRuleStackListType* EVPriceRuleStackListType) {
    int grammar_id = 98;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_EVPriceRuleStackListType(EVPriceRuleStackListType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 98:
            // Grammar: ID=98; read/write bits=1; START (EVPriceRuleStack)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVPriceRuleStack, EVPriceRuleStackType (EVPriceRuleStackType)); next=99
                    // decode: element array
                    if (EVPriceRuleStackListType->EVPriceRuleStack.arrayLen < iso20_EVPriceRuleStackType_1024_ARRAY_SIZE)
                    {
                        error = decode_iso20_EVPriceRuleStackType(stream, &EVPriceRuleStackListType->EVPriceRuleStack.array[EVPriceRuleStackListType->EVPriceRuleStack.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 99;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 99:
            // Grammar: ID=99; read/write bits=2; END Element, LOOP (EVPriceRuleStack)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: LOOP (EVPriceRuleStack, EVPriceRuleStackType (EVPriceRuleStackType)); next=3
                    // decode: element array
                    if (EVPriceRuleStackListType->EVPriceRuleStack.arrayLen < iso20_EVPriceRuleStackType_1024_ARRAY_SIZE)
                    {
                        error = decode_iso20_EVPriceRuleStackType(stream, &EVPriceRuleStackListType->EVPriceRuleStack.array[EVPriceRuleStackListType->EVPriceRuleStack.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 3:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_SPKIDataType(exi_bitstream_t* stream, struct iso20_SPKIDataType* SPKIDataType) {
    int grammar_id = 100;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_SPKIDataType(SPKIDataType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 100:
            // Grammar: ID=100; read/write bits=1; START (SPKISexp)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SPKISexp, base64Binary (base64Binary)); next=101
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SPKIDataType->SPKISexp.bytesLen, &SPKIDataType->SPKISexp.bytes[0], iso20_base64Binary_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 101;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 101:
            // Grammar: ID=101; read/write bits=2; END Element, START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SPKIDataType->ANY.bytesLen, &SPKIDataType->ANY.bytes[0], iso20_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        SPKIDataType->ANY_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_SignedInfoType(exi_bitstream_t* stream, struct iso20_SignedInfoType* SignedInfoType) {
    int grammar_id = 102;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_SignedInfoType(SignedInfoType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 102:
            // Grammar: ID=102; read/write bits=2; START (Id), START (CanonicalizationMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=103
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &SignedInfoType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (SignedInfoType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            SignedInfoType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, SignedInfoType->Id.charactersLen, SignedInfoType->Id.characters, iso20_Id_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    SignedInfoType->Id_isUsed = 1u;
                    grammar_id = 103;
                    break;
                case 1:
                    // Event: START (CanonicalizationMethod, CanonicalizationMethodType (CanonicalizationMethodType)); next=104
                    // decode: element
                    error = decode_iso20_CanonicalizationMethodType(stream, &SignedInfoType->CanonicalizationMethod);
                    if (error == 0)
                    {
                        grammar_id = 104;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 103:
            // Grammar: ID=103; read/write bits=1; START (CanonicalizationMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (CanonicalizationMethod, CanonicalizationMethodType (CanonicalizationMethodType)); next=104
                    // decode: element
                    error = decode_iso20_CanonicalizationMethodType(stream, &SignedInfoType->CanonicalizationMethod);
                    if (error == 0)
                    {
                        grammar_id = 104;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 104:
            // Grammar: ID=104; read/write bits=1; START (SignatureMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SignatureMethod, SignatureMethodType (SignatureMethodType)); next=105
                    // decode: element
                    error = decode_iso20_SignatureMethodType(stream, &SignedInfoType->SignatureMethod);
                    if (error == 0)
                    {
                        grammar_id = 105;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 105:
            // Grammar: ID=105; read/write bits=1; START (Reference)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Reference, ReferenceType (ReferenceType)); next=106
                    // decode: element
                    error = decode_iso20_ReferenceType(stream, &SignedInfoType->Reference);
                    if (error == 0)
                    {
                        grammar_id = 106;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 106:
            // Grammar: ID=106; read/write bits=2; END Element, START (Reference)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Reference, ReferenceType (ReferenceType)); next=2
                    // decode: element
                    error = decode_iso20_ReferenceType(stream, &SignedInfoType->Reference);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}EVPowerSchedule; type={urn:iso:std:iso:15118:-20:CommonMessages}EVPowerScheduleType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: TimeAnchor, unsignedLong (1, 1); EVPowerScheduleEntries, EVPowerScheduleEntryListType (1, 1);
static int decode_iso20_EVPowerScheduleType(exi_bitstream_t* stream, struct iso20_EVPowerScheduleType* EVPowerScheduleType) {
    int grammar_id = 107;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_EVPowerScheduleType(EVPowerScheduleType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 107:
            // Grammar: ID=107; read/write bits=1; START (TimeAnchor)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TimeAnchor, unsignedLong (nonNegativeInteger)); next=108
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &EVPowerScheduleType->TimeAnchor);
                    if (error == 0)
                    {
                        grammar_id = 108;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 108:
            // Grammar: ID=108; read/write bits=1; START (EVPowerScheduleEntries)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVPowerScheduleEntries, EVPowerScheduleEntryListType (EVPowerScheduleEntryListType)); next=2
                    // decode: element
                    error = decode_iso20_EVPowerScheduleEntryListType(stream, &EVPowerScheduleType->EVPowerScheduleEntries);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_SignatureValueType(exi_bitstream_t* stream, struct iso20_SignatureValueType* SignatureValueType) {
    int grammar_id = 109;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_SignatureValueType(SignatureValueType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 109:
            // Grammar: ID=109; read/write bits=2; START (Id), START (CONTENT)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=110
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &SignatureValueType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (SignatureValueType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            SignatureValueType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, SignatureValueType->Id.charactersLen, SignatureValueType->Id.characters, iso20_Id_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    SignatureValueType->Id_isUsed = 1u;
                    grammar_id = 110;
                    break;
                case 1:
                    // Event: START (CONTENT, SignatureValueType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SignatureValueType->CONTENT.bytesLen, &SignatureValueType->CONTENT.bytes[0], iso20_SignatureValueType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 110:
            // Grammar: ID=110; read/write bits=1; START (CONTENT)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (CONTENT, SignatureValueType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SignatureValueType->CONTENT.bytesLen, &SignatureValueType->CONTENT.bytes[0], iso20_SignatureValueType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}SubCertificates; type={urn:iso:std:iso:15118:-20:CommonMessages}SubCertificatesType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Certificate, certificateType (1, 3);
static int decode_iso20_SubCertificatesType(exi_bitstream_t* stream, struct iso20_SubCertificatesType* SubCertificatesType) {
    int grammar_id = 111;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_SubCertificatesType(SubCertificatesType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 111:
            // Grammar: ID=111; read/write bits=1; START (Certificate)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Certificate, certificateType (base64Binary)); next=112
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SubCertificatesType->Certificate.bytesLen, &SubCertificatesType->Certificate.bytes[0], iso20_certificateType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 112;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 112:
            // Grammar: ID=112; read/write bits=2; END Element, START (Certificate)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Certificate, certificateType (base64Binary)); next=113
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SubCertificatesType->Certificate.bytesLen, &SubCertificatesType->Certificate.bytes[0], iso20_certificateType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 113;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 113:
            // Grammar: ID=113; read/write bits=2; END Element, START (Certificate)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Certificate, certificateType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SubCertificatesType->Certificate.bytesLen, &SubCertificatesType->Certificate.bytes[0], iso20_certificateType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}Parameter; type={urn:iso:std:iso:15118:-20:CommonMessages}ParameterType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False; choice=True;
// Particle: Name, nameType (1, 1); boolValue, boolean (0, 1); byteValue, byte (0, 1); shortValue, short (0, 1); intValue, int (0, 1); rationalNumber, RationalNumberType (0, 1); finiteString, nameType (0, 1);
static int decode_iso20_ParameterType(exi_bitstream_t* stream, struct iso20_ParameterType* ParameterType) {
    int grammar_id = 114;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ParameterType(ParameterType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 114:
            // Grammar: ID=114; read/write bits=1; START (Name)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Name, nameType (string)); next=115
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ParameterType->Name.charactersLen);
                    if (error == 0)
                    {
                        if (ParameterType->Name.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ParameterType->Name.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ParameterType->Name.charactersLen, ParameterType->Name.characters, iso20_Name_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    grammar_id = 115;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 115:
            // Grammar: ID=115; read/write bits=3; START (boolValue), START (byteValue), START (shortValue), START (intValue), START (rationalNumber), START (finiteString)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (boolValue, boolean (boolean)); next=2
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ParameterType->boolValue = value;
                                ParameterType->boolValue_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (byteValue, byte (short)); next=2
                    // decode: byte (restricted integer)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 8, &value);
                            if (error == 0)
                            {
                                // type has min_value = -128
                                ParameterType->byteValue = (int8_t)(value + -128);
                                ParameterType->byteValue_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: START (shortValue, short (int)); next=2
                    // decode: short
                    error = decode_exi_type_integer16(stream, &ParameterType->shortValue);
                    if (error == 0)
                    {
                        ParameterType->shortValue_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 3:
                    // Event: START (intValue, int (long)); next=2
                    // decode: int
                    error = decode_exi_type_integer32(stream, &ParameterType->intValue);
                    if (error == 0)
                    {
                        ParameterType->intValue_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 4:
                    // Event: START (rationalNumber, RationalNumberType (RationalNumberType)); next=2
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &ParameterType->rationalNumber);
                    if (error == 0)
                    {
                        ParameterType->rationalNumber_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 5:
                    // Event: START (finiteString, nameType (string)); next=2
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &ParameterType->finiteString.charactersLen);
                            if (error == 0)
                            {
                                if (ParameterType->finiteString.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    ParameterType->finiteString.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, ParameterType->finiteString.charactersLen, ParameterType->finiteString.characters, iso20_finiteString_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                ParameterType->finiteString_isUsed = 1u;
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}EVAbsolutePriceSchedule; type={urn:iso:std:iso:15118:-20:CommonMessages}EVAbsolutePriceScheduleType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: TimeAnchor, unsignedLong (1, 1); Currency, currencyType (1, 1); PriceAlgorithm, identifierType (1, 1); EVPriceRuleStacks, EVPriceRuleStackListType (1, 1);
static int decode_iso20_EVAbsolutePriceScheduleType(exi_bitstream_t* stream, struct iso20_EVAbsolutePriceScheduleType* EVAbsolutePriceScheduleType) {
    int grammar_id = 116;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_EVAbsolutePriceScheduleType(EVAbsolutePriceScheduleType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 116:
            // Grammar: ID=116; read/write bits=1; START (TimeAnchor)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TimeAnchor, unsignedLong (nonNegativeInteger)); next=117
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &EVAbsolutePriceScheduleType->TimeAnchor);
                    if (error == 0)
                    {
                        grammar_id = 117;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 117:
            // Grammar: ID=117; read/write bits=1; START (Currency)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Currency, currencyType (string)); next=118
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &EVAbsolutePriceScheduleType->Currency.charactersLen);
                            if (error == 0)
                            {
                                if (EVAbsolutePriceScheduleType->Currency.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    EVAbsolutePriceScheduleType->Currency.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, EVAbsolutePriceScheduleType->Currency.charactersLen, EVAbsolutePriceScheduleType->Currency.characters, iso20_Currency_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 118;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 118:
            // Grammar: ID=118; read/write bits=1; START (PriceAlgorithm)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PriceAlgorithm, identifierType (string)); next=119
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &EVAbsolutePriceScheduleType->PriceAlgorithm.charactersLen);
                            if (error == 0)
                            {
                                if (EVAbsolutePriceScheduleType->PriceAlgorithm.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    EVAbsolutePriceScheduleType->PriceAlgorithm.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, EVAbsolutePriceScheduleType->PriceAlgorithm.charactersLen, EVAbsolutePriceScheduleType->PriceAlgorithm.characters, iso20_PriceAlgorithm_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 119;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 119:
            // Grammar: ID=119; read/write bits=1; START (EVPriceRuleStacks)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVPriceRuleStacks, EVPriceRuleStackListType (EVPriceRuleStackListType)); next=2
                    // decode: element
                    error = decode_iso20_EVPriceRuleStackListType(stream, &EVAbsolutePriceScheduleType->EVPriceRuleStacks);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_DetailedCostType(exi_bitstream_t* stream, struct iso20_DetailedCostType* DetailedCostType) {
    int grammar_id = 120;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_DetailedCostType(DetailedCostType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 120:
            // Grammar: ID=120; read/write bits=1; START (Amount)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Amount, RationalNumberType (RationalNumberType)); next=121
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &DetailedCostType->Amount);
                    if (error == 0)
                    {
                        grammar_id = 121;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 121:
            // Grammar: ID=121; read/write bits=1; START (CostPerUnit)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (CostPerUnit, RationalNumberType (RationalNumberType)); next=2
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &DetailedCostType->CostPerUnit);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_KeyInfoType(exi_bitstream_t* stream, struct iso20_KeyInfoType* KeyInfoType) {
    int grammar_id = 122;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_KeyInfoType(KeyInfoType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 122:
            // Grammar: ID=122; read/write bits=4; START (Id), START (KeyName), START (KeyValue), START (RetrievalMethod), START (X509Data), START (PGPData), START (SPKIData), START (MgmtData), START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 4, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=123
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &KeyInfoType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (KeyInfoType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            KeyInfoType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, KeyInfoType->Id.charactersLen, KeyInfoType->Id.characters, iso20_Id_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    KeyInfoType->Id_isUsed = 1u;
                    grammar_id = 123;
                    break;
                case 1:
                    // Event: START (KeyName, string (string)); next=2
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &KeyInfoType->KeyName.charactersLen);
                            if (error == 0)
                            {
                                if (KeyInfoType->KeyName.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    KeyInfoType->KeyName.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, KeyInfoType->KeyName.charactersLen, KeyInfoType->KeyName.characters, iso20_KeyName_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                KeyInfoType->KeyName_isUsed = 1u;
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: START (KeyValue, KeyValueType (KeyValueType)); next=2
                    // decode: element
                    error = decode_iso20_KeyValueType(stream, &KeyInfoType->KeyValue);
                    if (error == 0)
                    {
                        KeyInfoType->KeyValue_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 3:
                    // Event: START (RetrievalMethod, RetrievalMethodType (RetrievalMethodType)); next=2
                    // decode: element
                    error = decode_iso20_RetrievalMethodType(stream, &KeyInfoType->RetrievalMethod);
                    if (error == 0)
                    {
                        KeyInfoType->RetrievalMethod_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 4:
                    // Event: START (X509Data, X509DataType (X509DataType)); next=2
                    // decode: element
                    error = decode_iso20_X509DataType(stream, &KeyInfoType->X509Data);
                    if (error == 0)
                    {
                        KeyInfoType->X509Data_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 5:
                    // Event: START (PGPData, PGPDataType (PGPDataType)); next=2
                    // decode: element
                    error = decode_iso20_PGPDataType(stream, &KeyInfoType->PGPData);
                    if (error == 0)
                    {
                        KeyInfoType->PGPData_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 6:
                    // Event: START (SPKIData, SPKIDataType (SPKIDataType)); next=2
                    // decode: element
                    error = decode_iso20_SPKIDataType(stream, &KeyInfoType->SPKIData);
                    if (error == 0)
                    {
                        KeyInfoType->SPKIData_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 7:
                    // Event: START (MgmtData, string (string)); next=2
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &KeyInfoType->MgmtData.charactersLen);
                            if (error == 0)
                            {
                                if (KeyInfoType->MgmtData.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    KeyInfoType->MgmtData.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, KeyInfoType->MgmtData.charactersLen, KeyInfoType->MgmtData.characters, iso20_MgmtData_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                KeyInfoType->MgmtData_isUsed = 1u;
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 8:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &KeyInfoType->ANY.bytesLen, &KeyInfoType->ANY.bytes[0], iso20_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        KeyInfoType->ANY_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 123:
            // Grammar: ID=123; read/write bits=4; START (KeyName), START (KeyValue), START (RetrievalMethod), START (X509Data), START (PGPData), START (SPKIData), START (MgmtData), START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 4, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (KeyName, string (string)); next=2
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &KeyInfoType->KeyName.charactersLen);
                            if (error == 0)
                            {
                                if (KeyInfoType->KeyName.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    KeyInfoType->KeyName.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, KeyInfoType->KeyName.charactersLen, KeyInfoType->KeyName.characters, iso20_KeyName_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                KeyInfoType->KeyName_isUsed = 1u;
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (KeyValue, KeyValueType (KeyValueType)); next=2
                    // decode: element
                    error = decode_iso20_KeyValueType(stream, &KeyInfoType->KeyValue);
                    if (error == 0)
                    {
                        KeyInfoType->KeyValue_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 2:
                    // Event: START (RetrievalMethod, RetrievalMethodType (RetrievalMethodType)); next=2
                    // decode: element
                    error = decode_iso20_RetrievalMethodType(stream, &KeyInfoType->RetrievalMethod);
                    if (error == 0)
                    {
                        KeyInfoType->RetrievalMethod_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 3:
                    // Event: START (X509Data, X509DataType (X509DataType)); next=2
                    // decode: element
                    error = decode_iso20_X509DataType(stream, &KeyInfoType->X509Data);
                    if (error == 0)
                    {
                        KeyInfoType->X509Data_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 4:
                    // Event: START (PGPData, PGPDataType (PGPDataType)); next=2
                    // decode: element
                    error = decode_iso20_PGPDataType(stream, &KeyInfoType->PGPData);
                    if (error == 0)
                    {
                        KeyInfoType->PGPData_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 5:
                    // Event: START (SPKIData, SPKIDataType (SPKIDataType)); next=2
                    // decode: element
                    error = decode_iso20_SPKIDataType(stream, &KeyInfoType->SPKIData);
                    if (error == 0)
                    {
                        KeyInfoType->SPKIData_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 6:
                    // Event: START (MgmtData, string (string)); next=2
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &KeyInfoType->MgmtData.charactersLen);
                            if (error == 0)
                            {
                                if (KeyInfoType->MgmtData.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    KeyInfoType->MgmtData.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, KeyInfoType->MgmtData.charactersLen, KeyInfoType->MgmtData.characters, iso20_MgmtData_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                KeyInfoType->MgmtData_isUsed = 1u;
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 7:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &KeyInfoType->ANY.bytesLen, &KeyInfoType->ANY.bytes[0], iso20_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        KeyInfoType->ANY_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_ObjectType(exi_bitstream_t* stream, struct iso20_ObjectType* ObjectType) {
    int grammar_id = 124;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ObjectType(ObjectType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 124:
            // Grammar: ID=124; read/write bits=3; START (Encoding), START (Id), START (MimeType), START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Encoding, anyURI (anyURI)); next=125
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ObjectType->Encoding.charactersLen);
                    if (error == 0)
                    {
                        if (ObjectType->Encoding.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ObjectType->Encoding.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ObjectType->Encoding.charactersLen, ObjectType->Encoding.characters, iso20_Encoding_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ObjectType->Encoding_isUsed = 1u;
                    grammar_id = 125;
                    break;
                case 1:
                    // Event: START (Id, ID (NCName)); next=126
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ObjectType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (ObjectType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ObjectType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ObjectType->Id.charactersLen, ObjectType->Id.characters, iso20_Id_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ObjectType->Id_isUsed = 1u;
                    grammar_id = 126;
                    break;
                case 2:
                    // Event: START (MimeType, string (string)); next=127
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ObjectType->MimeType.charactersLen);
                    if (error == 0)
                    {
                        if (ObjectType->MimeType.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ObjectType->MimeType.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ObjectType->MimeType.charactersLen, ObjectType->MimeType.characters, iso20_MimeType_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ObjectType->MimeType_isUsed = 1u;
                    grammar_id = 127;
                    break;
                case 3:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &ObjectType->ANY.bytesLen, &ObjectType->ANY.bytes[0], iso20_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 125:
            // Grammar: ID=125; read/write bits=2; START (Id), START (MimeType), START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=126
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ObjectType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (ObjectType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ObjectType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ObjectType->Id.charactersLen, ObjectType->Id.characters, iso20_Id_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ObjectType->Id_isUsed = 1u;
                    grammar_id = 126;
                    break;
                case 1:
                    // Event: START (MimeType, string (string)); next=127
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ObjectType->MimeType.charactersLen);
                    if (error == 0)
                    {
                        if (ObjectType->MimeType.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ObjectType->MimeType.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ObjectType->MimeType.charactersLen, ObjectType->MimeType.characters, iso20_MimeType_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ObjectType->MimeType_isUsed = 1u;
                    grammar_id = 127;
                    break;
                case 2:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &ObjectType->ANY.bytesLen, &ObjectType->ANY.bytes[0], iso20_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 126:
            // Grammar: ID=126; read/write bits=2; START (MimeType), START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (MimeType, string (string)); next=127
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ObjectType->MimeType.charactersLen);
                    if (error == 0)
                    {
                        if (ObjectType->MimeType.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ObjectType->MimeType.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ObjectType->MimeType.charactersLen, ObjectType->MimeType.characters, iso20_MimeType_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ObjectType->MimeType_isUsed = 1u;
                    grammar_id = 127;
                    break;
                case 1:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &ObjectType->ANY.bytesLen, &ObjectType->ANY.bytes[0], iso20_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 127:
            // Grammar: ID=127; read/write bits=1; START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &ObjectType->ANY.bytesLen, &ObjectType->ANY.bytes[0], iso20_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}PriceLevelScheduleEntries; type={urn:iso:std:iso:15118:-20:CommonMessages}PriceLevelScheduleEntryListType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: PriceLevelScheduleEntry, PriceLevelScheduleEntryType (1, 1024);
static int decode_iso20_PriceLevelScheduleEntryListType(exi_bitstream_t* stream, struct iso20_PriceLevelScheduleEntryListType* PriceLevelScheduleEntryListType) {
    int grammar_id = 128;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_PriceLevelScheduleEntryListType(PriceLevelScheduleEntryListType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 128:
            // Grammar: ID=128; read/write bits=1; START (PriceLevelScheduleEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PriceLevelScheduleEntry, PriceLevelScheduleEntryType (PriceLevelScheduleEntryType)); next=129
                    // decode: element array
                    if (PriceLevelScheduleEntryListType->PriceLevelScheduleEntry.arrayLen < iso20_PriceLevelScheduleEntryType_1024_ARRAY_SIZE)
                    {
                        error = decode_iso20_PriceLevelScheduleEntryType(stream, &PriceLevelScheduleEntryListType->PriceLevelScheduleEntry.array[PriceLevelScheduleEntryListType->PriceLevelScheduleEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 129;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 129:
            // Grammar: ID=129; read/write bits=2; END Element, LOOP (PriceLevelScheduleEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case -1:
                    // Event: LOOP (PriceLevelScheduleEntry, PriceLevelScheduleEntryType (PriceLevelScheduleEntryType)); next=3
                    // decode: element array
                    if (PriceLevelScheduleEntryListType->PriceLevelScheduleEntry.arrayLen < iso20_PriceLevelScheduleEntryType_1024_ARRAY_SIZE)
                    {
                        error = decode_iso20_PriceLevelScheduleEntryType(stream, &PriceLevelScheduleEntryListType->PriceLevelScheduleEntry.array[PriceLevelScheduleEntryListType->PriceLevelScheduleEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_DetailedTaxType(exi_bitstream_t* stream, struct iso20_DetailedTaxType* DetailedTaxType) {
    int grammar_id = 130;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_DetailedTaxType(DetailedTaxType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 130:
            // Grammar: ID=130; read/write bits=1; START (TaxRuleID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxRuleID, numericIDType (unsignedInt)); next=131
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &DetailedTaxType->TaxRuleID);
                    if (error == 0)
                    {
                        grammar_id = 131;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 131:
            // Grammar: ID=131; read/write bits=1; START (Amount)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Amount, RationalNumberType (RationalNumberType)); next=2
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &DetailedTaxType->Amount);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}TaxRules; type={urn:iso:std:iso:15118:-20:CommonMessages}TaxRuleListType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: TaxRule, TaxRuleType (1, 10);
static int decode_iso20_TaxRuleListType(exi_bitstream_t* stream, struct iso20_TaxRuleListType* TaxRuleListType) {
    int grammar_id = 132;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_TaxRuleListType(TaxRuleListType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 132:
            // Grammar: ID=132; read/write bits=1; START (TaxRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxRule, TaxRuleType (TaxRuleType)); next=133
                    // decode: element array
                    if (TaxRuleListType->TaxRule.arrayLen < iso20_TaxRuleType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_TaxRuleType(stream, &TaxRuleListType->TaxRule.array[TaxRuleListType->TaxRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 133;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 133:
            // Grammar: ID=133; read/write bits=2; END Element, START (TaxRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxRule, TaxRuleType (TaxRuleType)); next=134
                    // decode: element array
                    if (TaxRuleListType->TaxRule.arrayLen < iso20_TaxRuleType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_TaxRuleType(stream, &TaxRuleListType->TaxRule.array[TaxRuleListType->TaxRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 134;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 134:
            // Grammar: ID=134; read/write bits=2; END Element, START (TaxRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxRule, TaxRuleType (TaxRuleType)); next=135
                    // decode: element array
                    if (TaxRuleListType->TaxRule.arrayLen < iso20_TaxRuleType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_TaxRuleType(stream, &TaxRuleListType->TaxRule.array[TaxRuleListType->TaxRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 135;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 135:
            // Grammar: ID=135; read/write bits=2; END Element, START (TaxRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxRule, TaxRuleType (TaxRuleType)); next=136
                    // decode: element array
                    if (TaxRuleListType->TaxRule.arrayLen < iso20_TaxRuleType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_TaxRuleType(stream, &TaxRuleListType->TaxRule.array[TaxRuleListType->TaxRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 136;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 136:
            // Grammar: ID=136; read/write bits=2; END Element, START (TaxRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxRule, TaxRuleType (TaxRuleType)); next=137
                    // decode: element array
                    if (TaxRuleListType->TaxRule.arrayLen < iso20_TaxRuleType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_TaxRuleType(stream, &TaxRuleListType->TaxRule.array[TaxRuleListType->TaxRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 137;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 137:
            // Grammar: ID=137; read/write bits=2; END Element, START (TaxRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxRule, TaxRuleType (TaxRuleType)); next=138
                    // decode: element array
                    if (TaxRuleListType->TaxRule.arrayLen < iso20_TaxRuleType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_TaxRuleType(stream, &TaxRuleListType->TaxRule.array[TaxRuleListType->TaxRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 138;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 138:
            // Grammar: ID=138; read/write bits=2; END Element, START (TaxRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxRule, TaxRuleType (TaxRuleType)); next=139
                    // decode: element array
                    if (TaxRuleListType->TaxRule.arrayLen < iso20_TaxRuleType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_TaxRuleType(stream, &TaxRuleListType->TaxRule.array[TaxRuleListType->TaxRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 139;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 139:
            // Grammar: ID=139; read/write bits=2; END Element, START (TaxRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxRule, TaxRuleType (TaxRuleType)); next=140
                    // decode: element array
                    if (TaxRuleListType->TaxRule.arrayLen < iso20_TaxRuleType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_TaxRuleType(stream, &TaxRuleListType->TaxRule.array[TaxRuleListType->TaxRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 140;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 140:
            // Grammar: ID=140; read/write bits=2; END Element, START (TaxRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxRule, TaxRuleType (TaxRuleType)); next=141
                    // decode: element array
                    if (TaxRuleListType->TaxRule.arrayLen < iso20_TaxRuleType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_TaxRuleType(stream, &TaxRuleListType->TaxRule.array[TaxRuleListType->TaxRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 141;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 141:
            // Grammar: ID=141; read/write bits=2; END Element, START (TaxRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxRule, TaxRuleType (TaxRuleType)); next=2
                    // decode: element array
                    if (TaxRuleListType->TaxRule.arrayLen < iso20_TaxRuleType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_TaxRuleType(stream, &TaxRuleListType->TaxRule.array[TaxRuleListType->TaxRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 2;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}PriceRuleStacks; type={urn:iso:std:iso:15118:-20:CommonMessages}PriceRuleStackListType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: PriceRuleStack, PriceRuleStackType (1, 64);
static int decode_iso20_PriceRuleStackListType(exi_bitstream_t* stream, struct iso20_PriceRuleStackListType* PriceRuleStackListType) {
    int grammar_id = 142;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_PriceRuleStackListType(PriceRuleStackListType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 142:
            // Grammar: ID=142; read/write bits=1; START (PriceRuleStack)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PriceRuleStack, PriceRuleStackType (PriceRuleStackType)); next=143
                    // decode: element array
                    if (PriceRuleStackListType->PriceRuleStack.arrayLen < iso20_PriceRuleStackType_64_ARRAY_SIZE)
                    {
                        error = decode_iso20_PriceRuleStackType(stream, &PriceRuleStackListType->PriceRuleStack.array[PriceRuleStackListType->PriceRuleStack.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 143;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 143:
            // Grammar: ID=143; read/write bits=2; END Element, LOOP (PriceRuleStack)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case -1:
                    // Event: LOOP (PriceRuleStack, PriceRuleStackType (PriceRuleStackType)); next=3
                    // decode: element array
                    if (PriceRuleStackListType->PriceRuleStack.arrayLen < iso20_PriceRuleStackType_64_ARRAY_SIZE)
                    {
                        error = decode_iso20_PriceRuleStackType(stream, &PriceRuleStackListType->PriceRuleStack.array[PriceRuleStackListType->PriceRuleStack.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}OverstayRules; type={urn:iso:std:iso:15118:-20:CommonMessages}OverstayRuleListType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: OverstayTimeThreshold, unsignedInt (0, 1); OverstayPowerThreshold, RationalNumberType (0, 1); OverstayRule, OverstayRuleType (1, 5);
static int decode_iso20_OverstayRuleListType(exi_bitstream_t* stream, struct iso20_OverstayRuleListType* OverstayRuleListType) {
    int grammar_id = 144;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_OverstayRuleListType(OverstayRuleListType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 144:
            // Grammar: ID=144; read/write bits=2; START (OverstayTimeThreshold), START (OverstayPowerThreshold), START (OverstayRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OverstayTimeThreshold, unsignedInt (unsignedLong)); next=149
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &OverstayRuleListType->OverstayTimeThreshold);
                    if (error == 0)
                    {
                        OverstayRuleListType->OverstayTimeThreshold_isUsed = 1u;
                        grammar_id = 149;
                    }
                    break;
                case 1:
                    // Event: START (OverstayPowerThreshold, RationalNumberType (RationalNumberType)); next=154
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &OverstayRuleListType->OverstayPowerThreshold);
                    if (error == 0)
                    {
                        OverstayRuleListType->OverstayPowerThreshold_isUsed = 1u;
                        grammar_id = 154;
                    }
                    break;
                case 2:
                    // Event: START (OverstayRule, OverstayRuleType (OverstayRuleType)); next=2
                    // decode: element array
                    if (OverstayRuleListType->OverstayRule.arrayLen < iso20_OverstayRuleType_5_ARRAY_SIZE)
                    {
                        error = decode_iso20_OverstayRuleType(stream, &OverstayRuleListType->OverstayRule.array[OverstayRuleListType->OverstayRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 2;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 145:
            // Grammar: ID=145; read/write bits=2; END Element, START (OverstayRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OverstayRule, OverstayRuleType (OverstayRuleType)); next=146
                    // decode: element array
                    if (OverstayRuleListType->OverstayRule.arrayLen < iso20_OverstayRuleType_5_ARRAY_SIZE)
                    {
                        error = decode_iso20_OverstayRuleType(stream, &OverstayRuleListType->OverstayRule.array[OverstayRuleListType->OverstayRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 146;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 146:
            // Grammar: ID=146; read/write bits=2; END Element, START (OverstayRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OverstayRule, OverstayRuleType (OverstayRuleType)); next=147
                    // decode: element array
                    if (OverstayRuleListType->OverstayRule.arrayLen < iso20_OverstayRuleType_5_ARRAY_SIZE)
                    {
                        error = decode_iso20_OverstayRuleType(stream, &OverstayRuleListType->OverstayRule.array[OverstayRuleListType->OverstayRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 147;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 147:
            // Grammar: ID=147; read/write bits=2; END Element, START (OverstayRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OverstayRule, OverstayRuleType (OverstayRuleType)); next=148
                    // decode: element array
                    if (OverstayRuleListType->OverstayRule.arrayLen < iso20_OverstayRuleType_5_ARRAY_SIZE)
                    {
                        error = decode_iso20_OverstayRuleType(stream, &OverstayRuleListType->OverstayRule.array[OverstayRuleListType->OverstayRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 148;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 148:
            // Grammar: ID=148; read/write bits=2; END Element, START (OverstayRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OverstayRule, OverstayRuleType (OverstayRuleType)); next=149
                    // decode: element array
                    if (OverstayRuleListType->OverstayRule.arrayLen < iso20_OverstayRuleType_5_ARRAY_SIZE)
                    {
                        error = decode_iso20_OverstayRuleType(stream, &OverstayRuleListType->OverstayRule.array[OverstayRuleListType->OverstayRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 149;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 149:
            // Grammar: ID=149; read/write bits=2; START (OverstayPowerThreshold), START (OverstayRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OverstayPowerThreshold, RationalNumberType (RationalNumberType)); next=154
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &OverstayRuleListType->OverstayPowerThreshold);
                    if (error == 0)
                    {
                        OverstayRuleListType->OverstayPowerThreshold_isUsed = 1u;
                        grammar_id = 154;
                    }
                    break;
                case 1:
                    // Event: START (OverstayRule, OverstayRuleType (OverstayRuleType)); next=2
                    // decode: element array
                    if (OverstayRuleListType->OverstayRule.arrayLen < iso20_OverstayRuleType_5_ARRAY_SIZE)
                    {
                        error = decode_iso20_OverstayRuleType(stream, &OverstayRuleListType->OverstayRule.array[OverstayRuleListType->OverstayRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 2;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 150:
            // Grammar: ID=150; read/write bits=2; END Element, START (OverstayRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OverstayRule, OverstayRuleType (OverstayRuleType)); next=151
                    // decode: element array
                    if (OverstayRuleListType->OverstayRule.arrayLen < iso20_OverstayRuleType_5_ARRAY_SIZE)
                    {
                        error = decode_iso20_OverstayRuleType(stream, &OverstayRuleListType->OverstayRule.array[OverstayRuleListType->OverstayRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 151;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 151:
            // Grammar: ID=151; read/write bits=2; END Element, START (OverstayRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OverstayRule, OverstayRuleType (OverstayRuleType)); next=152
                    // decode: element array
                    if (OverstayRuleListType->OverstayRule.arrayLen < iso20_OverstayRuleType_5_ARRAY_SIZE)
                    {
                        error = decode_iso20_OverstayRuleType(stream, &OverstayRuleListType->OverstayRule.array[OverstayRuleListType->OverstayRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 152;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 152:
            // Grammar: ID=152; read/write bits=2; END Element, START (OverstayRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OverstayRule, OverstayRuleType (OverstayRuleType)); next=153
                    // decode: element array
                    if (OverstayRuleListType->OverstayRule.arrayLen < iso20_OverstayRuleType_5_ARRAY_SIZE)
                    {
                        error = decode_iso20_OverstayRuleType(stream, &OverstayRuleListType->OverstayRule.array[OverstayRuleListType->OverstayRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 153;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 153:
            // Grammar: ID=153; read/write bits=2; END Element, START (OverstayRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OverstayRule, OverstayRuleType (OverstayRuleType)); next=154
                    // decode: element array
                    if (OverstayRuleListType->OverstayRule.arrayLen < iso20_OverstayRuleType_5_ARRAY_SIZE)
                    {
                        error = decode_iso20_OverstayRuleType(stream, &OverstayRuleListType->OverstayRule.array[OverstayRuleListType->OverstayRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 154;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 154:
            // Grammar: ID=154; read/write bits=1; START (OverstayRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OverstayRule, OverstayRuleType (OverstayRuleType)); next=155
                    // decode: element array
                    if (OverstayRuleListType->OverstayRule.arrayLen < iso20_OverstayRuleType_5_ARRAY_SIZE)
                    {
                        error = decode_iso20_OverstayRuleType(stream, &OverstayRuleListType->OverstayRule.array[OverstayRuleListType->OverstayRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 155;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 155:
            // Grammar: ID=155; read/write bits=2; END Element, START (OverstayRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OverstayRule, OverstayRuleType (OverstayRuleType)); next=156
                    // decode: element array
                    if (OverstayRuleListType->OverstayRule.arrayLen < iso20_OverstayRuleType_5_ARRAY_SIZE)
                    {
                        error = decode_iso20_OverstayRuleType(stream, &OverstayRuleListType->OverstayRule.array[OverstayRuleListType->OverstayRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 156;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 156:
            // Grammar: ID=156; read/write bits=2; END Element, START (OverstayRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OverstayRule, OverstayRuleType (OverstayRuleType)); next=157
                    // decode: element array
                    if (OverstayRuleListType->OverstayRule.arrayLen < iso20_OverstayRuleType_5_ARRAY_SIZE)
                    {
                        error = decode_iso20_OverstayRuleType(stream, &OverstayRuleListType->OverstayRule.array[OverstayRuleListType->OverstayRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 157;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 157:
            // Grammar: ID=157; read/write bits=2; END Element, START (OverstayRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OverstayRule, OverstayRuleType (OverstayRuleType)); next=158
                    // decode: element array
                    if (OverstayRuleListType->OverstayRule.arrayLen < iso20_OverstayRuleType_5_ARRAY_SIZE)
                    {
                        error = decode_iso20_OverstayRuleType(stream, &OverstayRuleListType->OverstayRule.array[OverstayRuleListType->OverstayRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 158;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 158:
            // Grammar: ID=158; read/write bits=2; END Element, START (OverstayRule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OverstayRule, OverstayRuleType (OverstayRuleType)); next=2
                    // decode: element array
                    if (OverstayRuleListType->OverstayRule.arrayLen < iso20_OverstayRuleType_5_ARRAY_SIZE)
                    {
                        error = decode_iso20_OverstayRuleType(stream, &OverstayRuleListType->OverstayRule.array[OverstayRuleListType->OverstayRule.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 2;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}AdditionalSelectedServices; type={urn:iso:std:iso:15118:-20:CommonMessages}AdditionalServiceListType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: AdditionalService, AdditionalServiceType (1, 5);
static int decode_iso20_AdditionalServiceListType(exi_bitstream_t* stream, struct iso20_AdditionalServiceListType* AdditionalServiceListType) {
    int grammar_id = 159;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_AdditionalServiceListType(AdditionalServiceListType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 159:
            // Grammar: ID=159; read/write bits=1; START (AdditionalService)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AdditionalService, AdditionalServiceType (AdditionalServiceType)); next=160
                    // decode: element array
                    if (AdditionalServiceListType->AdditionalService.arrayLen < iso20_AdditionalServiceType_5_ARRAY_SIZE)
                    {
                        error = decode_iso20_AdditionalServiceType(stream, &AdditionalServiceListType->AdditionalService.array[AdditionalServiceListType->AdditionalService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 160;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 160:
            // Grammar: ID=160; read/write bits=2; END Element, START (AdditionalService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AdditionalService, AdditionalServiceType (AdditionalServiceType)); next=161
                    // decode: element array
                    if (AdditionalServiceListType->AdditionalService.arrayLen < iso20_AdditionalServiceType_5_ARRAY_SIZE)
                    {
                        error = decode_iso20_AdditionalServiceType(stream, &AdditionalServiceListType->AdditionalService.array[AdditionalServiceListType->AdditionalService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 161;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 161:
            // Grammar: ID=161; read/write bits=2; END Element, START (AdditionalService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AdditionalService, AdditionalServiceType (AdditionalServiceType)); next=162
                    // decode: element array
                    if (AdditionalServiceListType->AdditionalService.arrayLen < iso20_AdditionalServiceType_5_ARRAY_SIZE)
                    {
                        error = decode_iso20_AdditionalServiceType(stream, &AdditionalServiceListType->AdditionalService.array[AdditionalServiceListType->AdditionalService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 162;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 162:
            // Grammar: ID=162; read/write bits=2; END Element, START (AdditionalService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AdditionalService, AdditionalServiceType (AdditionalServiceType)); next=163
                    // decode: element array
                    if (AdditionalServiceListType->AdditionalService.arrayLen < iso20_AdditionalServiceType_5_ARRAY_SIZE)
                    {
                        error = decode_iso20_AdditionalServiceType(stream, &AdditionalServiceListType->AdditionalService.array[AdditionalServiceListType->AdditionalService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 163;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 163:
            // Grammar: ID=163; read/write bits=2; END Element, START (AdditionalService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AdditionalService, AdditionalServiceType (AdditionalServiceType)); next=2
                    // decode: element array
                    if (AdditionalServiceListType->AdditionalService.arrayLen < iso20_AdditionalServiceType_5_ARRAY_SIZE)
                    {
                        error = decode_iso20_AdditionalServiceType(stream, &AdditionalServiceListType->AdditionalService.array[AdditionalServiceListType->AdditionalService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 2;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}Service; type={urn:iso:std:iso:15118:-20:CommonMessages}ServiceType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: ServiceID, serviceIDType (1, 1); FreeService, boolean (1, 1);
static int decode_iso20_ServiceType(exi_bitstream_t* stream, struct iso20_ServiceType* ServiceType) {
    int grammar_id = 164;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ServiceType(ServiceType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 164:
            // Grammar: ID=164; read/write bits=1; START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=165
                    // decode: unsigned short
                    error = decode_exi_type_uint16(stream, &ServiceType->ServiceID);
                    if (error == 0)
                    {
                        grammar_id = 165;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 165:
            // Grammar: ID=165; read/write bits=1; START (FreeService)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (FreeService, boolean (boolean)); next=2
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ServiceType->FreeService = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}ParameterSet; type={urn:iso:std:iso:15118:-20:CommonMessages}ParameterSetType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: ParameterSetID, serviceIDType (1, 1); Parameter, ParameterType (1, 32);
static int decode_iso20_ParameterSetType(exi_bitstream_t* stream, struct iso20_ParameterSetType* ParameterSetType) {
    int grammar_id = 166;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ParameterSetType(ParameterSetType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 166:
            // Grammar: ID=166; read/write bits=1; START (ParameterSetID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ParameterSetID, serviceIDType (unsignedShort)); next=167
                    // decode: unsigned short
                    error = decode_exi_type_uint16(stream, &ParameterSetType->ParameterSetID);
                    if (error == 0)
                    {
                        grammar_id = 167;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 167:
            // Grammar: ID=167; read/write bits=1; START (Parameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Parameter, ParameterType (ParameterType)); next=168
                    // decode: element array
                    if (ParameterSetType->Parameter.arrayLen < iso20_ParameterType_32_ARRAY_SIZE)
                    {
                        error = decode_iso20_ParameterType(stream, &ParameterSetType->Parameter.array[ParameterSetType->Parameter.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 168;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 168:
            // Grammar: ID=168; read/write bits=2; END Element, LOOP (Parameter)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case -1:
                    // Event: LOOP (Parameter, ParameterType (ParameterType)); next=3
                    // decode: element array
                    if (ParameterSetType->Parameter.arrayLen < iso20_ParameterType_32_ARRAY_SIZE)
                    {
                        error = decode_iso20_ParameterType(stream, &ParameterSetType->Parameter.array[ParameterSetType->Parameter.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}SupportedProviders; type={urn:iso:std:iso:15118:-20:CommonMessages}SupportedProvidersListType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: ProviderID, nameType (1, 128);
static int decode_iso20_SupportedProvidersListType(exi_bitstream_t* stream, struct iso20_SupportedProvidersListType* SupportedProvidersListType) {
    int grammar_id = 169;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_SupportedProvidersListType(SupportedProvidersListType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 169:
            // Grammar: ID=169; read/write bits=1; START (ProviderID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ProviderID, nameType (string)); next=170
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &SupportedProvidersListType->ProviderID.charactersLen);
                            if (error == 0)
                            {
                                if (SupportedProvidersListType->ProviderID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    SupportedProvidersListType->ProviderID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, SupportedProvidersListType->ProviderID.charactersLen, SupportedProvidersListType->ProviderID.characters, iso20_ProviderID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 170;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 170:
            // Grammar: ID=170; read/write bits=2; END Element, LOOP (ProviderID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case -1:
                    // Event: LOOP (ProviderID, nameType (string)); next=3
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &SupportedProvidersListType->ProviderID.charactersLen);
                            if (error == 0)
                            {
                                if (SupportedProvidersListType->ProviderID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    SupportedProvidersListType->ProviderID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, SupportedProvidersListType->ProviderID.charactersLen, SupportedProvidersListType->ProviderID.characters, iso20_ProviderID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 3;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}ContractCertificateChain; type={urn:iso:std:iso:15118:-20:CommonMessages}ContractCertificateChainType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Certificate, certificateType (1, 1); SubCertificates, SubCertificatesType (1, 1);
static int decode_iso20_ContractCertificateChainType(exi_bitstream_t* stream, struct iso20_ContractCertificateChainType* ContractCertificateChainType) {
    int grammar_id = 171;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ContractCertificateChainType(ContractCertificateChainType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 171:
            // Grammar: ID=171; read/write bits=1; START (Certificate)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Certificate, certificateType (base64Binary)); next=172
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &ContractCertificateChainType->Certificate.bytesLen, &ContractCertificateChainType->Certificate.bytes[0], iso20_certificateType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 172;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 172:
            // Grammar: ID=172; read/write bits=1; START (SubCertificates)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SubCertificates, SubCertificatesType (SubCertificatesType)); next=2
                    // decode: element
                    error = decode_iso20_SubCertificatesType(stream, &ContractCertificateChainType->SubCertificates);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}Dynamic_EVPPTControlMode; type={urn:iso:std:iso:15118:-20:CommonMessages}Dynamic_EVPPTControlModeType; base type=; content type=empty;
//          abstract=False; final=False;
static int decode_iso20_Dynamic_EVPPTControlModeType(exi_bitstream_t* stream, struct iso20_Dynamic_EVPPTControlModeType* Dynamic_EVPPTControlModeType) {
    // Element has no particles, so the function just returns zero
    (void)stream;
    (void)Dynamic_EVPPTControlModeType;

    return 0;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}MeterInfo; type={urn:iso:std:iso:15118:-20:CommonTypes}MeterInfoType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: MeterID, meterIDType (1, 1); ChargedEnergyReadingWh, unsignedLong (1, 1); BPT_DischargedEnergyReadingWh, unsignedLong (0, 1); CapacitiveEnergyReadingVARh, unsignedLong (0, 1); BPT_InductiveEnergyReadingVARh, unsignedLong (0, 1); MeterSignature, meterSignatureType (0, 1); MeterStatus, short (0, 1); MeterTimestamp, unsignedLong (0, 1);
static int decode_iso20_MeterInfoType(exi_bitstream_t* stream, struct iso20_MeterInfoType* MeterInfoType) {
    int grammar_id = 173;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_MeterInfoType(MeterInfoType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 173:
            // Grammar: ID=173; read/write bits=1; START (MeterID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (MeterID, meterIDType (string)); next=174
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &MeterInfoType->MeterID.charactersLen);
                            if (error == 0)
                            {
                                if (MeterInfoType->MeterID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    MeterInfoType->MeterID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, MeterInfoType->MeterID.charactersLen, MeterInfoType->MeterID.characters, iso20_MeterID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 174;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 174:
            // Grammar: ID=174; read/write bits=1; START (ChargedEnergyReadingWh)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ChargedEnergyReadingWh, unsignedLong (nonNegativeInteger)); next=175
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &MeterInfoType->ChargedEnergyReadingWh);
                    if (error == 0)
                    {
                        grammar_id = 175;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 175:
            // Grammar: ID=175; read/write bits=3; END Element, START (BPT_DischargedEnergyReadingWh), START (CapacitiveEnergyReadingVARh), START (BPT_InductiveEnergyReadingVARh), START (MeterSignature), START (MeterStatus), START (MeterTimestamp)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (BPT_DischargedEnergyReadingWh, unsignedLong (nonNegativeInteger)); next=176
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &MeterInfoType->BPT_DischargedEnergyReadingWh);
                    if (error == 0)
                    {
                        MeterInfoType->BPT_DischargedEnergyReadingWh_isUsed = 1u;
                        grammar_id = 176;
                    }
                    break;
                case 1:
                    // Event: START (CapacitiveEnergyReadingVARh, unsignedLong (nonNegativeInteger)); next=177
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &MeterInfoType->CapacitiveEnergyReadingVARh);
                    if (error == 0)
                    {
                        MeterInfoType->CapacitiveEnergyReadingVARh_isUsed = 1u;
                        grammar_id = 177;
                    }
                    break;
                case 2:
                    // Event: START (BPT_InductiveEnergyReadingVARh, unsignedLong (nonNegativeInteger)); next=178
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &MeterInfoType->BPT_InductiveEnergyReadingVARh);
                    if (error == 0)
                    {
                        MeterInfoType->BPT_InductiveEnergyReadingVARh_isUsed = 1u;
                        grammar_id = 178;
                    }
                    break;
                case 3:
                    // Event: START (MeterSignature, meterSignatureType (base64Binary)); next=179
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &MeterInfoType->MeterSignature.bytesLen, &MeterInfoType->MeterSignature.bytes[0], iso20_meterSignatureType_BYTES_SIZE);
                    if (error == 0)
                    {
                        MeterInfoType->MeterSignature_isUsed = 1u;
                        grammar_id = 179;
                    }
                    break;
                case 4:
                    // Event: START (MeterStatus, short (int)); next=180
                    // decode: short
                    error = decode_exi_type_integer16(stream, &MeterInfoType->MeterStatus);
                    if (error == 0)
                    {
                        MeterInfoType->MeterStatus_isUsed = 1u;
                        grammar_id = 180;
                    }
                    break;
                case 5:
                    // Event: START (MeterTimestamp, unsignedLong (nonNegativeInteger)); next=2
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &MeterInfoType->MeterTimestamp);
                    if (error == 0)
                    {
                        MeterInfoType->MeterTimestamp_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 6:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 176:
            // Grammar: ID=176; read/write bits=3; END Element, START (CapacitiveEnergyReadingVARh), START (BPT_InductiveEnergyReadingVARh), START (MeterSignature), START (MeterStatus), START (MeterTimestamp)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (CapacitiveEnergyReadingVARh, unsignedLong (nonNegativeInteger)); next=177
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &MeterInfoType->CapacitiveEnergyReadingVARh);
                    if (error == 0)
                    {
                        MeterInfoType->CapacitiveEnergyReadingVARh_isUsed = 1u;
                        grammar_id = 177;
                    }
                    break;
                case 1:
                    // Event: START (BPT_InductiveEnergyReadingVARh, unsignedLong (nonNegativeInteger)); next=178
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &MeterInfoType->BPT_InductiveEnergyReadingVARh);
                    if (error == 0)
                    {
                        MeterInfoType->BPT_InductiveEnergyReadingVARh_isUsed = 1u;
                        grammar_id = 178;
                    }
                    break;
                case 2:
                    // Event: START (MeterSignature, meterSignatureType (base64Binary)); next=179
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &MeterInfoType->MeterSignature.bytesLen, &MeterInfoType->MeterSignature.bytes[0], iso20_meterSignatureType_BYTES_SIZE);
                    if (error == 0)
                    {
                        MeterInfoType->MeterSignature_isUsed = 1u;
                        grammar_id = 179;
                    }
                    break;
                case 3:
                    // Event: START (MeterStatus, short (int)); next=180
                    // decode: short
                    error = decode_exi_type_integer16(stream, &MeterInfoType->MeterStatus);
                    if (error == 0)
                    {
                        MeterInfoType->MeterStatus_isUsed = 1u;
                        grammar_id = 180;
                    }
                    break;
                case 4:
                    // Event: START (MeterTimestamp, unsignedLong (nonNegativeInteger)); next=2
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &MeterInfoType->MeterTimestamp);
                    if (error == 0)
                    {
                        MeterInfoType->MeterTimestamp_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 5:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 177:
            // Grammar: ID=177; read/write bits=3; END Element, START (BPT_InductiveEnergyReadingVARh), START (MeterSignature), START (MeterStatus), START (MeterTimestamp)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (BPT_InductiveEnergyReadingVARh, unsignedLong (nonNegativeInteger)); next=178
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &MeterInfoType->BPT_InductiveEnergyReadingVARh);
                    if (error == 0)
                    {
                        MeterInfoType->BPT_InductiveEnergyReadingVARh_isUsed = 1u;
                        grammar_id = 178;
                    }
                    break;
                case 1:
                    // Event: START (MeterSignature, meterSignatureType (base64Binary)); next=179
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &MeterInfoType->MeterSignature.bytesLen, &MeterInfoType->MeterSignature.bytes[0], iso20_meterSignatureType_BYTES_SIZE);
                    if (error == 0)
                    {
                        MeterInfoType->MeterSignature_isUsed = 1u;
                        grammar_id = 179;
                    }
                    break;
                case 2:
                    // Event: START (MeterStatus, short (int)); next=180
                    // decode: short
                    error = decode_exi_type_integer16(stream, &MeterInfoType->MeterStatus);
                    if (error == 0)
                    {
                        MeterInfoType->MeterStatus_isUsed = 1u;
                        grammar_id = 180;
                    }
                    break;
                case 3:
                    // Event: START (MeterTimestamp, unsignedLong (nonNegativeInteger)); next=2
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &MeterInfoType->MeterTimestamp);
                    if (error == 0)
                    {
                        MeterInfoType->MeterTimestamp_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 4:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 178:
            // Grammar: ID=178; read/write bits=3; END Element, START (MeterSignature), START (MeterStatus), START (MeterTimestamp)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (MeterSignature, meterSignatureType (base64Binary)); next=179
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &MeterInfoType->MeterSignature.bytesLen, &MeterInfoType->MeterSignature.bytes[0], iso20_meterSignatureType_BYTES_SIZE);
                    if (error == 0)
                    {
                        MeterInfoType->MeterSignature_isUsed = 1u;
                        grammar_id = 179;
                    }
                    break;
                case 1:
                    // Event: START (MeterStatus, short (int)); next=180
                    // decode: short
                    error = decode_exi_type_integer16(stream, &MeterInfoType->MeterStatus);
                    if (error == 0)
                    {
                        MeterInfoType->MeterStatus_isUsed = 1u;
                        grammar_id = 180;
                    }
                    break;
                case 2:
                    // Event: START (MeterTimestamp, unsignedLong (nonNegativeInteger)); next=2
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &MeterInfoType->MeterTimestamp);
                    if (error == 0)
                    {
                        MeterInfoType->MeterTimestamp_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 3:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 179:
            // Grammar: ID=179; read/write bits=2; END Element, START (MeterStatus), START (MeterTimestamp)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (MeterStatus, short (int)); next=180
                    // decode: short
                    error = decode_exi_type_integer16(stream, &MeterInfoType->MeterStatus);
                    if (error == 0)
                    {
                        MeterInfoType->MeterStatus_isUsed = 1u;
                        grammar_id = 180;
                    }
                    break;
                case 1:
                    // Event: START (MeterTimestamp, unsignedLong (nonNegativeInteger)); next=2
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &MeterInfoType->MeterTimestamp);
                    if (error == 0)
                    {
                        MeterInfoType->MeterTimestamp_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 2:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 180:
            // Grammar: ID=180; read/write bits=2; END Element, START (MeterTimestamp)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (MeterTimestamp, unsignedLong (nonNegativeInteger)); next=2
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &MeterInfoType->MeterTimestamp);
                    if (error == 0)
                    {
                        MeterInfoType->MeterTimestamp_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_SignatureType(exi_bitstream_t* stream, struct iso20_SignatureType* SignatureType) {
    int grammar_id = 181;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_SignatureType(SignatureType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 181:
            // Grammar: ID=181; read/write bits=2; START (Id), START (SignedInfo)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=182
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &SignatureType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (SignatureType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            SignatureType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, SignatureType->Id.charactersLen, SignatureType->Id.characters, iso20_Id_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    SignatureType->Id_isUsed = 1u;
                    grammar_id = 182;
                    break;
                case 1:
                    // Event: START (SignedInfo, SignedInfoType (SignedInfoType)); next=183
                    // decode: element
                    error = decode_iso20_SignedInfoType(stream, &SignatureType->SignedInfo);
                    if (error == 0)
                    {
                        grammar_id = 183;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 182:
            // Grammar: ID=182; read/write bits=1; START (SignedInfo)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SignedInfo, SignedInfoType (SignedInfoType)); next=183
                    // decode: element
                    error = decode_iso20_SignedInfoType(stream, &SignatureType->SignedInfo);
                    if (error == 0)
                    {
                        grammar_id = 183;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 183:
            // Grammar: ID=183; read/write bits=1; START (SignatureValue)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SignatureValue, SignatureValueType (base64Binary)); next=184
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SignatureType->SignatureValue.CONTENT.bytesLen, &SignatureType->SignatureValue.CONTENT.bytes[0], iso20_SignatureValueType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 184;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 184:
            // Grammar: ID=184; read/write bits=2; END Element, START (KeyInfo), START (Object)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (KeyInfo, KeyInfoType (KeyInfoType)); next=186
                    // decode: element
                    error = decode_iso20_KeyInfoType(stream, &SignatureType->KeyInfo);
                    if (error == 0)
                    {
                        SignatureType->KeyInfo_isUsed = 1u;
                        grammar_id = 186;
                    }
                    break;
                case 1:
                    // Event: START (Object, ObjectType (ObjectType)); next=2
                    // decode: element
                    error = decode_iso20_ObjectType(stream, &SignatureType->Object);
                    if (error == 0)
                    {
                        SignatureType->Object_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 2:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 185:
            // Grammar: ID=185; read/write bits=2; END Element, START (Object)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Object, ObjectType (ObjectType)); next=186
                    // decode: element
                    error = decode_iso20_ObjectType(stream, &SignatureType->Object);
                    if (error == 0)
                    {
                        SignatureType->Object_isUsed = 1u;
                        grammar_id = 186;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 186:
            // Grammar: ID=186; read/write bits=2; END Element, START (Object)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Object, ObjectType (ObjectType)); next=187
                    // decode: element
                    error = decode_iso20_ObjectType(stream, &SignatureType->Object);
                    if (error == 0)
                    {
                        SignatureType->Object_isUsed = 1u;
                        grammar_id = 187;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 187:
            // Grammar: ID=187; read/write bits=2; END Element, START (Object)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Object, ObjectType (ObjectType)); next=2
                    // decode: element
                    error = decode_iso20_ObjectType(stream, &SignatureType->Object);
                    if (error == 0)
                    {
                        SignatureType->Object_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}Scheduled_EVPPTControlMode; type={urn:iso:std:iso:15118:-20:CommonMessages}Scheduled_EVPPTControlModeType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: SelectedScheduleTupleID, numericIDType (1, 1); PowerToleranceAcceptance, powerToleranceAcceptanceType (0, 1);
static int decode_iso20_Scheduled_EVPPTControlModeType(exi_bitstream_t* stream, struct iso20_Scheduled_EVPPTControlModeType* Scheduled_EVPPTControlModeType) {
    int grammar_id = 188;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_Scheduled_EVPPTControlModeType(Scheduled_EVPPTControlModeType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 188:
            // Grammar: ID=188; read/write bits=1; START (SelectedScheduleTupleID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedScheduleTupleID, numericIDType (unsignedInt)); next=189
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &Scheduled_EVPPTControlModeType->SelectedScheduleTupleID);
                    if (error == 0)
                    {
                        grammar_id = 189;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 189:
            // Grammar: ID=189; read/write bits=2; END Element, START (PowerToleranceAcceptance)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PowerToleranceAcceptance, powerToleranceAcceptanceType (string)); next=2
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                Scheduled_EVPPTControlModeType->PowerToleranceAcceptance = (iso20_powerToleranceAcceptanceType)value;
                                Scheduled_EVPPTControlModeType->PowerToleranceAcceptance_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}Receipt; type={urn:iso:std:iso:15118:-20:CommonTypes}ReceiptType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: TimeAnchor, unsignedLong (1, 1); EnergyCosts, DetailedCostType (0, 1); OccupancyCosts, DetailedCostType (0, 1); AdditionalServicesCosts, DetailedCostType (0, 1); OverstayCosts, DetailedCostType (0, 1); TaxCosts, DetailedTaxType (0, 10);
static int decode_iso20_ReceiptType(exi_bitstream_t* stream, struct iso20_ReceiptType* ReceiptType) {
    int grammar_id = 190;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ReceiptType(ReceiptType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 190:
            // Grammar: ID=190; read/write bits=1; START (TimeAnchor)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TimeAnchor, unsignedLong (nonNegativeInteger)); next=191
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &ReceiptType->TimeAnchor);
                    if (error == 0)
                    {
                        grammar_id = 191;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 191:
            // Grammar: ID=191; read/write bits=3; END Element, START (EnergyCosts), START (OccupancyCosts), START (AdditionalServicesCosts), START (OverstayCosts), START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EnergyCosts, DetailedCostType (DetailedCostType)); next=201
                    // decode: element
                    error = decode_iso20_DetailedCostType(stream, &ReceiptType->EnergyCosts);
                    if (error == 0)
                    {
                        ReceiptType->EnergyCosts_isUsed = 1u;
                        grammar_id = 201;
                    }
                    break;
                case 1:
                    // Event: START (OccupancyCosts, DetailedCostType (DetailedCostType)); next=211
                    // decode: element
                    error = decode_iso20_DetailedCostType(stream, &ReceiptType->OccupancyCosts);
                    if (error == 0)
                    {
                        ReceiptType->OccupancyCosts_isUsed = 1u;
                        grammar_id = 211;
                    }
                    break;
                case 2:
                    // Event: START (AdditionalServicesCosts, DetailedCostType (DetailedCostType)); next=221
                    // decode: element
                    error = decode_iso20_DetailedCostType(stream, &ReceiptType->AdditionalServicesCosts);
                    if (error == 0)
                    {
                        ReceiptType->AdditionalServicesCosts_isUsed = 1u;
                        grammar_id = 221;
                    }
                    break;
                case 3:
                    // Event: START (OverstayCosts, DetailedCostType (DetailedCostType)); next=231
                    // decode: element
                    error = decode_iso20_DetailedCostType(stream, &ReceiptType->OverstayCosts);
                    if (error == 0)
                    {
                        ReceiptType->OverstayCosts_isUsed = 1u;
                        grammar_id = 231;
                    }
                    break;
                case 4:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=2
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 2;
                    break;
                case 5:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 192:
            // Grammar: ID=192; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=193
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 193;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 193:
            // Grammar: ID=193; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=194
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 194;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 194:
            // Grammar: ID=194; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=195
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 195;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 195:
            // Grammar: ID=195; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=196
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 196;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 196:
            // Grammar: ID=196; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=197
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 197;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 197:
            // Grammar: ID=197; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=198
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 198;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 198:
            // Grammar: ID=198; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=199
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 199;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 199:
            // Grammar: ID=199; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=200
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 200;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 200:
            // Grammar: ID=200; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=201
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 201;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 201:
            // Grammar: ID=201; read/write bits=3; END Element, START (OccupancyCosts), START (AdditionalServicesCosts), START (OverstayCosts), START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OccupancyCosts, DetailedCostType (DetailedCostType)); next=211
                    // decode: element
                    error = decode_iso20_DetailedCostType(stream, &ReceiptType->OccupancyCosts);
                    if (error == 0)
                    {
                        ReceiptType->OccupancyCosts_isUsed = 1u;
                        grammar_id = 211;
                    }
                    break;
                case 1:
                    // Event: START (AdditionalServicesCosts, DetailedCostType (DetailedCostType)); next=221
                    // decode: element
                    error = decode_iso20_DetailedCostType(stream, &ReceiptType->AdditionalServicesCosts);
                    if (error == 0)
                    {
                        ReceiptType->AdditionalServicesCosts_isUsed = 1u;
                        grammar_id = 221;
                    }
                    break;
                case 2:
                    // Event: START (OverstayCosts, DetailedCostType (DetailedCostType)); next=231
                    // decode: element
                    error = decode_iso20_DetailedCostType(stream, &ReceiptType->OverstayCosts);
                    if (error == 0)
                    {
                        ReceiptType->OverstayCosts_isUsed = 1u;
                        grammar_id = 231;
                    }
                    break;
                case 3:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=2
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 2;
                    break;
                case 4:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 202:
            // Grammar: ID=202; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=203
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 203;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 203:
            // Grammar: ID=203; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=204
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 204;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 204:
            // Grammar: ID=204; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=205
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 205;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 205:
            // Grammar: ID=205; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=206
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 206;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 206:
            // Grammar: ID=206; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=207
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 207;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 207:
            // Grammar: ID=207; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=208
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 208;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 208:
            // Grammar: ID=208; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=209
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 209;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 209:
            // Grammar: ID=209; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=210
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 210;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 210:
            // Grammar: ID=210; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=211
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 211;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 211:
            // Grammar: ID=211; read/write bits=3; END Element, START (AdditionalServicesCosts), START (OverstayCosts), START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AdditionalServicesCosts, DetailedCostType (DetailedCostType)); next=221
                    // decode: element
                    error = decode_iso20_DetailedCostType(stream, &ReceiptType->AdditionalServicesCosts);
                    if (error == 0)
                    {
                        ReceiptType->AdditionalServicesCosts_isUsed = 1u;
                        grammar_id = 221;
                    }
                    break;
                case 1:
                    // Event: START (OverstayCosts, DetailedCostType (DetailedCostType)); next=231
                    // decode: element
                    error = decode_iso20_DetailedCostType(stream, &ReceiptType->OverstayCosts);
                    if (error == 0)
                    {
                        ReceiptType->OverstayCosts_isUsed = 1u;
                        grammar_id = 231;
                    }
                    break;
                case 2:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=2
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 2;
                    break;
                case 3:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 212:
            // Grammar: ID=212; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=213
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 213;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 213:
            // Grammar: ID=213; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=214
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 214;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 214:
            // Grammar: ID=214; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=215
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 215;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 215:
            // Grammar: ID=215; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=216
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 216;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 216:
            // Grammar: ID=216; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=217
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 217;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 217:
            // Grammar: ID=217; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=218
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 218;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 218:
            // Grammar: ID=218; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=219
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 219;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 219:
            // Grammar: ID=219; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=220
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 220;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 220:
            // Grammar: ID=220; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=221
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 221;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 221:
            // Grammar: ID=221; read/write bits=2; END Element, START (OverstayCosts), START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OverstayCosts, DetailedCostType (DetailedCostType)); next=231
                    // decode: element
                    error = decode_iso20_DetailedCostType(stream, &ReceiptType->OverstayCosts);
                    if (error == 0)
                    {
                        ReceiptType->OverstayCosts_isUsed = 1u;
                        grammar_id = 231;
                    }
                    break;
                case 1:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=2
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 2;
                    break;
                case 2:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 222:
            // Grammar: ID=222; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=223
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 223;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 223:
            // Grammar: ID=223; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=224
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 224;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 224:
            // Grammar: ID=224; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=225
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 225;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 225:
            // Grammar: ID=225; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=226
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 226;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 226:
            // Grammar: ID=226; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=227
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 227;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 227:
            // Grammar: ID=227; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=228
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 228;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 228:
            // Grammar: ID=228; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=229
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 229;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 229:
            // Grammar: ID=229; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=230
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 230;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 230:
            // Grammar: ID=230; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=231
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 231;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 231:
            // Grammar: ID=231; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=232
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 232;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 232:
            // Grammar: ID=232; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=233
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 233;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 233:
            // Grammar: ID=233; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=234
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 234;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 234:
            // Grammar: ID=234; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=235
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 235;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 235:
            // Grammar: ID=235; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=236
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 236;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 236:
            // Grammar: ID=236; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=237
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 237;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 237:
            // Grammar: ID=237; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=238
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 238;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 238:
            // Grammar: ID=238; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=239
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 239;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 239:
            // Grammar: ID=239; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=240
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 240;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 240:
            // Grammar: ID=240; read/write bits=2; END Element, START (TaxCosts)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxCosts, DetailedTaxType (DetailedTaxType)); next=2
                    // decode: element array
                    if (ReceiptType->TaxCosts.arrayLen < iso20_DetailedTaxType_10_ARRAY_SIZE)
                    {
                        error = decode_iso20_DetailedTaxType(stream, &ReceiptType->TaxCosts.array[ReceiptType->TaxCosts.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 2;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}AbsolutePriceSchedule; type={urn:iso:std:iso:15118:-20:CommonMessages}AbsolutePriceScheduleType; base type=PriceScheduleType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Id, ID (0, 1); TimeAnchor, unsignedLong (1, 1); PriceScheduleID, numericIDType (1, 1); PriceScheduleDescription, descriptionType (0, 1); Currency, currencyType (1, 1); Language, languageType (1, 1); PriceAlgorithm, identifierType (1, 1); MinimumCost, RationalNumberType (0, 1); MaximumCost, RationalNumberType (0, 1); TaxRules, TaxRuleListType (0, 1); PriceRuleStacks, PriceRuleStackListType (1, 1); OverstayRules, OverstayRuleListType (0, 1); AdditionalSelectedServices, AdditionalServiceListType (0, 1);
static int decode_iso20_AbsolutePriceScheduleType(exi_bitstream_t* stream, struct iso20_AbsolutePriceScheduleType* AbsolutePriceScheduleType) {
    int grammar_id = 241;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_AbsolutePriceScheduleType(AbsolutePriceScheduleType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 241:
            // Grammar: ID=241; read/write bits=2; START (Id), START (TimeAnchor)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=242
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &AbsolutePriceScheduleType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (AbsolutePriceScheduleType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            AbsolutePriceScheduleType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, AbsolutePriceScheduleType->Id.charactersLen, AbsolutePriceScheduleType->Id.characters, iso20_Id_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    AbsolutePriceScheduleType->Id_isUsed = 1u;
                    grammar_id = 242;
                    break;
                case 1:
                    // Event: START (TimeAnchor, unsignedLong (nonNegativeInteger)); next=243
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &AbsolutePriceScheduleType->TimeAnchor);
                    if (error == 0)
                    {
                        grammar_id = 243;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 242:
            // Grammar: ID=242; read/write bits=1; START (TimeAnchor)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TimeAnchor, unsignedLong (nonNegativeInteger)); next=243
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &AbsolutePriceScheduleType->TimeAnchor);
                    if (error == 0)
                    {
                        grammar_id = 243;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 243:
            // Grammar: ID=243; read/write bits=1; START (PriceScheduleID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PriceScheduleID, numericIDType (unsignedInt)); next=244
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &AbsolutePriceScheduleType->PriceScheduleID);
                    if (error == 0)
                    {
                        grammar_id = 244;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 244:
            // Grammar: ID=244; read/write bits=2; START (PriceScheduleDescription), START (Currency)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PriceScheduleDescription, descriptionType (string)); next=245
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &AbsolutePriceScheduleType->PriceScheduleDescription.charactersLen);
                            if (error == 0)
                            {
                                if (AbsolutePriceScheduleType->PriceScheduleDescription.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    AbsolutePriceScheduleType->PriceScheduleDescription.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, AbsolutePriceScheduleType->PriceScheduleDescription.charactersLen, AbsolutePriceScheduleType->PriceScheduleDescription.characters, iso20_PriceScheduleDescription_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                AbsolutePriceScheduleType->PriceScheduleDescription_isUsed = 1u;
                                grammar_id = 245;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (Currency, currencyType (string)); next=246
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &AbsolutePriceScheduleType->Currency.charactersLen);
                            if (error == 0)
                            {
                                if (AbsolutePriceScheduleType->Currency.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    AbsolutePriceScheduleType->Currency.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, AbsolutePriceScheduleType->Currency.charactersLen, AbsolutePriceScheduleType->Currency.characters, iso20_Currency_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 246;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 245:
            // Grammar: ID=245; read/write bits=1; START (Currency)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Currency, currencyType (string)); next=246
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &AbsolutePriceScheduleType->Currency.charactersLen);
                            if (error == 0)
                            {
                                if (AbsolutePriceScheduleType->Currency.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    AbsolutePriceScheduleType->Currency.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, AbsolutePriceScheduleType->Currency.charactersLen, AbsolutePriceScheduleType->Currency.characters, iso20_Currency_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 246;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 246:
            // Grammar: ID=246; read/write bits=1; START (Language)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Language, languageType (string)); next=247
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &AbsolutePriceScheduleType->Language.charactersLen);
                            if (error == 0)
                            {
                                if (AbsolutePriceScheduleType->Language.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    AbsolutePriceScheduleType->Language.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, AbsolutePriceScheduleType->Language.charactersLen, AbsolutePriceScheduleType->Language.characters, iso20_Language_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 247;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 247:
            // Grammar: ID=247; read/write bits=1; START (PriceAlgorithm)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PriceAlgorithm, identifierType (string)); next=248
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &AbsolutePriceScheduleType->PriceAlgorithm.charactersLen);
                            if (error == 0)
                            {
                                if (AbsolutePriceScheduleType->PriceAlgorithm.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    AbsolutePriceScheduleType->PriceAlgorithm.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, AbsolutePriceScheduleType->PriceAlgorithm.charactersLen, AbsolutePriceScheduleType->PriceAlgorithm.characters, iso20_PriceAlgorithm_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 248;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 248:
            // Grammar: ID=248; read/write bits=3; START (MinimumCost), START (MaximumCost), START (TaxRules), START (PriceRuleStacks)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (MinimumCost, RationalNumberType (RationalNumberType)); next=249
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &AbsolutePriceScheduleType->MinimumCost);
                    if (error == 0)
                    {
                        AbsolutePriceScheduleType->MinimumCost_isUsed = 1u;
                        grammar_id = 249;
                    }
                    break;
                case 1:
                    // Event: START (MaximumCost, RationalNumberType (RationalNumberType)); next=250
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &AbsolutePriceScheduleType->MaximumCost);
                    if (error == 0)
                    {
                        AbsolutePriceScheduleType->MaximumCost_isUsed = 1u;
                        grammar_id = 250;
                    }
                    break;
                case 2:
                    // Event: START (TaxRules, TaxRuleListType (TaxRuleListType)); next=251
                    // decode: element
                    error = decode_iso20_TaxRuleListType(stream, &AbsolutePriceScheduleType->TaxRules);
                    if (error == 0)
                    {
                        AbsolutePriceScheduleType->TaxRules_isUsed = 1u;
                        grammar_id = 251;
                    }
                    break;
                case 3:
                    // Event: START (PriceRuleStacks, PriceRuleStackListType (PriceRuleStackListType)); next=252
                    // decode: element
                    error = decode_iso20_PriceRuleStackListType(stream, &AbsolutePriceScheduleType->PriceRuleStacks);
                    if (error == 0)
                    {
                        grammar_id = 252;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 249:
            // Grammar: ID=249; read/write bits=2; START (MaximumCost), START (TaxRules), START (PriceRuleStacks)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (MaximumCost, RationalNumberType (RationalNumberType)); next=250
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &AbsolutePriceScheduleType->MaximumCost);
                    if (error == 0)
                    {
                        AbsolutePriceScheduleType->MaximumCost_isUsed = 1u;
                        grammar_id = 250;
                    }
                    break;
                case 1:
                    // Event: START (TaxRules, TaxRuleListType (TaxRuleListType)); next=251
                    // decode: element
                    error = decode_iso20_TaxRuleListType(stream, &AbsolutePriceScheduleType->TaxRules);
                    if (error == 0)
                    {
                        AbsolutePriceScheduleType->TaxRules_isUsed = 1u;
                        grammar_id = 251;
                    }
                    break;
                case 2:
                    // Event: START (PriceRuleStacks, PriceRuleStackListType (PriceRuleStackListType)); next=252
                    // decode: element
                    error = decode_iso20_PriceRuleStackListType(stream, &AbsolutePriceScheduleType->PriceRuleStacks);
                    if (error == 0)
                    {
                        grammar_id = 252;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 250:
            // Grammar: ID=250; read/write bits=2; START (TaxRules), START (PriceRuleStacks)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TaxRules, TaxRuleListType (TaxRuleListType)); next=251
                    // decode: element
                    error = decode_iso20_TaxRuleListType(stream, &AbsolutePriceScheduleType->TaxRules);
                    if (error == 0)
                    {
                        AbsolutePriceScheduleType->TaxRules_isUsed = 1u;
                        grammar_id = 251;
                    }
                    break;
                case 1:
                    // Event: START (PriceRuleStacks, PriceRuleStackListType (PriceRuleStackListType)); next=252
                    // decode: element
                    error = decode_iso20_PriceRuleStackListType(stream, &AbsolutePriceScheduleType->PriceRuleStacks);
                    if (error == 0)
                    {
                        grammar_id = 252;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 251:
            // Grammar: ID=251; read/write bits=1; START (PriceRuleStacks)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PriceRuleStacks, PriceRuleStackListType (PriceRuleStackListType)); next=252
                    // decode: element
                    error = decode_iso20_PriceRuleStackListType(stream, &AbsolutePriceScheduleType->PriceRuleStacks);
                    if (error == 0)
                    {
                        grammar_id = 252;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 252:
            // Grammar: ID=252; read/write bits=2; END Element, START (OverstayRules), START (AdditionalSelectedServices)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OverstayRules, OverstayRuleListType (OverstayRuleListType)); next=253
                    // decode: element
                    error = decode_iso20_OverstayRuleListType(stream, &AbsolutePriceScheduleType->OverstayRules);
                    if (error == 0)
                    {
                        AbsolutePriceScheduleType->OverstayRules_isUsed = 1u;
                        grammar_id = 253;
                    }
                    break;
                case 1:
                    // Event: START (AdditionalSelectedServices, AdditionalServiceListType (AdditionalServiceListType)); next=2
                    // decode: element
                    error = decode_iso20_AdditionalServiceListType(stream, &AbsolutePriceScheduleType->AdditionalSelectedServices);
                    if (error == 0)
                    {
                        AbsolutePriceScheduleType->AdditionalSelectedServices_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 2:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 253:
            // Grammar: ID=253; read/write bits=2; END Element, START (AdditionalSelectedServices)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AdditionalSelectedServices, AdditionalServiceListType (AdditionalServiceListType)); next=2
                    // decode: element
                    error = decode_iso20_AdditionalServiceListType(stream, &AbsolutePriceScheduleType->AdditionalSelectedServices);
                    if (error == 0)
                    {
                        AbsolutePriceScheduleType->AdditionalSelectedServices_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}EVPowerProfileEntries; type={urn:iso:std:iso:15118:-20:CommonMessages}EVPowerProfileEntryListType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EVPowerProfileEntry, PowerScheduleEntryType (1, 2048);
static int decode_iso20_EVPowerProfileEntryListType(exi_bitstream_t* stream, struct iso20_EVPowerProfileEntryListType* EVPowerProfileEntryListType) {
    int grammar_id = 254;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_EVPowerProfileEntryListType(EVPowerProfileEntryListType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 254:
            // Grammar: ID=254; read/write bits=1; START (EVPowerProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVPowerProfileEntry, PowerScheduleEntryType (PowerScheduleEntryType)); next=255
                    // decode: element array
                    if (EVPowerProfileEntryListType->EVPowerProfileEntry.arrayLen < iso20_PowerScheduleEntryType_2048_ARRAY_SIZE)
                    {
                        error = decode_iso20_PowerScheduleEntryType(stream, &EVPowerProfileEntryListType->EVPowerProfileEntry.array[EVPowerProfileEntryListType->EVPowerProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 255;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 255:
            // Grammar: ID=255; read/write bits=2; END Element, LOOP (EVPowerProfileEntry)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case -1 + 1:
                    // Event: LOOP (EVPowerProfileEntry, PowerScheduleEntryType (PowerScheduleEntryType)); next=3
                    // decode: element array
                    if (EVPowerProfileEntryListType->EVPowerProfileEntry.arrayLen < iso20_PowerScheduleEntryType_2048_ARRAY_SIZE)
                    {
                        error = decode_iso20_PowerScheduleEntryType(stream, &EVPowerProfileEntryListType->EVPowerProfileEntry.array[EVPowerProfileEntryListType->EVPowerProfileEntry.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;
                case 0 + 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}Dynamic_SMDTControlMode; type={urn:iso:std:iso:15118:-20:CommonMessages}Dynamic_SMDTControlModeType; base type=; content type=empty;
//          abstract=False; final=False;
static int decode_iso20_Dynamic_SMDTControlModeType(exi_bitstream_t* stream, struct iso20_Dynamic_SMDTControlModeType* Dynamic_SMDTControlModeType) {
    // Element has no particles, so the function just returns zero
    (void)stream;
    (void)Dynamic_SMDTControlModeType;

    return 0;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}EVEnergyOffer; type={urn:iso:std:iso:15118:-20:CommonMessages}EVEnergyOfferType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EVPowerSchedule, EVPowerScheduleType (1, 1); EVAbsolutePriceSchedule, EVAbsolutePriceScheduleType (1, 1);
static int decode_iso20_EVEnergyOfferType(exi_bitstream_t* stream, struct iso20_EVEnergyOfferType* EVEnergyOfferType) {
    int grammar_id = 256;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_EVEnergyOfferType(EVEnergyOfferType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 256:
            // Grammar: ID=256; read/write bits=1; START (EVPowerSchedule)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVPowerSchedule, EVPowerScheduleType (EVPowerScheduleType)); next=257
                    // decode: element
                    error = decode_iso20_EVPowerScheduleType(stream, &EVEnergyOfferType->EVPowerSchedule);
                    if (error == 0)
                    {
                        grammar_id = 257;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 257:
            // Grammar: ID=257; read/write bits=1; START (EVAbsolutePriceSchedule)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVAbsolutePriceSchedule, EVAbsolutePriceScheduleType (EVAbsolutePriceScheduleType)); next=2
                    // decode: element
                    error = decode_iso20_EVAbsolutePriceScheduleType(stream, &EVEnergyOfferType->EVAbsolutePriceSchedule);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}PriceLevelSchedule; type={urn:iso:std:iso:15118:-20:CommonMessages}PriceLevelScheduleType; base type=PriceScheduleType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Id, ID (0, 1); TimeAnchor, unsignedLong (1, 1); PriceScheduleID, numericIDType (1, 1); PriceScheduleDescription, descriptionType (0, 1); NumberOfPriceLevels, unsignedByte (1, 1); PriceLevelScheduleEntries, PriceLevelScheduleEntryListType (1, 1);
static int decode_iso20_PriceLevelScheduleType(exi_bitstream_t* stream, struct iso20_PriceLevelScheduleType* PriceLevelScheduleType) {
    int grammar_id = 258;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_PriceLevelScheduleType(PriceLevelScheduleType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 258:
            // Grammar: ID=258; read/write bits=2; START (Id), START (TimeAnchor)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=259
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &PriceLevelScheduleType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (PriceLevelScheduleType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            PriceLevelScheduleType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, PriceLevelScheduleType->Id.charactersLen, PriceLevelScheduleType->Id.characters, iso20_Id_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    PriceLevelScheduleType->Id_isUsed = 1u;
                    grammar_id = 259;
                    break;
                case 1:
                    // Event: START (TimeAnchor, unsignedLong (nonNegativeInteger)); next=260
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &PriceLevelScheduleType->TimeAnchor);
                    if (error == 0)
                    {
                        grammar_id = 260;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 259:
            // Grammar: ID=259; read/write bits=1; START (TimeAnchor)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TimeAnchor, unsignedLong (nonNegativeInteger)); next=260
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &PriceLevelScheduleType->TimeAnchor);
                    if (error == 0)
                    {
                        grammar_id = 260;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 260:
            // Grammar: ID=260; read/write bits=1; START (PriceScheduleID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PriceScheduleID, numericIDType (unsignedInt)); next=261
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &PriceLevelScheduleType->PriceScheduleID);
                    if (error == 0)
                    {
                        grammar_id = 261;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 261:
            // Grammar: ID=261; read/write bits=2; START (PriceScheduleDescription), START (NumberOfPriceLevels)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PriceScheduleDescription, descriptionType (string)); next=262
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &PriceLevelScheduleType->PriceScheduleDescription.charactersLen);
                            if (error == 0)
                            {
                                if (PriceLevelScheduleType->PriceScheduleDescription.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    PriceLevelScheduleType->PriceScheduleDescription.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, PriceLevelScheduleType->PriceScheduleDescription.charactersLen, PriceLevelScheduleType->PriceScheduleDescription.characters, iso20_PriceScheduleDescription_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                PriceLevelScheduleType->PriceScheduleDescription_isUsed = 1u;
                                grammar_id = 262;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (NumberOfPriceLevels, unsignedByte (unsignedShort)); next=263
                    // decode: unsigned byte (restricted integer)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 8, &value);
                            if (error == 0)
                            {
                                PriceLevelScheduleType->NumberOfPriceLevels = (uint8_t)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 263;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 262:
            // Grammar: ID=262; read/write bits=1; START (NumberOfPriceLevels)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (NumberOfPriceLevels, unsignedByte (unsignedShort)); next=263
                    // decode: unsigned byte (restricted integer)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 8, &value);
                            if (error == 0)
                            {
                                PriceLevelScheduleType->NumberOfPriceLevels = (uint8_t)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 263;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 263:
            // Grammar: ID=263; read/write bits=1; START (PriceLevelScheduleEntries)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PriceLevelScheduleEntries, PriceLevelScheduleEntryListType (PriceLevelScheduleEntryListType)); next=2
                    // decode: element
                    error = decode_iso20_PriceLevelScheduleEntryListType(stream, &PriceLevelScheduleType->PriceLevelScheduleEntries);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}ChargingSchedule; type={urn:iso:std:iso:15118:-20:CommonMessages}ChargingScheduleType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: PowerSchedule, PowerScheduleType (1, 1); AbsolutePriceSchedule, AbsolutePriceScheduleType (0, 1); PriceLevelSchedule, PriceLevelScheduleType (0, 1);
static int decode_iso20_ChargingScheduleType(exi_bitstream_t* stream, struct iso20_ChargingScheduleType* ChargingScheduleType) {
    int grammar_id = 264;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ChargingScheduleType(ChargingScheduleType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 264:
            // Grammar: ID=264; read/write bits=1; START (PowerSchedule)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PowerSchedule, PowerScheduleType (PowerScheduleType)); next=265
                    // decode: element
                    error = decode_iso20_PowerScheduleType(stream, &ChargingScheduleType->PowerSchedule);
                    if (error == 0)
                    {
                        grammar_id = 265;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 265:
            // Grammar: ID=265; read/write bits=2; END Element, START (AbsolutePriceSchedule), START (PriceLevelSchedule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AbsolutePriceSchedule, AbsolutePriceScheduleType (PriceScheduleType)); next=2
                    // decode: element
                    error = decode_iso20_AbsolutePriceScheduleType(stream, &ChargingScheduleType->AbsolutePriceSchedule);
                    if (error == 0)
                    {
                        ChargingScheduleType->AbsolutePriceSchedule_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: START (PriceLevelSchedule, PriceLevelScheduleType (PriceScheduleType)); next=2
                    // decode: element
                    error = decode_iso20_PriceLevelScheduleType(stream, &ChargingScheduleType->PriceLevelSchedule);
                    if (error == 0)
                    {
                        ChargingScheduleType->PriceLevelSchedule_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 2:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}ScheduleTuple; type={urn:iso:std:iso:15118:-20:CommonMessages}ScheduleTupleType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: ScheduleTupleID, numericIDType (1, 1); ChargingSchedule, ChargingScheduleType (1, 1); DischargingSchedule, ChargingScheduleType (0, 1);
static int decode_iso20_ScheduleTupleType(exi_bitstream_t* stream, struct iso20_ScheduleTupleType* ScheduleTupleType) {
    int grammar_id = 266;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ScheduleTupleType(ScheduleTupleType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 266:
            // Grammar: ID=266; read/write bits=1; START (ScheduleTupleID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ScheduleTupleID, numericIDType (unsignedInt)); next=267
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &ScheduleTupleType->ScheduleTupleID);
                    if (error == 0)
                    {
                        grammar_id = 267;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 267:
            // Grammar: ID=267; read/write bits=1; START (ChargingSchedule)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ChargingSchedule, ChargingScheduleType (ChargingScheduleType)); next=268
                    // decode: element
                    error = decode_iso20_ChargingScheduleType(stream, &ScheduleTupleType->ChargingSchedule);
                    if (error == 0)
                    {
                        grammar_id = 268;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 268:
            // Grammar: ID=268; read/write bits=2; END Element, START (DischargingSchedule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DischargingSchedule, ChargingScheduleType (ChargingScheduleType)); next=2
                    // decode: element
                    error = decode_iso20_ChargingScheduleType(stream, &ScheduleTupleType->DischargingSchedule);
                    if (error == 0)
                    {
                        ScheduleTupleType->DischargingSchedule_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}Scheduled_SMDTControlMode; type={urn:iso:std:iso:15118:-20:CommonMessages}Scheduled_SMDTControlModeType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: SelectedScheduleTupleID, numericIDType (1, 1);
static int decode_iso20_Scheduled_SMDTControlModeType(exi_bitstream_t* stream, struct iso20_Scheduled_SMDTControlModeType* Scheduled_SMDTControlModeType) {
    int grammar_id = 269;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_Scheduled_SMDTControlModeType(Scheduled_SMDTControlModeType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 269:
            // Grammar: ID=269; read/write bits=1; START (SelectedScheduleTupleID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedScheduleTupleID, numericIDType (unsignedInt)); next=2
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &Scheduled_SMDTControlModeType->SelectedScheduleTupleID);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_MessageHeaderType(exi_bitstream_t* stream, struct iso20_MessageHeaderType* MessageHeaderType) {
    int grammar_id = 270;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_MessageHeaderType(MessageHeaderType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 270:
            // Grammar: ID=270; read/write bits=1; START (SessionID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SessionID, sessionIDType (hexBinary)); next=271
                    // decode exi type: hexBinary
                    error = decode_exi_type_hex_binary(stream, &MessageHeaderType->SessionID.bytesLen, &MessageHeaderType->SessionID.bytes[0], iso20_sessionIDType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 271;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 271:
            // Grammar: ID=271; read/write bits=1; START (TimeStamp)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TimeStamp, unsignedLong (nonNegativeInteger)); next=272
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &MessageHeaderType->TimeStamp);
                    if (error == 0)
                    {
                        grammar_id = 272;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 272:
            // Grammar: ID=272; read/write bits=2; END Element, START (Signature)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Signature, SignatureType (SignatureType)); next=2
                    // decode: element
                    error = decode_iso20_SignatureType(stream, &MessageHeaderType->Signature);
                    if (error == 0)
                    {
                        MessageHeaderType->Signature_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_SignaturePropertyType(exi_bitstream_t* stream, struct iso20_SignaturePropertyType* SignaturePropertyType) {
    int grammar_id = 273;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_SignaturePropertyType(SignaturePropertyType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 273:
            // Grammar: ID=273; read/write bits=2; START (Id), START (Target)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=274
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &SignaturePropertyType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (SignaturePropertyType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            SignaturePropertyType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, SignaturePropertyType->Id.charactersLen, SignaturePropertyType->Id.characters, iso20_Id_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    SignaturePropertyType->Id_isUsed = 1u;
                    grammar_id = 274;
                    break;
                case 1:
                    // Event: START (Target, anyURI (anyURI)); next=275
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &SignaturePropertyType->Target.charactersLen);
                    if (error == 0)
                    {
                        if (SignaturePropertyType->Target.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            SignaturePropertyType->Target.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, SignaturePropertyType->Target.charactersLen, SignaturePropertyType->Target.characters, iso20_Target_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    grammar_id = 275;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 274:
            // Grammar: ID=274; read/write bits=1; START (Target)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Target, anyURI (anyURI)); next=275
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &SignaturePropertyType->Target.charactersLen);
                    if (error == 0)
                    {
                        if (SignaturePropertyType->Target.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            SignaturePropertyType->Target.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, SignaturePropertyType->Target.charactersLen, SignaturePropertyType->Target.characters, iso20_Target_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    grammar_id = 275;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 275:
            // Grammar: ID=275; read/write bits=1; START (ANY)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ANY, anyType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SignaturePropertyType->ANY.bytesLen, &SignaturePropertyType->ANY.bytes[0], iso20_anyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        SignaturePropertyType->ANY_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}SupportedServiceIDs; type={urn:iso:std:iso:15118:-20:CommonMessages}ServiceIDListType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: ServiceID, serviceIDType (1, 16);
static int decode_iso20_ServiceIDListType(exi_bitstream_t* stream, struct iso20_ServiceIDListType* ServiceIDListType) {
    int grammar_id = 276;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ServiceIDListType(ServiceIDListType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 276:
            // Grammar: ID=276; read/write bits=1; START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=277
                    // decode: unsigned short array
                    if (ServiceIDListType->ServiceID.arrayLen < iso20_serviceIDType_16_ARRAY_SIZE)
                    {
                        error = decode_exi_type_uint16(stream, &ServiceIDListType->ServiceID.array[ServiceIDListType->ServiceID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 277;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 277:
            // Grammar: ID=277; read/write bits=2; END Element, START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=278
                    // decode: unsigned short array
                    if (ServiceIDListType->ServiceID.arrayLen < iso20_serviceIDType_16_ARRAY_SIZE)
                    {
                        error = decode_exi_type_uint16(stream, &ServiceIDListType->ServiceID.array[ServiceIDListType->ServiceID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 278;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 278:
            // Grammar: ID=278; read/write bits=2; END Element, START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=279
                    // decode: unsigned short array
                    if (ServiceIDListType->ServiceID.arrayLen < iso20_serviceIDType_16_ARRAY_SIZE)
                    {
                        error = decode_exi_type_uint16(stream, &ServiceIDListType->ServiceID.array[ServiceIDListType->ServiceID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 279;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 279:
            // Grammar: ID=279; read/write bits=2; END Element, START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=280
                    // decode: unsigned short array
                    if (ServiceIDListType->ServiceID.arrayLen < iso20_serviceIDType_16_ARRAY_SIZE)
                    {
                        error = decode_exi_type_uint16(stream, &ServiceIDListType->ServiceID.array[ServiceIDListType->ServiceID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 280;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 280:
            // Grammar: ID=280; read/write bits=2; END Element, START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=281
                    // decode: unsigned short array
                    if (ServiceIDListType->ServiceID.arrayLen < iso20_serviceIDType_16_ARRAY_SIZE)
                    {
                        error = decode_exi_type_uint16(stream, &ServiceIDListType->ServiceID.array[ServiceIDListType->ServiceID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 281;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 281:
            // Grammar: ID=281; read/write bits=2; END Element, START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=282
                    // decode: unsigned short array
                    if (ServiceIDListType->ServiceID.arrayLen < iso20_serviceIDType_16_ARRAY_SIZE)
                    {
                        error = decode_exi_type_uint16(stream, &ServiceIDListType->ServiceID.array[ServiceIDListType->ServiceID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 282;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 282:
            // Grammar: ID=282; read/write bits=2; END Element, START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=283
                    // decode: unsigned short array
                    if (ServiceIDListType->ServiceID.arrayLen < iso20_serviceIDType_16_ARRAY_SIZE)
                    {
                        error = decode_exi_type_uint16(stream, &ServiceIDListType->ServiceID.array[ServiceIDListType->ServiceID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 283;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 283:
            // Grammar: ID=283; read/write bits=2; END Element, START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=284
                    // decode: unsigned short array
                    if (ServiceIDListType->ServiceID.arrayLen < iso20_serviceIDType_16_ARRAY_SIZE)
                    {
                        error = decode_exi_type_uint16(stream, &ServiceIDListType->ServiceID.array[ServiceIDListType->ServiceID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 284;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 284:
            // Grammar: ID=284; read/write bits=2; END Element, START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=285
                    // decode: unsigned short array
                    if (ServiceIDListType->ServiceID.arrayLen < iso20_serviceIDType_16_ARRAY_SIZE)
                    {
                        error = decode_exi_type_uint16(stream, &ServiceIDListType->ServiceID.array[ServiceIDListType->ServiceID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 285;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 285:
            // Grammar: ID=285; read/write bits=2; END Element, START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=286
                    // decode: unsigned short array
                    if (ServiceIDListType->ServiceID.arrayLen < iso20_serviceIDType_16_ARRAY_SIZE)
                    {
                        error = decode_exi_type_uint16(stream, &ServiceIDListType->ServiceID.array[ServiceIDListType->ServiceID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 286;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 286:
            // Grammar: ID=286; read/write bits=2; END Element, START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=287
                    // decode: unsigned short array
                    if (ServiceIDListType->ServiceID.arrayLen < iso20_serviceIDType_16_ARRAY_SIZE)
                    {
                        error = decode_exi_type_uint16(stream, &ServiceIDListType->ServiceID.array[ServiceIDListType->ServiceID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 287;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 287:
            // Grammar: ID=287; read/write bits=2; END Element, START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=288
                    // decode: unsigned short array
                    if (ServiceIDListType->ServiceID.arrayLen < iso20_serviceIDType_16_ARRAY_SIZE)
                    {
                        error = decode_exi_type_uint16(stream, &ServiceIDListType->ServiceID.array[ServiceIDListType->ServiceID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 288;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 288:
            // Grammar: ID=288; read/write bits=2; END Element, START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=289
                    // decode: unsigned short array
                    if (ServiceIDListType->ServiceID.arrayLen < iso20_serviceIDType_16_ARRAY_SIZE)
                    {
                        error = decode_exi_type_uint16(stream, &ServiceIDListType->ServiceID.array[ServiceIDListType->ServiceID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 289;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 289:
            // Grammar: ID=289; read/write bits=2; END Element, START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=290
                    // decode: unsigned short array
                    if (ServiceIDListType->ServiceID.arrayLen < iso20_serviceIDType_16_ARRAY_SIZE)
                    {
                        error = decode_exi_type_uint16(stream, &ServiceIDListType->ServiceID.array[ServiceIDListType->ServiceID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 290;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 290:
            // Grammar: ID=290; read/write bits=2; END Element, START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=291
                    // decode: unsigned short array
                    if (ServiceIDListType->ServiceID.arrayLen < iso20_serviceIDType_16_ARRAY_SIZE)
                    {
                        error = decode_exi_type_uint16(stream, &ServiceIDListType->ServiceID.array[ServiceIDListType->ServiceID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 291;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 291:
            // Grammar: ID=291; read/write bits=2; END Element, START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=2
                    // decode: unsigned short array
                    if (ServiceIDListType->ServiceID.arrayLen < iso20_serviceIDType_16_ARRAY_SIZE)
                    {
                        error = decode_exi_type_uint16(stream, &ServiceIDListType->ServiceID.array[ServiceIDListType->ServiceID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 2;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}SelectedEnergyTransferService; type={urn:iso:std:iso:15118:-20:CommonMessages}SelectedServiceType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: ServiceID, serviceIDType (1, 1); ParameterSetID, serviceIDType (1, 1);
static int decode_iso20_SelectedServiceType(exi_bitstream_t* stream, struct iso20_SelectedServiceType* SelectedServiceType) {
    int grammar_id = 292;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_SelectedServiceType(SelectedServiceType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 292:
            // Grammar: ID=292; read/write bits=1; START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=293
                    // decode: unsigned short
                    error = decode_exi_type_uint16(stream, &SelectedServiceType->ServiceID);
                    if (error == 0)
                    {
                        grammar_id = 293;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 293:
            // Grammar: ID=293; read/write bits=1; START (ParameterSetID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ParameterSetID, serviceIDType (unsignedShort)); next=2
                    // decode: unsigned short
                    error = decode_exi_type_uint16(stream, &SelectedServiceType->ParameterSetID);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}SignedMeteringData; type={urn:iso:std:iso:15118:-20:CommonMessages}SignedMeteringDataType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (1, 1); SessionID, sessionIDType (1, 1); MeterInfo, MeterInfoType (1, 1); Receipt, ReceiptType (0, 1); Dynamic_SMDTControlMode, Dynamic_SMDTControlModeType (0, 1); Scheduled_SMDTControlMode, Scheduled_SMDTControlModeType (0, 1);
static int decode_iso20_SignedMeteringDataType(exi_bitstream_t* stream, struct iso20_SignedMeteringDataType* SignedMeteringDataType) {
    int grammar_id = 294;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_SignedMeteringDataType(SignedMeteringDataType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 294:
            // Grammar: ID=294; read/write bits=1; START (Id)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=295
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &SignedMeteringDataType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (SignedMeteringDataType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            SignedMeteringDataType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, SignedMeteringDataType->Id.charactersLen, SignedMeteringDataType->Id.characters, iso20_Id_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    grammar_id = 295;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 295:
            // Grammar: ID=295; read/write bits=1; START (SessionID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SessionID, sessionIDType (hexBinary)); next=296
                    // decode exi type: hexBinary
                    error = decode_exi_type_hex_binary(stream, &SignedMeteringDataType->SessionID.bytesLen, &SignedMeteringDataType->SessionID.bytes[0], iso20_sessionIDType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 296;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 296:
            // Grammar: ID=296; read/write bits=1; START (MeterInfo)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (MeterInfo, MeterInfoType (MeterInfoType)); next=297
                    // decode: element
                    error = decode_iso20_MeterInfoType(stream, &SignedMeteringDataType->MeterInfo);
                    if (error == 0)
                    {
                        grammar_id = 297;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 297:
            // Grammar: ID=297; read/write bits=2; START (Receipt), START (Dynamic_SMDTControlMode), START (Scheduled_SMDTControlMode)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Receipt, ReceiptType (ReceiptType)); next=298
                    // decode: element
                    error = decode_iso20_ReceiptType(stream, &SignedMeteringDataType->Receipt);
                    if (error == 0)
                    {
                        SignedMeteringDataType->Receipt_isUsed = 1u;
                        grammar_id = 298;
                    }
                    break;
                case 1:
                    // Event: START (Dynamic_SMDTControlMode, Dynamic_SMDTControlModeType (Dynamic_SMDTControlModeType)); next=2
                    // decode: element
                    error = decode_iso20_Dynamic_SMDTControlModeType(stream, &SignedMeteringDataType->Dynamic_SMDTControlMode);
                    if (error == 0)
                    {
                        SignedMeteringDataType->Dynamic_SMDTControlMode_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 2:
                    // Event: START (Scheduled_SMDTControlMode, Scheduled_SMDTControlModeType (Scheduled_SMDTControlModeType)); next=2
                    // decode: element
                    error = decode_iso20_Scheduled_SMDTControlModeType(stream, &SignedMeteringDataType->Scheduled_SMDTControlMode);
                    if (error == 0)
                    {
                        SignedMeteringDataType->Scheduled_SMDTControlMode_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 298:
            // Grammar: ID=298; read/write bits=2; START (Dynamic_SMDTControlMode), START (Scheduled_SMDTControlMode)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Dynamic_SMDTControlMode, Dynamic_SMDTControlModeType (Dynamic_SMDTControlModeType)); next=2
                    // decode: element
                    error = decode_iso20_Dynamic_SMDTControlModeType(stream, &SignedMeteringDataType->Dynamic_SMDTControlMode);
                    if (error == 0)
                    {
                        SignedMeteringDataType->Dynamic_SMDTControlMode_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: START (Scheduled_SMDTControlMode, Scheduled_SMDTControlModeType (Scheduled_SMDTControlModeType)); next=2
                    // decode: element
                    error = decode_iso20_Scheduled_SMDTControlModeType(stream, &SignedMeteringDataType->Scheduled_SMDTControlMode);
                    if (error == 0)
                    {
                        SignedMeteringDataType->Scheduled_SMDTControlMode_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}OEMProvisioningCertificateChain; type={urn:iso:std:iso:15118:-20:CommonMessages}SignedCertificateChainType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (1, 1); Certificate, certificateType (1, 1); SubCertificates, SubCertificatesType (0, 1);
static int decode_iso20_SignedCertificateChainType(exi_bitstream_t* stream, struct iso20_SignedCertificateChainType* SignedCertificateChainType) {
    int grammar_id = 299;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_SignedCertificateChainType(SignedCertificateChainType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 299:
            // Grammar: ID=299; read/write bits=1; START (Id)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=300
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &SignedCertificateChainType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (SignedCertificateChainType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            SignedCertificateChainType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, SignedCertificateChainType->Id.charactersLen, SignedCertificateChainType->Id.characters, iso20_Id_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    grammar_id = 300;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 300:
            // Grammar: ID=300; read/write bits=1; START (Certificate)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Certificate, certificateType (base64Binary)); next=301
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SignedCertificateChainType->Certificate.bytesLen, &SignedCertificateChainType->Certificate.bytes[0], iso20_certificateType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 301;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 301:
            // Grammar: ID=301; read/write bits=2; END Element, START (SubCertificates)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SubCertificates, SubCertificatesType (SubCertificatesType)); next=2
                    // decode: element
                    error = decode_iso20_SubCertificatesType(stream, &SignedCertificateChainType->SubCertificates);
                    if (error == 0)
                    {
                        SignedCertificateChainType->SubCertificates_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}EIM_AReqAuthorizationMode; type={urn:iso:std:iso:15118:-20:CommonMessages}EIM_AReqAuthorizationModeType; base type=; content type=empty;
//          abstract=False; final=False;
static int decode_iso20_EIM_AReqAuthorizationModeType(exi_bitstream_t* stream, struct iso20_EIM_AReqAuthorizationModeType* EIM_AReqAuthorizationModeType) {
    // Element has no particles, so the function just returns zero
    (void)stream;
    (void)EIM_AReqAuthorizationModeType;

    return 0;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}SelectedVASList; type={urn:iso:std:iso:15118:-20:CommonMessages}SelectedServiceListType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: SelectedService, SelectedServiceType (1, 16);
static int decode_iso20_SelectedServiceListType(exi_bitstream_t* stream, struct iso20_SelectedServiceListType* SelectedServiceListType) {
    int grammar_id = 302;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_SelectedServiceListType(SelectedServiceListType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 302:
            // Grammar: ID=302; read/write bits=1; START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=303
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso20_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso20_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 303;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 303:
            // Grammar: ID=303; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=304
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso20_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso20_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 304;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 304:
            // Grammar: ID=304; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=305
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso20_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso20_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 305;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 305:
            // Grammar: ID=305; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=306
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso20_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso20_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 306;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 306:
            // Grammar: ID=306; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=307
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso20_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso20_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 307;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 307:
            // Grammar: ID=307; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=308
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso20_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso20_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 308;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 308:
            // Grammar: ID=308; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=309
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso20_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso20_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 309;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 309:
            // Grammar: ID=309; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=310
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso20_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso20_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 310;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 310:
            // Grammar: ID=310; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=311
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso20_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso20_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 311;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 311:
            // Grammar: ID=311; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=312
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso20_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso20_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 312;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 312:
            // Grammar: ID=312; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=313
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso20_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso20_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 313;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 313:
            // Grammar: ID=313; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=314
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso20_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso20_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 314;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 314:
            // Grammar: ID=314; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=315
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso20_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso20_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 315;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 315:
            // Grammar: ID=315; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=316
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso20_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso20_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 316;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 316:
            // Grammar: ID=316; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=317
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso20_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso20_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 317;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 317:
            // Grammar: ID=317; read/write bits=2; END Element, START (SelectedService)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedService, SelectedServiceType (SelectedServiceType)); next=2
                    // decode: element array
                    if (SelectedServiceListType->SelectedService.arrayLen < iso20_SelectedServiceType_16_ARRAY_SIZE)
                    {
                        error = decode_iso20_SelectedServiceType(stream, &SelectedServiceListType->SelectedService.array[SelectedServiceListType->SelectedService.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 2;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}Dynamic_SEReqControlMode; type={urn:iso:std:iso:15118:-20:CommonMessages}Dynamic_SEReqControlModeType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: DepartureTime, unsignedInt (1, 1); MinimumSOC, percentValueType (0, 1); TargetSOC, percentValueType (0, 1); EVTargetEnergyRequest, RationalNumberType (1, 1); EVMaximumEnergyRequest, RationalNumberType (1, 1); EVMinimumEnergyRequest, RationalNumberType (1, 1); EVMaximumV2XEnergyRequest, RationalNumberType (0, 1); EVMinimumV2XEnergyRequest, RationalNumberType (0, 1);
static int decode_iso20_Dynamic_SEReqControlModeType(exi_bitstream_t* stream, struct iso20_Dynamic_SEReqControlModeType* Dynamic_SEReqControlModeType) {
    int grammar_id = 318;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_Dynamic_SEReqControlModeType(Dynamic_SEReqControlModeType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 318:
            // Grammar: ID=318; read/write bits=1; START (DepartureTime)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DepartureTime, unsignedInt (unsignedLong)); next=319
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &Dynamic_SEReqControlModeType->DepartureTime);
                    if (error == 0)
                    {
                        grammar_id = 319;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 319:
            // Grammar: ID=319; read/write bits=2; START (MinimumSOC), START (TargetSOC), START (EVTargetEnergyRequest)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (MinimumSOC, percentValueType (byte)); next=320
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 7, &value);
                            if (error == 0)
                            {
                                Dynamic_SEReqControlModeType->MinimumSOC = (int8_t)value;
                                Dynamic_SEReqControlModeType->MinimumSOC_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 320;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (TargetSOC, percentValueType (byte)); next=321
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 7, &value);
                            if (error == 0)
                            {
                                Dynamic_SEReqControlModeType->TargetSOC = (int8_t)value;
                                Dynamic_SEReqControlModeType->TargetSOC_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 321;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: START (EVTargetEnergyRequest, RationalNumberType (RationalNumberType)); next=322
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &Dynamic_SEReqControlModeType->EVTargetEnergyRequest);
                    if (error == 0)
                    {
                        grammar_id = 322;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 320:
            // Grammar: ID=320; read/write bits=2; START (TargetSOC), START (EVTargetEnergyRequest)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TargetSOC, percentValueType (byte)); next=321
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 7, &value);
                            if (error == 0)
                            {
                                Dynamic_SEReqControlModeType->TargetSOC = (int8_t)value;
                                Dynamic_SEReqControlModeType->TargetSOC_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 321;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (EVTargetEnergyRequest, RationalNumberType (RationalNumberType)); next=322
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &Dynamic_SEReqControlModeType->EVTargetEnergyRequest);
                    if (error == 0)
                    {
                        grammar_id = 322;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 321:
            // Grammar: ID=321; read/write bits=1; START (EVTargetEnergyRequest)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVTargetEnergyRequest, RationalNumberType (RationalNumberType)); next=322
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &Dynamic_SEReqControlModeType->EVTargetEnergyRequest);
                    if (error == 0)
                    {
                        grammar_id = 322;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 322:
            // Grammar: ID=322; read/write bits=1; START (EVMaximumEnergyRequest)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVMaximumEnergyRequest, RationalNumberType (RationalNumberType)); next=323
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &Dynamic_SEReqControlModeType->EVMaximumEnergyRequest);
                    if (error == 0)
                    {
                        grammar_id = 323;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 323:
            // Grammar: ID=323; read/write bits=1; START (EVMinimumEnergyRequest)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVMinimumEnergyRequest, RationalNumberType (RationalNumberType)); next=324
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &Dynamic_SEReqControlModeType->EVMinimumEnergyRequest);
                    if (error == 0)
                    {
                        grammar_id = 324;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 324:
            // Grammar: ID=324; read/write bits=2; END Element, START (EVMaximumV2XEnergyRequest), START (EVMinimumV2XEnergyRequest)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVMaximumV2XEnergyRequest, RationalNumberType (RationalNumberType)); next=325
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &Dynamic_SEReqControlModeType->EVMaximumV2XEnergyRequest);
                    if (error == 0)
                    {
                        Dynamic_SEReqControlModeType->EVMaximumV2XEnergyRequest_isUsed = 1u;
                        grammar_id = 325;
                    }
                    break;
                case 1:
                    // Event: START (EVMinimumV2XEnergyRequest, RationalNumberType (RationalNumberType)); next=2
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &Dynamic_SEReqControlModeType->EVMinimumV2XEnergyRequest);
                    if (error == 0)
                    {
                        Dynamic_SEReqControlModeType->EVMinimumV2XEnergyRequest_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 2:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 325:
            // Grammar: ID=325; read/write bits=2; END Element, START (EVMinimumV2XEnergyRequest)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVMinimumV2XEnergyRequest, RationalNumberType (RationalNumberType)); next=2
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &Dynamic_SEReqControlModeType->EVMinimumV2XEnergyRequest);
                    if (error == 0)
                    {
                        Dynamic_SEReqControlModeType->EVMinimumV2XEnergyRequest_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}EVSEStatus; type={urn:iso:std:iso:15118:-20:CommonTypes}EVSEStatusType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: NotificationMaxDelay, unsignedShort (1, 1); EVSENotification, evseNotificationType (1, 1);
static int decode_iso20_EVSEStatusType(exi_bitstream_t* stream, struct iso20_EVSEStatusType* EVSEStatusType) {
    int grammar_id = 326;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_EVSEStatusType(EVSEStatusType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 326:
            // Grammar: ID=326; read/write bits=1; START (NotificationMaxDelay)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (NotificationMaxDelay, unsignedShort (unsignedInt)); next=327
                    // decode: unsigned short
                    error = decode_exi_type_uint16(stream, &EVSEStatusType->NotificationMaxDelay);
                    if (error == 0)
                    {
                        grammar_id = 327;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 327:
            // Grammar: ID=327; read/write bits=1; START (EVSENotification)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSENotification, evseNotificationType (string)); next=2
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 3, &value);
                            if (error == 0)
                            {
                                EVSEStatusType->EVSENotification = (iso20_evseNotificationType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}ListOfRootCertificateIDs; type={urn:iso:std:iso:15118:-20:CommonTypes}ListOfRootCertificateIDsType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: RootCertificateID, X509IssuerSerialType (1, 20);
static int decode_iso20_ListOfRootCertificateIDsType(exi_bitstream_t* stream, struct iso20_ListOfRootCertificateIDsType* ListOfRootCertificateIDsType) {
    int grammar_id = 328;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ListOfRootCertificateIDsType(ListOfRootCertificateIDsType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 328:
            // Grammar: ID=328; read/write bits=1; START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=329
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso20_X509IssuerSerialType_20_ARRAY_SIZE)
                    {
                        error = decode_iso20_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 329;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 329:
            // Grammar: ID=329; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=330
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso20_X509IssuerSerialType_20_ARRAY_SIZE)
                    {
                        error = decode_iso20_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 330;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 330:
            // Grammar: ID=330; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=331
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso20_X509IssuerSerialType_20_ARRAY_SIZE)
                    {
                        error = decode_iso20_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 331;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 331:
            // Grammar: ID=331; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=332
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso20_X509IssuerSerialType_20_ARRAY_SIZE)
                    {
                        error = decode_iso20_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 332;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 332:
            // Grammar: ID=332; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=333
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso20_X509IssuerSerialType_20_ARRAY_SIZE)
                    {
                        error = decode_iso20_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 333;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 333:
            // Grammar: ID=333; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=334
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso20_X509IssuerSerialType_20_ARRAY_SIZE)
                    {
                        error = decode_iso20_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 334;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 334:
            // Grammar: ID=334; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=335
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso20_X509IssuerSerialType_20_ARRAY_SIZE)
                    {
                        error = decode_iso20_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 335;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 335:
            // Grammar: ID=335; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=336
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso20_X509IssuerSerialType_20_ARRAY_SIZE)
                    {
                        error = decode_iso20_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 336;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 336:
            // Grammar: ID=336; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=337
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso20_X509IssuerSerialType_20_ARRAY_SIZE)
                    {
                        error = decode_iso20_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 337;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 337:
            // Grammar: ID=337; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=338
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso20_X509IssuerSerialType_20_ARRAY_SIZE)
                    {
                        error = decode_iso20_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 338;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 338:
            // Grammar: ID=338; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=339
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso20_X509IssuerSerialType_20_ARRAY_SIZE)
                    {
                        error = decode_iso20_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 339;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 339:
            // Grammar: ID=339; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=340
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso20_X509IssuerSerialType_20_ARRAY_SIZE)
                    {
                        error = decode_iso20_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 340;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 340:
            // Grammar: ID=340; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=341
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso20_X509IssuerSerialType_20_ARRAY_SIZE)
                    {
                        error = decode_iso20_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 341;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 341:
            // Grammar: ID=341; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=342
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso20_X509IssuerSerialType_20_ARRAY_SIZE)
                    {
                        error = decode_iso20_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 342;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 342:
            // Grammar: ID=342; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=343
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso20_X509IssuerSerialType_20_ARRAY_SIZE)
                    {
                        error = decode_iso20_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 343;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 343:
            // Grammar: ID=343; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=344
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso20_X509IssuerSerialType_20_ARRAY_SIZE)
                    {
                        error = decode_iso20_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 344;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 344:
            // Grammar: ID=344; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=345
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso20_X509IssuerSerialType_20_ARRAY_SIZE)
                    {
                        error = decode_iso20_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 345;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 345:
            // Grammar: ID=345; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=346
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso20_X509IssuerSerialType_20_ARRAY_SIZE)
                    {
                        error = decode_iso20_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 346;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 346:
            // Grammar: ID=346; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=347
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso20_X509IssuerSerialType_20_ARRAY_SIZE)
                    {
                        error = decode_iso20_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 347;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 347:
            // Grammar: ID=347; read/write bits=2; END Element, START (RootCertificateID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RootCertificateID, X509IssuerSerialType (X509IssuerSerialType)); next=2
                    // decode: element array
                    if (ListOfRootCertificateIDsType->RootCertificateID.arrayLen < iso20_X509IssuerSerialType_20_ARRAY_SIZE)
                    {
                        error = decode_iso20_X509IssuerSerialType(stream, &ListOfRootCertificateIDsType->RootCertificateID.array[ListOfRootCertificateIDsType->RootCertificateID.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 2;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}PnC_AReqAuthorizationMode; type={urn:iso:std:iso:15118:-20:CommonMessages}PnC_AReqAuthorizationModeType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (1, 1); GenChallenge, genChallengeType (1, 1); ContractCertificateChain, ContractCertificateChainType (1, 1);
static int decode_iso20_PnC_AReqAuthorizationModeType(exi_bitstream_t* stream, struct iso20_PnC_AReqAuthorizationModeType* PnC_AReqAuthorizationModeType) {
    int grammar_id = 348;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_PnC_AReqAuthorizationModeType(PnC_AReqAuthorizationModeType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 348:
            // Grammar: ID=348; read/write bits=1; START (Id)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=349
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &PnC_AReqAuthorizationModeType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (PnC_AReqAuthorizationModeType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            PnC_AReqAuthorizationModeType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, PnC_AReqAuthorizationModeType->Id.charactersLen, PnC_AReqAuthorizationModeType->Id.characters, iso20_Id_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    grammar_id = 349;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 349:
            // Grammar: ID=349; read/write bits=1; START (GenChallenge)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (GenChallenge, genChallengeType (base64Binary)); next=350
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PnC_AReqAuthorizationModeType->GenChallenge.bytesLen, &PnC_AReqAuthorizationModeType->GenChallenge.bytes[0], iso20_genChallengeType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 350;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 350:
            // Grammar: ID=350; read/write bits=1; START (ContractCertificateChain)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ContractCertificateChain, ContractCertificateChainType (ContractCertificateChainType)); next=2
                    // decode: element
                    error = decode_iso20_ContractCertificateChainType(stream, &PnC_AReqAuthorizationModeType->ContractCertificateChain);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}EnergyTransferServiceList; type={urn:iso:std:iso:15118:-20:CommonMessages}ServiceListType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Service, ServiceType (1, 8);
static int decode_iso20_ServiceListType(exi_bitstream_t* stream, struct iso20_ServiceListType* ServiceListType) {
    int grammar_id = 351;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ServiceListType(ServiceListType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 351:
            // Grammar: ID=351; read/write bits=1; START (Service)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Service, ServiceType (ServiceType)); next=352
                    // decode: element array
                    if (ServiceListType->Service.arrayLen < iso20_ServiceType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_ServiceType(stream, &ServiceListType->Service.array[ServiceListType->Service.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 352;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 352:
            // Grammar: ID=352; read/write bits=2; END Element, START (Service)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Service, ServiceType (ServiceType)); next=353
                    // decode: element array
                    if (ServiceListType->Service.arrayLen < iso20_ServiceType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_ServiceType(stream, &ServiceListType->Service.array[ServiceListType->Service.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 353;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 353:
            // Grammar: ID=353; read/write bits=2; END Element, START (Service)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Service, ServiceType (ServiceType)); next=354
                    // decode: element array
                    if (ServiceListType->Service.arrayLen < iso20_ServiceType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_ServiceType(stream, &ServiceListType->Service.array[ServiceListType->Service.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 354;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 354:
            // Grammar: ID=354; read/write bits=2; END Element, START (Service)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Service, ServiceType (ServiceType)); next=355
                    // decode: element array
                    if (ServiceListType->Service.arrayLen < iso20_ServiceType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_ServiceType(stream, &ServiceListType->Service.array[ServiceListType->Service.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 355;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 355:
            // Grammar: ID=355; read/write bits=2; END Element, START (Service)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Service, ServiceType (ServiceType)); next=356
                    // decode: element array
                    if (ServiceListType->Service.arrayLen < iso20_ServiceType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_ServiceType(stream, &ServiceListType->Service.array[ServiceListType->Service.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 356;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 356:
            // Grammar: ID=356; read/write bits=2; END Element, START (Service)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Service, ServiceType (ServiceType)); next=357
                    // decode: element array
                    if (ServiceListType->Service.arrayLen < iso20_ServiceType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_ServiceType(stream, &ServiceListType->Service.array[ServiceListType->Service.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 357;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 357:
            // Grammar: ID=357; read/write bits=2; END Element, START (Service)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Service, ServiceType (ServiceType)); next=358
                    // decode: element array
                    if (ServiceListType->Service.arrayLen < iso20_ServiceType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_ServiceType(stream, &ServiceListType->Service.array[ServiceListType->Service.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 358;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 358:
            // Grammar: ID=358; read/write bits=2; END Element, START (Service)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Service, ServiceType (ServiceType)); next=2
                    // decode: element array
                    if (ServiceListType->Service.arrayLen < iso20_ServiceType_8_ARRAY_SIZE)
                    {
                        error = decode_iso20_ServiceType(stream, &ServiceListType->Service.array[ServiceListType->Service.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 2;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}ServiceParameterList; type={urn:iso:std:iso:15118:-20:CommonMessages}ServiceParameterListType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: ParameterSet, ParameterSetType (1, 32);
static int decode_iso20_ServiceParameterListType(exi_bitstream_t* stream, struct iso20_ServiceParameterListType* ServiceParameterListType) {
    int grammar_id = 359;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ServiceParameterListType(ServiceParameterListType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 359:
            // Grammar: ID=359; read/write bits=1; START (ParameterSet)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ParameterSet, ParameterSetType (ParameterSetType)); next=360
                    // decode: element array
                    if (ServiceParameterListType->ParameterSet.arrayLen < iso20_ParameterSetType_32_ARRAY_SIZE)
                    {
                        error = decode_iso20_ParameterSetType(stream, &ServiceParameterListType->ParameterSet.array[ServiceParameterListType->ParameterSet.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 360;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 360:
            // Grammar: ID=360; read/write bits=2; END Element, LOOP (ParameterSet)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case -1:
                    // Event: LOOP (ParameterSet, ParameterSetType (ParameterSetType)); next=3
                    // decode: element array
                    if (ServiceParameterListType->ParameterSet.arrayLen < iso20_ParameterSetType_32_ARRAY_SIZE)
                    {
                        error = decode_iso20_ParameterSetType(stream, &ServiceParameterListType->ParameterSet.array[ServiceParameterListType->ParameterSet.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 3;
                    break;
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}Scheduled_SEReqControlMode; type={urn:iso:std:iso:15118:-20:CommonMessages}Scheduled_SEReqControlModeType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: DepartureTime, unsignedInt (0, 1); EVTargetEnergyRequest, RationalNumberType (0, 1); EVMaximumEnergyRequest, RationalNumberType (0, 1); EVMinimumEnergyRequest, RationalNumberType (0, 1); EVEnergyOffer, EVEnergyOfferType (0, 1);
static int decode_iso20_Scheduled_SEReqControlModeType(exi_bitstream_t* stream, struct iso20_Scheduled_SEReqControlModeType* Scheduled_SEReqControlModeType) {
    int grammar_id = 361;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_Scheduled_SEReqControlModeType(Scheduled_SEReqControlModeType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 361:
            // Grammar: ID=361; read/write bits=3; END Element, START (DepartureTime), START (EVTargetEnergyRequest), START (EVMaximumEnergyRequest), START (EVMinimumEnergyRequest), START (EVEnergyOffer)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DepartureTime, unsignedInt (unsignedLong)); next=362
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &Scheduled_SEReqControlModeType->DepartureTime);
                    if (error == 0)
                    {
                        Scheduled_SEReqControlModeType->DepartureTime_isUsed = 1u;
                        grammar_id = 362;
                    }
                    break;
                case 1:
                    // Event: START (EVTargetEnergyRequest, RationalNumberType (RationalNumberType)); next=363
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &Scheduled_SEReqControlModeType->EVTargetEnergyRequest);
                    if (error == 0)
                    {
                        Scheduled_SEReqControlModeType->EVTargetEnergyRequest_isUsed = 1u;
                        grammar_id = 363;
                    }
                    break;
                case 2:
                    // Event: START (EVMaximumEnergyRequest, RationalNumberType (RationalNumberType)); next=364
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &Scheduled_SEReqControlModeType->EVMaximumEnergyRequest);
                    if (error == 0)
                    {
                        Scheduled_SEReqControlModeType->EVMaximumEnergyRequest_isUsed = 1u;
                        grammar_id = 364;
                    }
                    break;
                case 3:
                    // Event: START (EVMinimumEnergyRequest, RationalNumberType (RationalNumberType)); next=365
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &Scheduled_SEReqControlModeType->EVMinimumEnergyRequest);
                    if (error == 0)
                    {
                        Scheduled_SEReqControlModeType->EVMinimumEnergyRequest_isUsed = 1u;
                        grammar_id = 365;
                    }
                    break;
                case 4:
                    // Event: START (EVEnergyOffer, EVEnergyOfferType (EVEnergyOfferType)); next=2
                    // decode: element
                    error = decode_iso20_EVEnergyOfferType(stream, &Scheduled_SEReqControlModeType->EVEnergyOffer);
                    if (error == 0)
                    {
                        Scheduled_SEReqControlModeType->EVEnergyOffer_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 5:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 362:
            // Grammar: ID=362; read/write bits=3; END Element, START (EVTargetEnergyRequest), START (EVMaximumEnergyRequest), START (EVMinimumEnergyRequest), START (EVEnergyOffer)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVTargetEnergyRequest, RationalNumberType (RationalNumberType)); next=363
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &Scheduled_SEReqControlModeType->EVTargetEnergyRequest);
                    if (error == 0)
                    {
                        Scheduled_SEReqControlModeType->EVTargetEnergyRequest_isUsed = 1u;
                        grammar_id = 363;
                    }
                    break;
                case 1:
                    // Event: START (EVMaximumEnergyRequest, RationalNumberType (RationalNumberType)); next=364
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &Scheduled_SEReqControlModeType->EVMaximumEnergyRequest);
                    if (error == 0)
                    {
                        Scheduled_SEReqControlModeType->EVMaximumEnergyRequest_isUsed = 1u;
                        grammar_id = 364;
                    }
                    break;
                case 2:
                    // Event: START (EVMinimumEnergyRequest, RationalNumberType (RationalNumberType)); next=365
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &Scheduled_SEReqControlModeType->EVMinimumEnergyRequest);
                    if (error == 0)
                    {
                        Scheduled_SEReqControlModeType->EVMinimumEnergyRequest_isUsed = 1u;
                        grammar_id = 365;
                    }
                    break;
                case 3:
                    // Event: START (EVEnergyOffer, EVEnergyOfferType (EVEnergyOfferType)); next=2
                    // decode: element
                    error = decode_iso20_EVEnergyOfferType(stream, &Scheduled_SEReqControlModeType->EVEnergyOffer);
                    if (error == 0)
                    {
                        Scheduled_SEReqControlModeType->EVEnergyOffer_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 4:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 363:
            // Grammar: ID=363; read/write bits=3; END Element, START (EVMaximumEnergyRequest), START (EVMinimumEnergyRequest), START (EVEnergyOffer)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVMaximumEnergyRequest, RationalNumberType (RationalNumberType)); next=364
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &Scheduled_SEReqControlModeType->EVMaximumEnergyRequest);
                    if (error == 0)
                    {
                        Scheduled_SEReqControlModeType->EVMaximumEnergyRequest_isUsed = 1u;
                        grammar_id = 364;
                    }
                    break;
                case 1:
                    // Event: START (EVMinimumEnergyRequest, RationalNumberType (RationalNumberType)); next=365
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &Scheduled_SEReqControlModeType->EVMinimumEnergyRequest);
                    if (error == 0)
                    {
                        Scheduled_SEReqControlModeType->EVMinimumEnergyRequest_isUsed = 1u;
                        grammar_id = 365;
                    }
                    break;
                case 2:
                    // Event: START (EVEnergyOffer, EVEnergyOfferType (EVEnergyOfferType)); next=2
                    // decode: element
                    error = decode_iso20_EVEnergyOfferType(stream, &Scheduled_SEReqControlModeType->EVEnergyOffer);
                    if (error == 0)
                    {
                        Scheduled_SEReqControlModeType->EVEnergyOffer_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 3:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 364:
            // Grammar: ID=364; read/write bits=2; END Element, START (EVMinimumEnergyRequest), START (EVEnergyOffer)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVMinimumEnergyRequest, RationalNumberType (RationalNumberType)); next=365
                    // decode: element
                    error = decode_iso20_RationalNumberType(stream, &Scheduled_SEReqControlModeType->EVMinimumEnergyRequest);
                    if (error == 0)
                    {
                        Scheduled_SEReqControlModeType->EVMinimumEnergyRequest_isUsed = 1u;
                        grammar_id = 365;
                    }
                    break;
                case 1:
                    // Event: START (EVEnergyOffer, EVEnergyOfferType (EVEnergyOfferType)); next=2
                    // decode: element
                    error = decode_iso20_EVEnergyOfferType(stream, &Scheduled_SEReqControlModeType->EVEnergyOffer);
                    if (error == 0)
                    {
                        Scheduled_SEReqControlModeType->EVEnergyOffer_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 2:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 365:
            // Grammar: ID=365; read/write bits=2; END Element, START (EVEnergyOffer)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVEnergyOffer, EVEnergyOfferType (EVEnergyOfferType)); next=2
                    // decode: element
                    error = decode_iso20_EVEnergyOfferType(stream, &Scheduled_SEReqControlModeType->EVEnergyOffer);
                    if (error == 0)
                    {
                        Scheduled_SEReqControlModeType->EVEnergyOffer_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}EVPowerProfile; type={urn:iso:std:iso:15118:-20:CommonMessages}EVPowerProfileType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: TimeAnchor, unsignedLong (1, 1); Dynamic_EVPPTControlMode, Dynamic_EVPPTControlModeType (0, 1); Scheduled_EVPPTControlMode, Scheduled_EVPPTControlModeType (0, 1); EVPowerProfileEntries, EVPowerProfileEntryListType (1, 1);
static int decode_iso20_EVPowerProfileType(exi_bitstream_t* stream, struct iso20_EVPowerProfileType* EVPowerProfileType) {
    int grammar_id = 366;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_EVPowerProfileType(EVPowerProfileType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 366:
            // Grammar: ID=366; read/write bits=1; START (TimeAnchor)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TimeAnchor, unsignedLong (nonNegativeInteger)); next=367
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &EVPowerProfileType->TimeAnchor);
                    if (error == 0)
                    {
                        grammar_id = 367;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 367:
            // Grammar: ID=367; read/write bits=2; START (Dynamic_EVPPTControlMode), START (Scheduled_EVPPTControlMode)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Dynamic_EVPPTControlMode, Dynamic_EVPPTControlModeType (Dynamic_EVPPTControlModeType)); next=368
                    // decode: element
                    error = decode_iso20_Dynamic_EVPPTControlModeType(stream, &EVPowerProfileType->Dynamic_EVPPTControlMode);
                    if (error == 0)
                    {
                        EVPowerProfileType->Dynamic_EVPPTControlMode_isUsed = 1u;
                        grammar_id = 368;
                    }
                    break;
                case 1:
                    // Event: START (Scheduled_EVPPTControlMode, Scheduled_EVPPTControlModeType (Scheduled_EVPPTControlModeType)); next=368
                    // decode: element
                    error = decode_iso20_Scheduled_EVPPTControlModeType(stream, &EVPowerProfileType->Scheduled_EVPPTControlMode);
                    if (error == 0)
                    {
                        EVPowerProfileType->Scheduled_EVPPTControlMode_isUsed = 1u;
                        grammar_id = 368;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 368:
            // Grammar: ID=368; read/write bits=1; START (EVPowerProfileEntries)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVPowerProfileEntries, EVPowerProfileEntryListType (EVPowerProfileEntryListType)); next=2
                    // decode: element
                    error = decode_iso20_EVPowerProfileEntryListType(stream, &EVPowerProfileType->EVPowerProfileEntries);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}CPSCertificateChain; type={urn:iso:std:iso:15118:-20:CommonMessages}CertificateChainType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Certificate, certificateType (1, 1); SubCertificates, SubCertificatesType (0, 1);
static int decode_iso20_CertificateChainType(exi_bitstream_t* stream, struct iso20_CertificateChainType* CertificateChainType) {
    int grammar_id = 369;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_CertificateChainType(CertificateChainType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 369:
            // Grammar: ID=369; read/write bits=1; START (Certificate)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Certificate, certificateType (base64Binary)); next=370
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &CertificateChainType->Certificate.bytesLen, &CertificateChainType->Certificate.bytes[0], iso20_certificateType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 370;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 370:
            // Grammar: ID=370; read/write bits=2; END Element, START (SubCertificates)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SubCertificates, SubCertificatesType (SubCertificatesType)); next=2
                    // decode: element
                    error = decode_iso20_SubCertificatesType(stream, &CertificateChainType->SubCertificates);
                    if (error == 0)
                    {
                        CertificateChainType->SubCertificates_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}EIM_ASResAuthorizationMode; type={urn:iso:std:iso:15118:-20:CommonMessages}EIM_ASResAuthorizationModeType; base type=; content type=empty;
//          abstract=False; final=False;
static int decode_iso20_EIM_ASResAuthorizationModeType(exi_bitstream_t* stream, struct iso20_EIM_ASResAuthorizationModeType* EIM_ASResAuthorizationModeType) {
    // Element has no particles, so the function just returns zero
    (void)stream;
    (void)EIM_ASResAuthorizationModeType;

    return 0;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}Dynamic_SEResControlMode; type={urn:iso:std:iso:15118:-20:CommonMessages}Dynamic_SEResControlModeType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: DepartureTime, unsignedInt (0, 1); MinimumSOC, percentValueType (0, 1); TargetSOC, percentValueType (0, 1); AbsolutePriceSchedule, AbsolutePriceScheduleType (0, 1); PriceLevelSchedule, PriceLevelScheduleType (0, 1);
static int decode_iso20_Dynamic_SEResControlModeType(exi_bitstream_t* stream, struct iso20_Dynamic_SEResControlModeType* Dynamic_SEResControlModeType) {
    int grammar_id = 371;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_Dynamic_SEResControlModeType(Dynamic_SEResControlModeType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 371:
            // Grammar: ID=371; read/write bits=3; END Element, START (DepartureTime), START (MinimumSOC), START (TargetSOC), START (AbsolutePriceSchedule), START (PriceLevelSchedule)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DepartureTime, unsignedInt (unsignedLong)); next=372
                    // decode: unsigned int
                    error = decode_exi_type_uint32(stream, &Dynamic_SEResControlModeType->DepartureTime);
                    if (error == 0)
                    {
                        Dynamic_SEResControlModeType->DepartureTime_isUsed = 1u;
                        grammar_id = 372;
                    }
                    break;
                case 1:
                    // Event: START (MinimumSOC, percentValueType (byte)); next=373
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 7, &value);
                            if (error == 0)
                            {
                                Dynamic_SEResControlModeType->MinimumSOC = (int8_t)value;
                                Dynamic_SEResControlModeType->MinimumSOC_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 373;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: START (TargetSOC, percentValueType (byte)); next=374
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 7, &value);
                            if (error == 0)
                            {
                                Dynamic_SEResControlModeType->TargetSOC = (int8_t)value;
                                Dynamic_SEResControlModeType->TargetSOC_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 374;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 3:
                    // Event: START (AbsolutePriceSchedule, AbsolutePriceScheduleType (PriceScheduleType)); next=2
                    // decode: element
                    error = decode_iso20_AbsolutePriceScheduleType(stream, &Dynamic_SEResControlModeType->AbsolutePriceSchedule);
                    if (error == 0)
                    {
                        Dynamic_SEResControlModeType->AbsolutePriceSchedule_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 4:
                    // Event: START (PriceLevelSchedule, PriceLevelScheduleType (PriceScheduleType)); next=2
                    // decode: element
                    error = decode_iso20_PriceLevelScheduleType(stream, &Dynamic_SEResControlModeType->PriceLevelSchedule);
                    if (error == 0)
                    {
                        Dynamic_SEResControlModeType->PriceLevelSchedule_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 5:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 372:
            // Grammar: ID=372; read/write bits=3; END Element, START (MinimumSOC), START (TargetSOC), START (AbsolutePriceSchedule), START (PriceLevelSchedule)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (MinimumSOC, percentValueType (byte)); next=373
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 7, &value);
                            if (error == 0)
                            {
                                Dynamic_SEResControlModeType->MinimumSOC = (int8_t)value;
                                Dynamic_SEResControlModeType->MinimumSOC_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 373;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (TargetSOC, percentValueType (byte)); next=374
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 7, &value);
                            if (error == 0)
                            {
                                Dynamic_SEResControlModeType->TargetSOC = (int8_t)value;
                                Dynamic_SEResControlModeType->TargetSOC_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 374;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: START (AbsolutePriceSchedule, AbsolutePriceScheduleType (PriceScheduleType)); next=2
                    // decode: element
                    error = decode_iso20_AbsolutePriceScheduleType(stream, &Dynamic_SEResControlModeType->AbsolutePriceSchedule);
                    if (error == 0)
                    {
                        Dynamic_SEResControlModeType->AbsolutePriceSchedule_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 3:
                    // Event: START (PriceLevelSchedule, PriceLevelScheduleType (PriceScheduleType)); next=2
                    // decode: element
                    error = decode_iso20_PriceLevelScheduleType(stream, &Dynamic_SEResControlModeType->PriceLevelSchedule);
                    if (error == 0)
                    {
                        Dynamic_SEResControlModeType->PriceLevelSchedule_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 4:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 373:
            // Grammar: ID=373; read/write bits=3; END Element, START (TargetSOC), START (AbsolutePriceSchedule), START (PriceLevelSchedule)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TargetSOC, percentValueType (byte)); next=374
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 7, &value);
                            if (error == 0)
                            {
                                Dynamic_SEResControlModeType->TargetSOC = (int8_t)value;
                                Dynamic_SEResControlModeType->TargetSOC_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 374;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (AbsolutePriceSchedule, AbsolutePriceScheduleType (PriceScheduleType)); next=2
                    // decode: element
                    error = decode_iso20_AbsolutePriceScheduleType(stream, &Dynamic_SEResControlModeType->AbsolutePriceSchedule);
                    if (error == 0)
                    {
                        Dynamic_SEResControlModeType->AbsolutePriceSchedule_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 2:
                    // Event: START (PriceLevelSchedule, PriceLevelScheduleType (PriceScheduleType)); next=2
                    // decode: element
                    error = decode_iso20_PriceLevelScheduleType(stream, &Dynamic_SEResControlModeType->PriceLevelSchedule);
                    if (error == 0)
                    {
                        Dynamic_SEResControlModeType->PriceLevelSchedule_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 3:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 374:
            // Grammar: ID=374; read/write bits=2; END Element, START (AbsolutePriceSchedule), START (PriceLevelSchedule)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AbsolutePriceSchedule, AbsolutePriceScheduleType (PriceScheduleType)); next=2
                    // decode: element
                    error = decode_iso20_AbsolutePriceScheduleType(stream, &Dynamic_SEResControlModeType->AbsolutePriceSchedule);
                    if (error == 0)
                    {
                        Dynamic_SEResControlModeType->AbsolutePriceSchedule_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: START (PriceLevelSchedule, PriceLevelScheduleType (PriceScheduleType)); next=2
                    // decode: element
                    error = decode_iso20_PriceLevelScheduleType(stream, &Dynamic_SEResControlModeType->PriceLevelSchedule);
                    if (error == 0)
                    {
                        Dynamic_SEResControlModeType->PriceLevelSchedule_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 2:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}PrioritizedEMAIDs; type={urn:iso:std:iso:15118:-20:CommonMessages}EMAIDListType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: EMAID, identifierType (1, 8);
static int decode_iso20_EMAIDListType(exi_bitstream_t* stream, struct iso20_EMAIDListType* EMAIDListType) {
    int grammar_id = 375;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_EMAIDListType(EMAIDListType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 375:
            // Grammar: ID=375; read/write bits=1; START (EMAID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EMAID, identifierType (string)); next=376
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &EMAIDListType->EMAID.charactersLen);
                            if (error == 0)
                            {
                                if (EMAIDListType->EMAID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    EMAIDListType->EMAID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, EMAIDListType->EMAID.charactersLen, EMAIDListType->EMAID.characters, iso20_EMAID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 376;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 376:
            // Grammar: ID=376; read/write bits=2; END Element, START (EMAID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EMAID, identifierType (string)); next=377
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &EMAIDListType->EMAID.charactersLen);
                            if (error == 0)
                            {
                                if (EMAIDListType->EMAID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    EMAIDListType->EMAID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, EMAIDListType->EMAID.charactersLen, EMAIDListType->EMAID.characters, iso20_EMAID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 377;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 377:
            // Grammar: ID=377; read/write bits=2; END Element, START (EMAID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EMAID, identifierType (string)); next=378
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &EMAIDListType->EMAID.charactersLen);
                            if (error == 0)
                            {
                                if (EMAIDListType->EMAID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    EMAIDListType->EMAID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, EMAIDListType->EMAID.charactersLen, EMAIDListType->EMAID.characters, iso20_EMAID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 378;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 378:
            // Grammar: ID=378; read/write bits=2; END Element, START (EMAID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EMAID, identifierType (string)); next=379
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &EMAIDListType->EMAID.charactersLen);
                            if (error == 0)
                            {
                                if (EMAIDListType->EMAID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    EMAIDListType->EMAID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, EMAIDListType->EMAID.charactersLen, EMAIDListType->EMAID.characters, iso20_EMAID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 379;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 379:
            // Grammar: ID=379; read/write bits=2; END Element, START (EMAID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EMAID, identifierType (string)); next=380
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &EMAIDListType->EMAID.charactersLen);
                            if (error == 0)
                            {
                                if (EMAIDListType->EMAID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    EMAIDListType->EMAID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, EMAIDListType->EMAID.charactersLen, EMAIDListType->EMAID.characters, iso20_EMAID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 380;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 380:
            // Grammar: ID=380; read/write bits=2; END Element, START (EMAID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EMAID, identifierType (string)); next=381
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &EMAIDListType->EMAID.charactersLen);
                            if (error == 0)
                            {
                                if (EMAIDListType->EMAID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    EMAIDListType->EMAID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, EMAIDListType->EMAID.charactersLen, EMAIDListType->EMAID.characters, iso20_EMAID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 381;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 381:
            // Grammar: ID=381; read/write bits=2; END Element, START (EMAID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EMAID, identifierType (string)); next=382
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &EMAIDListType->EMAID.charactersLen);
                            if (error == 0)
                            {
                                if (EMAIDListType->EMAID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    EMAIDListType->EMAID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, EMAIDListType->EMAID.charactersLen, EMAIDListType->EMAID.characters, iso20_EMAID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 382;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 382:
            // Grammar: ID=382; read/write bits=2; END Element, START (EMAID)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EMAID, identifierType (string)); next=2
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &EMAIDListType->EMAID.charactersLen);
                            if (error == 0)
                            {
                                if (EMAIDListType->EMAID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    EMAIDListType->EMAID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, EMAIDListType->EMAID.charactersLen, EMAIDListType->EMAID.characters, iso20_EMAID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}SignedInstallationData; type={urn:iso:std:iso:15118:-20:CommonMessages}SignedInstallationDataType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (1, 1); ContractCertificateChain, ContractCertificateChainType (1, 1); ECDHCurve, ecdhCurveType (1, 1); DHPublicKey, dhPublicKeyType (1, 1); SECP521_EncryptedPrivateKey, secp521_EncryptedPrivateKeyType (0, 1); X448_EncryptedPrivateKey, x448_EncryptedPrivateKeyType (0, 1); TPM_EncryptedPrivateKey, tpm_EncryptedPrivateKeyType (0, 1);
static int decode_iso20_SignedInstallationDataType(exi_bitstream_t* stream, struct iso20_SignedInstallationDataType* SignedInstallationDataType) {
    int grammar_id = 383;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_SignedInstallationDataType(SignedInstallationDataType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 383:
            // Grammar: ID=383; read/write bits=1; START (Id)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=384
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &SignedInstallationDataType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (SignedInstallationDataType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            SignedInstallationDataType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, SignedInstallationDataType->Id.charactersLen, SignedInstallationDataType->Id.characters, iso20_Id_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    grammar_id = 384;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 384:
            // Grammar: ID=384; read/write bits=1; START (ContractCertificateChain)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ContractCertificateChain, ContractCertificateChainType (ContractCertificateChainType)); next=385
                    // decode: element
                    error = decode_iso20_ContractCertificateChainType(stream, &SignedInstallationDataType->ContractCertificateChain);
                    if (error == 0)
                    {
                        grammar_id = 385;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 385:
            // Grammar: ID=385; read/write bits=1; START (ECDHCurve)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ECDHCurve, ecdhCurveType (string)); next=386
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                SignedInstallationDataType->ECDHCurve = (iso20_ecdhCurveType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 386;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 386:
            // Grammar: ID=386; read/write bits=1; START (DHPublicKey)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DHPublicKey, dhPublicKeyType (base64Binary)); next=387
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SignedInstallationDataType->DHPublicKey.bytesLen, &SignedInstallationDataType->DHPublicKey.bytes[0], iso20_dhPublicKeyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 387;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 387:
            // Grammar: ID=387; read/write bits=2; START (SECP521_EncryptedPrivateKey), START (X448_EncryptedPrivateKey), START (TPM_EncryptedPrivateKey)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SECP521_EncryptedPrivateKey, secp521_EncryptedPrivateKeyType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SignedInstallationDataType->SECP521_EncryptedPrivateKey.bytesLen, &SignedInstallationDataType->SECP521_EncryptedPrivateKey.bytes[0], iso20_secp521_EncryptedPrivateKeyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        SignedInstallationDataType->SECP521_EncryptedPrivateKey_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: START (X448_EncryptedPrivateKey, x448_EncryptedPrivateKeyType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SignedInstallationDataType->X448_EncryptedPrivateKey.bytesLen, &SignedInstallationDataType->X448_EncryptedPrivateKey.bytes[0], iso20_x448_EncryptedPrivateKeyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        SignedInstallationDataType->X448_EncryptedPrivateKey_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 2:
                    // Event: START (TPM_EncryptedPrivateKey, tpm_EncryptedPrivateKeyType (base64Binary)); next=2
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &SignedInstallationDataType->TPM_EncryptedPrivateKey.bytesLen, &SignedInstallationDataType->TPM_EncryptedPrivateKey.bytes[0], iso20_tpm_EncryptedPrivateKeyType_BYTES_SIZE);
                    if (error == 0)
                    {
                        SignedInstallationDataType->TPM_EncryptedPrivateKey_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}PnC_ASResAuthorizationMode; type={urn:iso:std:iso:15118:-20:CommonMessages}PnC_ASResAuthorizationModeType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: GenChallenge, genChallengeType (1, 1); SupportedProviders, SupportedProvidersListType (0, 1);
static int decode_iso20_PnC_ASResAuthorizationModeType(exi_bitstream_t* stream, struct iso20_PnC_ASResAuthorizationModeType* PnC_ASResAuthorizationModeType) {
    int grammar_id = 388;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_PnC_ASResAuthorizationModeType(PnC_ASResAuthorizationModeType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 388:
            // Grammar: ID=388; read/write bits=1; START (GenChallenge)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (GenChallenge, genChallengeType (base64Binary)); next=389
                    // decode exi type: base64Binary
                    error = decode_exi_type_hex_binary(stream, &PnC_ASResAuthorizationModeType->GenChallenge.bytesLen, &PnC_ASResAuthorizationModeType->GenChallenge.bytes[0], iso20_genChallengeType_BYTES_SIZE);
                    if (error == 0)
                    {
                        grammar_id = 389;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 389:
            // Grammar: ID=389; read/write bits=2; END Element, START (SupportedProviders)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SupportedProviders, SupportedProvidersListType (SupportedProvidersListType)); next=2
                    // decode: element
                    error = decode_iso20_SupportedProvidersListType(stream, &PnC_ASResAuthorizationModeType->SupportedProviders);
                    if (error == 0)
                    {
                        PnC_ASResAuthorizationModeType->SupportedProviders_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}Scheduled_SEResControlMode; type={urn:iso:std:iso:15118:-20:CommonMessages}Scheduled_SEResControlModeType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: ScheduleTuple, ScheduleTupleType (1, 3);
static int decode_iso20_Scheduled_SEResControlModeType(exi_bitstream_t* stream, struct iso20_Scheduled_SEResControlModeType* Scheduled_SEResControlModeType) {
    int grammar_id = 390;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_Scheduled_SEResControlModeType(Scheduled_SEResControlModeType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 390:
            // Grammar: ID=390; read/write bits=1; START (ScheduleTuple)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ScheduleTuple, ScheduleTupleType (ScheduleTupleType)); next=391
                    // decode: element array
                    if (Scheduled_SEResControlModeType->ScheduleTuple.arrayLen < iso20_ScheduleTupleType_3_ARRAY_SIZE)
                    {
                        error = decode_iso20_ScheduleTupleType(stream, &Scheduled_SEResControlModeType->ScheduleTuple.array[Scheduled_SEResControlModeType->ScheduleTuple.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 391;
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 391:
            // Grammar: ID=391; read/write bits=2; END Element, START (ScheduleTuple)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ScheduleTuple, ScheduleTupleType (ScheduleTupleType)); next=392
                    // decode: element array
                    if (Scheduled_SEResControlModeType->ScheduleTuple.arrayLen < iso20_ScheduleTupleType_3_ARRAY_SIZE)
                    {
                        error = decode_iso20_ScheduleTupleType(stream, &Scheduled_SEResControlModeType->ScheduleTuple.array[Scheduled_SEResControlModeType->ScheduleTuple.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 392;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 392:
            // Grammar: ID=392; read/write bits=2; END Element, START (ScheduleTuple)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ScheduleTuple, ScheduleTupleType (ScheduleTupleType)); next=2
                    // decode: element array
                    if (Scheduled_SEResControlModeType->ScheduleTuple.arrayLen < iso20_ScheduleTupleType_3_ARRAY_SIZE)
                    {
                        error = decode_iso20_ScheduleTupleType(stream, &Scheduled_SEResControlModeType->ScheduleTuple.array[Scheduled_SEResControlModeType->ScheduleTuple.arrayLen++]);
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    grammar_id = 2;
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}SessionSetupReq; type={urn:iso:std:iso:15118:-20:CommonMessages}SessionSetupReqType; base type=V2GRequestType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); EVCCID, identifierType (1, 1);
static int decode_iso20_SessionSetupReqType(exi_bitstream_t* stream, struct iso20_SessionSetupReqType* SessionSetupReqType) {
    int grammar_id = 393;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_SessionSetupReqType(SessionSetupReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 393:
            // Grammar: ID=393; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=394
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &SessionSetupReqType->Header);
                    if (error == 0)
                    {
                        grammar_id = 394;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 394:
            // Grammar: ID=394; read/write bits=1; START (EVCCID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVCCID, identifierType (string)); next=2
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &SessionSetupReqType->EVCCID.charactersLen);
                            if (error == 0)
                            {
                                if (SessionSetupReqType->EVCCID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    SessionSetupReqType->EVCCID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, SessionSetupReqType->EVCCID.charactersLen, SessionSetupReqType->EVCCID.characters, iso20_EVCCID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}SessionSetupRes; type={urn:iso:std:iso:15118:-20:CommonMessages}SessionSetupResType; base type=V2GResponseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); EVSEID, identifierType (1, 1);
static int decode_iso20_SessionSetupResType(exi_bitstream_t* stream, struct iso20_SessionSetupResType* SessionSetupResType) {
    int grammar_id = 395;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_SessionSetupResType(SessionSetupResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 395:
            // Grammar: ID=395; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=396
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &SessionSetupResType->Header);
                    if (error == 0)
                    {
                        grammar_id = 396;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 396:
            // Grammar: ID=396; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=397
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 6, &value);
                            if (error == 0)
                            {
                                SessionSetupResType->ResponseCode = (iso20_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 397;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 397:
            // Grammar: ID=397; read/write bits=1; START (EVSEID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEID, identifierType (string)); next=2
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &SessionSetupResType->EVSEID.charactersLen);
                            if (error == 0)
                            {
                                if (SessionSetupResType->EVSEID.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    SessionSetupResType->EVSEID.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, SessionSetupResType->EVSEID.charactersLen, SessionSetupResType->EVSEID.characters, iso20_EVSEID_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}AuthorizationSetupReq; type={urn:iso:std:iso:15118:-20:CommonMessages}AuthorizationSetupReqType; base type=V2GRequestType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1);
static int decode_iso20_AuthorizationSetupReqType(exi_bitstream_t* stream, struct iso20_AuthorizationSetupReqType* AuthorizationSetupReqType) {
    int grammar_id = 398;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_AuthorizationSetupReqType(AuthorizationSetupReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 398:
            // Grammar: ID=398; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=2
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &AuthorizationSetupReqType->Header);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}AuthorizationSetupRes; type={urn:iso:std:iso:15118:-20:CommonMessages}AuthorizationSetupResType; base type=V2GResponseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); AuthorizationServices, authorizationType (1, 2); CertificateInstallationService, boolean (1, 1); EIM_ASResAuthorizationMode, EIM_ASResAuthorizationModeType (0, 1); PnC_ASResAuthorizationMode, PnC_ASResAuthorizationModeType (0, 1);
static int decode_iso20_AuthorizationSetupResType(exi_bitstream_t* stream, struct iso20_AuthorizationSetupResType* AuthorizationSetupResType) {
    int grammar_id = 399;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_AuthorizationSetupResType(AuthorizationSetupResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 399:
            // Grammar: ID=399; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=400
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &AuthorizationSetupResType->Header);
                    if (error == 0)
                    {
                        grammar_id = 400;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 400:
            // Grammar: ID=400; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=401
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 6, &value);
                            if (error == 0)
                            {
                                AuthorizationSetupResType->ResponseCode = (iso20_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 401;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 401:
            // Grammar: ID=401; read/write bits=1; START (AuthorizationServices)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AuthorizationServices, authorizationType (string)); next=402
                    // decode: enum array
                    if (AuthorizationSetupResType->AuthorizationServices.arrayLen < iso20_authorizationType_2_ARRAY_SIZE)
                    {
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                uint32_t value;
                                error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                                if (error == 0)
                                {
                                    AuthorizationSetupResType->AuthorizationServices.array[AuthorizationSetupResType->AuthorizationServices.arrayLen] = (iso20_authorizationType)value;
                                    AuthorizationSetupResType->AuthorizationServices.arrayLen++;
                                }
                            }
                            else
                            {
                                // second level event is not supported
                                error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                            }
                        }
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 402;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 402:
            // Grammar: ID=402; read/write bits=1; START (CertificateInstallationService)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (CertificateInstallationService, boolean (boolean)); next=403
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                AuthorizationSetupResType->CertificateInstallationService = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 403;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 403:
            // Grammar: ID=403; read/write bits=1; START (AuthorizationServices)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (AuthorizationServices, authorizationType (string)); next=404
                    // decode: enum array
                    if (AuthorizationSetupResType->AuthorizationServices.arrayLen < iso20_authorizationType_2_ARRAY_SIZE)
                    {
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                uint32_t value;
                                error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                                if (error == 0)
                                {
                                    AuthorizationSetupResType->AuthorizationServices.array[AuthorizationSetupResType->AuthorizationServices.arrayLen] = (iso20_authorizationType)value;
                                    AuthorizationSetupResType->AuthorizationServices.arrayLen++;
                                }
                            }
                            else
                            {
                                // second level event is not supported
                                error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                            }
                        }
                    }
                    else
                    {
                        error = EXI_ERROR__ARRAY_OUT_OF_BOUNDS;
                    }
                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 404;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 404:
            // Grammar: ID=404; read/write bits=1; START (CertificateInstallationService)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (CertificateInstallationService, boolean (boolean)); next=405
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                AuthorizationSetupResType->CertificateInstallationService = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 405;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 405:
            // Grammar: ID=405; read/write bits=2; START (EIM_ASResAuthorizationMode), START (PnC_ASResAuthorizationMode)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EIM_ASResAuthorizationMode, EIM_ASResAuthorizationModeType (EIM_ASResAuthorizationModeType)); next=2
                    // decode: element
                    error = decode_iso20_EIM_ASResAuthorizationModeType(stream, &AuthorizationSetupResType->EIM_ASResAuthorizationMode);
                    if (error == 0)
                    {
                        AuthorizationSetupResType->EIM_ASResAuthorizationMode_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: START (PnC_ASResAuthorizationMode, PnC_ASResAuthorizationModeType (PnC_ASResAuthorizationModeType)); next=2
                    // decode: element
                    error = decode_iso20_PnC_ASResAuthorizationModeType(stream, &AuthorizationSetupResType->PnC_ASResAuthorizationMode);
                    if (error == 0)
                    {
                        AuthorizationSetupResType->PnC_ASResAuthorizationMode_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}AuthorizationReq; type={urn:iso:std:iso:15118:-20:CommonMessages}AuthorizationReqType; base type=V2GRequestType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); SelectedAuthorizationService, authorizationType (1, 1); EIM_AReqAuthorizationMode, EIM_AReqAuthorizationModeType (0, 1); PnC_AReqAuthorizationMode, PnC_AReqAuthorizationModeType (0, 1);
static int decode_iso20_AuthorizationReqType(exi_bitstream_t* stream, struct iso20_AuthorizationReqType* AuthorizationReqType) {
    int grammar_id = 406;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_AuthorizationReqType(AuthorizationReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 406:
            // Grammar: ID=406; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=407
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &AuthorizationReqType->Header);
                    if (error == 0)
                    {
                        grammar_id = 407;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 407:
            // Grammar: ID=407; read/write bits=1; START (SelectedAuthorizationService)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedAuthorizationService, authorizationType (string)); next=408
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                AuthorizationReqType->SelectedAuthorizationService = (iso20_authorizationType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 408;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 408:
            // Grammar: ID=408; read/write bits=2; START (EIM_AReqAuthorizationMode), START (PnC_AReqAuthorizationMode)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EIM_AReqAuthorizationMode, EIM_AReqAuthorizationModeType (EIM_AReqAuthorizationModeType)); next=2
                    // decode: element
                    error = decode_iso20_EIM_AReqAuthorizationModeType(stream, &AuthorizationReqType->EIM_AReqAuthorizationMode);
                    if (error == 0)
                    {
                        AuthorizationReqType->EIM_AReqAuthorizationMode_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: START (PnC_AReqAuthorizationMode, PnC_AReqAuthorizationModeType (PnC_AReqAuthorizationModeType)); next=2
                    // decode: element
                    error = decode_iso20_PnC_AReqAuthorizationModeType(stream, &AuthorizationReqType->PnC_AReqAuthorizationMode);
                    if (error == 0)
                    {
                        AuthorizationReqType->PnC_AReqAuthorizationMode_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}AuthorizationRes; type={urn:iso:std:iso:15118:-20:CommonMessages}AuthorizationResType; base type=V2GResponseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); EVSEProcessing, processingType (1, 1);
static int decode_iso20_AuthorizationResType(exi_bitstream_t* stream, struct iso20_AuthorizationResType* AuthorizationResType) {
    int grammar_id = 409;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_AuthorizationResType(AuthorizationResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 409:
            // Grammar: ID=409; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=410
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &AuthorizationResType->Header);
                    if (error == 0)
                    {
                        grammar_id = 410;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 410:
            // Grammar: ID=410; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=411
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 6, &value);
                            if (error == 0)
                            {
                                AuthorizationResType->ResponseCode = (iso20_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 411;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 411:
            // Grammar: ID=411; read/write bits=1; START (EVSEProcessing)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEProcessing, processingType (string)); next=2
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                AuthorizationResType->EVSEProcessing = (iso20_processingType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}ServiceDiscoveryReq; type={urn:iso:std:iso:15118:-20:CommonMessages}ServiceDiscoveryReqType; base type=V2GRequestType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); SupportedServiceIDs, ServiceIDListType (0, 1);
static int decode_iso20_ServiceDiscoveryReqType(exi_bitstream_t* stream, struct iso20_ServiceDiscoveryReqType* ServiceDiscoveryReqType) {
    int grammar_id = 412;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ServiceDiscoveryReqType(ServiceDiscoveryReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 412:
            // Grammar: ID=412; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=413
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &ServiceDiscoveryReqType->Header);
                    if (error == 0)
                    {
                        grammar_id = 413;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 413:
            // Grammar: ID=413; read/write bits=2; END Element, START (SupportedServiceIDs)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SupportedServiceIDs, ServiceIDListType (ServiceIDListType)); next=2
                    // decode: element
                    error = decode_iso20_ServiceIDListType(stream, &ServiceDiscoveryReqType->SupportedServiceIDs);
                    if (error == 0)
                    {
                        ServiceDiscoveryReqType->SupportedServiceIDs_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}ServiceDiscoveryRes; type={urn:iso:std:iso:15118:-20:CommonMessages}ServiceDiscoveryResType; base type=V2GResponseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); ServiceRenegotiationSupported, boolean (1, 1); EnergyTransferServiceList, ServiceListType (1, 1); VASList, ServiceListType (0, 1);
static int decode_iso20_ServiceDiscoveryResType(exi_bitstream_t* stream, struct iso20_ServiceDiscoveryResType* ServiceDiscoveryResType) {
    int grammar_id = 414;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ServiceDiscoveryResType(ServiceDiscoveryResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 414:
            // Grammar: ID=414; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=415
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &ServiceDiscoveryResType->Header);
                    if (error == 0)
                    {
                        grammar_id = 415;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 415:
            // Grammar: ID=415; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=416
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 6, &value);
                            if (error == 0)
                            {
                                ServiceDiscoveryResType->ResponseCode = (iso20_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 416;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 416:
            // Grammar: ID=416; read/write bits=1; START (ServiceRenegotiationSupported)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceRenegotiationSupported, boolean (boolean)); next=417
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ServiceDiscoveryResType->ServiceRenegotiationSupported = value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 417;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 417:
            // Grammar: ID=417; read/write bits=1; START (EnergyTransferServiceList)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EnergyTransferServiceList, ServiceListType (ServiceListType)); next=418
                    // decode: element
                    error = decode_iso20_ServiceListType(stream, &ServiceDiscoveryResType->EnergyTransferServiceList);
                    if (error == 0)
                    {
                        grammar_id = 418;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 418:
            // Grammar: ID=418; read/write bits=2; END Element, START (VASList)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (VASList, ServiceListType (ServiceListType)); next=2
                    // decode: element
                    error = decode_iso20_ServiceListType(stream, &ServiceDiscoveryResType->VASList);
                    if (error == 0)
                    {
                        ServiceDiscoveryResType->VASList_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}ServiceDetailReq; type={urn:iso:std:iso:15118:-20:CommonMessages}ServiceDetailReqType; base type=V2GRequestType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ServiceID, serviceIDType (1, 1);
static int decode_iso20_ServiceDetailReqType(exi_bitstream_t* stream, struct iso20_ServiceDetailReqType* ServiceDetailReqType) {
    int grammar_id = 419;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ServiceDetailReqType(ServiceDetailReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 419:
            // Grammar: ID=419; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=420
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &ServiceDetailReqType->Header);
                    if (error == 0)
                    {
                        grammar_id = 420;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 420:
            // Grammar: ID=420; read/write bits=1; START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=2
                    // decode: unsigned short
                    error = decode_exi_type_uint16(stream, &ServiceDetailReqType->ServiceID);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}ServiceDetailRes; type={urn:iso:std:iso:15118:-20:CommonMessages}ServiceDetailResType; base type=V2GResponseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); ServiceID, serviceIDType (1, 1); ServiceParameterList, ServiceParameterListType (1, 1);
static int decode_iso20_ServiceDetailResType(exi_bitstream_t* stream, struct iso20_ServiceDetailResType* ServiceDetailResType) {
    int grammar_id = 421;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ServiceDetailResType(ServiceDetailResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 421:
            // Grammar: ID=421; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=422
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &ServiceDetailResType->Header);
                    if (error == 0)
                    {
                        grammar_id = 422;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 422:
            // Grammar: ID=422; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=423
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 6, &value);
                            if (error == 0)
                            {
                                ServiceDetailResType->ResponseCode = (iso20_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 423;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 423:
            // Grammar: ID=423; read/write bits=1; START (ServiceID)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceID, serviceIDType (unsignedShort)); next=424
                    // decode: unsigned short
                    error = decode_exi_type_uint16(stream, &ServiceDetailResType->ServiceID);
                    if (error == 0)
                    {
                        grammar_id = 424;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 424:
            // Grammar: ID=424; read/write bits=1; START (ServiceParameterList)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ServiceParameterList, ServiceParameterListType (ServiceParameterListType)); next=2
                    // decode: element
                    error = decode_iso20_ServiceParameterListType(stream, &ServiceDetailResType->ServiceParameterList);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}ServiceSelectionReq; type={urn:iso:std:iso:15118:-20:CommonMessages}ServiceSelectionReqType; base type=V2GRequestType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); SelectedEnergyTransferService, SelectedServiceType (1, 1); SelectedVASList, SelectedServiceListType (0, 1);
static int decode_iso20_ServiceSelectionReqType(exi_bitstream_t* stream, struct iso20_ServiceSelectionReqType* ServiceSelectionReqType) {
    int grammar_id = 425;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ServiceSelectionReqType(ServiceSelectionReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 425:
            // Grammar: ID=425; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=426
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &ServiceSelectionReqType->Header);
                    if (error == 0)
                    {
                        grammar_id = 426;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 426:
            // Grammar: ID=426; read/write bits=1; START (SelectedEnergyTransferService)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedEnergyTransferService, SelectedServiceType (SelectedServiceType)); next=427
                    // decode: element
                    error = decode_iso20_SelectedServiceType(stream, &ServiceSelectionReqType->SelectedEnergyTransferService);
                    if (error == 0)
                    {
                        grammar_id = 427;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 427:
            // Grammar: ID=427; read/write bits=2; END Element, START (SelectedVASList)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SelectedVASList, SelectedServiceListType (SelectedServiceListType)); next=2
                    // decode: element
                    error = decode_iso20_SelectedServiceListType(stream, &ServiceSelectionReqType->SelectedVASList);
                    if (error == 0)
                    {
                        ServiceSelectionReqType->SelectedVASList_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}ServiceSelectionRes; type={urn:iso:std:iso:15118:-20:CommonMessages}ServiceSelectionResType; base type=V2GResponseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1);
static int decode_iso20_ServiceSelectionResType(exi_bitstream_t* stream, struct iso20_ServiceSelectionResType* ServiceSelectionResType) {
    int grammar_id = 428;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ServiceSelectionResType(ServiceSelectionResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 428:
            // Grammar: ID=428; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=429
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &ServiceSelectionResType->Header);
                    if (error == 0)
                    {
                        grammar_id = 429;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 429:
            // Grammar: ID=429; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=2
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 6, &value);
                            if (error == 0)
                            {
                                ServiceSelectionResType->ResponseCode = (iso20_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}ScheduleExchangeReq; type={urn:iso:std:iso:15118:-20:CommonMessages}ScheduleExchangeReqType; base type=V2GRequestType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); MaximumSupportingPoints, maxSupportingPointsScheduleTupleType (1, 1); Dynamic_SEReqControlMode, Dynamic_SEReqControlModeType (0, 1); Scheduled_SEReqControlMode, Scheduled_SEReqControlModeType (0, 1);
static int decode_iso20_ScheduleExchangeReqType(exi_bitstream_t* stream, struct iso20_ScheduleExchangeReqType* ScheduleExchangeReqType) {
    int grammar_id = 430;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ScheduleExchangeReqType(ScheduleExchangeReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 430:
            // Grammar: ID=430; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=431
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &ScheduleExchangeReqType->Header);
                    if (error == 0)
                    {
                        grammar_id = 431;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 431:
            // Grammar: ID=431; read/write bits=1; START (MaximumSupportingPoints)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (MaximumSupportingPoints, maxSupportingPointsScheduleTupleType (unsignedShort)); next=432
                    // decode: restricted integer (4096 or fewer values)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 10, &value);
                            if (error == 0)
                            {
                                // type has min_value = 12
                                ScheduleExchangeReqType->MaximumSupportingPoints = (uint16_t)(value + 12);
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 432;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 432:
            // Grammar: ID=432; read/write bits=2; START (Dynamic_SEReqControlMode), START (Scheduled_SEReqControlMode)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Dynamic_SEReqControlMode, Dynamic_SEReqControlModeType (Dynamic_SEReqControlModeType)); next=2
                    // decode: element
                    error = decode_iso20_Dynamic_SEReqControlModeType(stream, &ScheduleExchangeReqType->Dynamic_SEReqControlMode);
                    if (error == 0)
                    {
                        ScheduleExchangeReqType->Dynamic_SEReqControlMode_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: START (Scheduled_SEReqControlMode, Scheduled_SEReqControlModeType (Scheduled_SEReqControlModeType)); next=2
                    // decode: element
                    error = decode_iso20_Scheduled_SEReqControlModeType(stream, &ScheduleExchangeReqType->Scheduled_SEReqControlMode);
                    if (error == 0)
                    {
                        ScheduleExchangeReqType->Scheduled_SEReqControlMode_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}ScheduleExchangeRes; type={urn:iso:std:iso:15118:-20:CommonMessages}ScheduleExchangeResType; base type=V2GResponseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); EVSEProcessing, processingType (1, 1); GoToPause, boolean (0, 1); Dynamic_SEResControlMode, Dynamic_SEResControlModeType (0, 1); Scheduled_SEResControlMode, Scheduled_SEResControlModeType (0, 1);
static int decode_iso20_ScheduleExchangeResType(exi_bitstream_t* stream, struct iso20_ScheduleExchangeResType* ScheduleExchangeResType) {
    int grammar_id = 433;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ScheduleExchangeResType(ScheduleExchangeResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 433:
            // Grammar: ID=433; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=434
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &ScheduleExchangeResType->Header);
                    if (error == 0)
                    {
                        grammar_id = 434;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 434:
            // Grammar: ID=434; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=435
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 6, &value);
                            if (error == 0)
                            {
                                ScheduleExchangeResType->ResponseCode = (iso20_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 435;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 435:
            // Grammar: ID=435; read/write bits=1; START (EVSEProcessing)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEProcessing, processingType (string)); next=436
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                ScheduleExchangeResType->EVSEProcessing = (iso20_processingType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 436;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 436:
            // Grammar: ID=436; read/write bits=2; START (GoToPause), START (Dynamic_SEResControlMode), START (Scheduled_SEResControlMode)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (GoToPause, boolean (boolean)); next=437
                    // decode: boolean
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                ScheduleExchangeResType->GoToPause = value;
                                ScheduleExchangeResType->GoToPause_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 437;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (Dynamic_SEResControlMode, Dynamic_SEResControlModeType (Dynamic_SEResControlModeType)); next=2
                    // decode: element
                    error = decode_iso20_Dynamic_SEResControlModeType(stream, &ScheduleExchangeResType->Dynamic_SEResControlMode);
                    if (error == 0)
                    {
                        ScheduleExchangeResType->Dynamic_SEResControlMode_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 2:
                    // Event: START (Scheduled_SEResControlMode, Scheduled_SEResControlModeType (Scheduled_SEResControlModeType)); next=2
                    // decode: element
                    error = decode_iso20_Scheduled_SEResControlModeType(stream, &ScheduleExchangeResType->Scheduled_SEResControlMode);
                    if (error == 0)
                    {
                        ScheduleExchangeResType->Scheduled_SEResControlMode_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 437:
            // Grammar: ID=437; read/write bits=2; START (Dynamic_SEResControlMode), START (Scheduled_SEResControlMode)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Dynamic_SEResControlMode, Dynamic_SEResControlModeType (Dynamic_SEResControlModeType)); next=2
                    // decode: element
                    error = decode_iso20_Dynamic_SEResControlModeType(stream, &ScheduleExchangeResType->Dynamic_SEResControlMode);
                    if (error == 0)
                    {
                        ScheduleExchangeResType->Dynamic_SEResControlMode_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: START (Scheduled_SEResControlMode, Scheduled_SEResControlModeType (Scheduled_SEResControlModeType)); next=2
                    // decode: element
                    error = decode_iso20_Scheduled_SEResControlModeType(stream, &ScheduleExchangeResType->Scheduled_SEResControlMode);
                    if (error == 0)
                    {
                        ScheduleExchangeResType->Scheduled_SEResControlMode_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}PowerDeliveryReq; type={urn:iso:std:iso:15118:-20:CommonMessages}PowerDeliveryReqType; base type=V2GRequestType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); EVProcessing, processingType (1, 1); ChargeProgress, chargeProgressType (1, 1); EVPowerProfile, EVPowerProfileType (0, 1); BPT_ChannelSelection, channelSelectionType (0, 1);
static int decode_iso20_PowerDeliveryReqType(exi_bitstream_t* stream, struct iso20_PowerDeliveryReqType* PowerDeliveryReqType) {
    int grammar_id = 438;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_PowerDeliveryReqType(PowerDeliveryReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 438:
            // Grammar: ID=438; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=439
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &PowerDeliveryReqType->Header);
                    if (error == 0)
                    {
                        grammar_id = 439;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 439:
            // Grammar: ID=439; read/write bits=1; START (EVProcessing)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVProcessing, processingType (string)); next=440
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                PowerDeliveryReqType->EVProcessing = (iso20_processingType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 440;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 440:
            // Grammar: ID=440; read/write bits=1; START (ChargeProgress)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ChargeProgress, chargeProgressType (string)); next=441
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                PowerDeliveryReqType->ChargeProgress = (iso20_chargeProgressType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 441;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 441:
            // Grammar: ID=441; read/write bits=2; END Element, START (EVPowerProfile), START (BPT_ChannelSelection)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVPowerProfile, EVPowerProfileType (EVPowerProfileType)); next=442
                    // decode: element
                    error = decode_iso20_EVPowerProfileType(stream, &PowerDeliveryReqType->EVPowerProfile);
                    if (error == 0)
                    {
                        PowerDeliveryReqType->EVPowerProfile_isUsed = 1u;
                        grammar_id = 442;
                    }
                    break;
                case 1:
                    // Event: START (BPT_ChannelSelection, channelSelectionType (string)); next=2
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                PowerDeliveryReqType->BPT_ChannelSelection = (iso20_channelSelectionType)value;
                                PowerDeliveryReqType->BPT_ChannelSelection_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 442:
            // Grammar: ID=442; read/write bits=2; END Element, START (BPT_ChannelSelection)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (BPT_ChannelSelection, channelSelectionType (string)); next=2
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                PowerDeliveryReqType->BPT_ChannelSelection = (iso20_channelSelectionType)value;
                                PowerDeliveryReqType->BPT_ChannelSelection_isUsed = 1u;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}PowerDeliveryRes; type={urn:iso:std:iso:15118:-20:CommonMessages}PowerDeliveryResType; base type=V2GResponseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); EVSEStatus, EVSEStatusType (0, 1);
static int decode_iso20_PowerDeliveryResType(exi_bitstream_t* stream, struct iso20_PowerDeliveryResType* PowerDeliveryResType) {
    int grammar_id = 443;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_PowerDeliveryResType(PowerDeliveryResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 443:
            // Grammar: ID=443; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=444
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &PowerDeliveryResType->Header);
                    if (error == 0)
                    {
                        grammar_id = 444;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 444:
            // Grammar: ID=444; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=445
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 6, &value);
                            if (error == 0)
                            {
                                PowerDeliveryResType->ResponseCode = (iso20_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 445;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 445:
            // Grammar: ID=445; read/write bits=2; END Element, START (EVSEStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEStatus, EVSEStatusType (EVSEStatusType)); next=2
                    // decode: element
                    error = decode_iso20_EVSEStatusType(stream, &PowerDeliveryResType->EVSEStatus);
                    if (error == 0)
                    {
                        PowerDeliveryResType->EVSEStatus_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}MeteringConfirmationReq; type={urn:iso:std:iso:15118:-20:CommonMessages}MeteringConfirmationReqType; base type=V2GRequestType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); SignedMeteringData, SignedMeteringDataType (1, 1);
static int decode_iso20_MeteringConfirmationReqType(exi_bitstream_t* stream, struct iso20_MeteringConfirmationReqType* MeteringConfirmationReqType) {
    int grammar_id = 446;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_MeteringConfirmationReqType(MeteringConfirmationReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 446:
            // Grammar: ID=446; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=447
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &MeteringConfirmationReqType->Header);
                    if (error == 0)
                    {
                        grammar_id = 447;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 447:
            // Grammar: ID=447; read/write bits=1; START (SignedMeteringData)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SignedMeteringData, SignedMeteringDataType (SignedMeteringDataType)); next=2
                    // decode: element
                    error = decode_iso20_SignedMeteringDataType(stream, &MeteringConfirmationReqType->SignedMeteringData);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}MeteringConfirmationRes; type={urn:iso:std:iso:15118:-20:CommonMessages}MeteringConfirmationResType; base type=V2GResponseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1);
static int decode_iso20_MeteringConfirmationResType(exi_bitstream_t* stream, struct iso20_MeteringConfirmationResType* MeteringConfirmationResType) {
    int grammar_id = 448;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_MeteringConfirmationResType(MeteringConfirmationResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 448:
            // Grammar: ID=448; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=449
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &MeteringConfirmationResType->Header);
                    if (error == 0)
                    {
                        grammar_id = 449;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 449:
            // Grammar: ID=449; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=2
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 6, &value);
                            if (error == 0)
                            {
                                MeteringConfirmationResType->ResponseCode = (iso20_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}SessionStopReq; type={urn:iso:std:iso:15118:-20:CommonMessages}SessionStopReqType; base type=V2GRequestType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ChargingSession, chargingSessionType (1, 1); EVTerminationCode, nameType (0, 1); EVTerminationExplanation, descriptionType (0, 1);
static int decode_iso20_SessionStopReqType(exi_bitstream_t* stream, struct iso20_SessionStopReqType* SessionStopReqType) {
    int grammar_id = 450;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_SessionStopReqType(SessionStopReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 450:
            // Grammar: ID=450; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=451
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &SessionStopReqType->Header);
                    if (error == 0)
                    {
                        grammar_id = 451;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 451:
            // Grammar: ID=451; read/write bits=1; START (ChargingSession)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ChargingSession, chargingSessionType (string)); next=452
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                SessionStopReqType->ChargingSession = (iso20_chargingSessionType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 452;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 452:
            // Grammar: ID=452; read/write bits=2; END Element, START (EVTerminationCode), START (EVTerminationExplanation)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVTerminationCode, nameType (string)); next=453
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &SessionStopReqType->EVTerminationCode.charactersLen);
                            if (error == 0)
                            {
                                if (SessionStopReqType->EVTerminationCode.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    SessionStopReqType->EVTerminationCode.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, SessionStopReqType->EVTerminationCode.charactersLen, SessionStopReqType->EVTerminationCode.characters, iso20_EVTerminationCode_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                SessionStopReqType->EVTerminationCode_isUsed = 1u;
                                grammar_id = 453;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: START (EVTerminationExplanation, descriptionType (string)); next=2
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &SessionStopReqType->EVTerminationExplanation.charactersLen);
                            if (error == 0)
                            {
                                if (SessionStopReqType->EVTerminationExplanation.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    SessionStopReqType->EVTerminationExplanation.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, SessionStopReqType->EVTerminationExplanation.charactersLen, SessionStopReqType->EVTerminationExplanation.characters, iso20_EVTerminationExplanation_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                SessionStopReqType->EVTerminationExplanation_isUsed = 1u;
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 2:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 453:
            // Grammar: ID=453; read/write bits=2; END Element, START (EVTerminationExplanation)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVTerminationExplanation, descriptionType (string)); next=2
                    // decode: string (len, characters)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            error = exi_basetypes_decoder_uint_16(stream, &SessionStopReqType->EVTerminationExplanation.charactersLen);
                            if (error == 0)
                            {
                                if (SessionStopReqType->EVTerminationExplanation.charactersLen >= 2)
                                {
                                    // string tables and table partitions are not supported, so the length has to be decremented by 2
                                    SessionStopReqType->EVTerminationExplanation.charactersLen -= 2;
                                    error = exi_basetypes_decoder_characters(stream, SessionStopReqType->EVTerminationExplanation.charactersLen, SessionStopReqType->EVTerminationExplanation.characters, iso20_EVTerminationExplanation_CHARACTER_SIZE);
                                }
                                else
                                {
                                    // the string seems to be in the table, but this is not supported
                                    error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                                }
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_characters is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                SessionStopReqType->EVTerminationExplanation_isUsed = 1u;
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}SessionStopRes; type={urn:iso:std:iso:15118:-20:CommonMessages}SessionStopResType; base type=V2GResponseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1);
static int decode_iso20_SessionStopResType(exi_bitstream_t* stream, struct iso20_SessionStopResType* SessionStopResType) {
    int grammar_id = 454;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_SessionStopResType(SessionStopResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 454:
            // Grammar: ID=454; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=455
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &SessionStopResType->Header);
                    if (error == 0)
                    {
                        grammar_id = 455;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 455:
            // Grammar: ID=455; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=2
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 6, &value);
                            if (error == 0)
                            {
                                SessionStopResType->ResponseCode = (iso20_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}CertificateInstallationReq; type={urn:iso:std:iso:15118:-20:CommonMessages}CertificateInstallationReqType; base type=V2GRequestType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); OEMProvisioningCertificateChain, SignedCertificateChainType (1, 1); ListOfRootCertificateIDs, ListOfRootCertificateIDsType (1, 1); MaximumContractCertificateChains, unsignedByte (1, 1); PrioritizedEMAIDs, EMAIDListType (0, 1);
static int decode_iso20_CertificateInstallationReqType(exi_bitstream_t* stream, struct iso20_CertificateInstallationReqType* CertificateInstallationReqType) {
    int grammar_id = 456;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_CertificateInstallationReqType(CertificateInstallationReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 456:
            // Grammar: ID=456; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=457
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &CertificateInstallationReqType->Header);
                    if (error == 0)
                    {
                        grammar_id = 457;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 457:
            // Grammar: ID=457; read/write bits=1; START (OEMProvisioningCertificateChain)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (OEMProvisioningCertificateChain, SignedCertificateChainType (SignedCertificateChainType)); next=458
                    // decode: element
                    error = decode_iso20_SignedCertificateChainType(stream, &CertificateInstallationReqType->OEMProvisioningCertificateChain);
                    if (error == 0)
                    {
                        grammar_id = 458;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 458:
            // Grammar: ID=458; read/write bits=1; START (ListOfRootCertificateIDs)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ListOfRootCertificateIDs, ListOfRootCertificateIDsType (ListOfRootCertificateIDsType)); next=459
                    // decode: element
                    error = decode_iso20_ListOfRootCertificateIDsType(stream, &CertificateInstallationReqType->ListOfRootCertificateIDs);
                    if (error == 0)
                    {
                        grammar_id = 459;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 459:
            // Grammar: ID=459; read/write bits=1; START (MaximumContractCertificateChains)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (MaximumContractCertificateChains, unsignedByte (unsignedShort)); next=460
                    // decode: unsigned byte (restricted integer)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 8, &value);
                            if (error == 0)
                            {
                                CertificateInstallationReqType->MaximumContractCertificateChains = (uint8_t)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 460;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 460:
            // Grammar: ID=460; read/write bits=2; END Element, START (PrioritizedEMAIDs)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (PrioritizedEMAIDs, EMAIDListType (EMAIDListType)); next=2
                    // decode: element
                    error = decode_iso20_EMAIDListType(stream, &CertificateInstallationReqType->PrioritizedEMAIDs);
                    if (error == 0)
                    {
                        CertificateInstallationReqType->PrioritizedEMAIDs_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}CertificateInstallationRes; type={urn:iso:std:iso:15118:-20:CommonMessages}CertificateInstallationResType; base type=V2GResponseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); EVSEProcessing, processingType (1, 1); CPSCertificateChain, CertificateChainType (1, 1); SignedInstallationData, SignedInstallationDataType (1, 1); RemainingContractCertificateChains, unsignedByte (1, 1);
static int decode_iso20_CertificateInstallationResType(exi_bitstream_t* stream, struct iso20_CertificateInstallationResType* CertificateInstallationResType) {
    int grammar_id = 461;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_CertificateInstallationResType(CertificateInstallationResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 461:
            // Grammar: ID=461; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=462
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &CertificateInstallationResType->Header);
                    if (error == 0)
                    {
                        grammar_id = 462;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 462:
            // Grammar: ID=462; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=463
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 6, &value);
                            if (error == 0)
                            {
                                CertificateInstallationResType->ResponseCode = (iso20_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 463;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 463:
            // Grammar: ID=463; read/write bits=1; START (EVSEProcessing)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSEProcessing, processingType (string)); next=464
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                CertificateInstallationResType->EVSEProcessing = (iso20_processingType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 464;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 464:
            // Grammar: ID=464; read/write bits=1; START (CPSCertificateChain)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (CPSCertificateChain, CertificateChainType (CertificateChainType)); next=465
                    // decode: element
                    error = decode_iso20_CertificateChainType(stream, &CertificateInstallationResType->CPSCertificateChain);
                    if (error == 0)
                    {
                        grammar_id = 465;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 465:
            // Grammar: ID=465; read/write bits=1; START (SignedInstallationData)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SignedInstallationData, SignedInstallationDataType (SignedInstallationDataType)); next=466
                    // decode: element
                    error = decode_iso20_SignedInstallationDataType(stream, &CertificateInstallationResType->SignedInstallationData);
                    if (error == 0)
                    {
                        grammar_id = 466;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 466:
            // Grammar: ID=466; read/write bits=1; START (RemainingContractCertificateChains)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (RemainingContractCertificateChains, unsignedByte (unsignedShort)); next=2
                    // decode: unsigned byte (restricted integer)
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 8, &value);
                            if (error == 0)
                            {
                                CertificateInstallationResType->RemainingContractCertificateChains = (uint8_t)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}VehicleCheckInReq; type={urn:iso:std:iso:15118:-20:CommonMessages}VehicleCheckInReqType; base type=V2GRequestType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); EVCheckInStatus, evCheckInStatusType (1, 1); ParkingMethod, parkingMethodType (1, 1); VehicleFrame, short (0, 1); DeviceOffset, short (0, 1); VehicleTravel, short (0, 1);
static int decode_iso20_VehicleCheckInReqType(exi_bitstream_t* stream, struct iso20_VehicleCheckInReqType* VehicleCheckInReqType) {
    int grammar_id = 467;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_VehicleCheckInReqType(VehicleCheckInReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 467:
            // Grammar: ID=467; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=468
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &VehicleCheckInReqType->Header);
                    if (error == 0)
                    {
                        grammar_id = 468;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 468:
            // Grammar: ID=468; read/write bits=1; START (EVCheckInStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVCheckInStatus, evCheckInStatusType (string)); next=469
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                VehicleCheckInReqType->EVCheckInStatus = (iso20_evCheckInStatusType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 469;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 469:
            // Grammar: ID=469; read/write bits=1; START (ParkingMethod)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ParkingMethod, parkingMethodType (string)); next=470
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                VehicleCheckInReqType->ParkingMethod = (iso20_parkingMethodType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 470;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 470:
            // Grammar: ID=470; read/write bits=3; END Element, START (VehicleFrame), START (DeviceOffset), START (VehicleTravel)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (VehicleFrame, short (int)); next=471
                    // decode: short
                    error = decode_exi_type_integer16(stream, &VehicleCheckInReqType->VehicleFrame);
                    if (error == 0)
                    {
                        VehicleCheckInReqType->VehicleFrame_isUsed = 1u;
                        grammar_id = 471;
                    }
                    break;
                case 1:
                    // Event: START (DeviceOffset, short (int)); next=472
                    // decode: short
                    error = decode_exi_type_integer16(stream, &VehicleCheckInReqType->DeviceOffset);
                    if (error == 0)
                    {
                        VehicleCheckInReqType->DeviceOffset_isUsed = 1u;
                        grammar_id = 472;
                    }
                    break;
                case 2:
                    // Event: START (VehicleTravel, short (int)); next=2
                    // decode: short
                    error = decode_exi_type_integer16(stream, &VehicleCheckInReqType->VehicleTravel);
                    if (error == 0)
                    {
                        VehicleCheckInReqType->VehicleTravel_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 3:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 471:
            // Grammar: ID=471; read/write bits=2; END Element, START (DeviceOffset), START (VehicleTravel)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DeviceOffset, short (int)); next=472
                    // decode: short
                    error = decode_exi_type_integer16(stream, &VehicleCheckInReqType->DeviceOffset);
                    if (error == 0)
                    {
                        VehicleCheckInReqType->DeviceOffset_isUsed = 1u;
                        grammar_id = 472;
                    }
                    break;
                case 1:
                    // Event: START (VehicleTravel, short (int)); next=2
                    // decode: short
                    error = decode_exi_type_integer16(stream, &VehicleCheckInReqType->VehicleTravel);
                    if (error == 0)
                    {
                        VehicleCheckInReqType->VehicleTravel_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 2:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 472:
            // Grammar: ID=472; read/write bits=2; END Element, START (VehicleTravel)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (VehicleTravel, short (int)); next=2
                    // decode: short
                    error = decode_exi_type_integer16(stream, &VehicleCheckInReqType->VehicleTravel);
                    if (error == 0)
                    {
                        VehicleCheckInReqType->VehicleTravel_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}VehicleCheckInRes; type={urn:iso:std:iso:15118:-20:CommonMessages}VehicleCheckInResType; base type=V2GResponseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); ParkingSpace, short (0, 1); DeviceLocation, short (0, 1); TargetDistance, short (0, 1);
static int decode_iso20_VehicleCheckInResType(exi_bitstream_t* stream, struct iso20_VehicleCheckInResType* VehicleCheckInResType) {
    int grammar_id = 473;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_VehicleCheckInResType(VehicleCheckInResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 473:
            // Grammar: ID=473; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=474
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &VehicleCheckInResType->Header);
                    if (error == 0)
                    {
                        grammar_id = 474;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 474:
            // Grammar: ID=474; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=475
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 6, &value);
                            if (error == 0)
                            {
                                VehicleCheckInResType->ResponseCode = (iso20_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 475;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 475:
            // Grammar: ID=475; read/write bits=3; END Element, START (ParkingSpace), START (DeviceLocation), START (TargetDistance)
            error = exi_basetypes_decoder_nbit_uint(stream, 3, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ParkingSpace, short (int)); next=476
                    // decode: short
                    error = decode_exi_type_integer16(stream, &VehicleCheckInResType->ParkingSpace);
                    if (error == 0)
                    {
                        VehicleCheckInResType->ParkingSpace_isUsed = 1u;
                        grammar_id = 476;
                    }
                    break;
                case 1:
                    // Event: START (DeviceLocation, short (int)); next=477
                    // decode: short
                    error = decode_exi_type_integer16(stream, &VehicleCheckInResType->DeviceLocation);
                    if (error == 0)
                    {
                        VehicleCheckInResType->DeviceLocation_isUsed = 1u;
                        grammar_id = 477;
                    }
                    break;
                case 2:
                    // Event: START (TargetDistance, short (int)); next=2
                    // decode: short
                    error = decode_exi_type_integer16(stream, &VehicleCheckInResType->TargetDistance);
                    if (error == 0)
                    {
                        VehicleCheckInResType->TargetDistance_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 3:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 476:
            // Grammar: ID=476; read/write bits=2; END Element, START (DeviceLocation), START (TargetDistance)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (DeviceLocation, short (int)); next=477
                    // decode: short
                    error = decode_exi_type_integer16(stream, &VehicleCheckInResType->DeviceLocation);
                    if (error == 0)
                    {
                        VehicleCheckInResType->DeviceLocation_isUsed = 1u;
                        grammar_id = 477;
                    }
                    break;
                case 1:
                    // Event: START (TargetDistance, short (int)); next=2
                    // decode: short
                    error = decode_exi_type_integer16(stream, &VehicleCheckInResType->TargetDistance);
                    if (error == 0)
                    {
                        VehicleCheckInResType->TargetDistance_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 2:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 477:
            // Grammar: ID=477; read/write bits=2; END Element, START (TargetDistance)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (TargetDistance, short (int)); next=2
                    // decode: short
                    error = decode_exi_type_integer16(stream, &VehicleCheckInResType->TargetDistance);
                    if (error == 0)
                    {
                        VehicleCheckInResType->TargetDistance_isUsed = 1u;
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}VehicleCheckOutReq; type={urn:iso:std:iso:15118:-20:CommonMessages}VehicleCheckOutReqType; base type=V2GRequestType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); EVCheckOutStatus, evCheckOutStatusType (1, 1); CheckOutTime, unsignedLong (1, 1);
static int decode_iso20_VehicleCheckOutReqType(exi_bitstream_t* stream, struct iso20_VehicleCheckOutReqType* VehicleCheckOutReqType) {
    int grammar_id = 478;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_VehicleCheckOutReqType(VehicleCheckOutReqType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 478:
            // Grammar: ID=478; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=479
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &VehicleCheckOutReqType->Header);
                    if (error == 0)
                    {
                        grammar_id = 479;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 479:
            // Grammar: ID=479; read/write bits=1; START (EVCheckOutStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVCheckOutStatus, evCheckOutStatusType (string)); next=480
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 2, &value);
                            if (error == 0)
                            {
                                VehicleCheckOutReqType->EVCheckOutStatus = (iso20_evCheckOutStatusType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 480;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 480:
            // Grammar: ID=480; read/write bits=1; START (CheckOutTime)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (CheckOutTime, unsignedLong (nonNegativeInteger)); next=2
                    // decode: unsigned long int
                    error = decode_exi_type_uint64(stream, &VehicleCheckOutReqType->CheckOutTime);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonMessages}VehicleCheckOutRes; type={urn:iso:std:iso:15118:-20:CommonMessages}VehicleCheckOutResType; base type=V2GResponseType; content type=ELEMENT-ONLY;
//          abstract=False; final=False; derivation=extension;
// Particle: Header, MessageHeaderType (1, 1); ResponseCode, responseCodeType (1, 1); EVSECheckOutStatus, evseCheckOutStatusType (1, 1);
static int decode_iso20_VehicleCheckOutResType(exi_bitstream_t* stream, struct iso20_VehicleCheckOutResType* VehicleCheckOutResType) {
    int grammar_id = 481;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_VehicleCheckOutResType(VehicleCheckOutResType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 481:
            // Grammar: ID=481; read/write bits=1; START (Header)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Header, MessageHeaderType (MessageHeaderType)); next=482
                    // decode: element
                    error = decode_iso20_MessageHeaderType(stream, &VehicleCheckOutResType->Header);
                    if (error == 0)
                    {
                        grammar_id = 482;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 482:
            // Grammar: ID=482; read/write bits=1; START (ResponseCode)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (ResponseCode, responseCodeType (string)); next=483
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 6, &value);
                            if (error == 0)
                            {
                                VehicleCheckOutResType->ResponseCode = (iso20_responseCodeType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 483;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 483:
            // Grammar: ID=483; read/write bits=1; START (EVSECheckOutStatus)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (EVSECheckOutStatus, evseCheckOutStatusType (string)); next=2
                    // decode: enum
                    error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                    if (error == 0)
                    {
                        if (eventCode == 0)
                        {
                            uint32_t value;
                            error = exi_basetypes_decoder_nbit_uint(stream, 1, &value);
                            if (error == 0)
                            {
                                VehicleCheckOutResType->EVSECheckOutStatus = (iso20_evseCheckOutStatusType)value;
                            }
                        }
                        else
                        {
                            // second level event is not supported
                            error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                        }
                    }

                    // if nothing went wrong, the error of exi_basetypes_decoder_nbit_uint is evaluated here
                    if (error == 0)
                    {
                        // END Element for simple type
                        error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
                        if (error == 0)
                        {
                            if (eventCode == 0)
                            {
                                grammar_id = 2;
                            }
                            else
                            {
                                error = EXI_ERROR__DEVIANTS_NOT_SUPPORTED;
                            }
                        }
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_CLReqControlModeType(exi_bitstream_t* stream, struct iso20_CLReqControlModeType* CLReqControlModeType) {
    // Element has no particles, so the function just returns zero
    (void)stream;
    (void)CLReqControlModeType;

    return 0;
}

// Element: definition=complex; name={urn:iso:std:iso:15118:-20:CommonTypes}CLResControlMode; type={urn:iso:std:iso:15118:-20:CommonTypes}CLResControlModeType; base type=; content type=empty;
//          abstract=False; final=False;
static int decode_iso20_CLResControlModeType(exi_bitstream_t* stream, struct iso20_CLResControlModeType* CLResControlModeType) {
    // Element has no particles, so the function just returns zero
    (void)stream;
    (void)CLResControlModeType;

    return 0;
}

// Element: definition=complex; name={http://www.w3.org/2000/09/xmldsig#}Manifest; type={http://www.w3.org/2000/09/xmldsig#}ManifestType; base type=; content type=ELEMENT-ONLY;
//          abstract=False; final=False;
// Particle: Id, ID (0, 1); Reference, ReferenceType (1, 1);
static int decode_iso20_ManifestType(exi_bitstream_t* stream, struct iso20_ManifestType* ManifestType) {
    int grammar_id = 484;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_ManifestType(ManifestType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 484:
            // Grammar: ID=484; read/write bits=2; START (Id), START (Reference)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=486
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &ManifestType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (ManifestType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            ManifestType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, ManifestType->Id.charactersLen, ManifestType->Id.characters, iso20_Id_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    ManifestType->Id_isUsed = 1u;
                    grammar_id = 486;
                    break;
                case 1:
                    // Event: START (Reference, ReferenceType (ReferenceType)); next=2
                    // decode: element
                    error = decode_iso20_ReferenceType(stream, &ManifestType->Reference);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 485:
            // Grammar: ID=485; read/write bits=2; END Element, START (Reference)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Reference, ReferenceType (ReferenceType)); next=486
                    // decode: element
                    error = decode_iso20_ReferenceType(stream, &ManifestType->Reference);
                    if (error == 0)
                    {
                        grammar_id = 486;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 486:
            // Grammar: ID=486; read/write bits=1; START (Reference)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Reference, ReferenceType (ReferenceType)); next=487
                    // decode: element
                    error = decode_iso20_ReferenceType(stream, &ManifestType->Reference);
                    if (error == 0)
                    {
                        grammar_id = 487;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 487:
            // Grammar: ID=487; read/write bits=2; END Element, START (Reference)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Reference, ReferenceType (ReferenceType)); next=2
                    // decode: element
                    error = decode_iso20_ReferenceType(stream, &ManifestType->Reference);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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
static int decode_iso20_SignaturePropertiesType(exi_bitstream_t* stream, struct iso20_SignaturePropertiesType* SignaturePropertiesType) {
    int grammar_id = 488;
    int done = 0;
    uint32_t eventCode;
    int error;

    init_iso20_SignaturePropertiesType(SignaturePropertiesType);

    while(!done)
    {
        switch(grammar_id)
        {
        case 488:
            // Grammar: ID=488; read/write bits=2; START (Id), START (SignatureProperty)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (Id, ID (NCName)); next=490
                    // decode: string (len, characters) (Attribute)
                    error = exi_basetypes_decoder_uint_16(stream, &SignaturePropertiesType->Id.charactersLen);
                    if (error == 0)
                    {
                        if (SignaturePropertiesType->Id.charactersLen >= 2)
                        {
                            // string tables and table partitions are not supported, so the length has to be decremented by 2
                            SignaturePropertiesType->Id.charactersLen -= 2;
                            error = exi_basetypes_decoder_characters(stream, SignaturePropertiesType->Id.charactersLen, SignaturePropertiesType->Id.characters, iso20_Id_CHARACTER_SIZE);
                        }
                        else
                        {
                            // the string seems to be in the table, but this is not supported
                            error = EXI_ERROR__STRINGVALUES_NOT_SUPPORTED;
                        }
                    }
                    SignaturePropertiesType->Id_isUsed = 1u;
                    grammar_id = 490;
                    break;
                case 1:
                    // Event: START (SignatureProperty, SignaturePropertyType (SignaturePropertyType)); next=2
                    // decode: element
                    error = decode_iso20_SignaturePropertyType(stream, &SignaturePropertiesType->SignatureProperty);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 489:
            // Grammar: ID=489; read/write bits=2; END Element, START (SignatureProperty)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SignatureProperty, SignaturePropertyType (SignaturePropertyType)); next=490
                    // decode: element
                    error = decode_iso20_SignaturePropertyType(stream, &SignaturePropertiesType->SignatureProperty);
                    if (error == 0)
                    {
                        grammar_id = 490;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 490:
            // Grammar: ID=490; read/write bits=1; START (SignatureProperty)
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SignatureProperty, SignaturePropertyType (SignaturePropertyType)); next=491
                    // decode: element
                    error = decode_iso20_SignaturePropertyType(stream, &SignaturePropertiesType->SignatureProperty);
                    if (error == 0)
                    {
                        grammar_id = 491;
                    }
                    break;

                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 491:
            // Grammar: ID=491; read/write bits=2; END Element, START (SignatureProperty)
            error = exi_basetypes_decoder_nbit_uint(stream, 2, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: START (SignatureProperty, SignaturePropertyType (SignaturePropertyType)); next=2
                    // decode: element
                    error = decode_iso20_SignaturePropertyType(stream, &SignaturePropertiesType->SignatureProperty);
                    if (error == 0)
                    {
                        grammar_id = 2;
                    }
                    break;
                case 1:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
            }
            break;
        case 2:
            // Grammar: ID=2; read/write bits=1; END Element
            error = exi_basetypes_decoder_nbit_uint(stream, 1, &eventCode);
            if (error == 0)
            {
                switch(eventCode)
                {
                case 0:
                    // Event: END Element; set next=3
                    done = 1;
                    grammar_id = 3;
                    break;
                default:
                    error = EXI_ERROR__UNKNOWN_EVENT_CODE;
                    break;
                }
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


// main function for decoding
int decode_iso20_exiDocument(exi_bitstream_t* stream, struct iso20_exiDocument* exiDoc) {
    uint32_t eventCode;
    int error = exi_header_read_and_check(stream);

    if (error == 0)
    {
        init_iso20_exiDocument(exiDoc);

        error = exi_basetypes_decoder_nbit_uint(stream, 6, &eventCode);
        if (error == 0)
        {
            switch(eventCode)
            {
            case 0:
                error = decode_iso20_AuthorizationReqType(stream, &exiDoc->AuthorizationReq);
                exiDoc->AuthorizationReq_isUsed = 1u;
                break;
            case 1:
                error = decode_iso20_AuthorizationResType(stream, &exiDoc->AuthorizationRes);
                exiDoc->AuthorizationRes_isUsed = 1u;
                break;
            case 2:
                error = decode_iso20_AuthorizationSetupReqType(stream, &exiDoc->AuthorizationSetupReq);
                exiDoc->AuthorizationSetupReq_isUsed = 1u;
                break;
            case 3:
                error = decode_iso20_AuthorizationSetupResType(stream, &exiDoc->AuthorizationSetupRes);
                exiDoc->AuthorizationSetupRes_isUsed = 1u;
                break;
            case 4:
                error = decode_iso20_CLReqControlModeType(stream, &exiDoc->CLReqControlMode);
                exiDoc->CLReqControlMode_isUsed = 1u;
                break;
            case 5:
                error = decode_iso20_CLResControlModeType(stream, &exiDoc->CLResControlMode);
                exiDoc->CLResControlMode_isUsed = 1u;
                break;
            case 6:
                error = decode_iso20_CanonicalizationMethodType(stream, &exiDoc->CanonicalizationMethod);
                exiDoc->CanonicalizationMethod_isUsed = 1u;
                break;
            case 7:
                error = decode_iso20_CertificateInstallationReqType(stream, &exiDoc->CertificateInstallationReq);
                exiDoc->CertificateInstallationReq_isUsed = 1u;
                break;
            case 8:
                error = decode_iso20_CertificateInstallationResType(stream, &exiDoc->CertificateInstallationRes);
                exiDoc->CertificateInstallationRes_isUsed = 1u;
                break;
            case 9:
                error = decode_iso20_DSAKeyValueType(stream, &exiDoc->DSAKeyValue);
                exiDoc->DSAKeyValue_isUsed = 1u;
                break;
            case 10:
                error = decode_iso20_DigestMethodType(stream, &exiDoc->DigestMethod);
                exiDoc->DigestMethod_isUsed = 1u;
                break;
            case 11:
                // simple type! decode_iso20_DigestValue;
                break;
            case 12:
                error = decode_iso20_KeyInfoType(stream, &exiDoc->KeyInfo);
                exiDoc->KeyInfo_isUsed = 1u;
                break;
            case 13:
                // simple type! decode_iso20_KeyName;
                break;
            case 14:
                error = decode_iso20_KeyValueType(stream, &exiDoc->KeyValue);
                exiDoc->KeyValue_isUsed = 1u;
                break;
            case 15:
                error = decode_iso20_ManifestType(stream, &exiDoc->Manifest);
                exiDoc->Manifest_isUsed = 1u;
                break;
            case 16:
                error = decode_iso20_MeteringConfirmationReqType(stream, &exiDoc->MeteringConfirmationReq);
                exiDoc->MeteringConfirmationReq_isUsed = 1u;
                break;
            case 17:
                error = decode_iso20_MeteringConfirmationResType(stream, &exiDoc->MeteringConfirmationRes);
                exiDoc->MeteringConfirmationRes_isUsed = 1u;
                break;
            case 18:
                // simple type! decode_iso20_MgmtData;
                break;
            case 19:
                error = decode_iso20_ObjectType(stream, &exiDoc->Object);
                exiDoc->Object_isUsed = 1u;
                break;
            case 20:
                error = decode_iso20_PGPDataType(stream, &exiDoc->PGPData);
                exiDoc->PGPData_isUsed = 1u;
                break;
            case 21:
                error = decode_iso20_PowerDeliveryReqType(stream, &exiDoc->PowerDeliveryReq);
                exiDoc->PowerDeliveryReq_isUsed = 1u;
                break;
            case 22:
                error = decode_iso20_PowerDeliveryResType(stream, &exiDoc->PowerDeliveryRes);
                exiDoc->PowerDeliveryRes_isUsed = 1u;
                break;
            case 23:
                error = decode_iso20_RSAKeyValueType(stream, &exiDoc->RSAKeyValue);
                exiDoc->RSAKeyValue_isUsed = 1u;
                break;
            case 24:
                error = decode_iso20_ReferenceType(stream, &exiDoc->Reference);
                exiDoc->Reference_isUsed = 1u;
                break;
            case 25:
                error = decode_iso20_RetrievalMethodType(stream, &exiDoc->RetrievalMethod);
                exiDoc->RetrievalMethod_isUsed = 1u;
                break;
            case 26:
                error = decode_iso20_SPKIDataType(stream, &exiDoc->SPKIData);
                exiDoc->SPKIData_isUsed = 1u;
                break;
            case 27:
                error = decode_iso20_ScheduleExchangeReqType(stream, &exiDoc->ScheduleExchangeReq);
                exiDoc->ScheduleExchangeReq_isUsed = 1u;
                break;
            case 28:
                error = decode_iso20_ScheduleExchangeResType(stream, &exiDoc->ScheduleExchangeRes);
                exiDoc->ScheduleExchangeRes_isUsed = 1u;
                break;
            case 29:
                error = decode_iso20_ServiceDetailReqType(stream, &exiDoc->ServiceDetailReq);
                exiDoc->ServiceDetailReq_isUsed = 1u;
                break;
            case 30:
                error = decode_iso20_ServiceDetailResType(stream, &exiDoc->ServiceDetailRes);
                exiDoc->ServiceDetailRes_isUsed = 1u;
                break;
            case 31:
                error = decode_iso20_ServiceDiscoveryReqType(stream, &exiDoc->ServiceDiscoveryReq);
                exiDoc->ServiceDiscoveryReq_isUsed = 1u;
                break;
            case 32:
                error = decode_iso20_ServiceDiscoveryResType(stream, &exiDoc->ServiceDiscoveryRes);
                exiDoc->ServiceDiscoveryRes_isUsed = 1u;
                break;
            case 33:
                error = decode_iso20_ServiceSelectionReqType(stream, &exiDoc->ServiceSelectionReq);
                exiDoc->ServiceSelectionReq_isUsed = 1u;
                break;
            case 34:
                error = decode_iso20_ServiceSelectionResType(stream, &exiDoc->ServiceSelectionRes);
                exiDoc->ServiceSelectionRes_isUsed = 1u;
                break;
            case 35:
                error = decode_iso20_SessionSetupReqType(stream, &exiDoc->SessionSetupReq);
                exiDoc->SessionSetupReq_isUsed = 1u;
                break;
            case 36:
                error = decode_iso20_SessionSetupResType(stream, &exiDoc->SessionSetupRes);
                exiDoc->SessionSetupRes_isUsed = 1u;
                break;
            case 37:
                error = decode_iso20_SessionStopReqType(stream, &exiDoc->SessionStopReq);
                exiDoc->SessionStopReq_isUsed = 1u;
                break;
            case 38:
                error = decode_iso20_SessionStopResType(stream, &exiDoc->SessionStopRes);
                exiDoc->SessionStopRes_isUsed = 1u;
                break;
            case 39:
                error = decode_iso20_SignatureMethodType(stream, &exiDoc->SignatureMethod);
                exiDoc->SignatureMethod_isUsed = 1u;
                break;
            case 40:
                error = decode_iso20_SignaturePropertiesType(stream, &exiDoc->SignatureProperties);
                exiDoc->SignatureProperties_isUsed = 1u;
                break;
            case 41:
                error = decode_iso20_SignaturePropertyType(stream, &exiDoc->SignatureProperty);
                exiDoc->SignatureProperty_isUsed = 1u;
                break;
            case 42:
                error = decode_iso20_SignatureType(stream, &exiDoc->Signature);
                exiDoc->Signature_isUsed = 1u;
                break;
            case 43:
                error = decode_iso20_SignatureValueType(stream, &exiDoc->SignatureValue);
                exiDoc->SignatureValue_isUsed = 1u;
                break;
            case 44:
                error = decode_iso20_SignedInfoType(stream, &exiDoc->SignedInfo);
                exiDoc->SignedInfo_isUsed = 1u;
                break;
            case 45:
                error = decode_iso20_SignedInstallationDataType(stream, &exiDoc->SignedInstallationData);
                exiDoc->SignedInstallationData_isUsed = 1u;
                break;
            case 46:
                error = decode_iso20_SignedMeteringDataType(stream, &exiDoc->SignedMeteringData);
                exiDoc->SignedMeteringData_isUsed = 1u;
                break;
            case 47:
                error = decode_iso20_TransformType(stream, &exiDoc->Transform);
                exiDoc->Transform_isUsed = 1u;
                break;
            case 48:
                error = decode_iso20_TransformsType(stream, &exiDoc->Transforms);
                exiDoc->Transforms_isUsed = 1u;
                break;
            case 49:
                error = decode_iso20_VehicleCheckInReqType(stream, &exiDoc->VehicleCheckInReq);
                exiDoc->VehicleCheckInReq_isUsed = 1u;
                break;
            case 50:
                error = decode_iso20_VehicleCheckInResType(stream, &exiDoc->VehicleCheckInRes);
                exiDoc->VehicleCheckInRes_isUsed = 1u;
                break;
            case 51:
                error = decode_iso20_VehicleCheckOutReqType(stream, &exiDoc->VehicleCheckOutReq);
                exiDoc->VehicleCheckOutReq_isUsed = 1u;
                break;
            case 52:
                error = decode_iso20_VehicleCheckOutResType(stream, &exiDoc->VehicleCheckOutRes);
                exiDoc->VehicleCheckOutRes_isUsed = 1u;
                break;
            case 53:
                error = decode_iso20_X509DataType(stream, &exiDoc->X509Data);
                exiDoc->X509Data_isUsed = 1u;
                break;
            default:
                error = EXI_ERROR__UNSUPPORTED_SUB_EVENT;
                break;
            }
        }
    }

    return error;
}


