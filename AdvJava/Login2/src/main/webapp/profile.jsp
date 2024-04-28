<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@ page import="
					java.sql.Connection,
					javax.servlet.http.HttpSession,
					java.sql.Statement,
					java.sql.ResultSet,
					java.sql.ResultSetMetaData
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
	
	if(Auth.authenticate(uid,pass))
	{
		out.println("USER VERIFIED");
		Connection conn = DbConnect.connect();
		String fetch = String.format("SELECT * from login_details NATURAL JOIN user_details WHERE uid = %d", uid);
		Statement stmt = conn.createStatement();
		ResultSet res1 = stmt.executeQuery(fetch);
		
		ResultSetMetaData meta = res1.getMetaData();
		int colcnt = meta.getColumnCount();
		out.print("COLUMN COUNT " + colcnt);
		while(res1.next())
		{
			for(int i=1;i<=colcnt;i++)
			{
				String colName = meta.getColumnName(i);
				Object val = res1.getObject(i);
				out.print("<h4>"+colName+" : "+val+"</h2>\n");
			}
		}
	}
%>
</body>
</html>