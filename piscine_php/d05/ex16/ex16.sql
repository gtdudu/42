SELECT count(id_film) as 'films' FROM historique_membre WHERE (DATE_FORMAT (date, '%Y %m %d') BETWEEN '2006 10 30' AND '2007 07 27') OR (DATE_FORMAT (date, '%m %d') = '12 24');
