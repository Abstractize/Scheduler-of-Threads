import { HistogramErrorAction, HistogramRecievedAction } from "./histogram";

export type Action = HistogramRecievedAction | HistogramErrorAction;