<?php

function caja18_dashboard_page() {
  drupal_add_css(drupal_get_path("module", "caja18") . "/css/graficos.css");
  drupal_add_css(drupal_get_path("module", "caja18") . "/css/filter.css");

  drupal_add_js(drupal_get_path("module", "caja18") . "/js/filter.js");
  drupal_add_js(drupal_get_path("module", "caja18") . "/js/grafico-resumen.js");
  drupal_add_js(drupal_get_path("module", "caja18") . "/js/graficos-promedios.js");
  drupal_add_js(libraries_get_path('highcharts') . "/js/highcharts.js");
  drupal_add_js(libraries_get_path('highcharts') . "/js/highcharts-more.js");
  drupal_add_js(libraries_get_path('highcharts') . "/js/modules/solid-gauge.js");
  drupal_add_js(libraries_get_path('highcharts') . "/js/modules/drilldown.js");
  $sucursales = _caja18_get_sucursales();
  $preguntas = _caja18_get_preguntas();
  $indicadores = _caja18_get_indicadores();
  drupal_add_js(array(
    'caja18' => array(
      'sucursales' => $sucursales,
      'preguntas' => $preguntas,
      'indicadores' => $indicadores,
      'tipo' => 'trimestre',
      'drilldown' => array(
        "active" => false,
        "point" => null,
        "filter" => array(),
      ),
      'filter' => array(),
      'postData' => '',
    ),
  ), 'setting');
  $filterForm = drupal_get_form('caja18_dashboard_filter_form');
  $rol_access_class = "rol-sucursal";
  if (user_access("view any caja18 kpi data")) {
    $rol_access_class = "admin";
  }

  return theme('dashboard', array('filterForm' => drupal_render($filterForm), 'preguntas' => $preguntas, 'rol_access_class' => $rol_access_class));
}
