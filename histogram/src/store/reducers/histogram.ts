import { Reducer } from 'redux'
import { HistogramActionType } from '../action-types/histogram-action-types'
import { Action } from '../actions'
import { createData, Histogram } from '../states/histogram'

const initialState: Histogram = new Histogram();

const reducer: Reducer<Histogram, Action> = (
    state: Histogram | undefined,
    action: Action,
): Histogram => {
    if (state === undefined) return initialState
    switch (action.type) {
        case HistogramActionType.SUCCESS:
            const data = action.data;
            return {
                ...state,
                data: createData(data.name, [data.a, data.e, data.i, data.o, data.u])
              };
        case HistogramActionType.FAILURE:
            console.error(action.error);
            return {
                ...state,
                error: action.error
            }
        default:
            return state;
    }
}

export default reducer;