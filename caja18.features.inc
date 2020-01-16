<?php

/**
 * @file
 * caja18.features.inc
 */

/**
 * Implements hook_views_api().
 */
function caja18_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function caja18_eck_bundle_info() {
  $items = array(
    'datos_mediciones_grupo' => array(
      'machine_name' => 'datos_mediciones_grupo',
      'entity_type' => 'datos_mediciones',
      'name' => 'grupo',
      'label' => 'Grupo',
      'config' => array(),
    ),
    'datos_mediciones_indicador' => array(
      'machine_name' => 'datos_mediciones_indicador',
      'entity_type' => 'datos_mediciones',
      'name' => 'indicador',
      'label' => 'Indicador',
      'config' => array(),
    ),
    'datos_mediciones_semana' => array(
      'machine_name' => 'datos_mediciones_semana',
      'entity_type' => 'datos_mediciones',
      'name' => 'semana',
      'label' => 'Semana',
      'config' => array(),
    ),
    'datos_mediciones_sucursal' => array(
      'machine_name' => 'datos_mediciones_sucursal',
      'entity_type' => 'datos_mediciones',
      'name' => 'sucursal',
      'label' => 'Sucursal',
      'config' => array(),
    ),
    'datos_mediciones_trimestre' => array(
      'machine_name' => 'datos_mediciones_trimestre',
      'entity_type' => 'datos_mediciones',
      'name' => 'trimestre',
      'label' => 'Trimestre',
      'config' => array(),
    ),
    'datos_mediciones_zona' => array(
      'machine_name' => 'datos_mediciones_zona',
      'entity_type' => 'datos_mediciones',
      'name' => 'zona',
      'label' => 'Zona',
      'config' => array(),
    ),
    'estadistica_medicion_indicador_trimestre' => array(
      'machine_name' => 'estadistica_medicion_indicador_trimestre',
      'entity_type' => 'estadistica_medicion',
      'name' => 'indicador_trimestre',
      'label' => 'Indicador Trimestre',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function caja18_eck_entity_type_info() {
  $items = array(
    'datos_mediciones' => array(
      'name' => 'datos_mediciones',
      'label' => 'Datos Mediciones',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
      ),
    ),
    'estadistica_medicion' => array(
      'name' => 'estadistica_medicion',
      'label' => 'Estadística Medición',
      'properties' => array(
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
      ),
    ),
  );
  return $items;
}
