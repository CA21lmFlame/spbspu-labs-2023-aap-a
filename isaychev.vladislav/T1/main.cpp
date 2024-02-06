#include "deleteFigures.hpp"
#include "creatingFigures.hpp"
#include "stringManipulations.hpp"
#include "inputString.hpp"
#include "outputResults.hpp"
#include "isoscale.hpp"

int main()
{
  using namespace isaychev;
  const char * scaleStr = "SCALE ";
  char * currDesc = nullptr;
  size_t i = 0, figuresCount = 0, figDescMistakeCheck = 0, eofCheck = 0;
  Shape ** figures = nullptr;
  try
  {
    figures = new Shape *[1000]{};
  }
  catch(const std::bad_alloc &)
  {
    std::cerr << "can't allocate memory for figure array\n";
    return 1;
  }
  while (i < 1000)
  {
    try
    {
      currDesc = inputString(std::cin);
      if (checkString(currDesc, scaleStr) == 1 || std::cin.eof())
      {
        if (std::cin.eof())
        {
          eofCheck++;
        }
        break;
      }
      figures[i++] = createFigure(currDesc);
    }
    catch(const std::bad_alloc &)
    {
      deleteFigures(figures, figuresCount);
      delete [] currDesc;
      std::cerr << "can't allocate memory for description of figure or a figure itself\n";
      return 2;
    }
    catch(const std::logic_error &)
    {
      figDescMistakeCheck++;
    }
    if (figures[i - 1] == nullptr)
    {
      i--;
    }
    else
    {
      figuresCount++;
    }
    delete [] currDesc;
  }
  if (figuresCount == 0 && checkString(currDesc, scaleStr) == 1)
  {
    delete [] figures;
    delete [] currDesc;
    std::cerr << "nothing to scale\n";
    return 3;
  }
  else if (eofCheck == 1 && checkString(currDesc, scaleStr) == 0)
  {
    deleteFigures(figures, figuresCount);
    delete [] currDesc;
    std::cerr << "input was finished with eof symbol; scale wasn't inputed\n";
    return 4;
  }
  else
  {
    outputResults(figures, figuresCount);
    try
    {
      isoscale(currDesc, figures, figuresCount);
    }
    catch (const std::invalid_argument & e)
    {
      if (eofCheck > 0)
      {
        delete [] currDesc;
        std::cerr << "input was finished with eof symbol; " << e.what() << "\n";
        deleteFigures(figures, figuresCount);
        return 5;
      }
      delete [] currDesc;
      std::cerr << e.what() << "\n";
      deleteFigures(figures, figuresCount);
      return 6;
    }
    outputResults(figures, figuresCount);
  }
  if (figDescMistakeCheck > 0)
  {
    std::cerr << "There were mistakes in figure descriptions\n";
  }
  deleteFigures(figures, figuresCount);
  delete [] currDesc;
}
