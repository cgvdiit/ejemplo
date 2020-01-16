<?php

/**
 * @file
 * caja18.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function caja18_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'admin_datos_mediciones';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_datos_mediciones';
  $view->human_name = 'Admin Datos Mediciones';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Admin Datos Mediciones';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restablecer';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todo -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primero';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'type' => 'type',
    'field_id' => 'field_id',
    'title' => 'title',
    'view_link' => 'view_link',
    'delete_link' => 'view_link',
    'edit_link' => 'view_link',
  );
  $handler->display->display_options['style_options']['class'] = '';
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_link' => array(
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'delete_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Campo: Bulk operations: Datos Mediciones */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_datos_mediciones';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'log' => 0,
      ),
    ),
  );
  /* Campo: Datos Mediciones: datos_mediciones type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'eck_datos_mediciones';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Tipo';
  /* Campo: Datos Mediciones: ID */
  $handler->display->display_options['fields']['field_id']['id'] = 'field_id';
  $handler->display->display_options['fields']['field_id']['table'] = 'field_data_field_id';
  $handler->display->display_options['fields']['field_id']['field'] = 'field_id';
  $handler->display->display_options['fields']['field_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Campo: Datos Mediciones: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_datos_mediciones';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Título';
  /* Campo: Datos Mediciones: Enlace */
  $handler->display->display_options['fields']['view_link']['id'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['table'] = 'eck_datos_mediciones';
  $handler->display->display_options['fields']['view_link']['field'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['label'] = 'Acciones';
  /* Campo: Datos Mediciones: Enlace de borrado */
  $handler->display->display_options['fields']['delete_link']['id'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['table'] = 'eck_datos_mediciones';
  $handler->display->display_options['fields']['delete_link']['field'] = 'delete_link';
  /* Campo: Datos Mediciones: Enlace de edición */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_datos_mediciones';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  /* Criterio de ordenación: Datos Mediciones: datos_mediciones type */
  $handler->display->display_options['sorts']['type']['id'] = 'type';
  $handler->display->display_options['sorts']['type']['table'] = 'eck_datos_mediciones';
  $handler->display->display_options['sorts']['type']['field'] = 'type';
  /* Criterio de ordenación: Datos Mediciones: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'eck_datos_mediciones';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Criterios de filtrado: Datos Mediciones: datos_mediciones type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_datos_mediciones';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Tipo';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/datos-mediciones';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Datos Mediciones';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['admin_datos_mediciones'] = array(
    t('Master'),
    t('Admin Datos Mediciones'),
    t('más'),
    t('Aplicar'),
    t('Restablecer'),
    t('Ordenar por'),
    t('Asc'),
    t('Desc'),
    t('Elementos por página'),
    t('- Todo -'),
    t('Desplazamiento'),
    t('« primero'),
    t('‹ anterior'),
    t('siguiente ›'),
    t('última »'),
    t('Datos Mediciones'),
    t('- Choose an operation -'),
    t('Tipo'),
    t('ID'),
    t('Título'),
    t('Acciones'),
    t('Enlace de borrado'),
    t('Enlace de edición'),
    t('Page'),
  );
  $export['admin_datos_mediciones'] = $view;

  $view = new view();
  $view->name = 'admin_datos_trimestres';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_estadistica_medicion';
  $view->human_name = 'Admin Datos Trimestres';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Admin Datos Trimestres';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restablecer';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todo -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primero';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'field_trimestre' => 'field_trimestre',
    'field_tipo_indicador_trimestre' => 'field_tipo_indicador_trimestre',
    'field_sucursal' => 'field_sucursal',
    'field_zona' => 'field_zona',
    'field_grupo' => 'field_grupo',
    'view_link' => 'view_link',
    'delete_link' => 'view_link',
    'edit_link' => 'view_link',
  );
  $handler->display->display_options['style_options']['class'] = '';
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_trimestre' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tipo_indicador_trimestre' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sucursal' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_zona' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_grupo' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_link' => array(
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'delete_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Campo: Bulk operations: Estadística Medición */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_estadistica_medicion';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'log' => 0,
      ),
    ),
  );
  /* Campo: Estadística Medición: Trimestre */
  $handler->display->display_options['fields']['field_trimestre']['id'] = 'field_trimestre';
  $handler->display->display_options['fields']['field_trimestre']['table'] = 'field_data_field_trimestre';
  $handler->display->display_options['fields']['field_trimestre']['field'] = 'field_trimestre';
  $handler->display->display_options['fields']['field_trimestre']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Campo: Estadística Medición: Tipo */
  $handler->display->display_options['fields']['field_tipo_indicador_trimestre']['id'] = 'field_tipo_indicador_trimestre';
  $handler->display->display_options['fields']['field_tipo_indicador_trimestre']['table'] = 'field_data_field_tipo_indicador_trimestre';
  $handler->display->display_options['fields']['field_tipo_indicador_trimestre']['field'] = 'field_tipo_indicador_trimestre';
  /* Campo: Estadística Medición: Sucursal */
  $handler->display->display_options['fields']['field_sucursal']['id'] = 'field_sucursal';
  $handler->display->display_options['fields']['field_sucursal']['table'] = 'field_data_field_sucursal';
  $handler->display->display_options['fields']['field_sucursal']['field'] = 'field_sucursal';
  $handler->display->display_options['fields']['field_sucursal']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Campo: Campo: Zona */
  $handler->display->display_options['fields']['field_zona']['id'] = 'field_zona';
  $handler->display->display_options['fields']['field_zona']['table'] = 'field_data_field_zona';
  $handler->display->display_options['fields']['field_zona']['field'] = 'field_zona';
  $handler->display->display_options['fields']['field_zona']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Campo: Campo: Grupo */
  $handler->display->display_options['fields']['field_grupo']['id'] = 'field_grupo';
  $handler->display->display_options['fields']['field_grupo']['table'] = 'field_data_field_grupo';
  $handler->display->display_options['fields']['field_grupo']['field'] = 'field_grupo';
  $handler->display->display_options['fields']['field_grupo']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Campo: Estadística Medición: Enlace */
  $handler->display->display_options['fields']['view_link']['id'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['table'] = 'eck_estadistica_medicion';
  $handler->display->display_options['fields']['view_link']['field'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['label'] = 'Acciones';
  /* Campo: Estadística Medición: Enlace de borrado */
  $handler->display->display_options['fields']['delete_link']['id'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['table'] = 'eck_estadistica_medicion';
  $handler->display->display_options['fields']['delete_link']['field'] = 'delete_link';
  /* Campo: Estadística Medición: Enlace de edición */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_estadistica_medicion';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  /* Criterios de filtrado: Estadística Medición: Trimestre (field_trimestre) */
  $handler->display->display_options['filters']['field_trimestre_target_id']['id'] = 'field_trimestre_target_id';
  $handler->display->display_options['filters']['field_trimestre_target_id']['table'] = 'field_data_field_trimestre';
  $handler->display->display_options['filters']['field_trimestre_target_id']['field'] = 'field_trimestre_target_id';
  $handler->display->display_options['filters']['field_trimestre_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_trimestre_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_trimestre_target_id']['expose']['operator_id'] = 'field_trimestre_target_id_op';
  $handler->display->display_options['filters']['field_trimestre_target_id']['expose']['label'] = 'Trimestre';
  $handler->display->display_options['filters']['field_trimestre_target_id']['expose']['operator'] = 'field_trimestre_target_id_op';
  $handler->display->display_options['filters']['field_trimestre_target_id']['expose']['identifier'] = 'field_trimestre_target_id';
  $handler->display->display_options['filters']['field_trimestre_target_id']['expose']['remember_roles'] = array(
    2 => '2',
  );
  /* Criterios de filtrado: Estadística Medición: Tipo (field_tipo_indicador_trimestre) */
  $handler->display->display_options['filters']['field_tipo_indicador_trimestre_value']['id'] = 'field_tipo_indicador_trimestre_value';
  $handler->display->display_options['filters']['field_tipo_indicador_trimestre_value']['table'] = 'field_data_field_tipo_indicador_trimestre';
  $handler->display->display_options['filters']['field_tipo_indicador_trimestre_value']['field'] = 'field_tipo_indicador_trimestre_value';
  $handler->display->display_options['filters']['field_tipo_indicador_trimestre_value']['group'] = 1;
  $handler->display->display_options['filters']['field_tipo_indicador_trimestre_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tipo_indicador_trimestre_value']['expose']['operator_id'] = 'field_tipo_indicador_trimestre_value_op';
  $handler->display->display_options['filters']['field_tipo_indicador_trimestre_value']['expose']['label'] = 'Tipo';
  $handler->display->display_options['filters']['field_tipo_indicador_trimestre_value']['expose']['operator'] = 'field_tipo_indicador_trimestre_value_op';
  $handler->display->display_options['filters']['field_tipo_indicador_trimestre_value']['expose']['identifier'] = 'field_tipo_indicador_trimestre_value';
  $handler->display->display_options['filters']['field_tipo_indicador_trimestre_value']['expose']['remember_roles'] = array(
    2 => '2',
  );
  /* Criterios de filtrado: Estadística Medición: Sucursal (field_sucursal) */
  $handler->display->display_options['filters']['field_sucursal_target_id']['id'] = 'field_sucursal_target_id';
  $handler->display->display_options['filters']['field_sucursal_target_id']['table'] = 'field_data_field_sucursal';
  $handler->display->display_options['filters']['field_sucursal_target_id']['field'] = 'field_sucursal_target_id';
  $handler->display->display_options['filters']['field_sucursal_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_sucursal_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sucursal_target_id']['expose']['operator_id'] = 'field_sucursal_target_id_op';
  $handler->display->display_options['filters']['field_sucursal_target_id']['expose']['label'] = 'Sucursal';
  $handler->display->display_options['filters']['field_sucursal_target_id']['expose']['operator'] = 'field_sucursal_target_id_op';
  $handler->display->display_options['filters']['field_sucursal_target_id']['expose']['identifier'] = 'field_sucursal_target_id';
  $handler->display->display_options['filters']['field_sucursal_target_id']['expose']['remember_roles'] = array(
    2 => '2',
  );
  /* Criterios de filtrado: Campo: Zona (field_zona) */
  $handler->display->display_options['filters']['field_zona_target_id']['id'] = 'field_zona_target_id';
  $handler->display->display_options['filters']['field_zona_target_id']['table'] = 'field_data_field_zona';
  $handler->display->display_options['filters']['field_zona_target_id']['field'] = 'field_zona_target_id';
  $handler->display->display_options['filters']['field_zona_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_zona_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_zona_target_id']['expose']['operator_id'] = 'field_zona_target_id_op';
  $handler->display->display_options['filters']['field_zona_target_id']['expose']['label'] = 'Zona';
  $handler->display->display_options['filters']['field_zona_target_id']['expose']['operator'] = 'field_zona_target_id_op';
  $handler->display->display_options['filters']['field_zona_target_id']['expose']['identifier'] = 'field_zona_target_id';
  $handler->display->display_options['filters']['field_zona_target_id']['expose']['remember_roles'] = array(
    2 => '2',
  );
  /* Criterios de filtrado: Campo: Grupo (field_grupo) */
  $handler->display->display_options['filters']['field_grupo_target_id']['id'] = 'field_grupo_target_id';
  $handler->display->display_options['filters']['field_grupo_target_id']['table'] = 'field_data_field_grupo';
  $handler->display->display_options['filters']['field_grupo_target_id']['field'] = 'field_grupo_target_id';
  $handler->display->display_options['filters']['field_grupo_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_grupo_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_grupo_target_id']['expose']['operator_id'] = 'field_grupo_target_id_op';
  $handler->display->display_options['filters']['field_grupo_target_id']['expose']['label'] = 'Grupo';
  $handler->display->display_options['filters']['field_grupo_target_id']['expose']['operator'] = 'field_grupo_target_id_op';
  $handler->display->display_options['filters']['field_grupo_target_id']['expose']['identifier'] = 'field_grupo_target_id';
  $handler->display->display_options['filters']['field_grupo_target_id']['expose']['remember_roles'] = array(
    2 => '2',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/datos-trimestres';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Datos trimestre';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['admin_datos_trimestres'] = array(
    t('Master'),
    t('Admin Datos Trimestres'),
    t('más'),
    t('Aplicar'),
    t('Restablecer'),
    t('Ordenar por'),
    t('Asc'),
    t('Desc'),
    t('Elementos por página'),
    t('- Todo -'),
    t('Desplazamiento'),
    t('« primero'),
    t('‹ anterior'),
    t('siguiente ›'),
    t('última »'),
    t('- Choose an operation -'),
    t('Trimestre'),
    t('Tipo'),
    t('Sucursal'),
    t('Zona'),
    t('Grupo'),
    t('Acciones'),
    t('Enlace de borrado'),
    t('Enlace de edición'),
    t('Page'),
  );
  $export['admin_datos_trimestres'] = $view;

  return $export;
}
