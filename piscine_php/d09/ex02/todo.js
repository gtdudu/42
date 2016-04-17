
	var list = new Array();

	function myset() {
		ca = getCookie("save").split(',');
		for (var i = 0; i < ca.length; i++) {
			add(ca[i]);
			console.log(ca[i]);
		}
	}

	function setCookie(cname, cvalue, exdays) {
		var d = new Date();
		d.setTime(d.getTime() + (exdays*24*60*60*1000));
		var expires = "expires="+d.toUTCString();
		document.cookie = cname + "=" + cvalue + "; " + expires;

	}

	function getCookie(cname) {
		var name = cname + "=";
		var ca = document.cookie.split(';');
		for (var i = 0; i < ca.length; i++) {
			var c = ca[i];
			while (c.charAt(0) == ' ') 
				c = substring(1);
			if (c.indexOf(name) == 0)
				return c.substring(name.length, c.length);
		}
		return "";
	}

	function add(todo) {

		var newdiv = null;
		var verif = null;
		newdiv = document.createElement("div");
		newdiv.innerHTML = todo;
		newdiv.onclick = function() {
			if (confirm("I m sure you didn't do it, did you?")) {
				newdiv.parentNode.removeChild(newdiv);
			}
		}
		verif = document.getElementById("ft_list");
		document.getElementById("ft_list").insertBefore(newdiv, verif.firstChild);		
		list.push(todo);
		setCookie('save', list, 1);
	}

	function myFunc() {

		var todo = prompt("What would you like to do?", "Probably nothing right?");
		if (todo != null)
			add(todo);
	}

