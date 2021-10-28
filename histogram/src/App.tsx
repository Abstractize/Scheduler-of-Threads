import React from 'react';
import './App.css';
import configureStore from './store';
import { Provider } from 'react-redux';
import { HistogramService } from './infrastructure/services/histogram-service';
import { Home } from './views/home'

const store = configureStore();
const service = new HistogramService(store.dispatch);
class App extends React.Component {
  render(){
    return (
      <Provider store={store}>
        <Home/>
      </Provider>
    )
  }
}

export default App;
