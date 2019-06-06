/*
 * HelloWorld.h
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

#ifndef RTW_HEADER_HelloWorld_h_
#define RTW_HEADER_HelloWorld_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef HelloWorld_COMMON_INCLUDES_
# define HelloWorld_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* HelloWorld_COMMON_INCLUDES_ */

#include "HelloWorld_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint32_T count1;                     /* '<S1>/Chart' */
  uint32_T count2;                     /* '<S1>/Chart' */
  uint8_T is_active_c3_HelloWorld;     /* '<S1>/Chart' */
  uint8_T is_LedOut;                   /* '<S1>/Chart' */
} DW_HelloWorld_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  boolean_T gpio0;                     /* '<Root>/gpio0' */
} ExtU_HelloWorld_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  boolean_T gpio3;                     /* '<Root>/gpio3' */
  real_T gpio2;                        /* '<Root>/gpio2' */
} ExtY_HelloWorld_T;

/* Real-time Model Data Structure */
struct tag_RTM_HelloWorld_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block states (auto storage) */
extern DW_HelloWorld_T HelloWorld_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_HelloWorld_T HelloWorld_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_HelloWorld_T HelloWorld_Y;

/* Model entry point functions */
extern void HelloWorld_initialize(void);
extern void HelloWorld_step(void);
extern void HelloWorld_terminate(void);

/* Real-time Model object */
extern RT_MODEL_HelloWorld_T *const HelloWorld_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'HelloWorld'
 * '<S1>'   : 'HelloWorld/HelloWorld'
 * '<S2>'   : 'HelloWorld/HelloWorld/Chart'
 */
#endif                                 /* RTW_HEADER_HelloWorld_h_ */
