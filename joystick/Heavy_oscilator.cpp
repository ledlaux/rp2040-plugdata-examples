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
  numBytes += cDelay_init(this, &cDelay_6cIMZZ5c, 1000.0f);
  numBytes += cVar_init_f(&cVar_bUo8Q6QH, 1.0f);
  numBytes += cVar_init_f(&cVar_YxaBwyvH, 0.0f);
  numBytes += cIf_init(&cIf_lXOJ5ZUO, false);
  numBytes += cPack_init(&cPack_a02DMVPr, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_jGw6VDkp, 11.0f);
  numBytes += cVar_init_f(&cVar_hwKAbXgU, 1.0f);
  numBytes += cDelay_init(this, &cDelay_4HIsnHVk, 0.0f);
  numBytes += cVar_init_f(&cVar_3wExzgq0, 20.0f);
  numBytes += cBinop_init(&cBinop_qWUGInOO, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_gmoMKC4V, 0.0f);
  numBytes += cSlice_init(&cSlice_EVadOW7z, 1, -1);
  numBytes += cSlice_init(&cSlice_LjELob1Q, 1, -1);
  numBytes += cVar_init_f(&cVar_x9tu2yin, 0.0f);
  numBytes += cVar_init_f(&cVar_NiEls56W, 20.0f);
  numBytes += cVar_init_f(&cVar_qPdSy9Kp, 0.0f);
  numBytes += cVar_init_f(&cVar_nkRb1GIH, 0.0f);
  numBytes += cVar_init_f(&cVar_bNitOecK, 0.0f);
  numBytes += cSlice_init(&cSlice_NYHvxHMT, 1, 1);
  numBytes += cSlice_init(&cSlice_xC4L0naM, 0, 1);
  numBytes += cBinop_init(&cBinop_JEWaGsW2, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_RGtLDEyO, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_HbKRtZKT, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_jaTeGc6l, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_LSVBZjVK, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_euxzMNWi, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_hvzhr2Ya, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_07d5AF2e, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_pn4pioqt, 1.0f);
  numBytes += cVar_init_f(&cVar_0e2qYnMo, 11.0f);
  numBytes += cIf_init(&cIf_RDkVCSvN, true);
  numBytes += cVar_init_f(&cVar_1DcVJc5T, 1.0f);
  numBytes += cIf_init(&cIf_vNrEELkt, true);
  numBytes += cSlice_init(&cSlice_gbkM7qkt, 2, 1);
  numBytes += cSlice_init(&cSlice_g4WnD2jY, 1, 1);
  numBytes += cSlice_init(&cSlice_yVZ4Za9F, 0, 1);
  numBytes += cIf_init(&cIf_UMQ8otJM, false);
  numBytes += cIf_init(&cIf_kODPIagP, false);
  numBytes += cIf_init(&cIf_7aqpr9GZ, false);
  numBytes += cIf_init(&cIf_4za479rs, true);
  numBytes += cIf_init(&cIf_kxpQNChW, true);
  numBytes += cIf_init(&cIf_RZMGPphJ, true);
  numBytes += cIf_init(&cIf_gzuwevOs, true);
  numBytes += cIf_init(&cIf_HgZKMSFL, false);
  numBytes += cIf_init(&cIf_BFH0Tyln, false);
  numBytes += cVar_init_f(&cVar_CwRNl4gv, 0.0f);
  numBytes += cBinop_init(&cBinop_8lUuwXwK, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_JYfB4Hoj, 0.0f); // __eq
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_oscilator::~Heavy_oscilator() {
  cPack_free(&cPack_a02DMVPr);
}

HvTable *Heavy_oscilator::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_oscilator::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x41BE0F9C: { // __hv_ctlin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_pInKoDpQ_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WVlCvUEd_sendMessage);
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


void Heavy_oscilator::cCast_3HC5szNx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_wbSKx9ZS_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cSwitchcase_wbSKx9ZS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_ueDKGkJ4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_ueDKGkJ4_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_6cIMZZ5c, 1, m, &cDelay_6cIMZZ5c_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7TdoLQ7A_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cDelay_6cIMZZ5c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6cIMZZ5c, m);
  cMsg_Q57uYtzD_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cMsg_ueDKGkJ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_6cIMZZ5c, 0, m, &cDelay_6cIMZZ5c_sendMessage);
}

void Heavy_oscilator::cCast_7TdoLQ7A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6cIMZZ5c, 0, m, &cDelay_6cIMZZ5c_sendMessage);
}

void Heavy_oscilator::cVar_bUo8Q6QH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_sT96zeuw_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 127.0f, 0, m, &cBinop_C4gvBpPn_sendMessage);
}

void Heavy_oscilator::cBinop_sT96zeuw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bUo8Q6QH, 1, m, &cVar_bUo8Q6QH_sendMessage);
}

void Heavy_oscilator::cVar_YxaBwyvH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_mdByKKRN_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_lXOJ5ZUO, 0, m, &cIf_lXOJ5ZUO_sendMessage);
}

void Heavy_oscilator::cUnop_eI0Ykmen_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 127.0f, 0, m, &cBinop_RmTkbZLY_sendMessage);
}

void Heavy_oscilator::cUnop_zJypmdxN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 127.0f, 0, m, &cBinop_RmTkbZLY_sendMessage);
}

void Heavy_oscilator::cIf_lXOJ5ZUO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_zJypmdxN_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_eI0Ykmen_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_mdByKKRN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_lXOJ5ZUO, 1, m, &cIf_lXOJ5ZUO_sendMessage);
}

void Heavy_oscilator::cPack_a02DMVPr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_52M7NFGt_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cVar_jGw6VDkp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_fwV6ds5O_sendMessage);
}

void Heavy_oscilator::cVar_hwKAbXgU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_a02DMVPr, 1, m, &cPack_a02DMVPr_sendMessage);
}

void Heavy_oscilator::cSend_52M7NFGt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "__hv_ctlout", 0xE5E2A040, m);
}

void Heavy_oscilator::cCast_AdSzTRhI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hwKAbXgU, 0, m, &cVar_hwKAbXgU_sendMessage);
}

void Heavy_oscilator::cCast_TCYXGYRk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jGw6VDkp, 0, m, &cVar_jGw6VDkp_sendMessage);
}

void Heavy_oscilator::cBinop_fwV6ds5O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_F0cQE6MN_sendMessage);
}

void Heavy_oscilator::cBinop_F0cQE6MN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_a02DMVPr, 2, m, &cPack_a02DMVPr_sendMessage);
}

void Heavy_oscilator::cMsg_CX6VZlEs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_F3y1nbfk_sendMessage);
}

void Heavy_oscilator::cSystem_F3y1nbfk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RGtLDEyO, HV_BINOP_MULTIPLY, 1, m, &cBinop_RGtLDEyO_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JEWaGsW2, HV_BINOP_MULTIPLY, 1, m, &cBinop_JEWaGsW2_sendMessage);
}

void Heavy_oscilator::cSwitchcase_4J7hujSU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_0s2rY33x_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_0s2rY33x_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WE2bvR61_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cDelay_4HIsnHVk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4HIsnHVk, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4HIsnHVk, 0, m, &cDelay_4HIsnHVk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gmoMKC4V, 0, m, &cVar_gmoMKC4V_sendMessage);
}

void Heavy_oscilator::cCast_WE2bvR61_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0s2rY33x_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4HIsnHVk, 0, m, &cDelay_4HIsnHVk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_gmoMKC4V, 0, m, &cVar_gmoMKC4V_sendMessage);
}

void Heavy_oscilator::cMsg_ImcBbEQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0xeoKUvP_sendMessage);
}

void Heavy_oscilator::cSystem_0xeoKUvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9kzv8zlw_sendMessage);
}

void Heavy_oscilator::cVar_3wExzgq0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qWUGInOO, HV_BINOP_MULTIPLY, 0, m, &cBinop_qWUGInOO_sendMessage);
}

void Heavy_oscilator::cMsg_0s2rY33x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_4HIsnHVk, 0, m, &cDelay_4HIsnHVk_sendMessage);
}

void Heavy_oscilator::cBinop_MfZWY3tB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4HIsnHVk, 2, m, &cDelay_4HIsnHVk_sendMessage);
}

void Heavy_oscilator::cBinop_9kzv8zlw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qWUGInOO, HV_BINOP_MULTIPLY, 1, m, &cBinop_qWUGInOO_sendMessage);
}

void Heavy_oscilator::cBinop_qWUGInOO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_MfZWY3tB_sendMessage);
}

void Heavy_oscilator::cVar_gmoMKC4V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HbKRtZKT, HV_BINOP_SUBTRACT, 0, m, &cBinop_HbKRtZKT_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_oT2Z9CKx_sendMessage);
}

void Heavy_oscilator::cSwitchcase_3J10EMpg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MVkbGniV_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DrswzZRK_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_oscilator::cCast_MVkbGniV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bNitOecK, 0, m, &cVar_bNitOecK_sendMessage);
}

void Heavy_oscilator::cCast_DrswzZRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_V9DV19lR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CQVZZtWh_sendMessage);
}

void Heavy_oscilator::cSwitchcase_xlPRIqnr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_EVadOW7z, 0, m, &cSlice_EVadOW7z_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LjELob1Q, 0, m, &cSlice_LjELob1Q_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yVsmMBXk_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_NYHvxHMT, 0, m, &cSlice_NYHvxHMT_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_xC4L0naM, 0, m, &cSlice_xC4L0naM_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PuqT9zas_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UNRufOQl_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_EVadOW7z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_u1mr3NYY_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_u1mr3NYY_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_LjELob1Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EkVRLv8a_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_el1tPONC_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EkVRLv8a_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_el1tPONC_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_x9tu2yin_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fS0M8U2y_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ApnhOF1D_sendMessage);
}

void Heavy_oscilator::cVar_NiEls56W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_PCRw88Z1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cSwitchcase_PCRw88Z1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OJGQ8E0a_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_RGtLDEyO, HV_BINOP_MULTIPLY, 0, m, &cBinop_RGtLDEyO_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_LSVBZjVK, HV_BINOP_DIVIDE, 1, m, &cBinop_LSVBZjVK_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_3wExzgq0, 0, m, &cVar_3wExzgq0_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cCast_OJGQ8E0a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CG6BxZvf_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cVar_qPdSy9Kp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_07d5AF2e, HV_BINOP_SUBTRACT, 1, m, &cBinop_07d5AF2e_sendMessage);
}

void Heavy_oscilator::cVar_nkRb1GIH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bNitOecK, 0, m, &cVar_bNitOecK_sendMessage);
}

void Heavy_oscilator::cVar_bNitOecK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jaTeGc6l, HV_BINOP_ADD, 0, m, &cBinop_jaTeGc6l_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hvzhr2Ya, HV_BINOP_ADD, 0, m, &cBinop_hvzhr2Ya_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bUo8Q6QH, 0, m, &cVar_bUo8Q6QH_sendMessage);
}

void Heavy_oscilator::cSlice_NYHvxHMT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fS0M8U2y_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ApnhOF1D_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_xC4L0naM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pWjh1qzs_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Jkoe4rwa_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_KtnLutqa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gmoMKC4V, 1, m, &cVar_gmoMKC4V_sendMessage);
}

void Heavy_oscilator::cBinop_JEWaGsW2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KtnLutqa_sendMessage);
}

void Heavy_oscilator::cBinop_RGtLDEyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fGvjlESN_sendMessage);
}

void Heavy_oscilator::cBinop_fGvjlESN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HbKRtZKT, HV_BINOP_SUBTRACT, 1, m, &cBinop_HbKRtZKT_sendMessage);
}

void Heavy_oscilator::cBinop_HbKRtZKT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gmoMKC4V, 1, m, &cVar_gmoMKC4V_sendMessage);
}

void Heavy_oscilator::cMsg_A2PZYQOp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_4J7hujSU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cMsg_xMUEwIQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_4J7hujSU_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hvzhr2Ya, HV_BINOP_ADD, 1, m, &cBinop_hvzhr2Ya_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jaTeGc6l, HV_BINOP_ADD, 1, m, &cBinop_jaTeGc6l_sendMessage);
}

void Heavy_oscilator::cBinop_oT2Z9CKx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3J10EMpg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cBinop_jaTeGc6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bNitOecK, 1, m, &cVar_bNitOecK_sendMessage);
}

void Heavy_oscilator::cBinop_LSVBZjVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_euxzMNWi, HV_BINOP_DIVIDE, 1, m, &cBinop_euxzMNWi_sendMessage);
}

void Heavy_oscilator::cBinop_euxzMNWi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hvzhr2Ya, HV_BINOP_ADD, 1, m, &cBinop_hvzhr2Ya_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jaTeGc6l, HV_BINOP_ADD, 1, m, &cBinop_jaTeGc6l_sendMessage);
}

void Heavy_oscilator::cCast_ApnhOF1D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LSVBZjVK, HV_BINOP_DIVIDE, 0, m, &cBinop_LSVBZjVK_sendMessage);
}

void Heavy_oscilator::cCast_fS0M8U2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JEWaGsW2, HV_BINOP_MULTIPLY, 0, m, &cBinop_JEWaGsW2_sendMessage);
}

void Heavy_oscilator::cCast_Jkoe4rwa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_07d5AF2e, HV_BINOP_SUBTRACT, 0, m, &cBinop_07d5AF2e_sendMessage);
}

void Heavy_oscilator::cCast_pWjh1qzs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nkRb1GIH, 1, m, &cVar_nkRb1GIH_sendMessage);
}

void Heavy_oscilator::cCast_V9DV19lR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xMUEwIQd_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_CQVZZtWh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nkRb1GIH, 0, m, &cVar_nkRb1GIH_sendMessage);
}

void Heavy_oscilator::cBinop_hvzhr2Ya_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qPdSy9Kp, 0, m, &cVar_qPdSy9Kp_sendMessage);
}

void Heavy_oscilator::cMsg_u1mr3NYY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_4J7hujSU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cMsg_BiZSf1X4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_x9tu2yin, 1, m, &cVar_x9tu2yin_sendMessage);
}

void Heavy_oscilator::cMsg_CG6BxZvf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RGtLDEyO, HV_BINOP_MULTIPLY, 0, m, &cBinop_RGtLDEyO_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_LSVBZjVK, HV_BINOP_DIVIDE, 1, m, &cBinop_LSVBZjVK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3wExzgq0, 0, m, &cVar_3wExzgq0_sendMessage);
}

void Heavy_oscilator::cCast_el1tPONC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PCgb7WDU_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hvzhr2Ya, HV_BINOP_ADD, 0, m, &cBinop_hvzhr2Ya_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bNitOecK, 1, m, &cVar_bNitOecK_sendMessage);
}

void Heavy_oscilator::cCast_EkVRLv8a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u1mr3NYY_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_07d5AF2e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_euxzMNWi, HV_BINOP_DIVIDE, 0, m, &cBinop_euxzMNWi_sendMessage);
}

void Heavy_oscilator::cCast_PCgb7WDU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xMUEwIQd_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_yVsmMBXk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_x9tu2yin, 0, m, &cVar_x9tu2yin_sendMessage);
}

void Heavy_oscilator::cCast_PuqT9zas_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_A2PZYQOp_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_UNRufOQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BiZSf1X4_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_wT04srut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_mKBqOAmR_sendMessage);
}

void Heavy_oscilator::cBinop_mKBqOAmR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_a02DMVPr, 0, m, &cPack_a02DMVPr_sendMessage);
}

void Heavy_oscilator::cVar_pn4pioqt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_xztpUmWv_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_A1cVKMvm_sendMessage);
}

void Heavy_oscilator::cBinop_xztpUmWv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pn4pioqt, 1, m, &cVar_pn4pioqt_sendMessage);
}

void Heavy_oscilator::cVar_0e2qYnMo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_JlzizZlh_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_RDkVCSvN, 0, m, &cIf_RDkVCSvN_sendMessage);
}

void Heavy_oscilator::cUnop_TIi8wsC5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FfgNerlg_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Fvbmv02M_sendMessage);
}

void Heavy_oscilator::cUnop_3vuJD6JQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FfgNerlg_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Fvbmv02M_sendMessage);
}

void Heavy_oscilator::cIf_RDkVCSvN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_3vuJD6JQ_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_TIi8wsC5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_JlzizZlh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RDkVCSvN, 1, m, &cIf_RDkVCSvN_sendMessage);
}

void Heavy_oscilator::cVar_1DcVJc5T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_fvL9K3rr_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_vNrEELkt, 0, m, &cIf_vNrEELkt_sendMessage);
}

void Heavy_oscilator::cUnop_x2fHMBod_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NGelARx1_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jilUrcfU_sendMessage);
}

void Heavy_oscilator::cUnop_txE4Clkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NGelARx1_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jilUrcfU_sendMessage);
}

void Heavy_oscilator::cIf_vNrEELkt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_txE4Clkj_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_x2fHMBod_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_fvL9K3rr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_vNrEELkt, 1, m, &cIf_vNrEELkt_sendMessage);
}

void Heavy_oscilator::cSlice_gbkM7qkt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Yjc58CMa_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_g4WnD2jY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_kODPIagP, 0, m, &cIf_kODPIagP_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_8lUuwXwK, HV_BINOP_EQ, 0, m, &cBinop_8lUuwXwK_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_yVZ4Za9F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_UMQ8otJM, 0, m, &cIf_UMQ8otJM_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_7aqpr9GZ, 0, m, &cIf_7aqpr9GZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_UMQ8otJM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3HC5szNx_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_pn4pioqt, 0, m, &cVar_pn4pioqt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_kODPIagP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_oscilator::cIf_7aqpr9GZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_kxpQNChW, 0, m, &cIf_kxpQNChW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_4za479rs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_gzuwevOs, 0, m, &cIf_gzuwevOs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_kxpQNChW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_RZMGPphJ, 0, m, &cIf_RZMGPphJ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_RZMGPphJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3HC5szNx_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_pn4pioqt, 0, m, &cVar_pn4pioqt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_gzuwevOs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_oscilator::cIf_HgZKMSFL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_JYfB4Hoj, HV_BINOP_EQ, 0, m, &cBinop_JYfB4Hoj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_BFH0Tyln_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_oscilator::cVar_CwRNl4gv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_4za479rs, 0, m, &cIf_4za479rs_sendMessage);
}

void Heavy_oscilator::cBinop_Yjc58CMa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_Aybv68As_sendMessage);
}

void Heavy_oscilator::cBinop_Aybv68As_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SuKAWnsB_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0BeH90bh_sendMessage);
}

void Heavy_oscilator::cBinop_8lUuwXwK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Yjw1DRW5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_38JtXbxA_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tOGJyI0c_sendMessage);
}

void Heavy_oscilator::cCast_Fvbmv02M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_6KYfv0uy_sendMessage);
}

void Heavy_oscilator::cCast_FfgNerlg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8lUuwXwK, HV_BINOP_EQ, 1, m, &cBinop_8lUuwXwK_sendMessage);
}

void Heavy_oscilator::cBinop_6KYfv0uy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8qCinMwh_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JpwRs5yB_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NNoArHGG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sOloAWjV_sendMessage);
}

void Heavy_oscilator::cBinop_3G1g5Uh3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_kxpQNChW, 1, m, &cIf_kxpQNChW_sendMessage);
}

void Heavy_oscilator::cCast_jilUrcfU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JYfB4Hoj, HV_BINOP_EQ, 1, m, &cBinop_JYfB4Hoj_sendMessage);
}

void Heavy_oscilator::cCast_NGelARx1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_4vJgNSOu_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_KIVxUVat_sendMessage);
}

void Heavy_oscilator::cBinop_4vJgNSOu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_HgZKMSFL, 1, m, &cIf_HgZKMSFL_sendMessage);
}

void Heavy_oscilator::cCast_SuKAWnsB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_HgZKMSFL, 0, m, &cIf_HgZKMSFL_sendMessage);
}

void Heavy_oscilator::cCast_0BeH90bh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_haweYlc0_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_W55j5CUz_sendMessage);
}

void Heavy_oscilator::cBinop_KIVxUVat_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gzuwevOs, 1, m, &cIf_gzuwevOs_sendMessage);
}

void Heavy_oscilator::cBinop_JYfB4Hoj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RZMGPphJ, 1, m, &cIf_RZMGPphJ_sendMessage);
}

void Heavy_oscilator::cCast_haweYlc0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BFH0Tyln, 0, m, &cIf_BFH0Tyln_sendMessage);
}

void Heavy_oscilator::cCast_W55j5CUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CwRNl4gv, 1, m, &cVar_CwRNl4gv_sendMessage);
}

void Heavy_oscilator::cCast_38JtXbxA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CwRNl4gv, 0, m, &cVar_CwRNl4gv_sendMessage);
}

void Heavy_oscilator::cCast_tOGJyI0c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_7aqpr9GZ, 1, m, &cIf_7aqpr9GZ_sendMessage);
}

void Heavy_oscilator::cCast_Yjw1DRW5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_4za479rs, 1, m, &cIf_4za479rs_sendMessage);
}

void Heavy_oscilator::cCast_NNoArHGG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_UMQ8otJM, 1, m, &cIf_UMQ8otJM_sendMessage);
}

void Heavy_oscilator::cCast_8qCinMwh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BFH0Tyln, 1, m, &cIf_BFH0Tyln_sendMessage);
}

void Heavy_oscilator::cCast_sOloAWjV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_3G1g5Uh3_sendMessage);
}

void Heavy_oscilator::cCast_JpwRs5yB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_kODPIagP, 1, m, &cIf_kODPIagP_sendMessage);
}

void Heavy_oscilator::cBinop_A1cVKMvm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DDLytDSj_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_C4gvBpPn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YxaBwyvH, 0, m, &cVar_YxaBwyvH_sendMessage);
}

void Heavy_oscilator::cBinop_RmTkbZLY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_oyqd7S6K_sendMessage);
}

void Heavy_oscilator::cBinop_oyqd7S6K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 127.0f, 0, m, &cBinop_wT04srut_sendMessage);
}

void Heavy_oscilator::cMsg_DDLytDSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSwitchcase_xlPRIqnr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cMsg_Q57uYtzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 4000.0f);
  cSwitchcase_xlPRIqnr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cReceive_WVlCvUEd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ImcBbEQb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3wExzgq0, 0, m, &cVar_3wExzgq0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TCYXGYRk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AdSzTRhI_sendMessage);
  cMsg_CX6VZlEs_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qPdSy9Kp, 0, m, &cVar_qPdSy9Kp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NiEls56W, 0, m, &cVar_NiEls56W_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1DcVJc5T, 0, m, &cVar_1DcVJc5T_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_0e2qYnMo, 0, m, &cVar_0e2qYnMo_sendMessage);
}

void Heavy_oscilator::cReceive_pInKoDpQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_gbkM7qkt, 0, m, &cSlice_gbkM7qkt_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_g4WnD2jY, 0, m, &cSlice_g4WnD2jY_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_yVZ4Za9F, 0, m, &cSlice_yVZ4Za9F_sendMessage);
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
