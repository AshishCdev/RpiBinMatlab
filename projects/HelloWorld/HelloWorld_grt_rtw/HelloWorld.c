/*
 * HelloWorld.c
 *
 * Code generation for model "HelloWorld".
 *
 * Model version              : 1.27
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Thu Jun  6 11:26:41 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HelloWorld.h"
#include "HelloWorld_private.h"

/* Named constants for Chart: '<S1>/Chart' */
#define HelloWorld_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define HelloWorld_IN_Off              ((uint8_T)1U)
#define HelloWorld_IN_On               ((uint8_T)2U)

/* Block states (auto storage) */
DW_HelloWorld_T HelloWorld_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_HelloWorld_T HelloWorld_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_HelloWorld_T HelloWorld_Y;

/* Real-time model */
RT_MODEL_HelloWorld_T HelloWorld_M_;
RT_MODEL_HelloWorld_T *const HelloWorld_M = &HelloWorld_M_;

/* Model step function */
void HelloWorld_step(void)
{
  boolean_T rtb_swLed;
  uint32_T qY;

  /* Outputs for Atomic SubSystem: '<Root>/HelloWorld' */
  /* Chart: '<S1>/Chart' incorporates:
   *  Inport: '<Root>/gpio0'
   */
  /* Gateway: HelloWorld/Chart */
  /* During: HelloWorld/Chart */
  if (HelloWorld_DW.is_active_c3_HelloWorld == 0U) {
    /* Entry: HelloWorld/Chart */
    HelloWorld_DW.is_active_c3_HelloWorld = 1U;

    /* Entry Internal: HelloWorld/Chart */
    /* Transition: '<S2>:4' */
    /* Entry Internal 'LedBlinkWithConsolePrint': '<S2>:3' */
    /* Entry 'LedOut': '<S2>:5' */
    /*  This state reads the input switch and turns off or on the Led  */
    /* Entry Internal 'LedOut': '<S2>:5' */
    /* Transition: '<S2>:20' */
    HelloWorld_DW.is_LedOut = HelloWorld_IN_Off;

    /* Entry 'Off': '<S2>:19' */
    /*  Keep the led off  */
    rtb_swLed = false;

    /* Entry 'SerialPrint': '<S2>:7' */
    /*  This state prints on the console  */
    /* Entry Internal 'SerialPrint': '<S2>:7' */
    /* Transition: '<S2>:10' */
    if (HelloWorld_DW.count1 > 1000000U) {
      /* Transition: '<S2>:14' */
      /* Transition: '<S2>:16' */
      HelloWorld_DW.count1 = 0U;
      qY = HelloWorld_DW.count2 + 1U;
      if (qY < HelloWorld_DW.count2) {
        qY = MAX_uint32_T;
      }

      HelloWorld_DW.count2 = qY;

      /* Outport: '<Root>/gpio2' */
      HelloWorld_Y.gpio2 = !(HelloWorld_Y.gpio2 != 0.0);
      printf("Execution timer has incremented by %d\n", HelloWorld_DW.count2);

      /* Transition: '<S2>:27' */
    } else {
      /* Transition: '<S2>:15' */
      qY = HelloWorld_DW.count1 + 1U;
      if (qY < HelloWorld_DW.count1) {
        qY = MAX_uint32_T;
      }

      HelloWorld_DW.count1 = qY;
    }
  } else {
    /* During 'LedBlinkWithConsolePrint': '<S2>:3' */
    /* During 'LedOut': '<S2>:5' */
    if (HelloWorld_DW.is_LedOut == HelloWorld_IN_Off) {
      /* During 'Off': '<S2>:19' */
      if (HelloWorld_U.gpio0) {
        /* Transition: '<S2>:22' */
        HelloWorld_DW.is_LedOut = HelloWorld_IN_On;

        /* Entry 'On': '<S2>:21' */
        /* Turn the led on */
        rtb_swLed = true;
      } else {
        /*  Keep the led off  */
        rtb_swLed = false;
      }
    } else {
      /* During 'On': '<S2>:21' */
      if (!HelloWorld_U.gpio0) {
        /* Transition: '<S2>:24' */
        HelloWorld_DW.is_LedOut = HelloWorld_IN_Off;

        /* Entry 'Off': '<S2>:19' */
        /*  Keep the led off  */
        rtb_swLed = false;
      } else {
        /* Turn the led on */
        rtb_swLed = true;
      }
    }

    /* During 'SerialPrint': '<S2>:7' */
    /* Transition: '<S2>:10' */
    if (HelloWorld_DW.count1 > 1000000U) {
      /* Transition: '<S2>:14' */
      /* Transition: '<S2>:16' */
      HelloWorld_DW.count1 = 0U;
      qY = HelloWorld_DW.count2 + 1U;
      if (qY < HelloWorld_DW.count2) {
        qY = MAX_uint32_T;
      }

      HelloWorld_DW.count2 = qY;

      /* Outport: '<Root>/gpio2' */
      HelloWorld_Y.gpio2 = !(HelloWorld_Y.gpio2 != 0.0);
      printf("Execution timer has incremented by %d\n", HelloWorld_DW.count2);

      /* Transition: '<S2>:27' */
    } else {
      /* Transition: '<S2>:15' */
      qY = HelloWorld_DW.count1 + 1U;
      if (qY < HelloWorld_DW.count1) {
        qY = MAX_uint32_T;
      }

      HelloWorld_DW.count1 = qY;
    }
  }

  /* End of Chart: '<S1>/Chart' */
  /* End of Outputs for SubSystem: '<Root>/HelloWorld' */

  /* Outport: '<Root>/gpio3' */
  HelloWorld_Y.gpio3 = rtb_swLed;

  /* Matfile logging */
  rt_UpdateTXYLogVars(HelloWorld_M->rtwLogInfo, (&HelloWorld_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(HelloWorld_M)!=-1) &&
        !((rtmGetTFinal(HelloWorld_M)-HelloWorld_M->Timing.taskTime0) >
          HelloWorld_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(HelloWorld_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++HelloWorld_M->Timing.clockTick0)) {
    ++HelloWorld_M->Timing.clockTickH0;
  }

  HelloWorld_M->Timing.taskTime0 = HelloWorld_M->Timing.clockTick0 *
    HelloWorld_M->Timing.stepSize0 + HelloWorld_M->Timing.clockTickH0 *
    HelloWorld_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void HelloWorld_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)HelloWorld_M, 0,
                sizeof(RT_MODEL_HelloWorld_T));
  rtmSetTFinal(HelloWorld_M, -1);
  HelloWorld_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    HelloWorld_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(HelloWorld_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(HelloWorld_M->rtwLogInfo, (NULL));
    rtliSetLogT(HelloWorld_M->rtwLogInfo, "tout");
    rtliSetLogX(HelloWorld_M->rtwLogInfo, "");
    rtliSetLogXFinal(HelloWorld_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(HelloWorld_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(HelloWorld_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(HelloWorld_M->rtwLogInfo, 0);
    rtliSetLogDecimation(HelloWorld_M->rtwLogInfo, 1);
    rtliSetLogY(HelloWorld_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(HelloWorld_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(HelloWorld_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&HelloWorld_DW, 0,
                sizeof(DW_HelloWorld_T));

  /* external inputs */
  HelloWorld_U.gpio0 = false;

  /* external outputs */
  (void) memset((void *)&HelloWorld_Y, 0,
                sizeof(ExtY_HelloWorld_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(HelloWorld_M->rtwLogInfo, 0.0, rtmGetTFinal
    (HelloWorld_M), HelloWorld_M->Timing.stepSize0, (&rtmGetErrorStatus
    (HelloWorld_M)));

  /* SystemInitialize for Atomic SubSystem: '<Root>/HelloWorld' */
  /* SystemInitialize for Chart: '<S1>/Chart' */
  HelloWorld_DW.is_LedOut = HelloWorld_IN_NO_ACTIVE_CHILD;
  HelloWorld_DW.is_active_c3_HelloWorld = 0U;
  HelloWorld_DW.count1 = 0U;
  HelloWorld_DW.count2 = 0U;

  /* SystemInitialize for Outport: '<Root>/gpio2' incorporates:
   *  SystemInitialize for Chart: '<S1>/Chart'
   */
  HelloWorld_Y.gpio2 = 0.0;

  /* End of SystemInitialize for SubSystem: '<Root>/HelloWorld' */
}

/* Model terminate function */
void HelloWorld_terminate(void)
{
  /* (no terminate code required) */
}
