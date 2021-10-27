import React, { Component } from 'react';
import { connect } from 'react-redux';
import './App.css';
import openSocket from 'socket.io-client';
import { HistogramActionType } from '../../store/action-types/histogram-action-types';
import * as ActionsCreators from '../../store/action-creators/histogram-action-creators';
import ReactLoading from 'react-loading';
import { Bar } from 'react-chartjs-2';
import { Props } from './props';

class Histogram extends Component<Props> {
    socket: any;
    constructor(props) {
        super(props);
        this.socket = openSocket('http://localhost:8080/websocket');
        this.socket.on(HistogramActionType.SUCCESS, data => {
            props.store.dispatch(ActionsCreators.GetSuccessHistogram(data));
        });
        this.socket.on(HistogramActionType.FAILURE, err => {
            props.store.dispatch(ActionsCreators.GetFailureHistogram(err));
        });
    }

    componentDidMount() {
        // Accessible because we 'connected'    
        this.props.GetHistogram({ socket: this.socket });
    }

    render() {
        if (this.props.isFetching) {
            return <ReactLoading type="bars" />;
        }
        return (
            <div>
                {this.props.data}
            </div>
            /*<div className="App">
                <header className="App-header">
                    <Bar data={this.props.data} />
                </header>
            </div>*/
        );
    }
}

export default connect(
    state => state,
    { GetData: ActionsCreators.GetHistogram }
)(Histogram);