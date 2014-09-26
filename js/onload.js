/* Main JS execution */

$(document).ready(function() {

	/* Load header HTML */
	$.ajax({
	  	url: "linked/header.html",
	  	dataType: "html",
	  	success: 	function(data) {
						$('body').html(data);
					}
	});

	/* Load footer HTML */
	$.ajax({
	  	url: "linked/footer.html",
	  	dataType: "html",
	  	success: 	function(data) {
						$('body').html(data);
					}
	});

});