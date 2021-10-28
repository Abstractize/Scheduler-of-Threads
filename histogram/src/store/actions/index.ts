import { HistogramDecrement, HistogramErrorAction, HistogramIncrement, HistogramRecievedAction, HistogramReset } from "./histogram";

export type Action = HistogramRecievedAction | HistogramErrorAction | HistogramDecrement | HistogramIncrement | HistogramReset;