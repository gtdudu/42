	    jQuery(function($){
	        //Navigation drop downs
	        $('.nav ul').superfish({
	        	autoArrows: true,
	        	animation:   {opacity:'show',height:'show'},
	        	speed: 'normal',
	        	delay: 0,
	        	dropShadows: false
	        });
	        //sliding content
	        $('#feature-slides').cycle({
				timeout: 5000,
				fx: 'scrollHorz',
				speed: 500,
				speedIn: 700,
				next:   '#next',
	    		prev:   '#prev'
			});
	    });