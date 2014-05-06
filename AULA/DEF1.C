 ‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹
  #define (directive)
 ﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂﬂ
Defines a macro

  #define <id1>[( <id2>, ... )] <token-string>

The #define directive defines a macro. Macros provide a mechanism for token
replacement with or without a set of formal, function-line parameters.

All subsequent instances of the identifier <id1> in the source text will be
replaced by the text defined by <token-string>.

If <id1> is followed IMMEDIATELY by a (, the identifiers following the open
parenthesis (<id2>, etc.) are treated like parameters to a function instead
of as part of <token-string>.

All instances of <id2> in <token-string> will be replaced with the actual
text defined for <id2> when <id1> is referenced in the source.

To continue the definitions on another line, end the current line with \.

 Example
 ﬂﬂﬂﬂﬂﬂﬂ
  #define MAXINT 32767
  #define ctrl(x) ((x) \
		   - 64)

See also

  #undef    #if    token pasting
