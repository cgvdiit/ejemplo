(function ($) {
  var appData = {};

  $.fn.updateDrilldown = function(point) {
    Drupal.settings.caja18.drilldown.point = $.extend({}, point);
    var url = "ajax/indicadores/" + Drupal.settings.caja18.tipo + "/" + point.id;
    $.ajax({
      type: "POST",
      url: url,
      data: Drupal.settings.caja18.postData, // serializes the form's elements.
      error: function( jqXHR, textStatus, errorThrown ) {
        console.log("error updateDrilldown");
      },
      success: function(data) {
        var chart = $('#grafico-resumen').highcharts();
        chart.options.lang.drillUpText = "◁ Volver";
        chart.hideLoading();
        if (Drupal.settings.caja18.drilldown.active) {
          $.each(chart.series, function() {
            var chartSerie = this;
            var serie = data.series.find(function(item) {
              return item.name == chartSerie.name;
            });
            var newSerie = $.extend({}, serie);
            chartSerie.setData(newSerie.data, true, null, false);
          });
        } else {
          $.each(data.series, function() {
            var serie = $.extend({}, this);
            chart.addSingleSeriesAsDrilldown(Drupal.settings.caja18.drilldown.point, serie);
          });
        }
        Drupal.settings.caja18.drilldown.active = true;
        chart.update({
          xAxis: {
            labels: {
              rotation: -90
            }
          }
        });
        chart.applyDrilldown();
      }
    });
  }

  $.fn.updatePromedios = function() {
    url = "ajax/promedios/" + Drupal.settings.caja18.tipo;
    $.ajax({
      type: "POST",
      url: url,
      error: function( jqXHR, textStatus, errorThrown ) {
        console.log("error updatePromedios");
      },
      data: Drupal.settings.caja18.postData,
      success: function(data) {
        $('.promedios .grafico').each(function() {
          var chart = $(this).highcharts();
          if (chart != undefined && chart.series.length) {
            chart.series[0].remove();
          }
        });

        $.each(data, function() {
          var chart = $('#grafico-ratio-' + this.point_id).highcharts();
          chart.update({
            yAxis: {
              title: {
                text: this.point_name
              }
            }
          });
          chart.addSeries({
            name: this.indicador_name,
            id:  this.indicador_name,
            data: [this.point_y * 1]
          });
        });
      }
    });
  }

  $.fn.updateData = function() {
    var url = "ajax/indicadores/" + Drupal.settings.caja18.tipo;
    $.ajax({
      type: "POST",
      url: url,
      data: Drupal.settings.caja18.postData,
      error: function( jqXHR, textStatus, errorThrown ) {
        console.log("error updateData");
      },
      success: function(data) {
        appData.tipo = data.tipo;
        appData.filtro_principal = data.filtro_principal;
        appData.seleccion_semana = data.seleccion_semana;
        appData.muestra = data.muestra;
        appData.load = true;
        var chart = $('#grafico-resumen').highcharts();
        chart.hideLoading();
        if (!chart.series.length) {
          $.each(data.series, function() {
            chart.addSeries(this);
          });
        }
        $.each(chart.series, function() {
          var chartSerie = this;
          var serie = data.series.find(function(item) {
            return item.name == chartSerie.name;
          });
          var newSerie = $.extend({}, serie);
          chartSerie.setData(newSerie.data, true, null, false);
        });
        Drupal.settings.caja18.drilldown.active = false;
        chart.update({
          xAxis: {
            labels: {
              rotation: 0
            }
          }
        });
        if (appData.setView) {
          updateSelectionView();
        }
      }
    });
  }

  function updateSelectionView() {
    $("#tipo_medicion").html("<strong>" + appData.tipo.label + "</strong>");
    var option = $("select[name='" + appData.filtro_principal.element + "'] option[value='" + appData.filtro_principal.valor + "']").html();
    if (!option) {
      option = "";
    }
    $("#filtro_principal").html(appData.filtro_principal.tipo + ": <strong>" + option + "</strong>");
    $("#seleccion_semana").html("");
    if (appData.seleccion_semana.label != "") {
      option = $("select[name='semana'] option[value='" + appData.seleccion_semana.from + "']").html();
      $("#seleccion_semana").html(appData.seleccion_semana.label + ": <strong>" + option + "</strong>");
    }
    var muestra = appData.muestra;
    if (!muestra) {
      muestra = "";
    }
    $("#tamano_muestra").html("Muestra Nº <strong>" + muestra + "</strong>");
  }

  $.fn.getFilterData = function(trimestre) {
    if (trimestre == undefined) {
      trimestre = "";
    }
    var url = "ajax/filter-data/" + Drupal.settings.caja18.tipo;
    if (trimestre) {
      url += "/" + trimestre;
    }
    $.ajax({
      type: "GET",
      url: url,
      trimestre: trimestre,
      error: function( jqXHR, textStatus, errorThrown ) {
        console.log("error getFilterData");
      },
      success: function(data) {
        var ajax = this;
        $.each(data, function(key, newOptions) {
          var select = $("#caja18-dashboard-filter-form select[name='" + key + "']");
          var selectedOption = select.val();
          if (key == "trimestre") {
            if (ajax.trimestre != "") {
              selectedOption = ajax.trimestre;
            } else {
              selectedOption = newOptions[0].id;
            }
          }
          var options;
          if(select.prop) {
            options = select.prop('options');
          }
          else {
            options = select.attr('options');
          }
          $('option', select).remove();
          var emptyItem = newOptions.find(title => title == '');
          if (newOptions.length == 1 && emptyItem != undefined) {
            return;
          }
          $.each(newOptions, function() {
              options[options.length] = new Option(this.title, this.id);
          });
          select.val(selectedOption);
        });
        Drupal.settings.caja18.postData = $('#caja18-dashboard-filter-form').serialize();
        if (appData.load) {
          updateSelectionView();
        }
        appData.setView = true;
      }
    });
  }

  Drupal.behaviors.caja18FilterForm = {
    attach: function (context, settings) {
      $('#caja18-dashboard-filter-form input[type="submit"]', context).click(function () {
        $("#console .messages.warning.semana").remove();
        $('#grafico-resumen').highcharts().showLoading('Cargando Selección ...');
        var form = $(this).closest('form');
        if ($("select[name='semana']", form).val() != "" && $("select[name='semana_hasta']", form).val() != "") {
          if ($("select[name='semana']", form).val() > $("select[name='semana_hasta']", form).val()) {
            $fin = $("select[name='semana']", form).val();
            $("select[name='semana']", form).val($("select[name='semana_hasta']", form).val());
            $("select[name='semana_hasta']", form).val($fin);
            if (!$("#console").get(0)) {
              $("#page #content > .element-invisible:first-child").after('<div id="console" class="clearfix"></div>');
            }
            $("#console").append('<div class="messages warning semana">Se ajusta rango de fecha: Semana debe ser menor que Hasta.</div>');
          }
        }
        Drupal.settings.caja18.filter = form.serializeArray();
        Drupal.settings.caja18.postData = form.serialize();
        if (Drupal.settings.caja18.drilldown.filter.length) {
          Drupal.settings.caja18.drilldown.active = false;
          $('#grafico-resumen').highcharts().drillUp();
        }
        appData.load = false;
        appData.setView = false;
        if (Drupal.settings.caja18.drilldown.active) {
          $.fn.updateDrilldown(Drupal.settings.caja18.drilldown.point);
        } else {
          $.fn.updateData();
        }
        $.fn.updatePromedios();
        $.fn.getFilterData($('#caja18-dashboard-filter-form select[name="trimestre"]').val());
        return false;
      });

      $('#caja18-dashboard-filter-form select[name="trimestre"]', context).change(function () {
        var form = $('#caja18-dashboard-filter-form', context);
        $('input[type="submit"]', form).click();
      });
      $('#caja18-dashboard-filter-form select[name="grupo"]', context).change(function () {
        var zonaValue = $('#caja18-dashboard-filter-form select[name="zona"]', context).val();
        var filter = {
          'grupo': this.value,
          'zona': zonaValue
        };
        $('#caja18-dashboard-filter-form select[name="zona"] option').each(function() {
          if (filter.grupo == '') {
            $(this).show();
          } else {
            $(this).hide();
          }
        });
        $('#caja18-dashboard-filter-form select[name="sucursal"] option', context).filterOptions(filter);
      });
      $('#caja18-dashboard-filter-form select[name="zona"]', context).change(function () {
        var grupoValue = $('#caja18-dashboard-filter-form select[name="grupo"]', context).val();
        var filter = {
          'grupo': grupoValue,
          'zona': this.value
        };
        $('#caja18-dashboard-filter-form select[name="sucursal"] option', context).filterOptions(filter);
      });

    }
  };

  $.fn.filterOptions = function(filter) {
    return this.each(function() {
      $(this).hide();
      var conditionGrupo = $(this).attr('grupo') == filter.grupo || filter.grupo == '' || $(this).attr('grupo') == undefined;
      var conditionZona = $(this).attr('zona') == filter.zona || filter.zona == '' || $(this).attr('zona') == undefined;
      if (conditionGrupo && conditionZona) {
        $(this).show();
        if (filter.grupo != '') {
          $('#caja18-dashboard-filter-form select[name="zona"] option[value="' + $(this).attr('zona') + '"]').show();
        }
      }
    });
  }

  $(document).ready(function() {
    $('form .medicion-actual').each(function() {
      $(this).show();
    });
    $('form .medicion-actual').show();
  });

}(jQuery));
