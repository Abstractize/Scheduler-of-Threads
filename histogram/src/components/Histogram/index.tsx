import React, { Component } from 'react';
import { connect } from 'react-redux';
import { Bar } from 'react-chartjs-2';
import { Props } from './props';
import { ApplicationState } from '../../store/states';
import { Button, ButtonGroup, Modal, ModalBody, ModalFooter, ModalHeader } from 'reactstrap';
import * as HistogramActions from "../../store/action-creators/histogram-action-creators";

class Histogram extends Component<Props> {
    buttons() {
        const size = this.props.dataChart.datasets[0].data.length;
        const prev = <Button onClick={() => this.props.decrement()}> Previous</Button>
        const next = <Button onClick={() => this.props.increment()}> Next </Button>;
        const reset = <Button onClick={() => this.props.reset()}> Back to First </Button>
        if (size > 0)
            return (
                <ButtonGroup>
                    {this.props.processCount !== 0 && prev}
                    {this.props.processCount !== 0 && reset}
                    {this.props.processCount !== size && next}
                    <Button disabled>
                        {this.props.processCount}
                    </Button>
                </ButtonGroup >
            )
    }

    constructor(props) {
        super(props);
    }

    render() {
        return (
            <div>
                <Bar data={this.props.dataChart} />
                {this.buttons()}
                <Modal isOpen={this.props.error !== undefined}>
                    <ModalHeader>An error has ocurred.</ModalHeader>
                    <ModalBody>
                        {this.props.error}
                    </ModalBody>
                    <ModalFooter>
                        Please reload this page when the server is running.
                    </ModalFooter>
                </Modal>
            </div>
        );
    }
}

export default connect(
    (state: ApplicationState) => state.histogram,
    HistogramActions.default
)(Histogram);