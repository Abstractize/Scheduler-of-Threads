import React, { Component } from 'react';
import { connect } from 'react-redux';
import { Bar } from 'react-chartjs-2';
import { Props } from './props';
import { ApplicationState } from '../../store/states';

class Histogram extends Component<Props> {
    constructor(props){
        super(props);
    }
    render() {
        return (
            <div className="App">
                <header className="App-header">
                    <Bar data={this.props.data} />
                </header>
            </div>
        );
    }
}

export default connect(
    (state: ApplicationState) => ({ ...state.histogram })
)(Histogram);