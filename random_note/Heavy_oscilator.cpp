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
  numBytes += cDelay_init(this, &cDelay_qVI2qLFw, 0.0f);
  numBytes += cVar_init_f(&cVar_5akChfHt, 100.0f);
  numBytes += cBinop_init(&cBinop_BNbbwbkD, 0.0f); // __mul
  numBytes += cPack_init(&cPack_Hpu9lGgO, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_6HwCaFgb, 0.0f);
  numBytes += cRandom_init(&cRandom_fghBiXcE, -1756758255);
  numBytes += cSlice_init(&cSlice_a1zWVM4l, 1, 1);
  numBytes += cRandom_init(&cRandom_VCPStqxY, -1058463643);
  numBytes += cSlice_init(&cSlice_bFSJfQyu, 1, 1);
  numBytes += cVar_init_f(&cVar_0t2Wjfp5, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_8hpiedtM, 0.0f);
  numBytes += cIf_init(&cIf_F13i6cdG, false);
  numBytes += cVar_init_f(&cVar_FEoOEkJ1, 500.0f);
  numBytes += cVar_init_f(&cVar_In7f1UFC, 0.0f);
  numBytes += cRandom_init(&cRandom_wEthnp8j, 1994036855);
  numBytes += cSlice_init(&cSlice_Uwqo7FPO, 1, 1);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_oscilator::~Heavy_oscilator() {
  cPack_free(&cPack_Hpu9lGgO);
}

HvTable *Heavy_oscilator::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_oscilator::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_eWbuJ1hW_sendMessage);
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


void Heavy_oscilator::cSwitchcase_u48BcOa1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_thb5hv9c_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_thb5hv9c_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zxWlnbzx_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cDelay_qVI2qLFw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qVI2qLFw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qVI2qLFw, 0, m, &cDelay_qVI2qLFw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gxmuX8pR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Yd8lLG6a_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XWHrq8uK_sendMessage);
}

void Heavy_oscilator::cCast_zxWlnbzx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_thb5hv9c_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qVI2qLFw, 0, m, &cDelay_qVI2qLFw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gxmuX8pR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Yd8lLG6a_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XWHrq8uK_sendMessage);
}

void Heavy_oscilator::cMsg_vOXr3lvm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XuDizEkF_sendMessage);
}

void Heavy_oscilator::cSystem_XuDizEkF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_FhMFlfDh_sendMessage);
}

void Heavy_oscilator::cVar_5akChfHt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BNbbwbkD, HV_BINOP_MULTIPLY, 0, m, &cBinop_BNbbwbkD_sendMessage);
}

void Heavy_oscilator::cMsg_thb5hv9c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_qVI2qLFw, 0, m, &cDelay_qVI2qLFw_sendMessage);
}

void Heavy_oscilator::cBinop_pWksGkvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qVI2qLFw, 2, m, &cDelay_qVI2qLFw_sendMessage);
}

void Heavy_oscilator::cBinop_FhMFlfDh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BNbbwbkD, HV_BINOP_MULTIPLY, 1, m, &cBinop_BNbbwbkD_sendMessage);
}

void Heavy_oscilator::cBinop_BNbbwbkD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_pWksGkvP_sendMessage);
}

void Heavy_oscilator::cPack_Hpu9lGgO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_XpvOLeDM_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cVar_6HwCaFgb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_1NVR8n6u_sendMessage);
}

void Heavy_oscilator::cSend_XpvOLeDM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "__hv_noteout", 0xD1D4AC2, m);
}

void Heavy_oscilator::cBinop_1NVR8n6u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_L5azJCpV_sendMessage);
}

void Heavy_oscilator::cBinop_L5azJCpV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Hpu9lGgO, 2, m, &cPack_Hpu9lGgO_sendMessage);
}

void Heavy_oscilator::cSwitchcase_wGhiJtjk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_a1zWVM4l, 0, m, &cSlice_a1zWVM4l_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fghBiXcE, 0, m, &cRandom_fghBiXcE_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cBinop_ZU3MBtE6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Q8XtEwAP_sendMessage);
}

void Heavy_oscilator::cUnop_Q8XtEwAP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FEoOEkJ1, 0, m, &cVar_FEoOEkJ1_sendMessage);
}

void Heavy_oscilator::cRandom_fghBiXcE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_ZU3MBtE6_sendMessage);
}

void Heavy_oscilator::cSlice_a1zWVM4l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fghBiXcE, 1, m, &cRandom_fghBiXcE_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSwitchcase_6UWDLNAc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_bFSJfQyu, 0, m, &cSlice_bFSJfQyu_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_VCPStqxY, 0, m, &cRandom_VCPStqxY_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cBinop_jZmSVXQE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_g8pNLTE5_sendMessage);
}

void Heavy_oscilator::cUnop_g8pNLTE5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_F13i6cdG, 0, m, &cIf_F13i6cdG_sendMessage);
}

void Heavy_oscilator::cRandom_VCPStqxY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 62.0f, 0, m, &cBinop_jZmSVXQE_sendMessage);
}

void Heavy_oscilator::cSlice_bFSJfQyu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_VCPStqxY, 1, m, &cRandom_VCPStqxY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_0t2Wjfp5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_4PyDYNNm_sendMessage);
}

void Heavy_oscilator::cDelay_8hpiedtM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8hpiedtM, m);
  cMsg_pGfO4CcK_sendMessage(_c, 0, m);
  cPack_onMessage(_c, &Context(_c)->cPack_Hpu9lGgO, 0, m, &cPack_Hpu9lGgO_sendMessage);
}

void Heavy_oscilator::cIf_F13i6cdG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SgypNNMO_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_Hpu9lGgO, 0, m, &cPack_Hpu9lGgO_sendMessage);
      cDelay_onMessage(_c, &Context(_c)->cDelay_8hpiedtM, 0, m, &cDelay_8hpiedtM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_FEoOEkJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_fW5MmYWM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_In7f1UFC, 1, m, &cVar_In7f1UFC_sendMessage);
}

void Heavy_oscilator::cVar_In7f1UFC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Hpu9lGgO, 1, m, &cPack_Hpu9lGgO_sendMessage);
}

void Heavy_oscilator::cMsg_pGfO4CcK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_Hpu9lGgO, 1, m, &cPack_Hpu9lGgO_sendMessage);
}

void Heavy_oscilator::cBinop_4PyDYNNm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8hpiedtM, 1, m, &cDelay_8hpiedtM_sendMessage);
}

void Heavy_oscilator::cBinop_fW5MmYWM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_F13i6cdG, 1, m, &cIf_F13i6cdG_sendMessage);
}

void Heavy_oscilator::cCast_SgypNNMO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_In7f1UFC, 0, m, &cVar_In7f1UFC_sendMessage);
}

void Heavy_oscilator::cSwitchcase_m4Copabz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Uwqo7FPO, 0, m, &cSlice_Uwqo7FPO_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_wEthnp8j, 0, m, &cRandom_wEthnp8j_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cBinop_hz6iaous_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_dl90YWPZ_sendMessage);
}

void Heavy_oscilator::cUnop_dl90YWPZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 10.0f, 0, m, &cBinop_ONRGvt8O_sendMessage);
}

void Heavy_oscilator::cRandom_wEthnp8j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_hz6iaous_sendMessage);
}

void Heavy_oscilator::cSlice_Uwqo7FPO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_wEthnp8j, 1, m, &cRandom_wEthnp8j_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cCast_Yd8lLG6a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_wGhiJtjk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cCast_gxmuX8pR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_m4Copabz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cCast_XWHrq8uK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_6UWDLNAc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cBinop_ONRGvt8O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5akChfHt, 0, m, &cVar_5akChfHt_sendMessage);
}

void Heavy_oscilator::cReceive_eWbuJ1hW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vOXr3lvm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5akChfHt, 0, m, &cVar_5akChfHt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6HwCaFgb, 0, m, &cVar_6HwCaFgb_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_0t2Wjfp5, 0, m, &cVar_0t2Wjfp5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_FEoOEkJ1, 0, m, &cVar_FEoOEkJ1_sendMessage);
  cSwitchcase_u48BcOa1_onMessage(_c, NULL, 0, m, NULL);
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
