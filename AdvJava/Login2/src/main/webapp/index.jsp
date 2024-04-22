<html>
<body>
<h2>Hello World!</h2>
<form action="Auth" method="POST">
User ID: <input type="number" name="uid"> <br>
Password: <input type="text" name="pass"> <br>
<input type="submit">
</form>
<%
    String loginStatus = (String)request.getAttribute("loginStatus");
    if(loginStatus != null) {
        out.println("<p>" + loginStatus + "</p>");
    }
%>
</body>
</html>

