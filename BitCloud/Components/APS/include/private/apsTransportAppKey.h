/**************************************************************************//**
  \file apsTransportAppKey.h

  \brief Interface of transport application key.

  \author
    Atmel Corporation: http://www.atmel.com \n
    Support email: avr@atmel.com

  Copyright (c) 2008 , Atmel Corporation. All rights reserved.
  Licensed under Atmel's Limited License Agreement (BitCloudTM).

  \internal
   History:
    2011-05-05 Max Gekk - Created.
   Last change:
    $Id: apsTransportAppKey.h 17813 2011-07-04 14:11:12Z dloskutnikov $
 ******************************************************************************/
#if !defined _APS_TRANSPORT_APP_KEY_H
#define _APS_TRANSPORT_APP_KEY_H

/******************************************************************************
                                Includes section
 ******************************************************************************/
#if defined _SECURITY_ && defined _LINK_SECURITY_ 
#include <apsTransportKey.h>

/******************************************************************************
                                 Types section
 ******************************************************************************/
BEGIN_PACK
/** Type of Transport-Key Command Frame (see ZigBee spec r19, Figure 4.8
 * with application master or link key descriptor field (see Figure 4.11). */
typedef struct PACK _ApsTransportAppKeyFrame_t
{
  /** Common part of APS transport key command frame. */
  ApsTransportKeyCommonFrame_t common;
  /** The key sub-field shall contain a master or link key that is shared
   * with the device identified in the partner address sub-field. See ZigBee
   * Specification, 4.4.9.2.3.3, page 481. */
  uint8_t key[SECURITY_KEY_SIZE];
  /** The partner address sub-field shall contain the address of the other
   * device that was sent this link or master key. */
  uint8_t partnerAddress[sizeof(ExtAddr_t)];
  /** The initiator flag sub-field shall be set to 1 if the device receiving
   * this packet requested this key. Otherwise, this sub-field shall be set
   * to 0. See ZigBee spec r19, 4.4.9.2.3.3, Figure 4.11, page 481. */
  uint8_t initiatorFlag;
} ApsTransportAppKeyFrame_t;
END_PACK

/******************************************************************************
                                Prototypes section
 ******************************************************************************/
#if defined _TRUST_CENTRE_
/**************************************************************************//**
  \brief Checks specific parameters of Transport Application Key request.

  \param[in] req - pointer to parameters of APSME-TRANSPORT-KEY.request.
  \return Pointer to function for preparing and sending APS Transport Key command.
 ******************************************************************************/
APS_PRIVATE ApsTransportKeyCommand_t
apsCheckTransportAppKeyReq(APS_TransportKeyReq_t *const req);
#endif /* _TRUST_CENTRE_ */

/**************************************************************************//**
  \brief Process an incoming transport key command with application key.

  \param[in] commandInd - pointer to received command descriptor.

  \return 'false' if structure commandInd->nwkDataInd is used otherwise 'true'.
 ******************************************************************************/
APS_PRIVATE bool apsTransportAppKeyInd(const ApsCommandInd_t *const commandInd);

#else
#define apsTransportAppKeyInd(commandInd) (true)
#endif /* _SECURITY_ and _LINK_SECURITY_ */

#if !(defined _SECURITY_ && defined _LINK_SECURITY_ && defined _TRUST_CENTRE_)

#define apsCheckTransportAppKeyReq(req) NULL
#endif
#endif /* _APS_TRANSPORT_APP_KEY_H */
/** eof apsTransportAppKey.h */
