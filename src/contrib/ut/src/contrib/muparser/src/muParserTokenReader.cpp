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
  
#include <cassert>
#include <cstdio>
#include <cstring>
#include <map>
#include <stack>
#include <string>
  
#include "muParserTokenReader.h"
#include "muParserBase.h"
  
/** \file
    \brief This file contains the parser token reader implementation.
*/ 
  
{
  
    // Forward declaration
    class ParserBase;
  
    //---------------------------------------------------------------------------
  /** \brief Copy constructor.

      \sa Assign
      \throw nothrow
  */ 
    ParserTokenReader::ParserTokenReader (const ParserTokenReader & a_Reader) 
  {
    
  
    //---------------------------------------------------------------------------
  /** \brief Assignment operator.

      Self assignment will be suppressed otherwise #Assign is called.

      \param a_Reader Object to copy to this token reader.
      \throw nothrow
  */ 
    ParserTokenReader & ParserTokenReader::
    operator= (const ParserTokenReader & a_Reader) 
  {
    
      
    
  
  
    //---------------------------------------------------------------------------
  /** \brief Assign state of a token reader to this token reader. 
      
      \param a_Reader Object from which the state should be copied.
      \throw nothrow
  */ 
  void ParserTokenReader::Assign (const ParserTokenReader & a_Reader) 
  {
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
  
    //---------------------------------------------------------------------------
  /** \brief Constructor. 
      
      Create a Token reader and bind it to a parser object. 

      \pre [assert] a_pParser may not be NULL
      \post #m_pParser==a_pParser
      \param a_pParent Parent parser object of the token reader.
  */ 
ParserTokenReader::ParserTokenReader (ParserBase * a_pParent) 
  m_pParser (a_pParent) 
  m_bIgnoreUndefVar (false) 
  m_pInfixOprtDef (NULL) 
  m_pStrVarDef (NULL) 
  m_pFactoryData (NULL) 
  m_iBrackets (0) 
  {
    
    
  
    //---------------------------------------------------------------------------
  /** \brief Create instance of a ParserTokenReader identical with this 
              and return its pointer. 

      This is a factory method the calling function must take care of the object destruction.

      \return A new ParserTokenReader object.
      \throw nothrow
  */ 
  ParserTokenReader * ParserTokenReader::Clone (ParserBase * a_pParent) const 
  {
    
    
    
  
   
    //---------------------------------------------------------------------------
   
    ParserTokenReader::token_type & ParserTokenReader::
    SaveBeforeReturn (const token_type & tok) 
  {
    
    
  
  
    //---------------------------------------------------------------------------
  void ParserTokenReader::AddValIdent (identfun_type a_pCallback) 
  {
    
      // Use push_front is used to give user defined callbacks a higher priority than
      // the built in ones. Otherwise reading hex numbers would not work
      // since the "0" in "0xff" would always be read first making parsing of 
      // the rest impossible.
      // reference:
      // http://sourceforge.net/projects/muparser/forums/forum/462843/topic/4824956
      m_vIdentFun.push_front (a_pCallback);
  
    //---------------------------------------------------------------------------
  void ParserTokenReader::SetVarCreator (facfun_type a_pFactory,
                                         void *pUserData) 
  {
    
    
  
    //---------------------------------------------------------------------------
  /** \brief Return the current position of the token reader in the formula string. 

      \return #m_iPos
      \throw nothrow
  */ 
  int ParserTokenReader::GetPos () const 
  {
    
  
   
    //---------------------------------------------------------------------------
  /** \brief Return a reference to the formula. 

      \return #m_strFormula
      \throw nothrow
  */ 
  const string_type & ParserTokenReader::GetExpr () const 
  {
    
  
   
    //---------------------------------------------------------------------------
  /** \brief Return a map containing the used variables only. */ 
    varmap_type & ParserTokenReader::GetUsedVar () 
  {
    
  
  
    //---------------------------------------------------------------------------
  /** \brief Initialize the token Reader. 
  
      Sets the formula position index to zero and set Syntax flags to default for initial formula parsing.
      \pre [assert] triggered if a_szFormula==0
  */ 
  void ParserTokenReader::SetFormula (const string_type & a_strFormula) 
  {
    
    
  
    //---------------------------------------------------------------------------
  /** \brief Set Flag that controls behavior in case of undefined variables being found. 
  
    If true, the parser does not throw an exception if an undefined variable is found. 
    otherwise it does. This variable is used internally only!
    It suppresses a "undefined variable" exception in GetUsedVar().  
    Those function should return a complete list of variables including 
    those the are not defined by the time of it's call.
  */ 
  void ParserTokenReader::IgnoreUndefVar (bool bIgnore) 
  {
    
  
    //---------------------------------------------------------------------------
  /** \brief Reset the token reader to the start of the formula. 

      The syntax flags will be reset to a value appropriate for the 
      start of a formula.
      \post #m_iPos==0, #m_iSynFlags = noOPT | noBC | noPOSTOP | noSTR
      \throw nothrow
      \sa ESynCodes
  */ 
  void ParserTokenReader::ReInit () 
  {
    
    
    
    
    
  
    //---------------------------------------------------------------------------
  /** \brief Read the next token from the string. */ 
    ParserTokenReader::token_type ParserTokenReader::ReadNextToken () 
  {
    
    
    
    
      // Ignore all non printable characters when reading the expression
      while (szFormula[m_iPos] > 0 && szFormula[m_iPos] <= 0x20)
      
+m_iPos;
    
      return SaveBeforeReturn (tok);    // Check for end of formula
    if (IsOprt (tok))
      return SaveBeforeReturn (tok);    // Check for user defined binary operator
    if (IsFunTok (tok))
      return SaveBeforeReturn (tok);    // Check for function token
    if (IsBuiltIn (tok))
      return SaveBeforeReturn (tok);    // Check built in operators / tokens
    if (IsArgSep (tok))
      return SaveBeforeReturn (tok);    // Check for function argument separators
    if (IsValTok (tok))
      return SaveBeforeReturn (tok);    // Check for values / constant tokens
    if (IsVarTok (tok))
      return SaveBeforeReturn (tok);    // Check for variable tokens
    if (IsStrVarTok (tok))
      return SaveBeforeReturn (tok);    // Check for string variables
    if (IsString (tok))
      return SaveBeforeReturn (tok);    // Check for String tokens
    if (IsInfixOpTok (tok))
      return SaveBeforeReturn (tok);    // Check for unary operators
    if (IsPostOpTok (tok))
      return SaveBeforeReturn (tok);    // Check for unary operators
    
      // Check String for undefined variable token. Done only if a 
      // flag is set indicating to ignore undefined variables.
      // This is a way to conditionally avoid an error if 
      // undefined variables occur. 
      // (The GetUsedVar function must suppress the error for
      // undefined variables in order to collect all variable 
      // names including the undefined ones.)
      if ((m_bIgnoreUndefVar || m_pFactory) && IsUndefVarTok (tok))
      
    
      // Check for unknown token
      // 
      // !!! From this point on there is no exit without an exception possible...
      // 
      string_type strTok;
    
    
      
    
    
  }
  
    //---------------------------------------------------------------------------
  void ParserTokenReader::SetParent (ParserBase * a_pParent) 
  {
    
    
    
    
    
    
    
    
  
    //---------------------------------------------------------------------------
  /** \brief Extract all characters that belong to a certain charset.

    \param a_szCharSet [in] Const char array of the characters allowed in the token. 
    \param a_strTok [out]  The string that consists entirely of characters listed in a_szCharSet.
    \param a_iPos [in] Position in the string from where to start reading.
    \return The Position of the first character not listed in a_szCharSet.
    \throw nothrow
  */ 
  int ParserTokenReader::ExtractToken (const char_type * a_szCharSet,
                                       
                                       
  {
    
     
      
     
      // Assign token string if there was something found
    if (a_iPos != iEnd)
       
        string_type (m_strFormula.begin () + a_iPos,
                     m_strFormula.begin () + iEnd);
     
   
   
    //---------------------------------------------------------------------------
  /** \brief Check Expression for the presence of a binary operator token.
  
    Userdefined binary operator "++" gives inconsistent parsing result for
    the equations "a++b" and "a ++ b" if alphabetic characters are allowed
    in operator tokens. To avoid this this function checks specifically
    for operator tokens.
  */ 
  int ParserTokenReader::ExtractOperatorToken (string_type & a_sTok,
                                               
  {
    
      // Changed as per Issue 6: https://code.google.com/p/muparser/issues/detail?id=6
    int iEnd =
      (int) m_strFormula.find_first_not_of (m_pParser->ValidOprtChars (),
                                            a_iPos);
     
      
     
      // Assign token string if there was something found
    if (a_iPos != iEnd)
       
    {
      
        string_type (m_strFormula.begin () + a_iPos,
                     m_strFormula.begin () + iEnd);
      
    
     
    else
       
    {
      
        // There is still the chance of having to deal with an operator consisting exclusively
        // of alphabetic characters.
        return ExtractToken (MUP_CHARS, a_sTok, a_iPos);
    
  
  
    //---------------------------------------------------------------------------
  /** \brief Check if a built in operator or other token can be found
      \param a_Tok  [out] Operator token if one is found. This can either be a binary operator or an infix operator token.
      \return true if an operator token has been found.
  */ 
    bool ParserTokenReader::IsBuiltIn (token_type & a_Tok) 
  {
    
      m_pParser->GetOprtDef (), 
    
      // Compare token with function and operator strings
      // check string for operator/function
      for (int i = 0; pOprtDef[i]; i++)
      
    {
      
      
           string_type (szFormula + m_iPos, szFormula + m_iPos + len))
        
      {
        
          
        {
          
            //case cmAND:
            //case cmOR:
            //case cmXOR:
        case cmLAND:
        
        
        
        
        
        
        
        
        
        
        
        
        
          
            //if (len!=sTok.length())
            //  continue;
            
            // The assignment operator need special treatment
            if (i == cmASSIGN && m_iSynFlags & noASSIGN)
            
          
            continue;
          
            
          {
            
              // Maybe its an infix operator not an operator
              // Both operator types can share characters in 
              // their identifiers
              if (IsInfixOpTok (a_Tok))
              
            
          
          
            noBC | noOPT | noARG_SEP | noPOSTOP | noASSIGN | noIF | noELSE |
            noEND;
          
        
          
            
          
            
              noOPT | noEND | noARG_SEP | noPOSTOP | noASSIGN | noIF | noELSE;
          
          else
            
              noBC | noOPT | noEND | noARG_SEP | noPOSTOP | noASSIGN | noIF |
              noELSE;
          
+m_iBrackets;
          
        
          
            
          
            noBO | noVAR | noVAL | noFUN | noINFIXOP | noSTR | noASSIGN;
          
            
          
        
          
            
          
          
        
          
            
          
          
        
          Error (ecINTERNAL_ERROR);
        
        
        
        
      
    }                           // end of for all operator strings
    
  
  
    //---------------------------------------------------------------------------
    bool ParserTokenReader::IsArgSep (token_type & a_Tok) 
  {
    
    
      
    {
      
        // copy the separator into null terminated string
        char_type szSep[2];
      
      
      
        
      
      
      
      
    
    
  
  
    //---------------------------------------------------------------------------
  /** \brief Check for End of Formula.

      \return true if an end of formula is found false otherwise.
      \param a_Tok [out] If an eof is found the corresponding token will be stored there.
      \throw nothrow
      \sa IsOprt, IsFunTok, IsStrFunTok, IsValTok, IsVarTok, IsString, IsInfixOpTok, IsPostOpTok
  */ 
    bool ParserTokenReader::IsEOF (token_type & a_Tok) 
  {
    
    
      // check for EOF
      if (!szFormula[m_iPos] /*|| szFormula[m_iPos] == '\n' */ )
      
    {
      
        
      
        
      
      
      
    
    
  
  
    //---------------------------------------------------------------------------
  /** \brief Check if a string position contains a unary infix operator. 
      \return true if a function token has been found false otherwise.
  */ 
    bool ParserTokenReader::IsInfixOpTok (token_type & a_Tok) 
  {
    
    
      ExtractToken (m_pParser->ValidInfixOprtChars (), sTok, m_iPos);
    
      
    
      // iterate over all postfix operator strings
      funmap_type::const_reverse_iterator it = m_pInfixOprtDef->rbegin ();
    
      
    {
      
        
      
      
      
        
      
      
    
    
    
/*
    a_Tok.Set(item->second, sTok);
    m_iPos = (int)iEnd;

    if (m_iSynFlags & noINFIXOP) 
      Error(ecUNEXPECTED_OPERATOR, m_iPos, a_Tok.GetAsString());

    m_iSynFlags = noPOSTOP | noINFIXOP | noOPT | noBC | noSTR | noASSIGN; 
    return true;
*/ 
  }
  
    //---------------------------------------------------------------------------
  /** \brief Check whether the token at a given position is a function token.
      \param a_Tok [out] If a value token is found it will be placed here.
      \throw ParserException if Syntaxflags do not allow a function at a_iPos
      \return true if a function token has been found false otherwise.
      \pre [assert] m_pParser!=0
  */ 
    bool ParserTokenReader::IsFunTok (token_type & a_Tok) 
  {
    
    
    
      
    
    
      
    
      // Check if the next sign is an opening bracket
    const char_type *szFormula = m_strFormula.c_str ();
    
      
    
    
    
      
              a_Tok.GetAsString ());
    
    
  
  
    //---------------------------------------------------------------------------
  /** \brief Check if a string position contains a binary operator.
      \param a_Tok  [out] Operator token if one is found. This can either be a binary operator or an infix operator token.
      \return true if an operator token has been found.
  */ 
    bool ParserTokenReader::IsOprt (token_type & a_Tok) 
  {
    
    
    
    
      
    
      // Check if the operator is a built in operator, if so ignore it here
    const char_type **const pOprtDef = m_pParser->GetOprtDef ();
    
      
    {
      
        
    
    
      // Note:
      // All tokens in oprt_bin_maptype are have been sorted by their length
      // Long operators must come first! Otherwise short names (like: "add") that
      // are part of long token names (like: "add123") will be found instead 
      // of the long ones.
      // Length sorting is done with ascending length so we use a reverse iterator here.
      funmap_type::const_reverse_iterator it = m_pOprtDef->rbegin ();
    
      
    {
      
      
           string_type (szExpr + m_iPos, szExpr + m_iPos + sID.length ()))
        
      {
        
        
          // operator was found
          if (m_iSynFlags & noOPT)
          
        {
          
            // An operator was found but is not expected to occur at
            // this position of the formula, maybe it is an infix 
            // operator, not a binary operator. Both operator types
            // can share characters in their identifiers.
            if (IsInfixOpTok (a_Tok))
            
          
          else
            
          {
            
              // nope, no infix operator
              return false;
            
              //Error(ecUNEXPECTED_OPERATOR, m_iPos, a_Tok.GetAsString()); 
          }
        
        
        
        
      
    
    
  
  
    //---------------------------------------------------------------------------
  /** \brief Check if a string position contains a unary post value operator. */ 
    bool ParserTokenReader::IsPostOpTok (token_type & a_Tok) 
  {
    
      // <ibg 20110629> Do not check for postfix operators if they are not allowed at
      //                the current expression index.
      //
      //  This will fix the bug reported here:  
      //
      //  http://sourceforge.net/tracker/index.php?func=detail&aid=3343891&group_id=137191&atid=737979
      //
      if (m_iSynFlags & noPOSTOP)
      
    
      // </ibg>
      
      // Tricky problem with equations like "3m+5":
      //     m is a postfix operator, + is a valid sign for postfix operators and 
      //     for binary operators parser detects "m+" as operator string and 
      //     finds no matching postfix operator.
      // 
      // This is a special case so this routine slightly differs from the other
      // token readers.
      
      // Test if there could be a postfix operator
      string_type sTok;
    
    
      
    
      // iterate over all postfix operator strings
      funmap_type::const_reverse_iterator it = m_pPostOprtDef->rbegin ();
    
      
    {
      
        
      
      
      
        noVAL | noVAR | noFUN | noBO | noPOSTOP | noSTR | noASSIGN;
      
    
    
  
  
    //---------------------------------------------------------------------------
  /** \brief Check whether the token at a given position is a value token.

    Value tokens are either values or constants.

    \param a_Tok [out] If a value token is found it will be placed here.
    \return true if a value token has been found.
  */ 
    bool ParserTokenReader::IsValTok (token_type & a_Tok) 
  {
    
    
    
    
    
    
      // 2.) Check for user defined constant
      // Read everything that could be a constant name
      iEnd = ExtractToken (m_pParser->ValidNameChars (), strTok, m_iPos);
    
      
    {
      
      
        
      {
        
        
        
          
        
          noVAL | noVAR | noFUN | noBO | noINFIXOP | noSTR | noASSIGN;
        
      
    
    
      // 3.call the value recognition functions provided by the user
      // Call user defined value recognition functions
      std::list < identfun_type >::const_iterator item = m_vIdentFun.begin ();
    
      
    {
      
      
        
      {
        
          // 2013-11-27 Issue 2:  https://code.google.com/p/muparser/issues/detail?id=2
          strTok.assign (m_strFormula.c_str (), iStart, m_iPos - iStart);
        
          
        
        
          noVAL | noVAR | noFUN | noBO | noINFIXOP | noSTR | noASSIGN;
        
      
    
    
  
  
    //---------------------------------------------------------------------------
  /** \brief Check wheter a token at a given position is a variable token. 
      \param a_Tok [out] If a variable token has been found it will be placed here.
	    \return true if a variable token has been found.
  */ 
    bool ParserTokenReader::IsVarTok (token_type & a_Tok) 
  {
    
      
    
    
    
      
    
    
      
    
      
    
    
    
    
    
    
//  Zur Info hier die SynFlags von IsVal():
//    m_iSynFlags = noVAL | noVAR | noFUN | noBO | noINFIXOP | noSTR | noASSIGN; 
      return true;
  
  
    //---------------------------------------------------------------------------
    bool ParserTokenReader::IsStrVarTok (token_type & a_Tok) 
  {
    
      
    
    
    
      
    
    
      
    
      
    
    
      
    
                        m_pParser->m_vStringVarBuf.size ());
    
    
  
  
    //---------------------------------------------------------------------------
  /** \brief Check wheter a token at a given position is an undefined variable. 

      \param a_Tok [out] If a variable tom_pParser->m_vStringBufken has been found it will be placed here.
	    \return true if a variable token has been found.
      \throw nothrow
  */ 
    bool ParserTokenReader::IsUndefVarTok (token_type & a_Tok) 
  {
    
    
    
      
    
      
    {
      
        // <ibg/> 20061021 added token string strTok instead of a_Tok.GetAsString() as the 
        //                 token identifier. 
        // related bug report:
        // http://sourceforge.net/tracker/index.php?func=detail&aid=1578779&group_id=137191&atid=737979
        Error (ecUNEXPECTED_VAR,
               m_iPos - (int) a_Tok.GetAsString ().length (), strTok);
    
    
      // If a factory is available implicitely create new variables
      if (m_pFactory)
      
    {
      
      
      
        // Do not use m_pParser->DefineVar( strTok, fVar );
        // in order to define the new variable, it will clear the
        // m_UsedVar array which will kill previously defined variables
        // from the list
        // This is safe because the new variable can never override an existing one
        // because they are checked first!
        (*m_pVarDef)[strTok] = fVar;
      
    }
    
    else
      
    {
      
      
    }
    
    
      // Call the variable factory in order to let it define a new parser variable
      m_iSynFlags =
      noVAL | noVAR | noFUN | noBO | noPOSTOP | noINFIXOP | noSTR;
    
  
  
    //---------------------------------------------------------------------------
  /** \brief Check wheter a token at a given position is a string.
      \param a_Tok [out] If a variable token has been found it will be placed here.
  	  \return true if a string token has been found.
      \sa IsOprt, IsFunTok, IsStrFunTok, IsValTok, IsVarTok, IsEOF, IsInfixOpTok, IsPostOpTok
      \throw nothrow
  */ 
    bool ParserTokenReader::IsString (token_type & a_Tok) 
  {
    
      
    
    
    
      // parser over escaped '\"' end replace them with '"'
      for (iEnd = (int) strBuf.find (_T ("\""));
           iEnd != 0 && iEnd != string_type::npos;
           iEnd = (int) strBuf.find (_T ("\""), iEnd))
      
    {
      
        break;
      
      
    
    
      
    
    
      
    
    a_Tok.SetString (strTok, m_pParser->m_vStringBuf.size ());
    
    m_iSynFlags = noANY ^ (noARG_SEP | noBC | noOPT | noEND);
    
  
  
    //---------------------------------------------------------------------------
  /** \brief Create an error containing the parse error position.

    This function will create an Parser Exception object containing the error text and its position.

    \param a_iErrc [in] The error code of type #EErrorCodes.
    \param a_iPos [in] The position where the error was detected.
    \param a_strTok [in] The token string representation associated with the error.
    \throw ParserException always throws thats the only purpose of this function.
  */ 
  void ParserTokenReader::Error (EErrorCodes a_iErrc, 
                                 
  {
    
  
    //---------------------------------------------------------------------------
  void ParserTokenReader::SetArgSep (char_type cArgSep) 
  {
    
  
    //---------------------------------------------------------------------------
  char_type ParserTokenReader::GetArgSep ()const 
  {
    
  
 
 