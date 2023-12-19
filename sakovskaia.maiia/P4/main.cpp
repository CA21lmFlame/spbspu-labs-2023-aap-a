#include <iostream>
#include <fstream>
#include <cstdlib>
#include "matrix.hpp"
#include "matrix_input_res.hpp"

int main(int argc, char * argv[])
{
  using namespace sakovskaia;
  counterclockWiseMatrixCounter matrixcounter;
  answerCounter answercounter;
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }

  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch(const std::invalid_argument & e)
  {
    std::cerr << "Cannot read first argument\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  int rows = 0, columns = 0;
  input >> rows >> columns;
  if (!input)
  {
    std::cerr << "Error in reading input file\n";
    return 2;
  }

  std::ofstream output(argv[3]);

  if (num == 1)
  {
    try
    {
      int inputmatrix[rows * columns] = {};
      int counterclockwisematrix[rows * columns] = {};
      staticMatrix(input, inputmatrix, rows * columns);
      int staticc = * staticMatrix;
      matrixcounter(counterclockwisematrix, rows, columns);
      answercounter(staticc, counterclockwisematrix, rows * columns);
      printAnswer(output, counterclockwisematrix, rows * columns);
    }
    catch (const std::logic_error & e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
    input.close();
    output.close();
  }
  else if (num == 2)
  {
    try
    {
      int * inputmatrix = new int[rows * columns];
      int * counterclockwisematrix = new int[rows * columns];
      dynamicMatrix(input, inputmatrix, rows * columns);
      int dynamic = * dynamicMatrix;
      matrixcounter(counterclockwisematrix, rows, columns);
      answercounter(dynamic, counterclockwisematrix, rows * columns);
      printAnswer(output, counterclockwisematrix, rows * columns);
      delete [] inputmatrix;
      delete [] counterclockwisematrix;
    }
    catch (const std::logic_error & e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
    input.close();
    output.close();
  }
  else if ((num > 2) || (num < 1))
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
}
