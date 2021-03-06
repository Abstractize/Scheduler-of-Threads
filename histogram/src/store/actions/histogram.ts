import { HistogramActionType as  ActionType } from "../action-types/histogram-action-types";
import { Action as ReduxAction} from "redux";
import { Histogram } from "../../infrastructure/models/histogram";

interface HistogramAction extends ReduxAction<ActionType> {
    type: ActionType;
}

export interface HistogramRecievedAction extends HistogramAction {
    type: ActionType.SUCCESS;
    data: Histogram
}

export interface HistogramErrorAction extends HistogramAction {
    type: ActionType.FAILURE;
    error: Event;
}

export interface HistogramDecrement extends HistogramAction{
    type: ActionType.DECREMENT
}

export interface HistogramIncrement extends HistogramAction{
    type: ActionType.INCREMENT
}

export interface HistogramReset extends HistogramAction{
    type: ActionType.RESET
}