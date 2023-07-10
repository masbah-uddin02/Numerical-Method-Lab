#include <iostream>
#include <vector>

double newtonInterpolation(double x, const std::vector<double>& x_values, const std::vector<double>& y_values) {
    int n = x_values.size() - 1;
    double h = x_values[1] - x_values[0];
    double result = y_values[0];

    std::vector<std::vector<double>> difference_table(n + 1, std::vector<double>(n + 1));
    for (int i = 0; i <= n; i++) {
        difference_table[i][0] = y_values[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            difference_table[j][i] = difference_table[j + 1][i - 1] - difference_table[j][i - 1];
        }
    }

    double u = (x - x_values[0]) / h;
    double term = 1.0;
    for (int i = 1; i <= n; i++) {
        term *= (u - i + 1) / i;
        result += term * difference_table[0][i];
    }

    return result;
}

int main() {
    std::vector<double> x_values = {1921, 1931, 1941, 1951, 1961};
    std::vector<double> y_values = {46, 66, 81, 93, 101};

    double year;


cout << "Enter the year for which you want to estimate the population: ";
    std::cin >> year;

    double estimated_population = newtonInterpolation(year, x_values, y_values);

   cout << "Estimated population for the year " << year << " is " << estimated_population << " thousand." << std::endl;

    return 0;
}
