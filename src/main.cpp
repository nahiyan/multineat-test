#include "Genome.h"
#include "Parameters.h"
#include "Population.h"
#include <iostream>
#include <vector>

using namespace std;

// float evaluate(NEAT::Genome& genome)
// {
//     NEAT::NeuralNetwork neuralNetwork;
//     genome.BuildPhenotype(neuralNetwork);

//     vector<double> input { 1, 0, 1 };
//     neuralNetwork.Input(input);
//     neuralNetwork.Activate();

//     return 1 - neuralNetwork.Output()[0];
// }

int main()
{
    NEAT::Parameters parameters;
    parameters.PopulationSize = 100;

    const int numberOfInput = 2;
    const int numberOfOutput = 2;
    NEAT::Genome genome(0, numberOfInput + 1, 0, numberOfOutput, false, NEAT::ActivationFunction::UNSIGNED_SIGMOID, NEAT::ActivationFunction::UNSIGNED_SIGMOID, 0, parameters, 0, 0);

    // Causes address boundary error
    auto population = new NEAT::Population(genome, parameters, true, 1, 0);

    // for (int i = 0; i < 10; i++) {
    //     auto genomes = population.GetGenomeList();

    //     float fitnessSum = 0;
    //     for (auto& genome : genomes) {
    //         auto fitness = evaluate(*genome);
    //         genome->SetFitness(fitness);
    //         fitnessSum += fitness;
    //     }

    //     cout << (fitnessSum / genomes.size()) << "\n";

    //     population.Epoch();
    // }

    return 0;
}