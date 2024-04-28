<html>
<body>

<form action="CreateUserSession" method="POST">
	<div class="inp">
		<label for="uid">Enter UserID: </label>
		<input type="number" name="uid">
	</div>
	<div class="inp">
		<label for="pass">Enter Password: </label>
		<input type="text" name="pass">
	</div>
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

