SELECT nom, prenom FROM fiche_personne WHERE nom LIKE '%-%' OR prenom LIKE '%-%' ORDER BY lower(nom), lower(prenom);
