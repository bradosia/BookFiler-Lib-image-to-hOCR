/*
 * @name BookFiler Library - Sort Filter Tree Widget
 * @author Branden Lee
 * @version 1.00
 * @license MIT
 * @brief Super fast tree sorting and filtering tree widget.
 */

// C++
#include <iostream>
#include <vector>

// Bookfiler Libraries
#include "../../src/core/Ocr.hpp"
#include <BookFiler-Lib-image-to-hOCR/Interface.hpp>

std::string testName = "Sort Filter Tree Widget Example 00";

void recognizeCallback(std::shared_ptr<bookfiler::OcrInternal> ocr);

int main(int argc, char *argv[]) {
  std::cout << testName << " BEGIN" << std::endl;

  // Must be a pointer because uses shared_from_this() internally
  std::shared_ptr<bookfiler::OcrInternal> ocrPtr = std::make_shared<bookfiler::OcrInternal>();
  ocrPtr->setMode("resources/traineddata");
  ocrPtr->openImageFile("resources/images/invoice.png");
  ocrPtr->connectRecognizeDone(std::bind(&recognizeCallback, std::placeholders::_1));
  ocrPtr->recognize();

  std::cout << testName << " END" << std::endl;
  return 0;
}

void recognizeCallback(std::shared_ptr<bookfiler::OcrInternal> ocrPtr) {
  std::cout << testName << " recognizeCallback" << std::endl;

  std::string hocr = ocrPtr->getHocr();
  std::cout << hocr << std::endl;
}
