import { HistogramActionType as  ActionType } from "../action-types/histogram-action-types";
import { Action as ReduxAction} from "redux";

interface HistogramAction extends ReduxAction<ActionType> {
    type: ActionType;
}

export interface RequestHistogramAction extends HistogramAction {
    type: ActionType.REQUEST;
}

export interface SuccessHistogramAction extends HistogramAction {
    type: ActionType.SUCCESS;
    data: any
}

export interface FailureHistogramAction extends HistogramAction {
    type: ActionType.FAILURE;
    error: any;
}