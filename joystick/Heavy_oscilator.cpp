/**
 * Copyright (c) 2025 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#include "Heavy_oscilator.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_oscilator *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_oscilator_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_oscilator));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_oscilator(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_oscilator_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_oscilator));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_oscilator(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_oscilator_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_oscilator();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_oscilator::Heavy_oscilator(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += cDelay_init(this, &cDelay_ADRIYkcU, 1000.0f);
  numBytes += cVar_init_f(&cVar_fxjqNf9g, 1.0f);
  numBytes += cVar_init_f(&cVar_zZr3pfAa, 0.0f);
  numBytes += cIf_init(&cIf_OCSIdUQD, false);
  numBytes += cDelay_init(this, &cDelay_xgv2mT3T, 0.0f);
  numBytes += cVar_init_f(&cVar_rKxWZwrv, 20.0f);
  numBytes += cBinop_init(&cBinop_sxqOg1kO, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_EFsPvjLy, 0.0f);
  numBytes += cSlice_init(&cSlice_956kD1M7, 1, -1);
  numBytes += cSlice_init(&cSlice_Lf2M2Axe, 1, -1);
  numBytes += cVar_init_f(&cVar_QFwGKWTx, 0.0f);
  numBytes += cVar_init_f(&cVar_CxS8E1rz, 20.0f);
  numBytes += cVar_init_f(&cVar_e2QzofsH, 0.0f);
  numBytes += cVar_init_f(&cVar_8kq40XDs, 0.0f);
  numBytes += cVar_init_f(&cVar_e7voqfOh, 0.0f);
  numBytes += cSlice_init(&cSlice_6I7PofHa, 1, 1);
  numBytes += cSlice_init(&cSlice_MknGRLfX, 0, 1);
  numBytes += cBinop_init(&cBinop_GjJfKUWN, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_wiyLKsdc, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_tEPXppmK, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_bz3TXvws, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_wJpTfBOK, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_CGvoqtIB, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_C9VKzEv2, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_uuWlXGq1, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_NM1txbBc, 1.0f);
  numBytes += cPack_init(&cPack_st09lugV, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_z414T7Bz, 1.0f);
  numBytes += cVar_init_f(&cVar_mTxXNMN7, 11.0f);
  numBytes += cVar_init_f(&cVar_hZpoTEBK, 1.0f);
  numBytes += cIf_init(&cIf_46VRmpyo, true);
  numBytes += cVar_init_f(&cVar_dJiytzPh, 11.0f);
  numBytes += cIf_init(&cIf_O7YgepM2, true);
  numBytes += cSlice_init(&cSlice_eTRYqz8h, 2, 1);
  numBytes += cSlice_init(&cSlice_IFkQln4R, 1, 1);
  numBytes += cSlice_init(&cSlice_Fjg2Hmd1, 0, 1);
  numBytes += cIf_init(&cIf_70gCMtEC, false);
  numBytes += cIf_init(&cIf_Ly1udjZ0, false);
  numBytes += cIf_init(&cIf_J4EbceIN, false);
  numBytes += cIf_init(&cIf_EhdYlMg1, true);
  numBytes += cIf_init(&cIf_wevA2Ty0, true);
  numBytes += cIf_init(&cIf_9jBOA7gp, true);
  numBytes += cIf_init(&cIf_cjBMuI5L, true);
  numBytes += cIf_init(&cIf_zLe9mwQM, false);
  numBytes += cIf_init(&cIf_7SdfT2wa, false);
  numBytes += cVar_init_f(&cVar_J0ccA27A, 0.0f);
  numBytes += cBinop_init(&cBinop_plJFnUXg, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_rh1e2meB, 0.0f); // __eq
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_oscilator::~Heavy_oscilator() {
  cPack_free(&cPack_st09lugV);
}

HvTable *Heavy_oscilator::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_oscilator::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x41BE0F9C: { // __hv_ctlin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_KK0VG5yu_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DMSVNCoZ_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_oscilator::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 0;
}



/*
 * Send Function Implementations
 */


void Heavy_oscilator::cCast_Pppyj9Wp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_cwvtHNJr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cSwitchcase_cwvtHNJr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_HiIW3WC1_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_HiIW3WC1_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_ADRIYkcU, 1, m, &cDelay_ADRIYkcU_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bcwu65pR_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cDelay_ADRIYkcU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ADRIYkcU, m);
  cMsg_BAlgXfHK_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cMsg_HiIW3WC1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ADRIYkcU, 0, m, &cDelay_ADRIYkcU_sendMessage);
}

void Heavy_oscilator::cCast_bcwu65pR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ADRIYkcU, 0, m, &cDelay_ADRIYkcU_sendMessage);
}

void Heavy_oscilator::cVar_fxjqNf9g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_15wzJrQr_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 127.0f, 0, m, &cBinop_w6iS2pft_sendMessage);
}

void Heavy_oscilator::cBinop_15wzJrQr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fxjqNf9g, 1, m, &cVar_fxjqNf9g_sendMessage);
}

void Heavy_oscilator::cVar_zZr3pfAa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_V1uBgHWe_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_OCSIdUQD, 0, m, &cIf_OCSIdUQD_sendMessage);
}

void Heavy_oscilator::cUnop_bEYxWuke_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 127.0f, 0, m, &cBinop_ksPi80zr_sendMessage);
}

void Heavy_oscilator::cUnop_51mJV9Ur_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 127.0f, 0, m, &cBinop_ksPi80zr_sendMessage);
}

void Heavy_oscilator::cIf_OCSIdUQD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_51mJV9Ur_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_bEYxWuke_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_V1uBgHWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_OCSIdUQD, 1, m, &cIf_OCSIdUQD_sendMessage);
}

void Heavy_oscilator::cMsg_pmOWo0AL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KkNp7KBT_sendMessage);
}

void Heavy_oscilator::cSystem_KkNp7KBT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wiyLKsdc, HV_BINOP_MULTIPLY, 1, m, &cBinop_wiyLKsdc_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GjJfKUWN, HV_BINOP_MULTIPLY, 1, m, &cBinop_GjJfKUWN_sendMessage);
}

void Heavy_oscilator::cSwitchcase_CROMJxG4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_hDAVU9lz_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_hDAVU9lz_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UFghpRqI_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cDelay_xgv2mT3T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xgv2mT3T, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xgv2mT3T, 0, m, &cDelay_xgv2mT3T_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EFsPvjLy, 0, m, &cVar_EFsPvjLy_sendMessage);
}

void Heavy_oscilator::cCast_UFghpRqI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hDAVU9lz_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xgv2mT3T, 0, m, &cDelay_xgv2mT3T_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EFsPvjLy, 0, m, &cVar_EFsPvjLy_sendMessage);
}

void Heavy_oscilator::cMsg_v6WwEou0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_K7QXO20W_sendMessage);
}

void Heavy_oscilator::cSystem_K7QXO20W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Kf73bCOG_sendMessage);
}

void Heavy_oscilator::cVar_rKxWZwrv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sxqOg1kO, HV_BINOP_MULTIPLY, 0, m, &cBinop_sxqOg1kO_sendMessage);
}

void Heavy_oscilator::cMsg_hDAVU9lz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_xgv2mT3T, 0, m, &cDelay_xgv2mT3T_sendMessage);
}

void Heavy_oscilator::cBinop_jx7qfSBX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xgv2mT3T, 2, m, &cDelay_xgv2mT3T_sendMessage);
}

void Heavy_oscilator::cBinop_Kf73bCOG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sxqOg1kO, HV_BINOP_MULTIPLY, 1, m, &cBinop_sxqOg1kO_sendMessage);
}

void Heavy_oscilator::cBinop_sxqOg1kO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_jx7qfSBX_sendMessage);
}

void Heavy_oscilator::cVar_EFsPvjLy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tEPXppmK, HV_BINOP_SUBTRACT, 0, m, &cBinop_tEPXppmK_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_bGYSRqtR_sendMessage);
}

void Heavy_oscilator::cSwitchcase_oAy4xkFv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wla2z7Gx_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TSPvr6Gm_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_oscilator::cCast_wla2z7Gx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_e7voqfOh, 0, m, &cVar_e7voqfOh_sendMessage);
}

void Heavy_oscilator::cCast_TSPvr6Gm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Jfr73jZP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cNX8Qh5X_sendMessage);
}

void Heavy_oscilator::cSwitchcase_l0OVPyx3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_956kD1M7, 0, m, &cSlice_956kD1M7_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Lf2M2Axe, 0, m, &cSlice_Lf2M2Axe_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IwOySgoB_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_6I7PofHa, 0, m, &cSlice_6I7PofHa_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_MknGRLfX, 0, m, &cSlice_MknGRLfX_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qeWubkxd_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_J7fTj8xz_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_956kD1M7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_DBIFlaz3_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_DBIFlaz3_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_Lf2M2Axe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_g0ALrrVJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TPSHxpHu_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_g0ALrrVJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TPSHxpHu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_QFwGKWTx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZyuzZ09t_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7mUp2Vkv_sendMessage);
}

void Heavy_oscilator::cVar_CxS8E1rz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_W9zEw6um_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cSwitchcase_W9zEw6um_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_INsfWBqn_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_wiyLKsdc, HV_BINOP_MULTIPLY, 0, m, &cBinop_wiyLKsdc_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_wJpTfBOK, HV_BINOP_DIVIDE, 1, m, &cBinop_wJpTfBOK_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_rKxWZwrv, 0, m, &cVar_rKxWZwrv_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cCast_INsfWBqn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qtKhezmj_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cVar_e2QzofsH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uuWlXGq1, HV_BINOP_SUBTRACT, 1, m, &cBinop_uuWlXGq1_sendMessage);
}

void Heavy_oscilator::cVar_8kq40XDs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_e7voqfOh, 0, m, &cVar_e7voqfOh_sendMessage);
}

void Heavy_oscilator::cVar_e7voqfOh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bz3TXvws, HV_BINOP_ADD, 0, m, &cBinop_bz3TXvws_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_C9VKzEv2, HV_BINOP_ADD, 0, m, &cBinop_C9VKzEv2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_fxjqNf9g, 0, m, &cVar_fxjqNf9g_sendMessage);
}

void Heavy_oscilator::cSlice_6I7PofHa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZyuzZ09t_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7mUp2Vkv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_MknGRLfX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OqKXIvHA_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Xvj7mAoU_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_C8CcNc4y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EFsPvjLy, 1, m, &cVar_EFsPvjLy_sendMessage);
}

void Heavy_oscilator::cBinop_GjJfKUWN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_C8CcNc4y_sendMessage);
}

void Heavy_oscilator::cBinop_wiyLKsdc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_uUL0dK7a_sendMessage);
}

void Heavy_oscilator::cBinop_uUL0dK7a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tEPXppmK, HV_BINOP_SUBTRACT, 1, m, &cBinop_tEPXppmK_sendMessage);
}

void Heavy_oscilator::cBinop_tEPXppmK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EFsPvjLy, 1, m, &cVar_EFsPvjLy_sendMessage);
}

void Heavy_oscilator::cMsg_6969VZ7c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_CROMJxG4_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cMsg_qFXUe27u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_CROMJxG4_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_C9VKzEv2, HV_BINOP_ADD, 1, m, &cBinop_C9VKzEv2_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bz3TXvws, HV_BINOP_ADD, 1, m, &cBinop_bz3TXvws_sendMessage);
}

void Heavy_oscilator::cBinop_bGYSRqtR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_oAy4xkFv_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cBinop_bz3TXvws_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_e7voqfOh, 1, m, &cVar_e7voqfOh_sendMessage);
}

void Heavy_oscilator::cBinop_wJpTfBOK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CGvoqtIB, HV_BINOP_DIVIDE, 1, m, &cBinop_CGvoqtIB_sendMessage);
}

void Heavy_oscilator::cBinop_CGvoqtIB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_C9VKzEv2, HV_BINOP_ADD, 1, m, &cBinop_C9VKzEv2_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bz3TXvws, HV_BINOP_ADD, 1, m, &cBinop_bz3TXvws_sendMessage);
}

void Heavy_oscilator::cCast_ZyuzZ09t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GjJfKUWN, HV_BINOP_MULTIPLY, 0, m, &cBinop_GjJfKUWN_sendMessage);
}

void Heavy_oscilator::cCast_7mUp2Vkv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wJpTfBOK, HV_BINOP_DIVIDE, 0, m, &cBinop_wJpTfBOK_sendMessage);
}

void Heavy_oscilator::cCast_OqKXIvHA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8kq40XDs, 1, m, &cVar_8kq40XDs_sendMessage);
}

void Heavy_oscilator::cCast_Xvj7mAoU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uuWlXGq1, HV_BINOP_SUBTRACT, 0, m, &cBinop_uuWlXGq1_sendMessage);
}

void Heavy_oscilator::cCast_cNX8Qh5X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8kq40XDs, 0, m, &cVar_8kq40XDs_sendMessage);
}

void Heavy_oscilator::cCast_Jfr73jZP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qFXUe27u_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_C9VKzEv2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_e2QzofsH, 0, m, &cVar_e2QzofsH_sendMessage);
}

void Heavy_oscilator::cMsg_DBIFlaz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_CROMJxG4_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cMsg_xLQajHPz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_QFwGKWTx, 1, m, &cVar_QFwGKWTx_sendMessage);
}

void Heavy_oscilator::cMsg_qtKhezmj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wiyLKsdc, HV_BINOP_MULTIPLY, 0, m, &cBinop_wiyLKsdc_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wJpTfBOK, HV_BINOP_DIVIDE, 1, m, &cBinop_wJpTfBOK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rKxWZwrv, 0, m, &cVar_rKxWZwrv_sendMessage);
}

void Heavy_oscilator::cCast_g0ALrrVJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DBIFlaz3_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_TPSHxpHu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KcWBiXKf_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_C9VKzEv2, HV_BINOP_ADD, 0, m, &cBinop_C9VKzEv2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_e7voqfOh, 1, m, &cVar_e7voqfOh_sendMessage);
}

void Heavy_oscilator::cBinop_uuWlXGq1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CGvoqtIB, HV_BINOP_DIVIDE, 0, m, &cBinop_CGvoqtIB_sendMessage);
}

void Heavy_oscilator::cCast_KcWBiXKf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qFXUe27u_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_qeWubkxd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6969VZ7c_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_J7fTj8xz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xLQajHPz_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_IwOySgoB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QFwGKWTx, 0, m, &cVar_QFwGKWTx_sendMessage);
}

void Heavy_oscilator::cBinop_lcrlcfaD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_2zr8hsDT_sendMessage);
}

void Heavy_oscilator::cBinop_2zr8hsDT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_st09lugV, 0, m, &cPack_st09lugV_sendMessage);
}

void Heavy_oscilator::cVar_NM1txbBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_gFnS1MLM_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_hhKOlndm_sendMessage);
}

void Heavy_oscilator::cBinop_gFnS1MLM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NM1txbBc, 1, m, &cVar_NM1txbBc_sendMessage);
}

void Heavy_oscilator::cPack_st09lugV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_PT6v4N35_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cVar_z414T7Bz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6fVgXta9_sendMessage);
}

void Heavy_oscilator::cVar_mTxXNMN7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_st09lugV, 1, m, &cPack_st09lugV_sendMessage);
}

void Heavy_oscilator::cSend_PT6v4N35_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "__hv_ctlout", 0xE5E2A040, m);
}

void Heavy_oscilator::cCast_xYsx3bwX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mTxXNMN7, 0, m, &cVar_mTxXNMN7_sendMessage);
}

void Heavy_oscilator::cCast_ZGHQQS02_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_z414T7Bz, 0, m, &cVar_z414T7Bz_sendMessage);
}

void Heavy_oscilator::cBinop_6fVgXta9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_zxUTBVGm_sendMessage);
}

void Heavy_oscilator::cBinop_zxUTBVGm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_st09lugV, 2, m, &cPack_st09lugV_sendMessage);
}

void Heavy_oscilator::cVar_hZpoTEBK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_oJbHfnVu_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_46VRmpyo, 0, m, &cIf_46VRmpyo_sendMessage);
}

void Heavy_oscilator::cUnop_R698B7d3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qSY9tPfq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MbzAxncz_sendMessage);
}

void Heavy_oscilator::cUnop_Dq48wTqZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qSY9tPfq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MbzAxncz_sendMessage);
}

void Heavy_oscilator::cIf_46VRmpyo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_Dq48wTqZ_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_R698B7d3_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_oJbHfnVu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_46VRmpyo, 1, m, &cIf_46VRmpyo_sendMessage);
}

void Heavy_oscilator::cVar_dJiytzPh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_8dFPSoPz_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_O7YgepM2, 0, m, &cIf_O7YgepM2_sendMessage);
}

void Heavy_oscilator::cUnop_ohkOfrtD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_a07kVl0h_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0w6byLTl_sendMessage);
}

void Heavy_oscilator::cUnop_9qU6Ln7n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_a07kVl0h_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0w6byLTl_sendMessage);
}

void Heavy_oscilator::cIf_O7YgepM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_9qU6Ln7n_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ohkOfrtD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_8dFPSoPz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_O7YgepM2, 1, m, &cIf_O7YgepM2_sendMessage);
}

void Heavy_oscilator::cSlice_eTRYqz8h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_D7sqgxyN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_IFkQln4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_Ly1udjZ0, 0, m, &cIf_Ly1udjZ0_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_plJFnUXg, HV_BINOP_EQ, 0, m, &cBinop_plJFnUXg_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_Fjg2Hmd1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_70gCMtEC, 0, m, &cIf_70gCMtEC_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_J4EbceIN, 0, m, &cIf_J4EbceIN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_70gCMtEC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Pppyj9Wp_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_NM1txbBc, 0, m, &cVar_NM1txbBc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_Ly1udjZ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_J4EbceIN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_wevA2Ty0, 0, m, &cIf_wevA2Ty0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_EhdYlMg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_cjBMuI5L, 0, m, &cIf_cjBMuI5L_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_wevA2Ty0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_9jBOA7gp, 0, m, &cIf_9jBOA7gp_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_9jBOA7gp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Pppyj9Wp_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_NM1txbBc, 0, m, &cVar_NM1txbBc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_cjBMuI5L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_zLe9mwQM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_rh1e2meB, HV_BINOP_EQ, 0, m, &cBinop_rh1e2meB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_7SdfT2wa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_J0ccA27A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EhdYlMg1, 0, m, &cIf_EhdYlMg1_sendMessage);
}

void Heavy_oscilator::cBinop_D7sqgxyN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_Xs5zlmbV_sendMessage);
}

void Heavy_oscilator::cBinop_Xs5zlmbV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lkJUCp9Z_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IFRcUTwD_sendMessage);
}

void Heavy_oscilator::cBinop_plJFnUXg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZS6uVSk8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8pI5zDVk_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TfJv0Boc_sendMessage);
}

void Heavy_oscilator::cCast_qSY9tPfq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_plJFnUXg, HV_BINOP_EQ, 1, m, &cBinop_plJFnUXg_sendMessage);
}

void Heavy_oscilator::cCast_MbzAxncz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_oGw3bWeJ_sendMessage);
}

void Heavy_oscilator::cBinop_oGw3bWeJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ur5CKBc3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FXqItFNM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Wc3Uc2Iw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RcCdhYHe_sendMessage);
}

void Heavy_oscilator::cBinop_vsLZWSFf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wevA2Ty0, 1, m, &cIf_wevA2Ty0_sendMessage);
}

void Heavy_oscilator::cCast_0w6byLTl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rh1e2meB, HV_BINOP_EQ, 1, m, &cBinop_rh1e2meB_sendMessage);
}

void Heavy_oscilator::cCast_a07kVl0h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_rF1U4crY_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_VhotNQMP_sendMessage);
}

void Heavy_oscilator::cBinop_rF1U4crY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zLe9mwQM, 1, m, &cIf_zLe9mwQM_sendMessage);
}

void Heavy_oscilator::cCast_IFRcUTwD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8dZ9cZHf_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rlZDIN2p_sendMessage);
}

void Heavy_oscilator::cCast_lkJUCp9Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zLe9mwQM, 0, m, &cIf_zLe9mwQM_sendMessage);
}

void Heavy_oscilator::cBinop_VhotNQMP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cjBMuI5L, 1, m, &cIf_cjBMuI5L_sendMessage);
}

void Heavy_oscilator::cBinop_rh1e2meB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_9jBOA7gp, 1, m, &cIf_9jBOA7gp_sendMessage);
}

void Heavy_oscilator::cCast_rlZDIN2p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_J0ccA27A, 1, m, &cVar_J0ccA27A_sendMessage);
}

void Heavy_oscilator::cCast_8dZ9cZHf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_7SdfT2wa, 0, m, &cIf_7SdfT2wa_sendMessage);
}

void Heavy_oscilator::cCast_ZS6uVSk8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EhdYlMg1, 1, m, &cIf_EhdYlMg1_sendMessage);
}

void Heavy_oscilator::cCast_TfJv0Boc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_J4EbceIN, 1, m, &cIf_J4EbceIN_sendMessage);
}

void Heavy_oscilator::cCast_8pI5zDVk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_J0ccA27A, 0, m, &cVar_J0ccA27A_sendMessage);
}

void Heavy_oscilator::cCast_RcCdhYHe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_vsLZWSFf_sendMessage);
}

void Heavy_oscilator::cCast_FXqItFNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Ly1udjZ0, 1, m, &cIf_Ly1udjZ0_sendMessage);
}

void Heavy_oscilator::cCast_Wc3Uc2Iw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_70gCMtEC, 1, m, &cIf_70gCMtEC_sendMessage);
}

void Heavy_oscilator::cCast_ur5CKBc3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_7SdfT2wa, 1, m, &cIf_7SdfT2wa_sendMessage);
}

void Heavy_oscilator::cBinop_hhKOlndm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZHSDgp1T_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_w6iS2pft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zZr3pfAa, 0, m, &cVar_zZr3pfAa_sendMessage);
}

void Heavy_oscilator::cBinop_ksPi80zr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_cam4J9fF_sendMessage);
}

void Heavy_oscilator::cBinop_cam4J9fF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 127.0f, 0, m, &cBinop_lcrlcfaD_sendMessage);
}

void Heavy_oscilator::cMsg_ZHSDgp1T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSwitchcase_l0OVPyx3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cMsg_BAlgXfHK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 4000.0f);
  cSwitchcase_l0OVPyx3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cReceive_DMSVNCoZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v6WwEou0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rKxWZwrv, 0, m, &cVar_rKxWZwrv_sendMessage);
  cMsg_pmOWo0AL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_e2QzofsH, 0, m, &cVar_e2QzofsH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_CxS8E1rz, 0, m, &cVar_CxS8E1rz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZGHQQS02_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xYsx3bwX_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_dJiytzPh, 0, m, &cVar_dJiytzPh_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hZpoTEBK, 0, m, &cVar_hZpoTEBK_sendMessage);
}

void Heavy_oscilator::cReceive_KK0VG5yu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_eTRYqz8h, 0, m, &cSlice_eTRYqz8h_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_IFkQln4R, 0, m, &cSlice_IFkQln4R_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Fjg2Hmd1, 0, m, &cSlice_Fjg2Hmd1_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_oscilator::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }

  sendBangToReceiver(0xDD21C0EB); // send to __hv_bang~ on next cycle
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars

  // input and output vars

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    

    // process all signal functions

    // save output vars to output buffer
    // no output channels
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_oscilator::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 0 channel(s)
  float **const bOut = NULL;

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_oscilator::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 0 channel(s)
  float *const bOut = NULL;

  int n = processInline(bIn, bOut, n4);

  

  return n;
}
