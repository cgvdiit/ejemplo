<div id="dashboard-header" class="container-fluid">
  <div class="row">
    <div class="col-sm-4 col-md-3 col-ld-2">
      <div id="filters"><?php print $filterForm; ?></div>
    </div>
    <div id="logo-caja18" class="col-sm-3 col-md-2 col-ld-3 imagen">
      <img src="/sites/all/modules/caja18/images/logo_caja_portal.jpg" width="150">
    </div>
    <div class="col-sm-3 col-md-2 seleccion-filtro">
      <div id="tipo_medicion"></div>
      <div id="filtro_principal"></div>
      <div id="seleccion_semana"></div>
      <div id="tamano_muestra"></div>
    </div>
    <div class="col-sm-2 col-md-5 imagen">
      <img src="/sites/all/modules/caja18/images/kronos.jpg" width="200">
    </div>
  </div>
</div>
<div id="grafico-resumen"></div>
<div class="content promedios <?php print $rol_access_class ?>">
  <?php foreach ($preguntas as $pregunta): ?>
  <div id="grafico-ratio-<?php print $pregunta->form_key; ?>" class="grafico"></div>
  <?php endforeach; ?>
</div>
