import { ChartData } from "chart.js";
import { Histogram as ModelHistogram } from "../../infrastructure/models/histogram";
export function createData(name: string = "", newData: number[] = [0, 0, 0, 0, 0]): ChartData<"bar", number[], string> {
    return {
        labels: ['A', 'E', 'I', 'O', 'U'],
        datasets: [
            {
                label: `Number of Vowels on ${name}`,
                data: newData,
                backgroundColor: [
                    'rgba(255, 99, 132, 0.2)',
                    'rgba(54, 162, 235, 0.2)',
                    'rgba(255, 206, 86, 0.2)',
                    'rgba(75, 192, 192, 0.2)',
                    'rgba(153, 102, 255, 0.2)',
                ],
                borderColor: [
                    'rgba(255, 99, 132, 1)',
                    'rgba(54, 162, 235, 1)',
                    'rgba(255, 206, 86, 1)',
                    'rgba(75, 192, 192, 1)',
                    'rgba(153, 102, 255, 1)',
                ],
                borderWidth: 1,
            },
        ],
    }
};

export class Histogram {
    constructor(
        public processCount: number = 0,
        public data: ModelHistogram = {
            name: ['Value not Provided'],
            a: [0],
            e: [0],
            i: [0],
            o: [0],
            u: [0]
        },
        public dataChart: ChartData<"bar", number[], string> = createData(),
        public error: string = undefined
    ) { }
}