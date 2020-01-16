(function ($) {

  $(document).ready(function() {
    $('#grafico-resumen').highcharts({
      chart: {
        type: 'column',
        events: {
          drillup: function() {
            $('.content.promedios').show();
            Drupal.settings.caja18.drilldown.active = false;
            setTimeout(function(){
              var chart = $('#grafico-resumen').highcharts();
              chart.update({
                xAxis: {
                  labels: {
                    rotation: 0
                  }
                }
              });
              chart.reflow();
            }, 0);
          },
          drilldown: function (e) {
            $('.content.promedios').hide();
            Drupal.settings.caja18.drilldown.filter = Drupal.settings.caja18.filter;
            if (!e.seriesOptions) {
              if (e.point.indicador == "3") {
                var chart = this;
                // Show the loading label
                chart.showLoading('Cargando Sucursales ...');
                $.fn.updateDrilldown(e.point);
              }
            }
          }
        }
      },
      title: {
          text: ''
      },
      credits: {
        enabled: false
      },
      subtitle: {
          text: ''
      },
      xAxis: {
        type: 'category'
      },
      yAxis: { // Primary yAxis
        title: {
          text: null
        }
      },
      plotOptions: {
        scatter: {
          marker: {
            symbol: 'circle',
            radius: 5
          }
        },
        series: {
            dataLabels: {
              enabled: true,
              color: '#000000',
              formatter: function () {
                return Highcharts.numberFormat(Math.abs(this.point.y), 1) + '%';
              }
            }
        },
        column: {
          grouping: false,
          shadow: false,
          borderWidth: 0
        }
      },
      tooltip: {
        formatter: function () {
          return '<b>' + this.series.name + '' + '</b><br/>' +
            'Valor Promedio: ' + Highcharts.numberFormat(Math.abs(this.point.y), 1) + '%';
        }
      },
      series: [],
      drilldown: {
        drillUpButton: {
          position: {
              verticalAlign: 'bottom',
              y: 90
          }
        },
        allowPointDrilldown: false,
        activeAxisLabelStyle: {
          textDecoration: 'none',
        },
        activeDataLabelStyle: {
            textDecoration: 'none',
            color: '#FFFFFF'
        },
        series: []
      }
    });
    $('#caja18-dashboard-filter-form input[type="submit"]').click();
  });

}(jQuery));
