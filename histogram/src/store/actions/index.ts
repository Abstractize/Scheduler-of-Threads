import { FailureHistogramAction, RequestHistogramAction, SuccessHistogramAction } from "./histogram";

export type Action = RequestHistogramAction | SuccessHistogramAction | FailureHistogramAction;