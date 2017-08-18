var	Keyword
a	Id
,	Delimiter
b	Id
,	Delimiter
c	Id
:	Delimiter
int	Keyword
;	Delimiter
var	Keyword
d	Id
:	Delimiter
bool	Keyword
;	Delimiter
var	Keyword
e	Id
,	Delimiter
f	Id
:	Delimiter
float	Keyword
;	Delimiter
var	Keyword
g	Id
[	Open Dimension Operator
10	Int
]	Close Dimension Operator
,	Delimiter
h	Id
[	Open Dimension Operator
1	Int
]	Close Dimension Operator
:	Delimiter
int	Keyword
;	Delimiter
procedure	Keyword
uno	Id
(	Group Operators
)	Group Operators
{	Group Operators
var	Keyword
a	Id
:	Delimiter
bool	Keyword
;	Delimiter
a	Id
=	Assign
true	Keyword
;	Delimiter
e	Id
=	Assign
100.0	float
;	Delimiter
}	Group Operators
procedure	Keyword
dos	Id
(	Group Operators
a	Id
:	Delimiter
float	Keyword
;	Delimiter
b	Id
:	Delimiter
bool	Keyword
)	Group Operators
{	Group Operators
switch	Keyword
(	Group Operators
c	Id
)	Group Operators
{	Group Operators
4	Int
:	Delimiter
{	Group Operators
f	Id
=	Assign
a	Id
*	AritmeticOperator
-	AritmeticOperator
1.0	float
;	Delimiter
}	Group Operators
5	Int
:	Delimiter
{	Group Operators
f	Id
=	Assign
a	Id
*	AritmeticOperator
10.0	float
;	Delimiter
}	Group Operators
9	Int
:	Delimiter
{	Group Operators
if	Keyword
(	Group Operators
b	Id
)	Group Operators
{	Group Operators
f	Id
=	Assign
a	Id
*	AritmeticOperator
100.0	float
;	Delimiter
}	Group Operators
}	Group Operators
default	Keyword
:	Delimiter
{	Group Operators
f	Id
=	Assign
1000.0	float
;	Delimiter
}	Group Operators
}	Group Operators
}	Group Operators
function	Keyword
func1	Id
(	Group Operators
)	Group Operators
:	Delimiter
float	Keyword
{	Group Operators
var	Keyword
total	Id
:	Delimiter
float	Keyword
;	Delimiter
total	Id
=	Assign
e	Id
+	AritmeticOperator
f	Id
;	Delimiter
return	Keyword
(	Group Operators
(	Group Operators
e	Id
*	AritmeticOperator
10.0	float
)	Group Operators
+	AritmeticOperator
total	Id
)	Group Operators
;	Delimiter
}	Group Operators
function	Keyword
func2	Id
(	Group Operators
)	Group Operators
:	Delimiter
int	Keyword
{	Group Operators
var	Keyword
x	Id
:	Delimiter
int	Keyword
;	Delimiter
var	Keyword
y	Id
,	Delimiter
z	Id
:	Delimiter
float	Keyword
;	Delimiter
x	Id
=	Assign
1	Int
;	Delimiter
y	Id
=	Assign
2.0	float
;	Delimiter
z	Id
=	Assign
1.0	float
;	Delimiter
x	Id
=	Assign
x	Id
+	AritmeticOperator
1	Int
;	Delimiter
y	Id
=	Assign
y	Id
*	AritmeticOperator
z	Id
;	Delimiter
z	Id
=	Assign
2.0	float
*	AritmeticOperator
y	Id
;	Delimiter
return	Keyword
x	Id
;	Delimiter
}	Group Operators
function	Keyword
func3	Id
(	Group Operators
param1	Id
:	Delimiter
float	Keyword
)	Group Operators
:	Delimiter
float	Keyword
{	Group Operators
var	Keyword
g	Id
:	Delimiter
float	Keyword
;	Delimiter
if	Keyword
(	Group Operators
g	Id
>	Relacional Operator
0.0	float
)	Group Operators
{	Group Operators
g	Id
=	Assign
200.0	float
;	Delimiter
return	Keyword
g	Id
;	Delimiter
}	Group Operators
else	Keyword
{	Group Operators
g	Id
=	Assign
100.0	float
;	Delimiter
}	Group Operators
return	Keyword
(	Group Operators
(	Group Operators
(	Group Operators
e	Id
*	AritmeticOperator
f	Id
)	Group Operators
+	AritmeticOperator
(	Group Operators
f	Id
-	AritmeticOperator
param1	Id
)	Group Operators
)	Group Operators
*	AritmeticOperator
(	Group Operators
e	Id
*	AritmeticOperator
g	Id
)	Group Operators
)	Group Operators
;	Delimiter
}	Group Operators
function	Keyword
func4	Id
(	Group Operators
)	Group Operators
:	Delimiter
bool	Keyword
{	Group Operators
if	Keyword
(	Group Operators
true	Keyword
)	Group Operators
{	Group Operators
}	Group Operators
return	Keyword
true	Keyword
;	Delimiter
}	Group Operators
main	Keyword
(	Group Operators
)	Group Operators
{	Group Operators
var	Keyword
x	Id
:	Delimiter
int	Keyword
;	Delimiter
a	Id
=	Assign
1	Int
;	Delimiter
a	Id
=	Assign
1	Int
;	Delimiter
g	Id
[	Open Dimension Operator
0	Int
]	Close Dimension Operator
=	Assign
1	Int
;	Delimiter
g	Id
[	Open Dimension Operator
1	Int
]	Close Dimension Operator
=	Assign
2	Int
;	Delimiter
g	Id
[	Open Dimension Operator
3	Int
]	Close Dimension Operator
=	Assign
3	Int
;	Delimiter
g	Id
[	Open Dimension Operator
4	Int
]	Close Dimension Operator
=	Assign
4	Int
;	Delimiter
g	Id
[	Open Dimension Operator
5	Int
]	Close Dimension Operator
=	Assign
5	Int
;	Delimiter
uno	Id
(	Group Operators
)	Group Operators
;	Delimiter
dos	Id
(	Group Operators
e	Id
,	Delimiter
false	Keyword
)	Group Operators
;	Delimiter
func4	Id
(	Group Operators
)	Group Operators
;	Delimiter
if	Keyword
(	Group Operators
(	Group Operators
g	Id
[	Open Dimension Operator
0	Int
]	Close Dimension Operator
+	AritmeticOperator
g	Id
[	Open Dimension Operator
5	Int
]	Close Dimension Operator
)	Group Operators
>	Relacional Operator
10	Int
)	Group Operators
{	Group Operators
g	Id
[	Open Dimension Operator
0	Int
]	Close Dimension Operator
=	Assign
283764	Int
;	Delimiter
}	Group Operators
if	Keyword
(	Group Operators
(	Group Operators
g	Id
[	Open Dimension Operator
0	Int
]	Close Dimension Operator
+	AritmeticOperator
g	Id
[	Open Dimension Operator
9	Int
]	Close Dimension Operator
)	Group Operators
>	Relacional Operator
10	Int
)	Group Operators
{	Group Operators
g	Id
[	Open Dimension Operator
0	Int
]	Close Dimension Operator
=	Assign
22222	Int
;	Delimiter
}	Group Operators
}	Group Operators
