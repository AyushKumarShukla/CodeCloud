<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Result</title>
</head>
<body>
	<center><h2>Result</h2></center>
	<%
		int num1 = Integer.parseInt(request.getParameter("num1"));
		int num2 = Integer.parseInt(request.getParameter("num2"));
		int res=0;
		String op = request.getParameter("operation");
		switch(op)
		{
		case "add":
			res = num1 + num2;
			break;
		case "sub":
			res = num1 - num2;
			break;
		case "mul":
			res = num1 * num2;
			break;
		case "div":
			if(num2 == 0)
				out.println("FATAL ERROR: DIVIDE BY ZERO");
			else
				res = num1 / num2;
			break;
		}
		out.println(num1);
		out.println(op);
		out.println(num2);
		out.println(res);
	%>
</body>
</html>