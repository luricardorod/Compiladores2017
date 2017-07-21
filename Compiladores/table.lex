var	Keyword
a	Id
,	Delimiter
b	Id
,	Delimiter
c123	Id
:	Delimiter
int	Keyword
;	Delimiter
var	Keyword
b1	Id
,	Delimiter
c12	Id
,	Delimiter
a	Id
:	Delimiter
float	Keyword
;	Delimiter
procedure	Keyword
myproc	Id
(	Group Operators
x	Id
,	Delimiter
y	Id
:	Delimiter
int	Keyword
;	Delimiter
z	Id
:	Delimiter
string	Keyword
)	Group Operators
{	Group Operators
var	Keyword
firstvar	Id
:	Delimiter
boolean	Id
;	Delimiter
var	Keyword
z	Id
:	Delimiter
int	Keyword
;	Delimiter
var	Keyword
w	Id
:	Delimiter
int	Keyword
;	Delimiter
var	Keyword
a	Id
:	Delimiter
float	Keyword
;	Delimiter
if	Keyword
(	Group Operators
(	Group Operators
(	Group Operators
(	Group Operators
x	Id
+	AritmeticOperator
y	Id
+	AritmeticOperator
3	Int
)	Group Operators
-	AritmeticOperator
1	Int
)	Group Operators
>	Relacional Operator
5	Int
)	Group Operators
)	Group Operators
{	Group Operators
w	Id
=	Assign
10	Int
;	Delimiter
}	Group Operators
firstvar	Id
=	Assign
secondvar	Id
;	Delimiter
if	Keyword
(	Group Operators
!	Logic Operator
firstvar	Id
)	Group Operators
{	Group Operators
secondvar	Id
=	Assign
secondvar	Id
*	AritmeticOperator
3.0	float
;	Delimiter
}	Group Operators
z	Id
=	Assign
100	Int
;	Delimiter
;	Delimiter
;	Delimiter
if	Keyword
9	Int
(	Group Operators
z	Id
+	AritmeticOperator
3	Int
)	Group Operators
{	Group Operators
w	Id
=	Assign
1	Int
}	Group Operators
while	Keyword
(	Group Operators
z	Id
+	AritmeticOperator
2	Int
{	Group Operators
w	Id
=	Assign
2	Int
;	Delimiter
}	Group Operators
if	Keyword
z	Id
+	AritmeticOperator
2	Int
)	Group Operators
{	Group Operators
w	Id
=	Assign
3	Int
;	Delimiter
}	Group Operators
while	Keyword
z	Id
+	AritmeticOperator
2	Int
{	Group Operators
w	Id
=	Assign
5	Int
;	Delimiter
}	Group Operators
if	Keyword
(	Group Operators
z	Id
2	Int
)	Group Operators
{	Group Operators
w	Id
==	Relacional Operator
4	Int
;	Delimiter
}	Group Operators
while	Keyword
(	Group Operators
z	Id
>	Relacional Operator
1	Int
)	Group Operators
{	Group Operators
}	Group Operators
if	Keyword
(	Group Operators
)	Group Operators
{	Group Operators
}	Group Operators
while	Keyword
)	Group Operators
z	Id
>	Relacional Operator
10	Int
)	Group Operators
{	Group Operators
}	Group Operators
while	Keyword
(	Group Operators
z	Id
<	Relacional Operator
1	Int
)	Group Operators
{	Group Operators
}	Group Operators
}	Group Operators
}	Group Operators
var	Keyword
a2	Id
:	Delimiter
boolean	Id
;	Delimiter
function	Keyword
facIter	Id
(	Group Operators
x	Id
:	Delimiter
int	Keyword
)	Group Operators
:	Delimiter
int	Keyword
{	Group Operators
if	Keyword
(	Group Operators
x	Id
<=	Relacional Operator
1	Int
)	Group Operators
{	Group Operators
return	Keyword
1	Int
;	Delimiter
}	Group Operators
return	Keyword
facIter	Id
(	Group Operators
x	Id
-	AritmeticOperator
1	Int
)	Group Operators
;	Delimiter
}	Group Operators
function	Keyword
sumInt	Id
(	Group Operators
x	Id
,	Delimiter
y	Id
:	Delimiter
int	Keyword
)	Group Operators
:	Delimiter
int	Keyword
{	Group Operators
result	Id
:	Delimiter
int	Keyword
;	Delimiter
result	Id
=	Assign
x	Id
+	AritmeticOperator
y	Id
;	Delimiter
}	Group Operators
procedure	Keyword
sumInt	Id
(	Group Operators
x	Id
,	Delimiter
y	Id
:	Delimiter
int	Keyword
)	Group Operators
{	Group Operators
result	Id
:	Delimiter
int	Keyword
;	Delimiter
result	Id
=	Assign
x	Id
+	AritmeticOperator
y	Id
;	Delimiter
}	Group Operators
procedure	Keyword
c123	Id
(	Group Operators
)	Group Operators
{	Group Operators
}	Group Operators
main	Keyword
(	Group Operators
)	Group Operators
{	Group Operators
var	Keyword
b	Id
:	Delimiter
float	Keyword
;	Delimiter
var	Keyword
c	Id
=	Assign
9.5	float
;	Delimiter
while	Keyword
(	Group Operators
b	Id
>	Relacional Operator
3.0	float
)	Group Operators
{	Group Operators
if	Keyword
(	Group Operators
c	Id
<	Relacional Operator
1.0	float
)	Group Operators
{	Group Operators
while	Keyword
(	Group Operators
b	Id
>	Relacional Operator
6.0	float
)	Group Operators
{	Group Operators
if	Keyword
(	Group Operators
c	Id
<	Relacional Operator
-	AritmeticOperator
1.0	float
)	Group Operators
{	Group Operators
while	Keyword
(	Group Operators
b	Id
>	Relacional Operator
9.0	float
)	Group Operators
{	Group Operators
if	Keyword
(	Group Operators
c	Id
<	Relacional Operator
-	AritmeticOperator
10.0	float
)	Group Operators
{	Group Operators
}	Group Operators
}	Group Operators
}	Group Operators
}	Group Operators
}	Group Operators
}	Group Operators
}	Group Operators
