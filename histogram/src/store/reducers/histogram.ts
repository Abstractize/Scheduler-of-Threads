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

    let value = state.processCount;

    switch (action.type) {
        case HistogramActionType.SUCCESS:
            const data = action.data;
            return {
                ...state,
                data: data,
                dataChart: createData(
                    data.name[state.processCount],
                    [data.a[state.processCount],
                    data.e[state.processCount],
                    data.i[state.processCount],
                    data.o[state.processCount],
                    data.u[state.processCount]
                    ])
            };
        case HistogramActionType.FAILURE:
            const error: any = action.error;
            console.error(error)
            return {
                ...state,
                error: `Connection Failed to ${error.currentTarget.url}`
            };
        case HistogramActionType.DECREMENT:
            value = value > 0 ? --value : 0;
            return {
                ...state,
                processCount: value,
                dataChart: createData(
                    state.data.name[value],
                    [
                        state.data.a[value],
                        state.data.e[value],
                        state.data.i[value],
                        state.data.o[value],
                        state.data.u[value]
                    ])
            };
        case HistogramActionType.INCREMENT:
            const size = state.dataChart.datasets[0].data.length;
            value = value < size? ++value : size - 1;
            return {
                ...state,
                processCount: value,
                dataChart: createData(
                    state.data.name[value],
                    [
                        state.data.a[value],
                        state.data.e[value],
                        state.data.i[value],
                        state.data.o[value],
                        state.data.u[value]
                    ])
            };
        case HistogramActionType.INCREMENT:
            return {
                ...state,
                processCount: 0
            }
        default:
            return state;
    }
}

export default reducer;