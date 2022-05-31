/*
                 __________                                      
    _____   __ __\______   \_____  _______  ______  ____ _______ 
   /     \ |  |  \|     ___/\__  \ \_  __ \/  ___/_/ __ \\_  __ \
  |  Y Y  \|  |  /|    |     / __ \_|  | \/\___ \ \  ___/ |  | \/
  |__|_|  /|____/ |____|    (____  /|__|  /____  > \___  >|__|   
        \/                       \/            \/      \/        
  Copyright (C) 2013 Ingo Berg

  Permission is hereby granted, free of charge, to any person obtaining a copy of this 
  software and associated documentation files (the "Software"), to deal in the Software
  without restriction, including without limitation the rights to use, copy, modify, 
  merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
  permit persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or 
  substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
  NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 
*/ 
  
  
#include "muParserTest.h"
  
#include <cstdio>
#include <cmath>
#include <iostream>
#include <limits>
  
#define PARSER_CONST_PI  3.141592653589793238462643
#define PARSER_CONST_E   2.718281828459045235360287
  

/** \file
    \brief This file contains the implementation of parser test cases.
*/ 
  
{
  
  {
    
    
      //---------------------------------------------------------------------------------------------
  ParserTester::ParserTester () 
    {
      
      
      
      
      
      
      
      
      
      
      
      
      
      
    
      //---------------------------------------------------------------------------------------------
    int ParserTester::IsHexVal (const char_type * a_szExpr, int *a_iPos,
                                value_type * a_fVal) 
    {
      
        
      
      
        // New code based on streams for UNICODE compliance:
        stringstream_type::pos_type nPos (0);
      
      
      
      
        
      
      
      
    
    
      //---------------------------------------------------------------------------------------------
    int ParserTester::TestInterface () 
    {
      
      
      
        // Test RemoveVar
        value_type afVal[3] =
      {
      1, 2, 3};
      
      
      {
        
        
        
        
        
      
      {
        
      } 
      {
        
        
        
      } 
      {
        
          // failure is expected...
      } 
        
      
      else
        
          console () << _T ("\n  failed with ") << iStat << _T (" errors") <<
          endl;
      
    
    
      //---------------------------------------------------------------------------------------------
    int ParserTester::TestStrArg () 
    {
      
      
      
      iStat +=
        EqnTest (_T ("valueof(\"aaa\")+valueof(\"bbb\")  "), 246, true);
      
        EqnTest (_T ("2*(valueof(\"aaa\")-23)+valueof(\"bbb\")"), 323, true);
      
        // use in expressions with variables
        iStat += EqnTest (_T ("a*(atof(\"10\")-b)"), 8, true);
      
      
        // string + numeric arguments
        iStat += EqnTest (_T ("strfun1(\"100\")"), 100, true);
      
      
      
        // string constants
        iStat += EqnTest (_T ("atof(str1)+atof(str2)"), 3.33, true);
      
        
      
      else
        
          console () << _T ("\n  failed with ") << iStat << _T (" errors") <<
          endl;
      
    
    
      //---------------------------------------------------------------------------------------------
    int ParserTester::TestBulkMode () 
    {
      
      
      
#define EQN_TEST_BULK(EXPR, R1, R2, R3, R4, PASS) \
      {
        \
        \
      \
        // Bulk Variables for the test:
        // a: 1,2,3,4
        // b: 2,2,2,2
        // c: 3,3,3,3
        // d: 5,4,3,2
        EQN_TEST_BULK ("a", 1, 1, 1, 1, false) 
        EQN_TEST_BULK ("a", 1, 2, 3, 4, true) 
        EQN_TEST_BULK ("b=a", 1, 2, 3, 4, true) 
        EQN_TEST_BULK ("b=a, b*10", 10, 20, 30, 40, true) 
        EQN_TEST_BULK ("b=a, b*10, a", 1, 2, 3, 4, true) 
        EQN_TEST_BULK ("a+b", 3, 4, 5, 6, true) 
        EQN_TEST_BULK ("c*(a+b)", 9, 12, 15, 18, true) 
#undef EQN_TEST_BULK
        
        
      
      else
        
          console () << _T ("\n  failed with ") << iStat << _T (" errors") <<
          endl;
      
    
    
      //---------------------------------------------------------------------------------------------
    int ParserTester::TestBinOprt () 
    {
      
      
      
        // built in operators
        // xor operator
        
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
        // Test logical operators, especially if user defined "&" and the internal "&&" collide
        iStat += EqnTest (_T ("1 && 1"), 1, true);
      
      
      
      
        //iStat += EqnTest(_T("12 and 255"), 12, true); 
        //iStat += EqnTest(_T("12 and 0"), 0, true); 
        iStat += EqnTest (_T ("12 & 255"), 12, true);
      
      
      
      
        // Assignment operator
        iStat += EqnTest (_T ("a = b"), 2, true);
      
      
      
      
      
      
      
      
      
      
        // reference: http://www.wolframalpha.com/input/?i=3%2B4*2%2F%281-5%29^2^3
        iStat += EqnTest (_T ("3+4*2/(1-5)^2^3"), 3.0001220703125, true);
      
        // Test user defined binary operators
        iStat += EqnTestInt (_T ("1 | 2"), 3, true);
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
        // Test reading of hex values:
        iStat += EqnTestInt (_T ("0xff"), 255, true);
      
      
      
      
      
      
      
// incorrect: '^' is yor here, not power
//    iStat += EqnTestInt("-(1+2)^2", -9, true);
//    iStat += EqnTestInt("-1^3", -1, true);          
        
        // Test precedence
        // a=1, b=2, c=3
        iStat += EqnTestInt (_T ("a + b * c"), 7, true);
      
      
      
      
      
      
      
      
      
        
      
      else
        
          console () << _T ("\n  failed with ") << iStat << _T (" errors") <<
          endl;
      
    
    
      //---------------------------------------------------------------------------------------------
    /** \brief Check muParser name restriction enforcement. */ 
    int ParserTester::TestNames () 
    {
      
      
      
      
#define PARSER_THROWCHECK(DOMAIN, FAIL, EXPR, ARG) \
        iErr = 0;
      \
      \
      {
        \
##DOMAIN(EXPR, ARG);                 \
      } \
      {
        \
      \
      
        // constant names
        PARSER_THROWCHECK (Const, false, _T ("0a"), 1) 
        PARSER_THROWCHECK (Const, false, _T ("9a"), 1) 
        PARSER_THROWCHECK (Const, false, _T ("+a"), 1) 
        PARSER_THROWCHECK (Const, false, _T ("-a"), 1) 
        PARSER_THROWCHECK (Const, false, _T ("a-"), 1) 
        PARSER_THROWCHECK (Const, false, _T ("a*"), 1) 
        PARSER_THROWCHECK (Const, false, _T ("a?"), 1) 
        PARSER_THROWCHECK (Const, true, _T ("a"), 1) 
        PARSER_THROWCHECK (Const, true, _T ("a_min"), 1) 
        PARSER_THROWCHECK (Const, true, _T ("a_min0"), 1) 
        PARSER_THROWCHECK (Const, true, _T ("a_min9"), 1) 
        // variable names
        value_type a;
      
      
        PARSER_THROWCHECK (Var, false, _T ("9a"), &a) 
        PARSER_THROWCHECK (Var, false, _T ("0a"), &a) 
        PARSER_THROWCHECK (Var, false, _T ("+a"), &a) 
        PARSER_THROWCHECK (Var, false, _T ("-a"), &a) 
        PARSER_THROWCHECK (Var, false, _T ("?a"), &a) 
        PARSER_THROWCHECK (Var, false, _T ("!a"), &a) 
        PARSER_THROWCHECK (Var, false, _T ("a+"), &a) 
        PARSER_THROWCHECK (Var, false, _T ("a-"), &a) 
        PARSER_THROWCHECK (Var, false, _T ("a*"), &a) 
        PARSER_THROWCHECK (Var, false, _T ("a?"), &a) 
        PARSER_THROWCHECK (Var, true, _T ("a"), &a) 
        PARSER_THROWCHECK (Var, true, _T ("a_min"), &a) 
        PARSER_THROWCHECK (Var, true, _T ("a_min0"), &a) 
        PARSER_THROWCHECK (Var, true, _T ("a_min9"), &a) 
        PARSER_THROWCHECK (Var, false, _T ("a_min9"), 0) 
        // Postfix operators
        // fail
        PARSER_THROWCHECK (PostfixOprt, false, _T ("(k"), f1of1) 
        PARSER_THROWCHECK (PostfixOprt, false, _T ("9+"), f1of1) 
        PARSER_THROWCHECK (PostfixOprt, false, _T ("+"), 0) 
        // pass
        PARSER_THROWCHECK (PostfixOprt, true, _T ("-a"), f1of1) 
        PARSER_THROWCHECK (PostfixOprt, true, _T ("?a"), f1of1) 
        PARSER_THROWCHECK (PostfixOprt, true, _T ("_"), f1of1) 
        PARSER_THROWCHECK (PostfixOprt, true, _T ("#"), f1of1) 
        PARSER_THROWCHECK (PostfixOprt, true, _T ("&&"), f1of1) 
        PARSER_THROWCHECK (PostfixOprt, true, _T ("||"), f1of1) 
        PARSER_THROWCHECK (PostfixOprt, true, _T ("&"), f1of1) 
        PARSER_THROWCHECK (PostfixOprt, true, _T ("|"), f1of1) 
        PARSER_THROWCHECK (PostfixOprt, true, _T ("++"), f1of1) 
        PARSER_THROWCHECK (PostfixOprt, true, _T ("--"), f1of1) 
        PARSER_THROWCHECK (PostfixOprt, true, _T ("?>"), f1of1) 
        PARSER_THROWCHECK (PostfixOprt, true, _T ("?<"), f1of1) 
        PARSER_THROWCHECK (PostfixOprt, true, _T ("**"), f1of1) 
        PARSER_THROWCHECK (PostfixOprt, true, _T ("xor"), f1of1) 
        PARSER_THROWCHECK (PostfixOprt, true, _T ("and"), f1of1) 
        PARSER_THROWCHECK (PostfixOprt, true, _T ("or"), f1of1) 
        PARSER_THROWCHECK (PostfixOprt, true, _T ("not"), f1of1) 
        PARSER_THROWCHECK (PostfixOprt, true, _T ("!"), f1of1) 
        // Binary operator
        // The following must fail with builtin operators activated
        // p.EnableBuiltInOp(true); -> this is the default
        p.ClearPostfixOprt ();
      
        PARSER_THROWCHECK (Oprt, false, _T ("-"), f1of2) 
        PARSER_THROWCHECK (Oprt, false, _T ("*"), f1of2) 
        PARSER_THROWCHECK (Oprt, false, _T ("/"), f1of2) 
        PARSER_THROWCHECK (Oprt, false, _T ("^"), f1of2) 
        PARSER_THROWCHECK (Oprt, false, _T ("&&"), f1of2) 
        PARSER_THROWCHECK (Oprt, false, _T ("||"), f1of2) 
        // without activated built in operators it should work
        p.EnableBuiltInOprt (false);
      
        PARSER_THROWCHECK (Oprt, true, _T ("-"), f1of2) 
        PARSER_THROWCHECK (Oprt, true, _T ("*"), f1of2) 
        PARSER_THROWCHECK (Oprt, true, _T ("/"), f1of2) 
        PARSER_THROWCHECK (Oprt, true, _T ("^"), f1of2) 
        PARSER_THROWCHECK (Oprt, true, _T ("&&"), f1of2) 
        PARSER_THROWCHECK (Oprt, true, _T ("||"), f1of2) 
#undef PARSER_THROWCHECK
        
        
      
      else
        
          console () << _T ("\n  failed with ") << iStat << _T (" errors") <<
          endl;
      
    
    
      //---------------------------------------------------------------------------
    int ParserTester::TestSyntax () 
    {
      
      
      
      iStat += ThrowTest (_T ("a,"), ecUNEXPECTED_EOF); // incomplete hex definition
      iStat += ThrowTest (_T ("sin(8),"), ecUNEXPECTED_EOF);    // incomplete hex definition
      iStat += ThrowTest (_T ("(sin(8)),"), ecUNEXPECTED_EOF);  // incomplete hex definition
      iStat += ThrowTest (_T ("a{m},"), ecUNEXPECTED_EOF);      // incomplete hex definition
      
      iStat += EqnTest (_T ("sqrt((4))"), 2, true);     // Multiple brackets
      iStat += EqnTest (_T ("sqrt((2)+2)"), 2, true);   // Multiple brackets
      iStat += EqnTest (_T ("sqrt(2+(2))"), 2, true);   // Multiple brackets
      iStat += EqnTest (_T ("sqrt(a+(3))"), 2, true);   // Multiple brackets
      iStat += EqnTest (_T ("sqrt((3)+a)"), 2, true);   // Multiple brackets
      iStat += EqnTest (_T ("order(1,2)"), 1, true);    // May not cause name collision with operator "or"
      iStat += EqnTest (_T ("(2+"), 0, false);  // missing closing bracket 
      iStat += EqnTest (_T ("2++4"), 0, false); // unexpected operator
      iStat += EqnTest (_T ("2+-4"), 0, false); // unexpected operator
      iStat += EqnTest (_T ("(2+)"), 0, false); // unexpected closing bracket
      iStat += EqnTest (_T ("--2"), 0, false);  // double sign
      iStat += EqnTest (_T ("ksdfj"), 0, false);        // unknown token
      iStat += EqnTest (_T ("()"), 0, false);   // empty bracket without a function
      iStat += EqnTest (_T ("5+()"), 0, false); // empty bracket without a function
      iStat += EqnTest (_T ("sin(cos)"), 0, false);     // unexpected function
      iStat += EqnTest (_T ("5t6"), 0, false);  // unknown token
      iStat += EqnTest (_T ("5 t 6"), 0, false);        // unknown token
      iStat += EqnTest (_T ("8*"), 0, false);   // unexpected end of formula
      iStat += EqnTest (_T (",3"), 0, false);   // unexpected comma
      iStat += EqnTest (_T ("3,5"), 0, false);  // unexpected comma
      iStat += EqnTest (_T ("sin(8,8)"), 0, false);     // too many function args
      iStat += EqnTest (_T ("(7,8)"), 0, false);        // too many function args
      iStat += EqnTest (_T ("sin)"), 0, false); // unexpected closing bracket
      iStat += EqnTest (_T ("a)"), 0, false);   // unexpected closing bracket
      iStat += EqnTest (_T ("pi)"), 0, false);  // unexpected closing bracket
      iStat += EqnTest (_T ("sin(())"), 0, false);      // unexpected closing bracket
      iStat += EqnTest (_T ("sin()"), 0, false);        // unexpected closing bracket
      
        
      
      else
        
          console () << _T ("\n  failed with ") << iStat << _T (" errors") <<
          endl;
      
    
    
      //---------------------------------------------------------------------------
    int ParserTester::TestVarConst () 
    {
      
      
      
        // Test if the result changes when a variable changes
        iStat += EqnTestWithVarChange (_T ("a"), 1, 1, 2, 2);
      
      
        // distinguish constants with same basename
        iStat += EqnTest (_T ("const"), 1, true);
      
      
      
      
      
      
      
      
      
      
      
      
        // distinguish variables with same basename
        iStat += EqnTest (_T ("a"), 1, true);
      
      
      
      
      
      
        // custom value recognition
        iStat += EqnTest (_T ("0xff"), 255, true);
      
      
        // Finally test querying of used variables
        try 
      {
        
        
        
        {
        1, 2, 3, 4, 5};
        
        
        
        
        
        
          // Test lookup of defined variables
          // 4 used variables
          p.SetExpr (_T ("a+b+c+d"));
        
        
        
          
        
          // the next check will fail if the parser 
          // erroneously creates new variables internally
          if (p.GetVar ().size () != 5)
          
        
        
          
        {
          
            
        
        
          // Test lookup of undefined variables
          p.SetExpr (_T ("undef1+undef2+undef3"));
        
        
        
          
        
          // the next check will fail if the parser 
          // erroneously creates new variables internally
          if (p.GetVar ().size () != 5)
          
        
          
        {
          
            
        }
        
          // 1 used variables
          p.SetExpr (_T ("a+b"));
        
        
        
          throw false;
        
        
          
            throw false;
      
      
      {
        
      
      
        
      
      else
        
          console () << _T ("\n  failed with ") << iStat << _T (" errors") <<
          endl;
      
    
    
      //---------------------------------------------------------------------------
    int ParserTester::TestMultiArg () 
    {
      
      
      
        // Compound expressions
        iStat += EqnTest (_T ("1,2,3"), 3, true);
      
      
      
      
      
      
      
      
      
        // picking the right argument
        iStat += EqnTest (_T ("f1of1(1)"), 1, true);
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
        // Too few arguments / Too many arguments
        iStat += EqnTest (_T ("1+ping()"), 11, true);
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
        // correct calculation of arguments
        iStat += EqnTest (_T ("min(a, 1)"), 1, true);
      
      
      
      
      
      
      
      
      
        // functions with Variable argument count
        iStat += EqnTest (_T ("sum(a)"), 1, true);
      
      
      
      
      
      
      
      
      
      
      
      
      
        EqnTest (_T ("sum(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2)"),
                 24, true);
      
        // some failures
        iStat += EqnTest (_T ("sum()"), 0, false);
      
      
      
      
        
      
      else
        
          console () << _T ("\n  failed with ") << iStat << _T (" errors") <<
          endl;
      
    
    
      //---------------------------------------------------------------------------
    int ParserTester::TestInfixOprt () 
    {
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
        // Postfix / infix priorities
        iStat += EqnTest (_T ("~2#"), 8, true);
      
      
      
      
      
      
        //
        iStat += EqnTest (_T ("-2^2"), -4, true);
      
      
      
      
      
        // The following assumes use of sqr as postfix operator ("�") together
        // with a sign operator of low priority:
        iStat += EqnTest (_T ("-2'"), -4, true);
      
      
      
      
        // This is the classic behavior of the infix sign operator (here: "$") which is
        // now deprecated:
        iStat += EqnTest (_T ("$2^2"), 4, true);
      
      
      
      
      
        // infix operators sharing the first few characters
        iStat += EqnTest (_T ("~ 123"), 123 + 2, true);
      
      
        
      
      else
        
          console () << _T ("\n  failed with ") << iStat << _T (" errors") <<
          endl;
      
    
    
      //---------------------------------------------------------------------------
    int ParserTester::TestPostFix () 
    {
      
      
      
        // application
        iStat += EqnTest (_T ("3{m}+5"), 5.003, true);
      
      
      
      
      
      
      
      
      
      
      
      
      
      
        // can postfix operators "m" und "meg" be told apart properly?
        iStat += EqnTest (_T ("2*3000meg+2"), 2 * 3e9 + 2, true);
      
        // some incorrect results
        iStat += EqnTest (_T ("1000{m}"), 0.1, false);
      
      
        // failure due to syntax checking
        iStat += ThrowTest (_T ("0x"), ecUNASSIGNABLE_TOKEN);   // incomplete hex definition
      iStat += ThrowTest (_T ("3+"), ecUNEXPECTED_EOF);
      
      
      
      
      
      
      
      
      
      
      
        
      
      else
        
          console () << _T ("\n  failed with ") << iStat << _T (" errors") <<
          endl;
      
    
    
      //---------------------------------------------------------------------------
    int ParserTester::TestExpression () 
    {
      
      
      
      
        // Optimization
        iStat += EqnTest (_T ("2*b*5"), 20, true);
      
      
      
        // Addition auf cmVARMUL 
        iStat += EqnTest (_T ("3+b"), b + 3, true);
      
      
      
      
      
      
      
      
      
      
      
      
        // operator precedences
        iStat += EqnTest (_T ("1+2-3*4/5^6"), 2.99923, true);
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
        EqnTest (_T ("(1*(2*(3*(4*(5*(6*(7*(a+b))))))))"), 15120, true);
      
        EqnTest (_T
                 ("(a/((((b+(((e*(((((pi*((((3.45*((pi+a)+pi))+b)+b)*a))+0.68)+e)+a)/a))+a)+b))+b)*a)-pi))"),
                 0.00377999, true);
      
        // long formula (Reference: Matlab)
        iStat +=
        EqnTest (
                 ("(((-9))-e/(((((((pi-(((-7)+(-3)/4/e))))/(((-5))-2)-((pi+(-0))*(sqrt((e+e))*(-8))*(((-pi)+(-pi)-(-9)*(6*5))")
                 
                 _T
                 ("/(-e)-e))/2)/((((sqrt(2/(-e)+6)-(4-2))+((5/(-2))/(1*(-pi)+3))/8)*pi*((pi/((-2)/(-6)*1*(-1))*(-6)+(-e)))))/")
                 
                 _T
                 ("((e+(-2)+(-e)*((((-3)*9+(-e)))+(-9)))))))-((((e-7+(((5/pi-(3/1+pi)))))/e)/(-5))/(sqrt((((((1+(-7))))+((((-")
                 
                 _T
                 ("e)*(-e)))-8))*(-5)/((-e)))*(-6)-((((((-2)-(-9)-(-e)-1)/3))))/(sqrt((8+(e-((-6))+(9*(-9))))*(((3+2-8))*(7+6")
                 
                 _T
                 ("+(-5))+((0/(-e)*(-pi))+7)))+(((((-e)/e/e)+((-6)*5)*e+(3+(-5)/pi))))+pi))/sqrt((((9))+((((pi))-8+2))+pi))/e")
                 
                 _T
                 ("*4)*((-5)/(((-pi))*(sqrt(e)))))-(((((((-e)*(e)-pi))/4+(pi)*(-9)))))))+(-pi)"),
                 -12.23016549, true);
      
        // long formula (Reference: Matlab)
        iStat +=
        EqnTest (
                 ("(atan(sin((((((((((((((((pi/cos((a/((((0.53-b)-pi)*e)/b))))+2.51)+a)-0.54)/0.98)+b)*b)+e)/a)+b)+a)+b)+pi)/e")
                 
      
        // long formula (Reference: Matlab)
        iStat +=
        EqnTest (_T ("1+2-3*4/5^6*(2*(1-5+(3*7^9)*(4+6*7-3)))+12"),
                 -7995810.09926, true);
      
        
      
      else
        
          console () << _T ("\n  failed with ") << iStat << _T (" errors") <<
          endl;
      
    
    
      //---------------------------------------------------------------------------
    int ParserTester::TestIfThenElse () 
    {
      
      
      
        // Test error detection
        iStat += ThrowTest (_T (":3"), ecUNEXPECTED_CONDITIONAL);
      
      
        ThrowTest (_T ("(a<b) ? (b<c) ? 1 : 2"), ecMISSING_ELSE_CLAUSE);
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
        EqnTest (_T ("((a>b) ? 1 : 0) ? 1 : sum((a>b) ? 1 : 2)"), 2, true);
      
        EqnTest (_T ("((a>b) ? 0 : 1) ? 1 : sum((a>b) ? 1 : 2)"), 1, true);
      
      
      
      
      
      
      
      
      
      
      
        EqnTest (_T ("(a<b) ? sum(3, (a<b) ? 3 : 10)*10 : 99"), 60, true);
      
        EqnTest (_T ("(a>b) ? sum(3, (a<b) ? 3 : 10)*10 : 99"), 99, true);
      
        EqnTest (_T ("(a<b) ? sum(3, (a<b) ? 3 : 10,10,20)*10 : 99"), 360,
                 true);
      
        EqnTest (_T ("(a>b) ? sum(3, (a<b) ? 3 : 10,10,20)*10 : 99"), 99,
                 true);
      
        EqnTest (_T
                 ("(a>b) ? sum(3, (a<b) ? 3 : 10,10,20)*10 : sum(3, (a<b) ? 3 : 10)*10"),
                 60, true);
      
        // todo: auch f�r muParserX hinzuf�gen!
        iStat += EqnTest (_T ("(a<b)&&(a<b) ? 128 : 255"), 128, true);
      
      
      
      
      
      
      
      
        EqnTest (_T ("1>0 ? 1>2 ? 128 : 255 : 1>0 ? 32 : 64"), 255, true);
      
        EqnTest (_T ("1>0 ? 1>2 ? 128 : 255 :(1>0 ? 32 : 64)"), 255, true);
      
        EqnTest (_T ("1>0 ? 1>0 ? 128 : 255 : 1>2 ? 32 : 64"), 128, true);
      
        EqnTest (_T ("1>0 ? 1>0 ? 128 : 255 :(1>2 ? 32 : 64)"), 128, true);
      
        EqnTest (_T ("1>2 ? 1>2 ? 128 : 255 : 1>0 ? 32 : 64"), 32, true);
      
        EqnTest (_T ("1>2 ? 1>0 ? 128 : 255 : 1>2 ? 32 : 64"), 64, true);
      
      
      
      
        EqnTest (_T ("1>2 ? 1>2 ? 128 : 255 : 1>0 ? 32 : 1>2 ? 64 : 16"), 32,
                 true);
      
        EqnTest (_T ("1>2 ? 1>2 ? 128 : 255 : 1>0 ? 32 :(1>2 ? 64 : 16)"), 32,
                 true);
      
        EqnTest (_T ("1>0 ? 1>2 ? 128 : 255 :  1>0 ? 32 :1>2 ? 64 : 16"), 255,
                 true);
      
        EqnTest (_T ("1>0 ? 1>2 ? 128 : 255 : (1>0 ? 32 :1>2 ? 64 : 16)"),
                 255, true);
      
      
        // assignment operators
        iStat += EqnTest (_T ("a= 0 ? 128 : 255, a"), 255, true);
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
        
      
      else
        
          console () << _T ("\n  failed with ") << iStat << _T (" errors") <<
          endl;
      
    
    
      //---------------------------------------------------------------------------
    int ParserTester::TestException () 
    {
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
#if defined(MUP_MATH_EXCEPTIONS)
        // divide by zero whilst constant folding
        iStat += ThrowTest (_T ("1/0"), ecDIV_BY_ZERO);
      
        // square root of a negative number
        iStat += ThrowTest (_T ("sqrt(-1)"), ecDOMAIN_ERROR);
      
        // logarithms of zero
        iStat += ThrowTest (_T ("ln(0)"), ecDOMAIN_ERROR);
      
      
      
      
        // logarithms of negative values
        iStat += ThrowTest (_T ("ln(-1)"), ecDOMAIN_ERROR);
      
      
      
      
#endif  /* 
        
        // functions without parameter
        iStat += ThrowTest (_T ("3+ping(2)"), ecTOO_MANY_PARAMS);
      
      
      
      
        // String function related
        iStat += ThrowTest (_T ("valueof(\"xxx\")"), 999, false);
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
        ThrowTest (_T ("strfun3(\"1\", \"100\", \"100\", \"100\")"),
                   ecTOO_MANY_PARAMS);
      
        // assignment operator
        iStat += ThrowTest (_T ("3=4"), ecUNEXPECTED_OPERATOR);
      
      
      
        // <ibg 20090529>
        // this is now legal, for reference see:
        // https://sourceforge.net/forum/message.php?msg_id=7411373
        //      iStat += ThrowTest( _T("sin=9"), ecUNEXPECTED_OPERATOR);    
        // </ibg>
        
      
      
      
        
      
      else
        
          console () << _T ("\n  failed with ") << iStat << _T (" errors") <<
          endl;
      
    
    
      //---------------------------------------------------------------------------
    void ParserTester::AddTest (testfun_type a_pFun) 
    {
      
    
      //---------------------------------------------------------------------------
    void ParserTester::Run () 
    {
      
      
      {
        
          
      
      {
        
        
        
      
      {
        
        
      
      {
        
        
      
        
      {
        
          c_iCount << " expressions)" << endl;
      
      
      else
        
      {
        
          <<" errors (" << ParserTester::c_iCount 
      
      
    
    
      //---------------------------------------------------------------------------
    int ParserTester::ThrowTest (const string_type & a_str, int a_iErrc,
                                 bool a_bFail) 
    {
      
      
      {
        
        {
        1, 1, 1};
        
        
        
        
        
        
        
        
        
        
        
        
        
      
      {
        
          // output the formula in case of an failed test
          if (a_bFail == false
              || (a_bFail == true && a_iErrc != e.GetCode ()))
          
        {
          
            <<_T ("Expression: ") << a_str 
            <<_T ("  Code:") << e.GetCode () << _T ("(") << e.
            GetMsg () << _T (")") 
        
        
      
      
        // if a_bFail==false no exception is expected
        bool bRet ((a_bFail == false) ? 0 : 1);
      
        
      {
        
          <<_T ("Expression: ") << a_str 
          <<_T ("  did evaluate; Expected error:") << a_iErrc;
      
      
    
    
      //---------------------------------------------------------------------------
    /** \brief Evaluate a tet expression. 

        \return 1 in case of a failure, 0 otherwise.
    */ 
    int ParserTester::EqnTestWithVarChange (const string_type & a_str,
                                            
                                            
                                            
    {
      
      
      {
        
        {
        -999, -999};            // should be equal
        
        
        
          // variable
          p.DefineVar (_T ("a"), &var);
        
        
        
        
        
        
          
        
          
      
      
      {
        
          c_str () << _T (" (") << e.GetMsg () << _T (")");
        
      
      
      {
        
          c_str () << _T (" (") << e.what () << _T (")");
        
      }
      
      {
        
          c_str () << _T (" (unexpected exception)");
        
      }
      
    
    
      //---------------------------------------------------------------------------
    /** \brief Evaluate a tet expression. 

        \return 1 in case of a failure, 0 otherwise.
    */ 
    int ParserTester::EqnTest (const string_type & a_str, double a_fRes,
                               bool a_fPass) 
    {
      
      
      
      {
      -999, -998, -997, -996, -995};    // initially should be different
      
      {
        
        
        // they will be used for testing copy and assignment operators
        // p1 is a pointer since i'm going to delete it in order to test if
        // parsers after copy construction still refer to members of it.
        // !! If this is the case this function will crash !!
        
        
          // Add constants
          p1->DefineConst (_T ("pi"), (value_type) PARSER_CONST_PI);
        
        
        
        
        
          // string constants
          p1->DefineStrConst (_T ("str1"), _T ("1.11"));
        
        
          // variables
          value_type vVarVal[] =
        {
        1, 2, 3, -2};
        
        
        
        
        
        
          // custom value ident functions
          p1->AddValIdent (&ParserTester::IsHexVal);
        
          // functions
          p1->DefineFun (_T ("ping"), Ping);
        
        p1->DefineFun (_T ("f1of2"), f1of2);    // two parameter
        p1->DefineFun (_T ("f2of2"), f2of2);
        
        p1->DefineFun (_T ("f2of3"), f2of3);
        
        
        p1->DefineFun (_T ("f2of4"), f2of4);
        
        
        
        p1->DefineFun (_T ("f2of5"), f2of5);
        
        
        
        
          // binary operators
          p1->DefineOprt (_T ("add"), add, 0);
        
        
        
          // sample functions
          p1->DefineFun (_T ("min"), Min);
        
        
        
        
        
        
        
        
        
        
        
          // infix / postfix operator
          // Note: Identifiers used here do not have any meaning 
          //       they are mere placeholders to test certain features.
          p1->DefineInfixOprt (_T ("$"), sign, prPOW + 1);      // sign with high priority
        p1->DefineInfixOprt (_T ("~"), plus2);  // high priority
        p1->DefineInfixOprt (_T ("~~"), plus2);
        
        
        
        
        
        
        
        
          // Test bytecode integrity
          // String parsing and bytecode parsing must yield the same result
          fVal[0] = p1->Eval ();        // result from stringparsing
        fVal[1] = p1->Eval ();  // result from bytecode
        if (fVal[0] != fVal[1])
          
            exception_type (_T ("Bytecode / string parsing mismatch."));
        
          // Test copy and assignment operators
          try 
        {
          
            // Test copy constructor
            std::vector < mu::Parser > vParser;
          
          
          
            // destroy the originals from p2
            vParser.clear ();   // delete the vector
          p1.reset (0);
          
          
            // Test assignment operator
            // additionally  disable Optimizer this time
            mu::Parser p3;
          
          
          
          
            // Test Eval function for multiple return values
            // use p2 since it has the optimizer enabled!
          int nNum;
          
          
        
        {
          
        
          // limited floating point accuracy requires the following test
          bool bCloseEnough (true);
        
          
        {
          
            (fabs (a_fRes - fVal[i]) <= fabs (fVal[i] * 0.00001));
          
            // The tests equations never result in infinity, if they do thats a bug.
            // reference:
            // http://sourceforge.net/projects/muparser/forums/forum/462843/topic/5037825
#pragma warning(push)
#pragma warning(disable:4127)
            if (std::numeric_limits < value_type >::has_infinity)
            
#pragma warning(pop)
          {
            
              (fabs (fVal[i]) != numeric_limits < value_type >::infinity ());
          
        
        
                   || (!bCloseEnough && !a_fPass)) ? 0 : 1;
        
          
        {
          
            <<_T (" (incorrect result; expected: ") << a_fRes 
            <<_T (" ;calculated: ") << fVal[0] << _T (",") 
            <<fVal[1] << _T (",") 
            <<fVal[2] << _T (",") 
            <<fVal[3] << _T (",") 
        
      
      
      {
        
          
        {
          
            
              c_str () << _T (" (copy construction)");
          
          else
            
              c_str () << _T (" (") << e.GetMsg () << _T (")");
          
        
      
      
      {
        
          c_str () << _T (" (") << e.what () << _T (")");
        
      }
      
      {
        
          c_str () << _T (" (unexpected exception)");
        
      }
      
    
    
      //---------------------------------------------------------------------------
    int ParserTester::EqnTestInt (const string_type & a_str, double a_fRes,
                                  bool a_fPass) 
    {
      
      
      {
      1, 2, 3};                 // variable values
      int iRet (0);
      
      {
        
        {
        -99, -999};             // results: initially should be different
        ParserInt p;
        
        
        
        
        
        
        
        fVal[1] = p.Eval ();    // result from bytecode
        
          
        
                   (a_fRes != fVal[0] && !a_fPass)) ? 0 : 1;
        
          
        {
          
            <<_T (" (incorrect result; expected: ") << a_fRes 
            <<_T (" ;calculated: ") << fVal[0] << _T (").");
        
      
      
      {
        
          
        {
          
            GetExpr () << _T (" : ") << e.GetMsg ();
          
        
      
      
      {
        
          c_str () << _T (" (unexpected exception)");
        
      }
      
    
    
      //---------------------------------------------------------------------------
    /** \brief Test an expression in Bulk Mode. */ 
    int ParserTester::EqnTestBulk (const string_type & a_str,
                                   double a_fRes[4], bool a_fPass) 
    {
      
      
        // Define Bulk Variables
      int nBulkSize = 4;
      
      {
      1, 2, 3, 4};              // variable values
      value_type vVariableB[] = { 2, 2, 2, 2 }; // variable values
      value_type vVariableC[] = { 3, 3, 3, 3 }; // variable values
      value_type vResults[] = { 0, 0, 0, 0 };   // variable values
      int iRet (0);
      
      {
        
        
        
        
        
        
        
        
        
        
          
        {
          
            (fabs (a_fRes[i] - vResults[i]) <= fabs (a_fRes[i] * 0.00001));
        
                      || (!bCloseEnough && !a_fPass)) ? 0 : 1;
        
          
        {
          
            <<_T (" (incorrect result; expected: {") << a_fRes[0] << _T (",")
            << a_fRes[1] << _T (",") << a_fRes[2] << _T (",") << a_fRes[3] <<
            _T ("}") 
            vResults[1] << _T (",") << vResults[2] << _T (",") << vResults[3]
            << _T ("}");
        
      
      
      {
        
          
        {
          
            GetExpr () << _T (" : ") << e.GetMsg ();
          
        
      
      
      {
        
          c_str () << _T (" (unexpected exception)");
        
      }
      
    
    
      //---------------------------------------------------------------------------
    /** \brief Internal error in test class Test is going to be aborted. */ 
    void ParserTester::Abort () const 
    {
      
        console () << _T ("Test failed (internal error in test class)") <<
        endl;
      
      
    
   
}                               // namespace mu