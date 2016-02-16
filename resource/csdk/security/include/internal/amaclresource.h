//******************************************************************
//
// Copyright 2015 Intel Mobile Communications GmbH All Rights Reserved.
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#ifndef IOTVT_SRM_AMACLR_H
#define IOTVT_SRM_AMACLR_H

/**
 * @file
 *
 * This file contains the APIs for the /oic/sec/amacl resource is an ACL structure that
 * specifies which resources will use an Access Manager Service (AMS) to resolve access decisions.
 * It dynamically obtains an ACL using an AMS.
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialize Amacl resource by loading data from persistent storage.
 *
 * @return ::OC_STACK_OK for Success, otherwise some error value.
 */
OCStackResult InitAmaclResource();

/**
 * Perform cleanup for Amacl resources.
 */
void DeInitAmaclResource();

/**
 * This method is used by PolicyEngine to retrieve amsId for the resource.
 * If the Amacl is found for the given resource then populate the parameter
 * amsId with Amacl resource amss id.
 *
 * @param resource for which AMS service is required.
 * @param amsId of the ams service for the given resource.
 *
 * @return ::OC_STACK_OK, if Amacl is found for the resource, else ::OC_STACK_ERROR,
 *  if no Amacl found for the resource.
 */
OCStackResult AmaclGetAmsDeviceId(const char *resource, OicUuid_t *amsId);

/**
 * This function converts Amacl data into CBOR format.
 * Caller needs to invoke 'free' when done using returned string.
 *
 * @param amacl instance of @ref OicSecAmacl_t structure.
 * @param cborPayload is the converted cbor value of @ref OicSecAmacl_t structure.
 * @param cborSize is the size of the cbor payload. This value is the size of the
 * cborPayload. It should not be NON-NULL value.
 *
 * @return ::OC_STACK_OK for Success. ::OC_STACK_INVALID in case of invalid parameters.
 * ::OC_STACK_ERROR in case of error in converting to cbor.
 */
OCStackResult AmaclToCBORPayload(const OicSecAmacl_t *amacl, uint8_t **cborPayload,
                                 size_t *cborSize);

#ifdef __cplusplus
}
#endif

#endif //IOTVT_SRM_AMACLR_H
