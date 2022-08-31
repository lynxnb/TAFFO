/*
* C translation of Fortran types defined in `definitions.f90`
* 
* The following documentation has been used for translations:
* - https://docs.oracle.com/cd/E19205-01/819-5262/6n7bvdr18/
* 
*/

// LOGICAL Fortran type
typedef int logical;

typedef struct state_type_t {
  logical defined;
  double density, energy, xvel, yvel;
  int geometry;
  double xmin;
  double xmax;
  double ymin;
  double ymax;
  double radius;
} state_type;

extern state_type *states;
extern int number_of_states;

typedef struct grid_type_t {
  double xmin;
  double ymin;
  double xmax;
  double ymax;
  int x_cells;
  int y_cells;
} grid_type;

extern int step;
extern logical advect_x;

extern int tiles_per_chunk;

extern int error_condition;

extern int test_problem;
extern logical complete;

extern logical use_fortran_kernels;
extern logical use_C_kernels;
extern logical use_OA_kernels;

extern logical profiler_on;

typedef struct profiler_type_t {
  double timestep;
  double acceleration;
  double PdV;
  double cell_advection;
  double mom_advection;
  double viscosity;
  double ideal_gas;
  double visit;
  double summary;
  double reset;
  double revert;
  double flux;
  double tile_halo_exchange;
  double self_halo_exchange;
  double mpi_halo_exchange;
} profiler_type;

extern profiler_type profiler;

extern double end_time;

extern int end_step;

extern double dtold;
extern double dt;
extern double time;
extern double dtinit;
extern double dtmin;
extern double dtmax;
extern double dtrise;
extern double dtu_safe;
extern double dtv_safe;
extern double dtc_safe;
extern double dtdiv_safe;
extern double dtc;
extern double dtu;
extern double dtv;
extern double dtdiv;

extern int visit_frequency;
extern int summary_frequency;

extern int jdt;
extern int kdt;

typedef struct field_type_t {
  double *density0;
  double *density1;
  double *energy0;
  double *energy1;
  double *pressure;
  double *viscosity;
  double *soundspeed;
  double *xvel0;
  double *xvel1;
  double *yvel0;
  double *yvel1;
  double *vol_flux_x;
  double *mass_flux_x;
  double *vol_flux_y;
  double *mass_flux_y;
  double *work_array1;
  double *work_array2;
  double *work_array3;
  double *work_array4;
  double *work_array5;
  double *work_array6;
  double *work_array7;

  double *cellx;
  double *celly;
  double *vertexx;
  double *vertexy;
  double *celldx;
  double *celldy;
  double *vertexdx;
  double *vertexdy;

  double *volume;
  double *xarea;
  double *yarea;
} field_type;

typedef struct tile_type_t {
  field_type field;
  int tile_neighbours[4];
  int external_tile_marks[4];
  
  int t_xmin;
  int t_xmax;
  int t_ymin;
  int t_ymax;

  int t_left;
  int t_right;
  int t_bottom;
  int t_top;
} tile_type;

typedef struct chunk_type_t {
  int task;
  int chunk_neighbours[4];

  double *left_rcv_buffer;
  double *right_rcv_buffer;
  double *bottom_rcv_buffer;
  double *top_rcv_buffer;

  double *left_snd_buffer;
  double *right_snd_buffer;
  double *bottom_snd_buffer;
  double *top_snd_buffer;

  tile_type *tiles; // allocatable

  int x_min;
  int y_min;
  int x_max;
  int y_max;

  int left;
  int right;
  int bottom;
  int top;
  int left_boundary;
  int right_boundary;
  int bottom_boundary;
  int top_boundary;
} chunk_type;

extern chunk_type chunk;
extern int number_of_chunks;

extern grid_type grid;
