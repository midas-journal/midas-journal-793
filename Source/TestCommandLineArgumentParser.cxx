#include "itkCommandLineArgumentParser.h"
#include <string>
#include <vector>

int main( int argc, char** argv )
{
  /** Create a command line argument parser. */
  itk::CommandLineArgumentParser::Pointer parser = itk::CommandLineArgumentParser::New();
  parser->SetCommandLineArguments( argc, argv );

  /** Get argument -in. */
  std::vector<std::string> inputFileNames; // no default
  bool retin = parser->GetCommandLineArgument( "-in", inputFileNames );
  std::cout << "-in: ";
  for ( std::size_t i = 0; i < inputFileNames.size(); i++ )
  {
    std::cout << " " << inputFileNames[ i ];
  }
  std::cout << std::endl;

  /** Get argument -out. */
  std::string outputFileName = "";
  if ( retin )
  {
    outputFileName = inputFileNames[ 0 ].substr( 0, inputFileNames[ 0 ].rfind( "." ) );
    outputFileName += "_processed.mhd"; // default
  }
  bool retout = parser->GetCommandLineArgument( "-out", outputFileName );
  std::cout << "-out: " << outputFileName << std::endl;

  /** Get argument -num. */
  short numberOfClasses = 3; // default
  bool retnum = parser->GetCommandLineArgument( "-num", numberOfClasses );
  std::cout << "-num: " << numberOfClasses << std::endl;

  /** Get argument -pA. */
  std::vector<int> vecA; // no default
  bool retpA = parser->GetCommandLineArgument( "-pA", vecA );
  std::cout << "-pA: ";
  for ( std::size_t i = 0; i < vecA.size(); i++ )
  {
    std::cout << " " << vecA[ i ];
  }
  std::cout << std::endl;

  /** Get argument -pB. */
  std::vector<float> vecB( 3, 1.0 ); // default 3 values
  bool retpB = parser->GetCommandLineArgument( "-pB", vecB );
  std::cout << "-pB: ";
  for ( std::size_t i = 0; i < vecB.size(); i++ )
  {
    std::cout << " " << vecB[ i ];
  }
  std::cout << std::endl;

  /** Get argument -z. */
  bool compress = parser->ArgumentExists( "-z" );
  std::cout << "-z: " << ( compress ? "true" : "false" ) << std::endl;

  /** Return a value. */
	return 0;

} // end main
