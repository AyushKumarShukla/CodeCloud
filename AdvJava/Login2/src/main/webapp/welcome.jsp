<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@ page import="
					java.sql.Connection,
					javax.servlet.http.HttpSession,
					java.sql.Statement,
					java.sql.ResultSet
				" 
%>
<%@ page import="com.ayush.Auth, com.ayush.DbConnect" %>
<!DOCTYPE html>	
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
	<h2>WELCOME WORLD!</h2>
<%

	HttpSession sess = request.getSession();
	int uid = (Integer) sess.getAttribute("uid");
	String pass = (String) sess.getAttribute("pass");
	Boolean loginStatus = (Boolean)sess.getAttribute("loginStatus");
	String name = null;
	if(Auth.authenticate(uid,pass))
	{
		out.println("Logged In Successfully");
		Connection conn = DbConnect.connect();
		String fetch = String.format("SELECT name from user_details WHERE uid = %d",uid);
		Statement stmt = conn.createStatement();
		ResultSet res1 = stmt.executeQuery(fetch);
		if(res1.next())
		{
			name = res1.getString("name");
		}
		out.print("WELCOME " + name);
	}
%>
<a href="profile.jsp">View Your Profile</a>
</body>
</html>